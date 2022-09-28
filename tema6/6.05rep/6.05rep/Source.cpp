// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include"bintree_eda.h"
using namespace std;
// función que resuelve el problema
bool resolver(const bintree<int>&tree,int& niveles,int k) {
    if (tree.empty()) {
       
        return true;
    }
    if (k > niveles)niveles = k;
    bool der = true;
    bool izq = true;
    if (!tree.right().empty()) {
       
        if (tree.left().empty())return false;
        else if (!(tree.left().root() - tree.right().root() >= 2))return false;
        else if (tree.root() - tree.right().root() >= 18)
            der = resolver(tree.right(), niveles,k+1);
        else return false;
    } 
    if (!tree.left().empty()) {
        if (tree.root() - tree.left().root() >= 18)
            izq = resolver(tree.left(), niveles,k+1);
        else return false;

    } 
    return (der && izq);
 
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int>tree;
   tree= leerArbol(-1);
   int niveles = 0;
   if (resolver(tree, niveles,1))cout << "SI " << niveles << endl;
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