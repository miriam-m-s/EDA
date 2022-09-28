// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

bool comprueba(vector<int>& tipos,int k, vector<int>& sol) {
    if (k > 0) {
        return (sol[k - 1] <sol[k]&&tipos[sol[k-1]]!= tipos[sol[k]]);
    }
    else return true;
}
// función que resuelve el problema
void resolver(vector<int>& sol,vector<int>& tipos, int rega, int k,vector<string>&h,bool &her) {

    for (int x = 0; x < rega; x++)
    {
        sol[k] = x;
        if (comprueba( tipos,  k,sol)) {         
            if (k == 1) {
                string b = "";
                for (int i = 0; i < 2; i++) {
                    string g = to_string(sol[i]);
                    b = b + (g + " ");
                }           
                h.push_back(b);
                her = true;
            }
            else
                resolver(sol, tipos, rega, k + 1, h,her);
        }
    }
}
void escribe(int ninos, const vector<string>& h,int k,  vector<string>& sol) {
    for (int i = 0; i < h.size(); i++) {
        sol[k] = h[i];
        if (k == ninos - 1) {
            for (int i = 0; i < ninos; i++) {
                cout << sol[i];
            }
            cout << endl;
        }
        else escribe(ninos, h, k + 1, sol);
        
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int rega= 0, ninos;
    cin >> rega >> ninos;
    if (!std::cin)
        return false;
    else {
        vector<int>tipos(rega);
        vector<string>sol(rega);
        for (int i = 0; i < rega; i++) {
            cin >> sol[i];
            int j = i;            
                if (i > 0&&sol[i] == sol[i - 1])tipos[i] = tipos[i - 1];
                else
                    tipos[i] = i;
        }
        bool her = false;
        vector<string> h;
        vector<int>solu(2);
        //resolver(sol, n, m, 0,suma,cont ,s,hol);
        resolver(solu, tipos, rega, 0, h,her);
        if (her) {
            vector<string>soluc(ninos);
            escribe(ninos, h, 0, soluc);
        }
        else {
            cout << "SIN SOLUCION" << endl;
        }
        
        cout << endl;
    }

    return true;


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