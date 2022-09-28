// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
bool TotalSuma(vector<int>suma,int i,int sumatotal) {
    if (suma[i]  <= sumatotal- suma[i] +1) {
        return true;
    }
    return false;

}
bool esValida(vector<int>sol,int k) 
{
    if (k < 2)return true;
    else {
        if (sol[k] == sol[k - 1] && sol[k] == sol[k - 2])return false;
        else return true;
    }
}
void resolver(vector<int>&sol,const vector<int>&bomb,int longitud,int consumo,int k,vector<int>&suma,int& actualconsumo,int &numcasos) {
    for (int i = 0; i < bomb.size(); i++) {
        sol[k] = i;
        suma[i]++;    
        actualconsumo += bomb[i];
        if (actualconsumo <= consumo&&esValida(sol,k)&&TotalSuma(suma,i, k+1))
        {
                if (k == longitud - 1) {
                    numcasos++;  
                }
                else {
                    resolver(sol, bomb, longitud, consumo, k + 1, suma,actualconsumo,numcasos);
                }           
        }
        suma[i]--;
     
        actualconsumo -= bomb[i];
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int longitud;
    int numcolors;
    int consumo;
    cin >> longitud>>numcolors>>consumo;
    if (longitud==0)
        return false;
    vector<int>bomb(numcolors);
    for (int i = 0; i < numcolors; i++) {
        cin >> bomb[i];
    }
    vector<int>sol(longitud);
    vector<int>suma(numcolors);

    int actualconsumo = 0;
    int numcasos=0;
    resolver(sol, bomb, longitud, consumo, 0, suma, actualconsumo,numcasos);
   cout << numcasos;

    cout << endl;
    //TipoSolucion sol = resolver(datos);

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
