// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;
bool mismocolor(vector<int>&sol,int k) {
    if (k >= 2) {
        if (sol[k - 2] == sol[k - 1] &&sol[k-1]== sol[k]&&sol[k-2]==sol[k])return false;
    }
    return true;
}
bool sumaluces(vector<int>& sol, int k, vector<int>& sumatotalluces,int suma) {
    int sumas = suma - sumatotalluces[sol[k]];
    if (sumatotalluces[sol[k]] > sumas+1) {
        return false;
    }
    return true;
}
// función que resuelve el problema
void  resolver(int longi,int consum,vector<int>&consumcolors,int k,vector<int>&sol,int& actualconsumo, vector<int>&sumatotalluces,int suma,int&result) {
    for (int i = 0; i < consumcolors.size(); i++) {
        sol[k] = i;
        suma++;
        sumatotalluces[i]++;
        actualconsumo += consumcolors[i];
        if (actualconsumo <= consum && mismocolor(sol, k)&&sumaluces(sol, k, sumatotalluces, suma)) {
            if (k + 1 >= longi) {
                result++;
            }
            else {
                resolver(longi, consum, consumcolors, k+1, sol, actualconsumo, sumatotalluces,suma,result);
            }
        }
        actualconsumo-= consumcolors[i];
        sumatotalluces[i]--;
        suma--;
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int longi,numcolr,consum;
    cin >> longi>>numcolr>>consum;
    if (longi==0)
        return false;
    vector<int>consumcolors(numcolr);
    for (int i = 0; i < numcolr; i++) {
        cin >> consumcolors[i];
    }
    vector<int>sol(longi);
    vector<int>sumatotalluces(numcolr);
    int actualconsumo = 0;
    int suma = 0;
    int result =0 ;

    resolver( longi,consum,consumcolors, 0,sol,actualconsumo, sumatotalluces,suma,result);
    cout << result;
    cout << endl;
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
