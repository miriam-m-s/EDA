// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include<cmath>

using namespace std;
bool noatac(vector<int>& v,int k, vector<bool>& filas, vector<bool>& d_asc, vector<bool>& d_desc,int n) {
    return(filas[v[k]] || d_asc[k + v[k]] || d_desc[(v[k]-k )+ (n - 1)]);
}
// función que resuelve el problema
void resolver(int& sol, vector<int>& v, int n, int k, vector<bool>& filas , vector<bool>& d_asc, vector<bool>& d_desc) {

    for (int x = 0; x < n; x++) {
        v[k] = x;
        if (!noatac(v,k,filas,d_asc,d_desc,n)) {
            if (k == n - 1) {
                sol=sol+1;
            }
            else {
                filas[x] = true;
                d_asc[x+k] = true;
                d_desc[(x-k)+(n-1)] = true;
                resolver(sol, v, n, k+1, filas, d_asc, d_desc);
                filas[x] = false;
                d_asc[x+k] = false;
                d_desc[(x - k)+ (n - 1)] = false;
            }
        }

    }
   
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    int  m = 0;
    cin >> m;
 
 
        int sol=0;
        vector<bool>filas(m,false);
        vector<bool>d_asc(2*m+1,false);
        vector<bool>d_desc(2*m+1,false);
        vector<int>v(m);
        resolver(sol, v,  m, 0, filas, d_asc, d_desc);
        cout << sol << endl;
    

 

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    //std::ifstream in("datos.txt");
    //auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 
    int casos;
    cin >> casos;
    for (int i = 0; i < casos; i++) {
        resuelveCaso();
    }


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
   /* std::cin.rdbuf(cinbuf);
    system("PAUSE");*/
#endif

    return 0;
}