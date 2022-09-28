// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
#include<climits>
using namespace std;
// función que resuelve el problema
void resolver(const vector<vector<int>>&m,int k,int product,int nsuper,int &precio,int &minprecio,vector<int>&vecessuper,vector<int>&minu) {
    for (int i = 0; i < nsuper; i++) {
        precio += m[i][k];
        vecessuper[i]++;
        if (vecessuper[i] <= 3&&precio<minprecio) {
          
            if (k == product - 1) {
                minprecio = precio;
            }
            else {
                if(minu[k+1]+precio<=minprecio)
                resolver(m, k+1, product, nsuper, precio, minprecio, vecessuper,minu);
            }
           
        }
        precio -= m[i][k];
        vecessuper[i]--;
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int nsuper, product;
    cin >> nsuper >> product;
    vector<vector<int>>m(nsuper, vector<int>(product));
    int min = INT_MAX;
    vector<int>mino(product);
    for (int i = 0; i < nsuper; i++) {
        for (int j = 0; j < product; j++) { 
            int h;
            cin >> h;
             m[i][j]=h;
            if (i == 0)mino[j] = h;
            else if (h < mino[j])mino[j] = h;
        }
 
    }
    int suma = 0;
    for (int i = 0; i < mino.size(); i++) {
       suma += mino[i ];
    }
    vector<int>minu(product);
    int l=0;
    for (int i = 0; i < minu.size(); i++) {
        minu[i] = suma -l;
        l += mino[i];
        
    }
    int minprecio = INT_MAX;
    int precio = 0;
    vector<int>vecessuper(nsuper, 0);
    
    resolver(m, 0, product, nsuper, precio, minprecio, vecessuper,minu);
    cout << minprecio << endl;

}

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
    system("PAUSE");
#endif

    return 0;
}