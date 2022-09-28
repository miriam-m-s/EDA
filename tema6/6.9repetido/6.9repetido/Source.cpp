// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;
// función que resuelve el problema
int resolver(const bintree<char>tree,int & maxlon) {
    if (tree.empty()) {
        return 0;
    }
    int izquierda, drecha;
    izquierda = resolver(tree.left(), maxlon);
    drecha = resolver(tree.right(), maxlon);
    int lon = drecha + izquierda + 1;
    if (maxlon < lon)maxlon=lon;
    if (izquierda > drecha)return izquierda+1;
    else return drecha+1;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<char>hey;
    hey = leerArbol('.');
    int maxlon = 0;
    resolver(hey, maxlon);
    cout << maxlon << endl;
   // TipoSolucion sol = resolver(datos);
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