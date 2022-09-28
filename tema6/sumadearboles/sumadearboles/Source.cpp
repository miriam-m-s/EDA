// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
#include"bintree.h"
using namespace std;
// función que resuelve el problema
void sumaarbol(bintree<int>tree, bintree<int>tree1, vector<int>& suma,int &sum) {
    if (tree.empty() && tree1.empty()) {
        suma.push_back(-1);

    }
    else if (tree.empty() && !tree1.empty()) {
        suma.push_back(tree1.root());
        sum += tree1.root();
        sumaarbol(tree, tree1.left(), suma, sum);
        sumaarbol(tree, tree1.right(), suma, sum);
    }
    else if (!tree.empty() && tree1.empty()) {
        suma.push_back(tree.root());
        sum += tree.root();
        sumaarbol(tree.left(), tree1, suma, sum);
        sumaarbol(tree.right(), tree1, suma, sum);
    }
    else {
        suma.push_back(tree.root()+ (tree1.root()));
        sum += tree.root()+ (tree1.root());
        sumaarbol(tree.left(), tree1.left(), suma, sum);
        sumaarbol(tree.right(), tree1.right(), suma, sum);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    bintree<int>tree;
    tree = leerArbol(-1); 
    bintree<int>tree1;
    tree1 = leerArbol(-1);
    int sum = 0;
    vector<int>suma;
    sumaarbol(tree, tree1, suma, sum);
  
    for (auto c:suma) {
        cout << c << " ";
    }
    cout << sum << endl;
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