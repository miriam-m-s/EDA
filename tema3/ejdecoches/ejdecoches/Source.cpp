// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;

// función que resuelve el problema
void resolver(vector<float>&espacio,vector<float>&coches,int k,float metros,vector<string>&sol) {
    bool h = false;
    if (espacio[0] + coches[k] <= metros) {
        h = true;
        espacio[0] += coches[k];
        sol[k] = "BABOR";
        
        if (k >= coches.size() - 1) {
            for (int i = 0; i < k; i++) {
                cout << sol[i] << " ";

            }
            cout << endl;

        }
        else
        {
            resolver(espacio, coches, k + 1, metros, sol);
        }
        espacio[0] -= coches[k];
     
  
    }
    if (espacio[1] + coches[k] <= metros) {
        h = true;
        espacio[1] += coches[k];
        sol[k] = "ESTRIBOR";
       
        if (k >= coches.size() - 1) {
            for (int i = 0; i < k; i++) {
                cout << sol[i] << " ";

            }
            cout << endl;

            
        }
        else
        {
            resolver(espacio, coches, k + 1, metros, sol);
        }
        espacio[1] -= coches[k];
       
    }
    if (!h) {
     
            
         
            for (int i = 0; i < k; i++) {
                cout << sol[i] << " ";
               
            }
            cout << endl;
        
    }


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int metros;
    cin >> metros;
    if (metros==0)
        return false;
    vector<float>v;
    float h;
    cin >> h;
    while (h != -1) {
        v.push_back(h);
        cin >> h;
    }
    //TipoSolucion sol = resolver(datos);
    vector<float>espacio(2);
    int numcoches = 0;
    int maxcoches = 0;
    vector<string>sol(v.size());
    int i = 0;

    resolver(espacio, v, 0, metros ,sol);
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
