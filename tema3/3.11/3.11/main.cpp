// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;
bool compsuma(const vector<int>& sumabomb,int x) {
    int i = 0;
    bool h = true;
    int cont = 0;
    while (i < sumabomb.size() ) { 
        if (i != x) {
            cont = cont + sumabomb[i];
        }
        i++;
    }
    if (sumabomb[x] - cont > 1)return false;
    else return true;
}
bool comprueba(int k, const vector<int>& sol) {
    if (k >=2) {
        if (sol[k] == sol[k - 1] && sol[k - 1] == sol[k - 2])return false;
        else return true;
    }
    return true;
}
// función que resuelve el problema , int a, int r, int v
void resolver(vector<int>& sol, const vector<int>&bombillas , int duracion, int  k,int l,int &cont,  vector<int>& sumabomb,int &solu) {
   
        for (int x = 0; x < bombillas.size(); x++) {
            sol[k] = x;
            sumabomb[x]++;
            cont = cont + bombillas[x];
            if (cont <= duracion&& comprueba( k, sol)&& compsuma( sumabomb,  x)) {
                if (k == l - 1) {
                    solu++;
                }
                else {
                    resolver(sol, bombillas, duracion, k + 1, l, cont,sumabomb,solu);

                }
            }
            cont = cont - bombillas[x];
            sumabomb[x]--;
        }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int l = 0, luces = 0, duracion;
    cin >> l >>luces>> duracion;
    if (l == 0 )
        return false;
    else {

        vector<int>bombillas(luces);
        vector<int>sol(l);
        for (int i = 0; i < bombillas.size(); i++) {
            cin >> bombillas[i];
        }
        int cont = 0;
        vector<int>bomb(luces);
        int solu=0;
        resolver(sol, bombillas, duracion, 0, l, cont,bomb,solu);
       cout <<solu<< endl;
    }

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