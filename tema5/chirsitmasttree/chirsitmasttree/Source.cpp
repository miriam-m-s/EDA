// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include"bintree.h"
#include<cmath>
using namespace std;
bool resuelve(bintree<char>tree,int & luces ) {
    if (tree.empty()) {
        luces = 0;
        return true;
    }
    int lucesizq = 0; int lucesder = 0;
    bool izq = resuelve(tree.left(), lucesizq);
    bool der= resuelve(tree.right(), lucesder);
    int l = 0;
    if (tree.root() == '*')l=1;
    luces = lucesizq + lucesder + l;
    return (izq && der && abs(lucesder - lucesizq) <= 1);
    
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    bintree<char>s;

    s = leerArbol(char('x'));
    int luces = 0;
    if (resuelve(s, luces))cout << "SI";
    else cout << "NO";
    cout << endl;

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        resuelveCaso();
    }

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}