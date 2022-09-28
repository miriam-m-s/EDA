// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include"queue_eda.h"
using namespace std;

void resuelveCaso() {
    queue<int>cola;
    int h;
    cin >> h;
    while (h != -1) {
        cout << h<<" ";
        cola.push(h);
        cin >> h;
    }
    cout << endl;
    int pringao;
    cin >> pringao;
    cin >> h;
    queue<int>cerv;
    while (h != -1) {
        cerv.push(h);
        cin >> h;
    }

    cola.colars(cerv, pringao);
    int size = cola.size();
    for (int i = 0; i < size; i++) {
        cout << cola.front()<<" ";
        cola.pop();
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