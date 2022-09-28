// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;
// función que resuelve el problema
bool combrueba(int k,vector<int>&puestos, const vector<vector<int>>& orden) {
    if (k > 0) {
        if (orden[puestos[k]][puestos[k - 1]]== 0)return false;
    }
    return true;
}
void resolver(const vector<vector<int>>&prices,int artists, const vector<vector<int>>&orden,int&sol,int k,vector<int>&puestos,int &maxprice,bool&a,vector<bool>&rep) {
    for (int i = 0; i < artists; i++) {
        if (!rep[i]) {
        sol += prices[i][k];
        puestos[k] = i;
        if (combrueba(k, puestos, orden)) {
            rep[i] = true;
            if (k >= artists - 1) {
                a = true;
                if (sol > maxprice)maxprice = sol;
            }
            else {
                resolver(prices, artists, orden, sol, k+1, puestos, maxprice,a,rep);
            }
            rep[i] = false;
        }
        sol -= prices[i][k];
        }
  }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int numart;
    cin >> numart;
    vector <vector<int>>prices(numart,vector<int>(numart));
    for (int i = 0; i < prices.size(); i++) {
        for(int j=0;j<prices[i].size();j++){
            cin >> prices[i][j];
        }
    }
    vector <vector<int>>orden(numart, vector<int>(numart));
    for (int i = 0; i < prices.size(); i++) {
        for (int j = 0; j < prices[i].size(); j++) {
            cin >> orden[i][j];
        }
    }
    int sol = 0;
    int maxprice = 0;
    vector<int>puestos(numart);
    bool a = false;
    vector<bool>reo(numart);
    resolver(prices, numart, orden, sol, 0, puestos, maxprice,a,reo);
    if (a)
        cout << maxprice << endl;
    else cout << "NEGOCIA CON LOS ARTISTAS" << endl;
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