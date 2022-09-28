// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
void resolver(vector<int>& sol, int n, int m, int k,int & suma,int &cont,vector<bool>usado,int& hol) {

    for(int x=hol;x<n;x++)
    {
        int h = sol[x];  
        if (h <= m) {
            suma = suma + h;
            if (k <= n - 1) {
                if (suma == m) {
                    cont++;
                }
                else if (suma < m) {
                    hol = x + 1;
                    resolver(sol, n, m, k + 1, suma, cont, usado, hol);

                }
            }
            
            suma = suma - h;
           
        }
     }
       
    

}
void rez(vector<int>& sol, int n, int m, int k, int& suma, int& cont) {
    int h = sol[k];
    suma = suma + h;
    if (suma <= m) {
        if (k <= n - 1) {
            if (suma == m) cont++;
            else {
                if (k < n - 1)
                    rez(sol, n, m, k + 1, suma, cont);
            }
        } 
    }
    suma = suma - h;
       
    if (k <= n - 1) {
        if (suma == m) cont++;
        
        else { 
            if (k < n - 1)
            rez(sol, n, m, k + 1, suma, cont); 
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int n = 0,m;
    cin >> n>>m;
    if (!std::cin)
        return false;
    else {

        vector<int>sol(n);
        for (int i = 0; i < n; i++) {
            cin >> sol[i];
        }
        int suma = 0;
        vector<bool>s(n);
        int cont = 0,hol=0;
        //resolver(sol, n, m, 0,suma,cont ,s,hol);
        rez(sol, n, m, 0, suma, cont);
        cout << cont;
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