// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
#include<cmath>
using namespace std;

// función que resuelve el problema
int resolver(vector<int>&v,int ini,int fin) {
    int n = fin - ini;
    if (n == 2) {
        if (abs(v[ini]) > abs(v[ini + 1])) {
            return v[ini];
        }
        else return v[ini+1];
    }
    else if (n == 1)return v[ini];
    int mid = (fin + ini) / 2;
    if (abs(v[ini]) < abs(v[mid]) && abs(v[fin - 1]) < abs(v[mid])) {
        if (abs(v[mid + 1]) > abs(v[mid])) {
            resolver(v, ini, mid);
        }
        else resolver(v, mid, fin);
    }
    if (abs(v[ini]) > abs(v[mid]) && abs(v[fin - 1]) > abs(v[mid])) {
        if (abs(v[fin-1]) > abs(v[ini]))resolver(v, mid, fin);
        else resolver(v, ini, mid);
    }
    else if(abs(v[ini]) < abs(v[mid]) && abs(v[fin - 1]) > abs(v[mid]))resolver(v, mid, fin);
    else resolver(v, ini, mid);

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int h;
    cin >> h;
    if (h==0)
        return false;
    vector<int>v;
    while (h != -1) {
        v.push_back(h);
        cin >> h;
    }
   cout<< resolver(v, 0, v.size())<<endl;
    //TipoSolucion sol = resolver(datos);

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
