// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<list>
using namespace std;

// función que resuelve el problema

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, k;
    cin >> n>>k;
    if (n==0&&k==0)
        return false;
    list<int>lis;

    for (int i = 0; i < n; i++) {
    
        lis.push_back(i+1);
    }
    int i = n;
    int j = 0;
    int cuenta=0;
    list<int>::iterator it= lis.begin();
    while (i > 1) {
        if (it == lis.end())it = lis.begin();
        if (cuenta == k) {
            it = lis.erase(it);
            i--;
            cuenta = 0;
           
        }
        else {
            ++it;
            cuenta++;
        }         
    }
    cout << lis.front() << endl;
    return true;

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
    system("PAUSE");
#endif

    return 0;
}
