// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;
// función que resuelve el problema
int resolver(bintree<int> tree,int &maxexcur,int &grupresc) {
    if (tree.empty()) {
        return 0;
    }
   int left= resolver(tree.left(), maxexcur, grupresc);
   int right= resolver(tree.right(), maxexcur, grupresc);
   if (left + tree.root() > maxexcur)maxexcur = left + tree.root();
   if (right + tree.root() > maxexcur)maxexcur = right + tree.root();
    if (tree.root() > 0&&left == 0 && right == 0) { grupresc++; }
    if (left > right) {
        return left + tree.root();
    }
    else {
        return right + tree.root();
    }
      
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int>tree;
    tree = leerArbol(-1);
    int grupresc = 0;
    int maxresc = 0;

    resolver(tree, maxresc, grupresc);
    cout << grupresc << " " << maxresc << endl;
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