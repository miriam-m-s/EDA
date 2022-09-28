// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


// función que resuelve el problema
void resolver(int ninos, int rega, int k, vector<vector<int>> gustninos,int &maxpunt,int &punt,vector<bool>&hey, vector<int>opti) {

    for (int x = 0; x < rega; x++)
    {
        int s = gustninos[k][x];
       
        if (!hey[x]) {
            punt = punt + s;
            hey[x] = true;
            if (k == ninos-1) {
                if (punt > maxpunt)maxpunt = punt;
            }
            else {
                if(punt+opti[k+1]>=maxpunt)
                resolver(ninos,  rega, k + 1, gustninos, maxpunt, punt, hey,opti);
            }
            hey[x] = false;
            punt = punt - s;
        }
      
        
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int rega = 0, ninos;
    cin >> rega >> ninos;
    if (!std::cin)
        return false;

        vector<vector<int>>gustninos(ninos, vector<int>(rega));
        vector<int>mayores(ninos);
        int mayor = -2147483647;
        for (int i = 0; i < ninos; i++) {
            for (int j = 0; j < rega; j++)
            {
                cin >> gustninos[i][j];
                if (gustninos[i][j] > mayor)mayor = gustninos[i][j];
            }
            mayores[i] = mayor;
            mayor = 0;
        }
        int resta = 0;
        int suma=0;
        for (int i = 0; i < mayores.size(); i++) {
            suma += mayores[i];

        }
        vector<int>optimi(ninos);
        for (int i = 0; i < mayores.size(); i++) {
            optimi[i] = suma - resta;
           
            resta =resta+ mayores[i];;
        }
        int  maxpunt = 0;
        int punt = 0;
        vector<bool>hey(rega);
        resolver(ninos, rega, 0, gustninos, maxpunt, punt, hey, optimi);
        cout << maxpunt;
        cout << endl;
    

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