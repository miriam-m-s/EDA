// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
#include"bintree.h"
#include<climits>
using namespace std;
// función que resuelve el problema

bool check_prime(int n) {
    bool is_prime = true;
    // 0 and 1 are not prime numbers
    if (n == 0 || n == 1) {
        is_prime = false;
    }
    for (int i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            is_prime = false;
            break;
        }
    }
    return is_prime;
}
void resolve(bintree<int>tree, int& altura, int k,int& number) {
    if (!tree.empty()) {
        if (tree.root()!=7&&tree.root() % 7 == 0) {
            if (k < altura) {
                number = tree.root();
                altura = k;
            }
        }
        else {
            if (!check_prime(tree.root())) {
                resolve(tree.left(), altura,k+1, number);
                resolve(tree.right(), altura, k + 1, number);
            }
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int>tree;
    tree = leerArbol(-1);
    int altura = INT_MAX;
    int number = -1;

    resolve(tree, altura, 1, number);
    if (number == -1) {
        cout << "NO HAY" << endl;
    }
    else cout << number << " " << altura << endl;

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