
#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree.h"
#include <climits>
using namespace std;
template <class T>
void menores(bintree<T>h,T&menor) {
    if (!h.empty()) {
        if (h.root() < menor)menor = h.root();
        menores(h.left(), menor);
        menores(h.right(), menor);
    }
   
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    string numCasos;
    cin >> numCasos;
    if (!std::cin)
        return false;
    
    if (numCasos == "P") {
        bintree<string> tree;
        string h = "#";
        tree = leerArbol(h);
       
        if (!tree.empty()) {
            string menos = tree.root();
            menores(tree, menos);
            cout << menos;
        }
        else cout << " ";
        
       
    }
    else {
        bintree<int> tree;
        tree = leerArbol(-1);
    
        if (!tree.empty()) {
            int menos = tree.root();
            menores(tree, menos);
            cout << menos;
        }           
        else cout << "0";
    }
    cout << endl;
   
  
   
}


int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

  
    while (resuelveCaso())
        ;

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
