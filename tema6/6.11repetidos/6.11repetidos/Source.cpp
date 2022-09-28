// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"


using namespace std;
// función que resuelve el problema
int resolver(bintree<int>hey, int& numequipos,int k) {
    if (hey.empty()) {
        return 0;
    }
    int recogidosizq, regogidosder;
    recogidosizq = resolver(hey.left() , numequipos,k++);
    regogidosder = resolver(hey.right(), numequipos,k++);
  
    if (recogidosizq > regogidosder) {
        if (regogidosder > 0)numequipos++;
     
        return hey.root() + recogidosizq;
    }
    else {
        if (recogidosizq > 0)numequipos++;
      
        return hey.root() + regogidosder;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int>hey;
    hey = leerArbol(int(-1));
    int maxexcursionista = 0;
    int excursionista = 0;
    int numequipos = 0;
    maxexcursionista= resolver(hey,numequipos, 0);
    if (maxexcursionista > 0)numequipos++;
    cout << numequipos <<" "<< maxexcursionista << endl;
    // escribir sol


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