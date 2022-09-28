// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

bool comprueba(vector<int>& tipos, int k, vector<int>& sol) {
    if (k > 0) {
        return (sol[k - 1] < sol[k] && tipos[sol[k - 1]] != tipos[sol[k]]);
    }
    else return true;
}
void resolver(int ninos,int nin,vector<vector<int>>& sol, vector<int>& tipos, int rega, int k, vector<int>& h, bool& her,int puntuacion,vector<vector<int>>gustninos, vector<int> &puntuation, vector<int>&numreg) {

    for (int x = 0; x < rega; x++)
    {
        sol[nin][k] = x;
        puntuation[nin] += gustninos[nin][x];
        numreg[x]--;
        if (numreg[x]>=0&&comprueba(tipos, k, sol[nin])) {
            
            if (k == 1) {
                if (puntuation[nin] >= puntuacion) {
                    int s = 0;
                    for (int i = nin*2; i < nin*2+2; i++) {
                        h[i]=sol[nin][s];

                        s++;
                    }
                    if (nin < ninos - 1) {
                        resolver(ninos, nin + 1, sol, tipos, rega,0, h, her, puntuacion, gustninos, puntuation, numreg);
                    }                 
                    else {

                        for (int i = 0; i < h.size(); i++) {
                            cout << h[i] << " ";
                        }
                        cout << endl;
                        her = true;
                    }
                }
               
            }
            else if(k<1) {
                resolver(ninos, nin, sol, tipos, rega, k + 1, h, her, puntuacion, gustninos, puntuation, numreg);
            }                     
        }
        numreg[x]++;
        puntuation[nin] -= gustninos[nin][x];
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int satisf;
    int rega = 0, ninos;
    cin >> rega >> ninos>>satisf;
    if (!std::cin)
        return false;
    else {
        vector<int>numreg(rega);
        for (int i = 0; i < rega; i++) {
            cin >> numreg[i];
        }
        vector<int>tipos(rega);
        vector<string>sol(rega);
        for (int i = 0; i < rega; i++) {
            cin >> sol[i];
          
            if (i > 0 && sol[i] == sol[i - 1])tipos[i] = tipos[i - 1];
            else
                tipos[i] = i;
        }
        vector<vector<int>>gustninos(ninos, vector<int>(rega));
        for (int i = 0; i < ninos; i++) {

            for (int j = 0; j < rega; j++) {
                cin >> gustninos[i][j];
            }
        }
        
        bool her = false;
   
        vector< vector<int>>solu(ninos,vector<int>(2));
        vector<int>he(ninos*2);
      vector< int > puntuation(ninos) ;

        resolver(ninos, 0, solu, tipos, rega, 0, he, her, satisf, gustninos, puntuation, numreg);
     
        if (!her) {
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