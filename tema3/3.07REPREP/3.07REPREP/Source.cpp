// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;
//dos piezas verdes juntas
//piezas verdes tiene que ser menor igual que azules
//parte roja al principio
//al final comprobar que piezas rojas es mayo que piezas a+v

// función que resuelve el problema
bool verdes(int k,vector<int>&sol) {
    if (k >= 1) {
        if (sol[k - 1] == 2 && sol[k] == 2)return false;
    }
    return true;
}
bool nomasverdes(vector<int>& numerodepiezas) {
    if (numerodepiezas[2] <= numerodepiezas[0])return true;
    return false;
}
void resolver(vector<int>&sol, vector<int>colores, vector<int>&numerodepiezas,int k,int altura,bool &s) {

    for (int i = 0; i < 3; i++) {
      
        if (colores[i]>0) {
            colores[i]--;
            numerodepiezas[i]++;
            sol[k] = i;
            if (nomasverdes(numerodepiezas) && verdes(k, sol)) {
                if (k >= altura - 1) {
                    if (numerodepiezas[1] > (numerodepiezas[0] + numerodepiezas[2])) {
                        for (int i = 0; i < sol.size(); i++) {
                            if (sol[i] == 0)cout << "azul ";
                            else if (sol[i] == 1)cout << "rojo ";
                            else cout << "verde ";
                        }
                        s = true;
                        cout << endl;
                    }
                   
                }
                else {
                    resolver(sol, colores, numerodepiezas, k+1,  altura,s);
                }
            }
            colores[i]++;
            numerodepiezas[i]--;
        }
     

    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int altura;
    vector<int>colores(3);
    cin >> altura;
    for (int i = 0; i < 3;i++) {
        cin >> colores[i];
    }
    if (altura==0&&colores[0]==0&& colores[1] == 0 && colores[2] == 0 )
        return false;
    vector<int>numerodepiezas(3);
    vector<int>sol(altura);
    if (colores[1] > 0) {
        bool s = false;
        sol[0] = 1;
        numerodepiezas[1]++;
        colores[1]--;
        resolver(sol, colores, numerodepiezas, 1, altura,s);
        if(!s)cout << "SIN SOLUCION"<<endl;
    }
    else cout << "SIN SOLUCION";
   
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
