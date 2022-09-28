// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>

#include<vector>
using namespace std;
void resuelve(vector<int>& v, int num, int k,vector<bool>&b,int&suma,int &result) {
    if (!b[k]) {
        b[k] = true;
        suma += v[k];
        if (suma == num) {
            result++;
        }
        else if (suma  < num) {
            if (k < v.size() - 1) {
                resuelve(v, num, k + 1, b, suma, result);
            } 
        }
        b[k] = false;
        suma -= v[k];
    }
    if (k < v.size() - 1) {
        resuelve(v, num, k + 1, b, suma, result);
    }
   
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tam, num;
    cin >> tam >> num ;
    if (!std::cin)
        return false;
    vector<int>v(tam);
    for (int i = 0; i < tam; i++) {
        cin >> v[i];
    }
    vector<bool>b(tam, false);
    int suma = 0;
    int result = 0;
    resuelve(v, num, 0, b, suma, result);
    cout << result << endl;
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