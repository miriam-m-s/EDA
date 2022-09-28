// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
bool estabien(int azul, int roj, int verd) {

    if (roj > (azul + verd))return true;
    else return false;
}
bool comprueba(int k, vector<int>& sol, vector<int>& col) {
    bool c;

    if (col[sol[k]] == -1)return true;

    if (k > 1 && sol[k] == 2) {
        if (sol[k - 1] == sol[k])return true;
        else return false;
    }
    else return false;


}
bool masazules(int azu, int verd) {
    if (azu >= verd)return true;
    else return false;
}
// función que resuelve el problema , int a, int r, int v
void resolver(vector<int>& sol, int n, int m, int k, vector<int>& color, vector<int>& cont, bool& h) {
    bool  control = false;
    if (k == 0) {
        if (color[1] > 0) {
            sol[k] = 1;
            cont[1]++;
            color[1]--;
            k++;
        }
        else control = true;
    }
    if (!control) {

        for (int x = 0; x < m; x++) {
            sol[k] = x;
            cont[x]++;
            color[x]--;
            if (!comprueba(k, sol, color) && masazules(cont[0], cont[2])) {
                if (k == n - 1) {
                    if (estabien(cont[0], cont[1], cont[2])) {
                        h = true;
                        for (int i = 0; i < n; i++) {
                            if (sol[i] == 0)
                                cout << "azul";
                            else if (sol[i] == 1) cout << "rojo";
                            else  cout << "verde";
                            cout << " ";
                        }
                        cout << endl;
                    }
                }
                else {
                    resolver(sol, n, m, k + 1, color, cont, h);

                }
            }
            cont[x]--;
            color[x]++;
        }
    }



}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int n = 0, m = 3, a, v, r;
    cin >> n >> a >> r >> v;
    if (n == 0 && a == 0 && r == 0 && v == 0)
        return false;
    else {
        bool h = false;
        vector<int>sol(n);
        vector<int>piezas(3);
        piezas[0] = a;
        piezas[1] = r;
        piezas[2] = v;
        vector<int>contador(3, 0);
        int ve = 0, ro = 0, az = 0;
        if (n >= 2)
            resolver(sol, n, m, 0, piezas, contador, h);

        if (h == false)cout << "SIN SOLUCION" << endl;
        cout << endl;
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