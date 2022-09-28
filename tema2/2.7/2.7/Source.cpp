// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;


// función que resuelve el problema
int resolver(vector<int>v,int& ini,int &fin) {
    int n = fin - ini;
    if (n == 1)return v[ini];
    else {
        int medio = (ini + fin) / 2;
        if (v[ini] > v[medio]) {
            //resuelve der
           return resolver(v, medio, fin);
        }
        else {
            //
          return  resolver(v, ini, medio);
        }

    }


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (!std::cin)
        return false;
    vector<int>h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    int ini = 0;
    int fin = h.size();
int  sol = resolver(h,ini,fin);
cout << sol << endl;
    // escribir sol


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