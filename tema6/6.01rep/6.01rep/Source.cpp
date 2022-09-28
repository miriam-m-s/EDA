// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree.h"
using namespace std;
// función que resuelve el problema
int resolve(bintree<char>tree,int&hojas,int k,int& altura) {
    if (tree.empty()) {
        if (altura < k)altura = k;
        return 0;
    }
    int left = resolve(tree.left(), hojas, k+1, altura);
    int right = resolve(tree.right(), hojas, k+1, altura);
    if (left == 0&&right==0)hojas++;
 
    return left + right + 1;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<char>tree;
    tree = leerArbol(char('.'));
    int hojas = 0;
    int altura=0;
    int n=resolve(tree, hojas,0 , altura);
    cout << n << " " << hojas << " " << altura << endl;



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