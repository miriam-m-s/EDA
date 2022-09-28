
#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree.h"
using namespace std;
//costte lineal
bool zurdo(const bintree<char>&tree,int&nnodos) {
    if (tree.empty()) {
        nnodos = 0;
        return true; }
    int numizqu=0 ,numder=0;
    bool esIz = zurdo(tree.left(), numizqu);
    bool esDer = zurdo(tree.right(), numder);
    nnodos = numder + numizqu+1;
    bool h;
    if (numder == 0 && numder == 0)h = true;
    else h = numizqu > numder;

    return esIz&&esDer&& h;
}
bool hey(bintree<char>const& tree) {
    int numnodos = 0;
    return zurdo(tree, numnodos);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<char> tree;
    tree = leerArbol('.');
    int s = 0;
   if (hey(tree))cout << "SI";
   else cout << "NO";
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
    //system("PAUSE");
#endif

    return 0;
}
