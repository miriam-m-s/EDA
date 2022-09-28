// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include"bintree.h"
using namespace std;
// función que resuelve el problema
bool resolve(bintree<char>tree1, bintree<char>tree2) {
    if (tree1.empty() && tree2.empty())return true;
    else if(tree1.empty() || tree2.empty()) return false;
    if (tree1.root() == tree2.root()) {
        bool izq = false; bool der = false;
        izq= resolve(tree1.left(), tree2.right());
        der= resolve(tree1.right(), tree2.left());
        return der && izq;
    }
    else return false;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<char>tree;
    tree = leerArbol(char('.'));
    if (resolve(tree.left(), tree.right())) {
        cout << "SI" << endl;
    }
    else cout << "NO" << endl;

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