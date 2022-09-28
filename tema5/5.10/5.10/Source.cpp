// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "list.h"

using namespace std;
// función que resuelve el problema
void resolver(list<int>&l) {
    int x;
    int i = 0;
    for (list<int>::iterator it = l.begin(); it != l.end();) {
        if (i != 0 && (*it) < x) {
            it=l.erase((it));
        }
        else {
            x = (*it);
            ++it;
        }
     
        i++;
    
    }
    for (list<int>::iterator it = l.begin(); it != l.end(); ++it) {
        cout << *it<<" ";
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    list<int>l;
    int s;
    cin >> s;
   
   
    while (s != -1) {       
        l.push_back(s);
        cin >> s;       
    }
    resolver( l);
  
    // escribir sol
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