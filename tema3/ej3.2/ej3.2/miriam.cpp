// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
void resolver(vector<int>&v, int n, int m, int k,vector<bool>&usadas) {

    for (int x = 0; x < m; x++) {
        v[k] = x;
        if (!usadas[x - 'a']) {
            if (k == n - 1) {
                for (int i = 0; i < n; i++) {
                    cout << sol[i];
                }
                cout << endl;
            }
            }
            else {
                usadas[x - 'a'] = true;
                resolver(v, n, m, k + 1, usadas);
                usadas[x - 'a'] = false;
            }
        }
        
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int  m = 0;
    cin >> m ;
    if (!std::cin)
        return false;
    else {

        int sol;
        vector<bool>u(m);
        vector<int> v(m)
        resolver(sol,v, n, m, 0,u);
      
    }

    return true;


    // escribir sol


    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    //std::ifstream in("datos.txt");
    //auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
   /* std::cin.rdbuf(cinbuf);
    system("PAUSE");*/
#endif

    return 0;
}