// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include"Class.h"
using namespace std;
// función que resuelve el problema
int resolve(bintree<int>tree, int& tramonavegable) {
    if (tree.empty()) {
        return 0;
    }
    if (tree.left().empty() && tree.right().empty())return 1;
    int izq = resolve(tree.left(), tramonavegable);
    int der = resolve(tree.right(), tramonavegable);
    if (der + izq - tree.root() >= 3)tramonavegable++;
    int resultado = der + izq - tree.root();
    if (resultado < 0)return 0;
    else return resultado;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    bintree<int>tree;
    tree = leerArbol(-1);
    int tramonavegable=0;
    int h=resolve(tree, tramonavegable);
    if (h >= 3)tramonavegable--;
    cout << tramonavegable << endl;

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