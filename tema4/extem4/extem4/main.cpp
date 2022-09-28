// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "set.h"
#include<vector>
using namespace std;
template <class T>
ostream& operator<<(ostream& out, set<T> const& set) {
    out << "";
    const T* elems = set.toArray();
    for (int i = 0; i < set.size() ; i++)
        out << elems[i] << " ";
    
    return out;
}

// función que resuelve el problema
void resolver(const vector<int> &arr,int k) {
    set<int> sol;
    for (int i = 0; i < arr.size(); i++) {
        if (sol.size() != k)sol.add(arr[i]);
        else {
            if (arr[i] < sol.min()) {
                sol.add(arr[i]);
                sol.remove(sol.max());
            }
            else if (arr[i] > sol.min() && arr[i] < sol.max()) {
                sol.add(arr[i]);
                sol.remove(sol.max());
            }
        }
       
        
    }
    cout << sol<<endl;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int k;
    
    cin >> k;
    if (k==0)
        return false;
    else {
        vector<int> arr;
        int s = 0;
        while (s!=-1) {
           
            cin >> s;
            if (s != -1)
                arr.push_back(s);
        }
        resolver(arr, k);
    }
  

    

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