// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "list_eda.h"
using namespace std;
// función que resuelve el problema
//TipoSolucion resolver(TipoDatos datos) {
//
//
//}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    list<int>l;
    int s;
    cin >> s;
    l.push_back(s);
    while (s != -1) {
        cin >> s;
        if(s!=-1)
        l.push_back(s);
    }
   
    int borrar;
    cin >> borrar;
    for (list<int>::iterator it = l.begin(); it != l.end(); ++it) {
        cout << *it << " ";
    }
    l = l.borragelem(borrar);
    
    
    cout << endl;
    for (list<int>::iterator it = l.begin(); it != l.end();it++) {
        cout << *it << " ";
        *it = 7;
       
    }
    

    cout << endl;
    // escribir sol


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