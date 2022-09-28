// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
bool resolver(const vector<int>&v,int ini,int fin) {
    int n = fin - ini;
    if (n == 2) {
        if (v[ini] < v[ini + 1]) {;
            return true;
        }
        else {
            return false;
        }
    }
    else {
        int med = (fin + ini) / 2;
        if (v[ini] <= v[med] && v[med - 1] <= v[fin-1]) {
   
            return (resolver(v, med, fin)&& resolver(v, ini, med));
        }
        else return false;
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int s;
    cin >> s;
    if (s==0)
        return false;
    vector<int>num;
    while (s != 0) {
        num.push_back(s);
        cin >> s;
    }
   
    if(resolver(num, 0, num.size())) cout << "SI"<<endl;
    else cout << "NO" << endl;
  // bool sol = resolver(num);

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
