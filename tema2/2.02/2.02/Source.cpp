// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;
bool resolve(const vector<int>& num, int ini, int fin,int k) {
    int n = fin - ini;
    if (n <= 2) {
        return abs(num[ini] - num[ini + 1]) >= k;
    }
    else {
        int mid = (fin + ini) / 2;
        if (abs(num[ini] - num[fin-1]) < k)return false;
        else {
            bool izq = resolve(num, ini, mid, k);
            bool der= resolve(num, mid, fin, k);
            return (izq && der);
        }
    }
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
   
    int tam; int k; 
    cin >> tam >> k ;
    if (!std::cin)
        return false;
    vector<int>num(tam);
    for (int i = 0; i < tam; i++) {
        cin >> num[i];
    }
    if(resolve(num, 0, tam, k))cout<<"SI"<<endl;
    else cout << "NO" << endl;
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