// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;
// función que resuelve el problema
int resolver(const vector<int>&v, int ini, int fin) {
    int n = fin - ini;
    if (n == 1) {
        return ini;
    }
    else {
        int mid=(fin + ini) / 2;
        if (v[mid] == v[mid + 1]) {
            if (((fin - 1) - mid + 1) % 2 != 0) {
                //Der
                return  resolver(v, mid+2, fin);
            }
            else {
                //izq
                return  resolver(v, ini, mid);
            }
        }
        else if (v[mid] == v[mid - 1]) {
            if ((mid - 1 - ini) % 2 != 0) {
                //izq
                return resolver(v, ini, mid - 1);
            }
            else {
                //Der
                return  resolver(v, mid+1 , fin);
            }
        }
        else {
            return mid;
        }
    }
    

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int tam;
    cin >> tam;
    vector<int>v(tam);
    for (int i = 0; i < tam; i++) {
        cin >> v[i];
    }
    cout << resolver(v, 0, v.size()) << endl;

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