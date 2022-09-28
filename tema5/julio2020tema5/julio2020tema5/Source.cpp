// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
#include<stack>
using namespace std;




// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int tam, pos1, anchura;
    list<int>lis;
    cin >> tam >> pos1 >> anchura;
    if (!std::cin)
        return false;
    pos1--;
    stack<int>pila;
    int h;
    for (int i = 0; i < tam; i++) {
        cin >> h;
        if (i >= pos1 && i < pos1 + anchura) {
            pila.push(h);
        }
        else lis.push_back(h);
    }
    int i = 0;
    bool hu = false;
    if (lis.size() == 0)hu = true;
    for (list<int>::iterator il = lis.begin(); il != lis.end() || hu; ++il) {
        if (i == pos1 ) {
            int s = pila.size();
            for (int j = 0; j < s; j++) {
                il=lis.insert( il,pila.top());
                pila.pop();
                ++il;
            }
            hu = false;
            il--;
        }
            i++;
    }
    for (list<int>::iterator il = lis.begin(); il != lis.end(); il++) {
        cout << *il<<" ";
    }
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


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}