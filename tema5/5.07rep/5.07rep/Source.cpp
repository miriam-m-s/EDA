// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include"queue_eda.h"
using namespace std;
// función que resuelve el problema

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    queue<int>first;
    int h;
    cin >> h;
    while (h != 0) {
        first.push(h);
        cin >> h;
    }

    queue<int>second;
    cin >> h;
    while (h != 0) {
        second.push(h);
        cin >> h;
    }
    if (first.size() == 0) {
        int s = second.size();
        for (int i = 0; i < s; i++) {
            cout << second.front() << " ";
            second.pop();
        }
    }
    else if (second.size() == 0) {
        int s = first.size();
        for (int i = 0; i < s; i++) {
            cout << first.front() << " ";
            first.pop();
        }
    }
    else {
        first.ordena(second);
        int s = first.size();
        for (int i = 0; i < s; i++) {
            cout << first.front() << " ";
            first.pop();
        }

    }
   
    cout << endl;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}