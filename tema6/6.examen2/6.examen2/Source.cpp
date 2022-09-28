
#include <iostream>
#include <fstream>
#include<vector>
#include "bintree.h"
using namespace std;
float resolver(bintree<int>const& tree, int& maxcamin,bool & nup, bool& mayor) {
    if (tree.empty()) {
        if (nup) return 0.5;        
        else return 0;
    }
    bool izq = false;
    bool der =false;
    if (tree.right().empty())der=true;
    if (tree.left().empty())izq = true;
    float caminizq = resolver(tree.left(), maxcamin,der,mayor);
    float caminder = resolver(tree.right(), maxcamin, izq,mayor);
    if (caminder  >= 3) {
        maxcamin=maxcamin+1;
      
    }
    if(caminizq>=3)maxcamin = maxcamin + 1;
    else mayor = false;
    if (tree.root() == 0) {
        return caminder + caminizq;
    }
    else {
        float s;
        s = (caminder + caminizq) - tree.root();
        if (s < 0)return 0;
        return s;
    }
 

}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    bintree<int> tree;
    tree = leerArbol(-1);
    int busqueda = 0;
    bool hey = false;
    bool hy=false;
    resolver(tree, busqueda,hey,hy);
   
    //if (hy) { 
 
      //  busqueda = busqueda - 1; }
    std::cout << busqueda << std::endl;

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
