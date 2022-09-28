// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;

// función que resuelve el problema
int resolver(const vector<int>&v,int ini ,int fin) {
    int n = fin - ini;
    if (n == 1) {
        if (v[ini] % 2 != 0)
            return v[ini];
        else return 0;
    }
    int mid = (fin + ini) / 2;
    if (v[ini] % 2 != 0)return v[ini];
    else if (v[fin - 1] % 2 != 0)return v[fin - 1];
    else {

        int l=resolver(v, ini, mid);
        if (l == 0) {
            return resolver(v, mid, fin);

        }
        else return l;
        
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tam;

    cin >> tam;
    if (tam==0)
        return false;
    vector<int>v(tam);
    for (int i = 0; i < tam; i++) {
        cin >> v[i];
    }
    cout << resolver(v, 0, v.size())<<endl;
    // escribir sol

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
