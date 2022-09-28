
#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
#include "bintree.h"

using namespace std;
bool essimetrico(bintree<char>const& tree, bintree<char>const& tree2) {
    if (tree.empty() && tree2.empty())return true;
    else if (!tree.empty() && tree2.empty() || tree.empty() && !tree2.empty())return false;
    else {
        return((essimetrico(tree.left(), tree2.right()))&&essimetrico(tree.right(),tree2.left()));
    }
    
  
    
}

void resolver(bintree<char>const &tree) {
    bool hey = true;
    if(!tree.empty())
    hey= essimetrico(tree,tree);

    if(hey)cout << "SI";
    else cout << "NO";
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    bintree<char> tree;
    tree = leerArbol('.');
    resolver(tree);
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
