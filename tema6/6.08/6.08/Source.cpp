
#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>

using namespace std;
#include "bintree.h"

bool resolver(bintree<int>const& tree, int& min, int& max) {
    if (tree.empty()) {
        min = 2147483647;
        max = -2147483648;
        return true;
    }
    int minizq, minder, maxizq, maxder;
    bool esizq = resolver(tree.left(), minizq, maxizq);
    bool esder = resolver(tree.right(), minder, maxder);
    if (minder < minizq) {
        if (minder < tree.root()) {
            min = minder;
        }
        else min = tree.root();
    }
    else {
        if (minizq < tree.root()) {
            min = minizq;
        }
        else min = tree.root();
    }
    if (maxder > maxizq) {
        if (maxder > tree.root()) {
           max = maxder;
        }
        else max = tree.root();
    }
    else {
        if (maxizq >tree.root()) {
            max = maxizq;
        }
        else max= tree.root();
    }
    return esizq && esder && tree.root() > maxizq && tree.root() < minder;

}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    bintree<int> tree;
    tree = leerArbol(-1);
    int min = 0;
    int max = 0;
  bool h=  resolver(tree, min, max);
  if (h)std::cout << "SI" << std::endl;
  else std::cout << "NO" << std::endl;

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
        //if (i == 2)cout << "hey";
        resuelveCaso();
    }


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
