// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
bool comprueba(int k, vector<int>& sol) {
    if (k > 1 && sol[k] == 2) {
        return (sol[k - 1] == sol[k]);
    }
    else return false;
}
// función que resuelve el problema
void resolver(vector<int>& sol, int n, int m, int k) {
    if (n == 1)cout << "rojo" << endl;
    else {
        if (k == 0) {
            sol[k] = 1;
            k++;
        }
        for (int x = 0; x < m; x++) {
            sol[k] = x;
            if (!comprueba(k, sol)) {
                if (k == n - 1) {
                    for (int i = 0; i < n; i++) {
                        if (sol[i] == 0)
                            cout << "azul";
                        else if (sol[i] == 1) cout << "rojo";
                        else  cout << "verde";
                        cout << " ";
                    }
                    cout << endl;
                }
                else {
                    resolver(sol, n, m, k + 1);
                }
            }

        }
    }
   
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int n = 0, m = 3;
    cin >> n;
    if (n == 0)
        return false;
    else {

        vector<int>sol(n);
       
        resolver(sol, n, m, 0);
        cout << endl;
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