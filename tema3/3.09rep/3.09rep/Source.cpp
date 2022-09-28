
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include<vector>
using namespace std;
struct criterios {
    int tipjuguetes;
    int numninos;
    int satisfaction;
};
struct juguete {
    int tipejuguete;
    int juguete;
};
bool llegalasatisfacion(int l, int satisfaccion, vector<int>& satisf,int k) {
    if (l == 1) {
        if (satisf[k] < satisfaccion)return false;
    }
    return true;
}
bool rep(int l, vector<vector<juguete>>& sol, int k) {
    if (l >= 1) {
        if (sol[k][l].tipejuguete == sol[k][l - 1].tipejuguete)return false;
    }
    return true;
}

void resuelve(vector<vector<juguete>>&sol,const vector<vector<int>>& ninos,const criterios&s, vector<int>&numjuguetes,int l,int k,vector<int>&satisf,vector<int>&tipjugu,int empieza,bool& r) {
    for (int i = empieza; i < s.tipjuguetes; i++) {
        sol[k][l].tipejuguete = tipjugu[i];
        sol[k][l].juguete = i;
        satisf[k] += ninos[k][i];
        if (k == 2) {
            int b = 7;
       }
        if (numjuguetes[i]>0&&llegalasatisfacion(l, s.satisfaction, satisf, k)&& rep(l, sol,k)) {
            numjuguetes[i]--;
            if (k >= s.numninos - 1&&l==1) {
                r= true;
                for (int i = 0; i < s.numninos; i++) {
                    for (int j = 0; j < 2; j++) {
                        cout << sol[i][j].juguete << " ";
                    }
                }
                cout << endl;
            }
            else {
                if (l == 1) {
                    resuelve(sol, ninos, s, numjuguetes, 0, k+1, satisf, tipjugu,0,r);
                }
                else {
                    resuelve(sol, ninos, s, numjuguetes, 1, k , satisf, tipjugu,i,r);
                }
            }
            numjuguetes[i]++;
        }
       
        satisf[k] -= ninos[k][i];
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    criterios s;
    cin >> s.tipjuguetes >> s.numninos >> s.satisfaction;
    if (!std::cin)
        return false;
    vector<int>numjuguetes(s.tipjuguetes);
    for (int i = 0; i < s.tipjuguetes; i++) {
        cin >> numjuguetes[i];
    }
    vector<int>tipos(s.tipjuguetes);
    vector<string>sol(s.tipjuguetes);
    for (int i = 0; i < s.tipjuguetes; i++) {
      
         cin >> sol[i];

         if (i > 0 && sol[i] == sol[i - 1])tipos[i] = tipos[i - 1];
         else
             tipos[i] = i;
    }
    vector<vector<int>>ninos(s.numninos, vector<int>(s.tipjuguetes));
    for (int i = 0; i < s.numninos; i++) {
        for (int j = 0; j < s.tipjuguetes; j++) {
            cin >> ninos[i][j];
        }
    }
    vector<vector<juguete>>solu(s.numninos, vector<juguete>(2));
    vector<int>satisf(s.numninos);
    bool r = false;
    resuelve(solu, ninos, s, numjuguetes, 0, 0, satisf, tipos,0,r);
    if (!r) {
        cout << "SIN SOLUCION" << endl;
    }
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