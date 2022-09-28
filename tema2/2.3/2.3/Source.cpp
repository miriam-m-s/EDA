// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
bool resolver(vector<int>const &v,int &ini,int &fin,int & max,int & min) {
    int n = fin - ini;
    if (n == 2) {
        if (v[ini] > v[ini + 1])return false;
        else {
            min = v[ini];
            max = v[ini + 1];
            return true;
        }
    }
    else {
        int med = (fin + ini) / 2;
        int maxder, minder, maxizq, minizq; 
        bool izq = resolver(v, ini, med, maxizq, minizq);
        bool der = resolver(v, med, fin, maxder, minder);
        bool s = true;
        if (minizq > minder)s= false;
        else if (maxder < maxizq)s= false;
        return s && izq && der;
      
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
    vector<int>h;
   
    while (s != 0) {
        h.push_back(s);
        cin >> s;
    }

    int ini = 0;
    int fin = h.size() ;
    int maxizq=0, minizq=0;
  bool hey= resolver(h, ini, fin, maxizq, minizq);
  if (hey)cout << "SI"<<endl;
  else cout << "NO" << endl;
    //ipoSolucion sol = resolver(datos);

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
