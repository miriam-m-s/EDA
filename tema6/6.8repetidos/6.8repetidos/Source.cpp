// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
#include "bintree.h"
#include <climits>
using namespace std;
int maximo(int a, int b, int c)
{
    if (a > b && a > c)
        return a;
    else if (b > c)
        return b;
    else
        return c;
}

int minimo(int a, int b, int c)
{
    if (a < b && a < c)
        return a;
    else if (b < c)
        return b;
    else
        return c;
}
// función que resuelve el problema
bool resolver( bintree<int>const &arbol,int & maxelem,int & minelem) {
    if (arbol.empty()) {
        minelem = 2147483647;
        maxelem = -2147483648;
        return true;
    }
    int maxelemder, maxelemizq, minelemder, minelemizq;
    bool izq = resolver(arbol.left(), maxelemizq, minelemizq);
    bool der= resolver(arbol.right(), maxelemder, minelemder);

       maxelem = maximo(maxelemizq, maxelemizq, arbol.root());
        minelem = minimo(minelemder, minelemizq, arbol.root());
        return izq && der && (maxelemizq < arbol.root() && minelemder > arbol.root());
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    bintree<int>arbol;
    arbol = leerArbol(int(-1));
    int maxelem ;
    int minelem ;

    bool h = resolver(arbol, maxelem, minelem);
    if (h)cout << "SI" << endl;
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