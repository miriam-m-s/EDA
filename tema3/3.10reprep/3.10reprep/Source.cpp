// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<climits>
#include <vector>
using namespace std;
void resolve(vector<vector<int>>&satisfacc,int & benef,int &maxbenef,int regalos,int ninos,int k,vector<bool>&rep,vector<int>&opti) {
    for (int i = 0; i < regalos; i++) {
        benef += satisfacc[k][i];
         if (rep[i]) {
            rep[i] = false;
            if (k >= ninos - 1) {
                if (benef > maxbenef) {
                    maxbenef = benef;
                }
            }
            else {
                if (opti[k + 1] + benef >= maxbenef) {
                    resolve(satisfacc, benef, maxbenef, regalos, ninos, k+1, rep, opti);
                }
            }
            rep[i] = true;
        }
        benef -= satisfacc[k][i];
    }
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int regalos, ninos;
    cin >> regalos >> ninos;
    
    if (!std::cin)
        return false;
    vector<vector<int>>satisfacc(ninos, vector<int>(regalos));
    vector<int>maxsatis(ninos);
    int h;
    int max = INT_MIN;
    for (int i = 0; i < ninos; i++) {
        for (int j = 0; j < regalos; j++) {
            cin >> h;
            satisfacc[i][j] = h;
            if (max < h)max = h;
      
        }
        maxsatis[i] = max;
        max = INT_MIN;
    }
    vector<int>opti(ninos);
    int suma = 0;
    for (int i = 0; i < ninos; i++) {
        suma += maxsatis[i];
    }
    int resta = 0;
    for (int i = 0; i < ninos; i++) {
        opti[i] = suma-resta;
        resta += maxsatis[i];
    }
     int benef = 0;
    int maxbenef = INT_MIN;
    vector<bool>rep(regalos,true);
    resolve(satisfacc, benef, maxbenef, regalos, ninos, 0, rep, opti);
    cout << maxbenef;
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