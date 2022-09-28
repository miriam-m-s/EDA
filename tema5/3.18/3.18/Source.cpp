
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
bool esvalida(vector<vector<bool>>& consentimientos,int artsia,int k, vector<int>&sol) {
    bool h=true;
    if (k > 0) {
        if (consentimientos[sol[k]][sol[k - 1]] != 1)h = false;
           
    }
   return h;
}


// función que resuelve el problema
void resolver(vector<int>&sol,int k,int artistas, vector<vector<int>> &beneficios, vector<vector<bool>> &consentimientos,int &precio,int &maxprecio,vector<bool>&rep, vector<int>&opti) {

    int arts = 0;

   while (arts < artistas) {
       if (!rep[arts]) {
           sol[k] = arts;
           if (esvalida(consentimientos, arts, k, sol)) {          
               rep[arts] = true;
               precio += beneficios[arts][k];
               if (k == artistas-1) {
                   if (precio > maxprecio) {
                       maxprecio = precio;
                   }

               }
               else {
                   if(opti[k+1]+precio>=maxprecio)
                   resolver(sol, k+1, artistas, beneficios, consentimientos, precio, maxprecio, rep,opti);
               }
               precio -= beneficios[arts][k];
               rep[arts] = false;
           }
          
       }
           
        
        
        arts++;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    vector<vector<int>> beneficios(n, vector<int>(n));
    vector<vector<bool>> consentimientos(n, vector<bool>(n));
    vector<int>may(n);


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          
            cin >> beneficios[i][j];
            if (may[j] < beneficios[i][j]) {
                
                may[j] = beneficios[i][j];
            }
          
        }

    }
    vector<int>optimi(n);
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            optimi[i] += may[j];
        }
    }


    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            int b;
            cin >> b;
            consentimientos[i][j] = b;
        }

    
  
   

    vector<int> sol(n);
    int precio = 0;
    int maxprecio = 0;
    vector<bool> rep(n);
    resolver(sol, 0, n, beneficios, consentimientos, precio, maxprecio, rep, optimi);
    if (maxprecio == 0)cout << "NEGOCIA CON LOS ARTISTAS" << endl;
    else cout << maxprecio << endl;

    //resolver(...);
    // salida
}

//#define DOMJUDGE
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
    //system("PAUSE");
#endif

    return 0;
}
