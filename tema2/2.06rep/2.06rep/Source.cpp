// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include<stack>
using namespace std;

int resuelve(const vector<int>& v, int ini, int fin) {
    int n = fin - ini;

    if (n == 2) {
        if (v[ini] < v[ini + 1])return v[ini];
        else return v[ini + 1];
    }
    else if(n==1)return v[ini];
    else {
        int mid = (fin + ini) / 2;
        if (v[ini] < v[mid] && v[mid] < v[fin - 1])//izquierda
        {
            return resuelve(v, ini, mid);
        }
        else if (v[ini] > v[mid] && v[mid] > v[fin - 1])//derecha
        {
            return resuelve(v, mid, fin);
        }
        else if (v[ini] > v[mid] && v[mid] < v[fin - 1]) {
            if (v[mid] < v[mid + 1] && v[mid] < v[mid - 1])return v[mid];
            else if(v[mid] > v[mid + 1] ) return resuelve(v, mid, fin);
            else   return resuelve(v, ini, mid);
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
    vector<int>h(tam);
    for (int i = 0; i < tam; i++) {
        cin >> h[i];
    }
    cout << resuelve(h, 0, h.size())<<endl;
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