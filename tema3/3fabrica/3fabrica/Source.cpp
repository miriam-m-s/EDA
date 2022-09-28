// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
#include<climits>
using namespace std;

// función que resuelve el problema
void resolver(vector<bool>&b,const vector<vector<int>>&v,int k,int maquinas,int& precio,int& minprecio) {
    for (int i = 0; i < maquinas; i++) {
        precio += v[i][k];
        if (v[i][k] != 0 && b[i]&&precio<minprecio) {
            b[i] = false;
            if (k >= maquinas - 1) {
                if (precio < minprecio) {
                    minprecio=precio ;
                }
                
            }
            else resolver(b, v, k + 1, maquinas, precio, minprecio);
            b[i] = true;
        }
        precio -= v[i][k];
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int maquinas;
    cin >> maquinas;
    if (maquinas==0)
        return false;
 
    vector<vector<int>>v(maquinas, vector<int>(maquinas));
    for (int i = 0; i < maquinas; i++) {
        for (int j = 0; j < maquinas; j++) {
            cin >> v[i][j];
        }
    }
    vector<bool> b(maquinas, true);
    int precio = 0;
    int minprecio = INT_MAX;
    resolver(b, v, 0, maquinas, precio, minprecio);
    cout << minprecio << endl;

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
