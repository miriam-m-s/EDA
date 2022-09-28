
#include <iostream>
#include <fstream>
#include<vector>
#include "bintree.h"
using namespace std;
int resolver(bintree<int>const& tree,int & navegable,bool & s) {
    if (tree.empty()) {
        navegable = 0;
        s = true;
        return 0;
    }
    int navizq; int navder;
    int numizq = resolver(tree.left(), navizq,s);
    int numder = resolver(tree.right(), navder,s);
    navegable = navizq + navder;
    if (s && numizq == 0 && numder == 0) { s = false; return 1; }

    else {
        int suma = numder + numizq - tree.root();
        if (suma >= 3)navegable++;
        if(suma>=0)return suma;
        else return 0;
    }
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    bintree<int> tree;
    tree = leerArbol(-1);
    int navegable = 0;
    bool h;
    int s = resolver(tree, navegable,h);
        if (s >= 3)navegable--;
        cout <<navegable << endl;
 
   

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
