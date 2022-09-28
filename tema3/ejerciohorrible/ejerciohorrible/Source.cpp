// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;
template < typename T, typename Equal = equal_to <T>>
pair < bool, T > mayoria(const vector <T >& v,int k,int& suma,T& numero,int & posnum){
    if (v[k]==numero) {
        suma++;
        if (k >= v.size() - 1) {
            if (suma > v.size() / 2) {
              
                return make_pair(true, numero);
            }
            else {
                suma = 0;
                int i = posnum+1;
                while (i != v.size() && v[i] == numero)i++;
                if (i == v.size())return make_pair(false, numero);
                else {
                    numero = v[i];
                    posnum = i;
                   return mayoria(v, i, suma, numero, posnum);
                }
            }
        }
        else {
            return mayoria(v, k + 1, suma, numero, posnum);
        }
     }
    if (k >= v.size() - 1) {
        if (suma > v.size() / 2) {
            return make_pair(true, numero);
        }
        else {
            suma = 0;
            int i = posnum + 1;
            while (i != v.size() && v[i] == numero)i++;
            if (i == v.size())make_pair(false, numero);
            else {
                numero = v[i];
                posnum = i;
                return mayoria(v, i, suma, numero, posnum);
            }
        }
    }
    else return mayoria(v, k + 1, suma, numero,posnum);


}
template < typename T >

bool resuelveCaso() {
    // leer los datos de la entrada
    int tam;
    cin >> tam;
    if (tam==-1)
        return false;
    vector<T>v(tam);
    for (int i = 0; i < tam; i++) {
        cin >> v[i];
    }
    if (tam > 0) {
        int suma = 0;
        T numero = v[0];
        int posnum = 0;

        pair<bool, int> s = mayoria(v, 0, suma, numero, posnum);
        if (s.first == true)cout << s.second << endl;
        else cout << "NADA" << endl;
    }
    else cout << "NADA" << endl;
    
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


    while (resuelveCaso<int>())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
