// nombre del alumno .....
// usuario del juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;


// función que resuelve el problema
int resolver(const vector<int>& v, int ini, int fin) {
   

        if (v[ini] % 2 != 0) {
            return v[ini];
        }
        else {
            return resolver(v, ini + 1, fin);
        }
    
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelvecaso() {
    // leer los datos de la entrada
    int caso = 0;
    cin >> caso;
    if (caso == 0)
        return false;
    vector<int>m(caso);
    for (int i = 0; i < m.size(); i++) {
        cin >> m[i];
    }
    int sol = resolver(m, 0, m.size());

    cout << sol << endl;

    return true;

}

int main() {
    // para la entrada por fichero.
    // comentar para acepta el reto
#ifndef domjudge
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelvecaso())
        ;


    /* para restablecer entrada. comentar para acepta el reto*/
#ifndef domjudge // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif

    return 0;
}
