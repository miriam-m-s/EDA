// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
void resolver(vector<char>& sol, int n, int m, int k) {

    for (char x = 'a'; x < 'a' + m; x++) {
        sol[k] = x;
        if (k == n - 1) {
            for (int i = 0; i < n; i++) {
                if(sol[i]=='a')
                cout << "azul";
                else if(sol[i] == 'b') cout << "rojo";
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

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int n = 0, m = 3;
    cin >> n;
    if (n==0)
        return false;
    else {

        vector<char>sol(n);
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