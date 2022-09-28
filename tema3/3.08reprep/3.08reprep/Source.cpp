// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
struct tipes {
    int tipo;
    int jug;
};
bool comprueba(vector<vector<tipes>>& sol,int k,int l) {
    if (l > 0) {
        if (sol[k][l - 1].tipo < sol[k][l].tipo)return true;
        else return false;
    }
    return true;
}
void resolver(vector<int>& v, int k, int ninos, int tipos, vector<vector<tipes>>& sol,int l,bool &s) {
    for (int i = 0; i < tipos; i++) {
        sol[k][l].tipo = v[i];
        sol[k][l].jug = i;
        if (comprueba(sol, k, l)) {
            if (k >= ninos - 1&&l==1) {
                for (int i = 0; i < ninos; i++) {
                    for (int j = 0; j < 2; j++) {
                        cout << sol[i][j].jug << " ";
                    }
                }
                cout << endl;
                s = true;
            }
            else {
                if (l == 0) {
                    resolver(v, k, ninos, tipos, sol, l + 1,s);
                }
                else {
                    resolver(v, k+1, ninos, tipos, sol, 0,s);
                }
               
            }
        }
    }
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tipos, ninos;
    cin >> tipos >> ninos;
    if (!std::cin)
        return false;
    string h;
    string n;
    vector<int>v(tipos);
    for (int i = 0; i < tipos; i++) {
        cin >> h;
        if (i != 0) {
            if (n == h) {
                v[i] = v[i - 1];
            }
            else {
                n = h;
                v[i] = v[i - 1] + 1;
            }
        }
        else {
            n = h;
            v[i] = 0;
        }
    }
    bool s = false;
    vector<vector<tipes>>sol(ninos, vector<tipes>(2));
    resolver(v, 0, ninos, tipos, sol, 0,s);
    if (!s) {
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