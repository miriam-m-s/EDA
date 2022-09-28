// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
#include "horas.h"

using namespace std;

// función que resuelve el problema
void resolver(const vector<horas>prev, const vector<horas>llegada) {
    for (int i = 0; i < llegada.size(); i++) {
        if (llegada[i].estamalahora())cout << "ERROR"<<endl;
        else {
            bool hey = false;
            int j = 0;
            while (j < prev.size() && !hey) {
                if (llegada[i] <= prev[j])hey = true;
                j++;
            }
            if (hey)cout << prev[j - 1]<<endl;
            else cout << "NO" << endl;
        }
       
    }
    cout << "---" << endl;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numtren ,nhor;
    cin >> numtren >> nhor;
    if (numtren==0&&nhor==0)
        return false;
    vector<horas>prev(numtren);
    for (int i = 0; i < prev.size(); i++) {
        cin >> prev[i];
    }
    vector<horas>llegada(nhor);
    for (int i = 0; i < nhor; i++) {
        cin >> llegada[i];
    }
    resolver(prev, llegada);


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