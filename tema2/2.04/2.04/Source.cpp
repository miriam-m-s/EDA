// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
#include <cmath>
using namespace std;

// función que resuelve el problema
bool resolver(vector<int>v,int ini,int fin) {
    int n = fin - ini;
    if (n <= 2) {
        /*int i = 0;
        int d = 0;
        if (v[ini] % 2 == 0)i = 1;
        if (v[ini + 1] % 2 == 0)d = 1;
        return(abs(i - d) <= 2);*/
        return true;
    }
    else {
        int mid = (fin + ini) / 2;
        int d = 0;
        int  izq = 0;
        for (int i = ini; i < mid; i++) {
            if (v[i] % 2 == 0)izq++;
        }
        for (int j = mid; j < fin; j++) {
            if (v[j] % 2 == 0)d++;
        }
        if (abs(izq - d) > 2)return false;
        else {
            bool izq1 = resolver(v, ini, mid);
            bool der = resolver(v, mid, fin);
            return(izq1 && der);
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tam;
    cin >> tam;
    if (tam==0)
        return false;
    vector<int>v(tam);
    for (int i = 0; i < tam; i++) {
        cin >> v[i];
    }
    if (resolver(v, 0, v.size()))cout << "SI" << endl;
    else cout << "NO" << endl;

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
