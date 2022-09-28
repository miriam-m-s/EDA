// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue.h"
using namespace std;


// función que resuelve el problema
void escribe(queue<int>&m) {
    int s = m.size();
    for (int i = 0; i < s; i++) {
        cout << m.front() << " ";
        m.pop();
    }
    cout << endl;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    queue<int>m;
    int h;
    cin >> h;
  


    while (h != 0) {
        m.push(h);
        cin >> h;
    }
    cin >> h;
    queue<int>r;
    while (h != 0) {
        r.push(h);
        cin >> h;
    }
    if (r.size() == 0) {
        escribe(m);
    }
    else if (m.size() == 0) {
        escribe(r);
    }
    else {
        m.une(r);
        escribe(m);
    }
    return true;
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