
#include <iostream>
#include <fstream>
#include<vector>
#include "bintree.h"
using namespace std;
int resolver(bintree<char>const& tree, int& maxcamin) {
    if (tree.empty()) {
        return 0;
    }
    int caminizq = resolver(tree.left(), maxcamin);
    int caminder = resolver(tree.right(), maxcamin);
    int camino = caminizq + caminder + 1;
    caminizq++;
    caminder++;
    if (camino > maxcamin)maxcamin = camino;
  
    if (caminizq > caminder)return caminizq;
    else return caminder;

}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    bintree<char> tree;
    tree = leerArbol('.');
    int busqueda = 0;
    int mayor = resolver(tree, busqueda);
    std::cout << busqueda  << std::endl;

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
    for (int i = 0; i < numCasos; ++i) {
      
        resuelveCaso();
    }


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
