// Nombre del alumno miriam martin.....
// Usuario del Juez vj34......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;

bool resolver1(const vector<int>& v, int ini, int fin) {
    int n = fin - ini;
  if (n <= 1) {
       return v[ini]==ini;
   }
   else {
      if (v[ini] == ini || v[fin - 1] == fin - 1) {
           return true;
       }
       else {
           int med = (fin + ini) / 2;
           bool h = false;
           bool s = false;
            h= resolver1(v, ini, med);
            s = resolver1(v, med, fin);
           return(s || h);
       }
   }
}

// función que resuelve el problema
bool resolver(const vector<int>& v, int ini, int fin) {
    int n = fin - ini;
    if (n >= 2) {
        if (v[ini] == ini || v[fin - 1] == fin - 1) {
            return true;
        }
        int med = (ini + fin) / 2;
        bool izq = resolver(v, ini, med);
        bool der = resolver(v, med, fin);
        return(izq || der);
    }
    else return (v[ini] == ini);
   
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bool sol;
    int tama = 0;
    cin >> tama;
    if (tama == 0)sol = false;
    else {
        vector<int>v(tama);
        for (int i = 0; i < tama; i++) {
            cin >> v[i];
        }
        sol = resolver1(v, 0, tama);
    }

    if (sol)cout << "SI" << endl;
    else cout << "NO" << endl;



}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}