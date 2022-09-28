// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include"bintree.h"
using namespace std;
// función que resuelve el problema
bool resolver(bintree<char>tree,int &nodos) {
    if (tree.empty()) {
        nodos = 0;
        return true;
    }
    int izq, der;
    bool izq1=resolver(tree.left(), izq);
    bool der1=resolver(tree.right(), der);
    nodos = izq + der+1;    
    if (der == 0 && izq == 0) {
        return izq1 && der1;
    }
    else if (izq  <= der) {
        return false;
    }
    else return izq1&&der1;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<char>tree;
    tree = leerArbol(char('.'));
    int nodos = 0;
    if (resolver(tree, nodos))cout << "SI" << endl;
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