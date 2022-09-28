// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;

int resolver(const vector<int>& v, int ini, int fin) {
    int n = fin - ini;
    if (n <= 1) {
        return v[ini];
    }
    else if (n <= 2) {
        if (v[ini] < v[ini + 1])return v[ini];
        else return v[ini + 1];
    }
    else
    {
        int mid = (ini + fin) / 2;
        if (v[ini] > v[fin - 1]) {
            if (v[mid] > v[fin - 1])return resolver(v, mid, fin);
            else return resolver(v, ini, mid);
        }
        else {
            if (v[mid] > v[ini])return resolver(v, ini, mid);
            else return resolver(v, mid, fin);
        }
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tam;
    cin >> tam;
    if (!std::cin)
        return false;
    vector<int>v(tam);
    for (int i = 0; i < tam; i++) {
        cin >> v[i];
    }
    cout << resolver(v, 0, v.size())<< endl;

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}