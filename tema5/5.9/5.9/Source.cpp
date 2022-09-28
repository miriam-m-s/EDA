// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<list>;
using namespace std;



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int nalums, salta;
    cin >> nalums >> salta;
    if (nalums==0&&salta==0)
        return false;
    list<int>hey;
    for (int i = 0; i < nalums; i++) {
        hey.push_back(i + 1);
    }
    int i = 0;
    list<int>::iterator it = hey.begin();
    while (hey.size() != 1) {
        if (i == salta) {
            i = 0;
            it = hey.erase(it);
            if(it == hey.end())  it = hey.begin();
        }
        else {
          
            if (it != hey.end()) {
                ++it;
                if((it != hey.end()))
                i++;
            }
            else {
                it = hey.begin();
                i++;
            }
            
        }
        
    }

    for (list<int>::iterator il = hey.begin(); il != hey.end(); ++il) {
        cout << *il << " ";
    }
    // escribir sol
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
