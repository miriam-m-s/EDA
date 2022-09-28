// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<climits>
#include"bintree.h"
using namespace std;
bool resolver(bintree<int>tree, int& max, int& min) {
    if (tree.empty()) {
        min = INT_MAX;
        max = INT_MIN;
        return true;
    }
    int minizq, maxizq, minder, maxder;
    bool izq = resolver(tree.left(), maxizq, minizq);
    bool der = resolver(tree.right(), maxder, minder);

   if (tree.root() > maxizq && tree.root() < minder) {
       if (maxizq == INT_MIN)min = tree.root();
       else min = maxizq;
       if (minder == INT_MAX)max = tree.root();
       else max = minder;
    
      
        return izq && der;
    }
    else return false;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int>tree;
    tree = leerArbol(-1);
   int max= INT_MIN;
  int min = INT_MAX;
  
  if (resolver(tree, max, min))cout << "SI" << endl;
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