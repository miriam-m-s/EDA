// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;
bool resolr(int precio, int minprecio) {
    if (minprecio == 0)return true;
    else {
        if (precio > minprecio)return false;
        else return true;
    }
   
}

void resolver(const vector<vector<int>>&mercados,int k,int nsuper, int products, int& minprecio,int & precio,vector<int>&rep) {
    for (int i = 0; i < nsuper; i++) {
        int s = mercados[i][k];
        if (rep[i] < 3) {
            rep[i]++;
            precio += s;
            if (resolr(precio, minprecio)) {
                if (k == products - 1) {
                    if (minprecio == 0) {
                        minprecio = precio;
                    }
                    else {
                        if (precio < minprecio)
                            minprecio = precio;
                    }
                }
                else {
                    resolver(mercados, k + 1, nsuper, products, minprecio, precio, rep);
                }
            }
           
            precio -= s;
            rep[i]--;
        }

    }
}


void resuelveCaso() {
    int nsuper;
    int products;
    cin >> nsuper >> products;
    vector<vector<int>>mercados(nsuper,vector<int>(products));

    for (int i = 0; i < nsuper; i++) {
        for (int j = 0; j < products; j++) {
            cin >> mercados[i][j];
        }
    }

    int minprecio=0;
    int precio=0;
    vector<int>rep(nsuper);
    resolver(mercados,0, nsuper, products, minprecio, precio, rep);
    cout << minprecio << endl;


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