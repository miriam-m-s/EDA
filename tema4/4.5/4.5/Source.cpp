// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
#include"Set.h"
using namespace std;
void resuelve(vector<int>& v, int k) {
    Set<int>se;
    for (int i = 0; i < v.size(); i++) {
        if (k!=se.size()) {
            se.add(v[i]);
        }
        else {
            int l = se.getmax();
            if (v[i] < l) {
                if (!se.contains(v[i])) {
                    se.removeMax();
                    se.add(v[i]);
                }                            
            }
        }
    }
    auto l = se.toArray();
    for (int i = 0; i < se.size(); i++) {
        cout << l[i]<<" ";
        
    }
    
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int k;
    cin >>k;
    
    if (k==0)
        return false;
    vector<int>v;
    int h;
    cin >> h;
    while (h != -1) {
        v.push_back(h);
        cin >> h;
    }
   
    resuelve(v, k);
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
