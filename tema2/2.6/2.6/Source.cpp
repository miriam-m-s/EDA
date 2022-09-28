﻿// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(vector<int>v,int ini,int fin) {
    int n = fin - ini;
    if (n == 1)return v[ini];
    else if (n == 2) {
        if (v[ini] > v[ini + 1])return v[ini + 1];
        else return v[ini];
    }
    else {
        int med = (ini + fin) / 2;
        if (v[med] > v[med + 1]&&v[med-1]>v[med]) {
            //derecha
            return resolver(v, med, fin);
        }
        else if (v[med] < v[med + 1] && v[med - 1] < v[med]) {
            //izquierda
           return resolver(v, ini, med);
        }
        else {
            return v[med];
        }
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int longi;
    cin >> longi;
    if (!std::cin)
        return false;
    vector<int>v(longi);
    for (int i = 0; i < longi; i++) {
        cin >> v[i];
    }
    if (longi != 0) {
        int sol = resolver(v, 0, v.size());
        cout << sol << endl;
    }
    else cout << endl;
    
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