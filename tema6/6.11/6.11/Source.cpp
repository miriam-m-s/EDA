
#include <iostream>
#include <fstream>
#include<vector>
#include "bintree.h"
using namespace std;
int resolver(bintree<int>const& tree, int& busqueda) {
    if (tree.empty()) {
        return 0;
    }
    int personaizq = resolver(tree.left(), busqueda);
    int personader = resolver(tree.right(), busqueda);
    if (tree.root() != 0) {
        if (personaizq == 0 && personader == 0) {
            busqueda++;
            return tree.root();
        }
        else if (personaizq > personader) {
            personaizq += tree.root();
        }
        else {
            personader += tree.root();
        }
    }
    if (personader > personaizq) {
        return personader;
    }
    else {
        return personaizq;
    }

}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    bintree<int> tree;
    tree = leerArbol(-1);
    int busqueda=0;
    int mayor = resolver(tree, busqueda);
    std::cout << busqueda << " " <<mayor<< std::endl;

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
