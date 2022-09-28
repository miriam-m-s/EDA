// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;

// función que resuelve el problema
bool resolver(const vector<int>&v,int ini,int fin) {
    int n = fin - ini;
    if (n <= 2) {
        return (v[ini] <= v[ini + 1]);
    }
    else {
        int med = (ini + fin) / 2;
        int min = v[ini];
        for (int i = ini+1; i < med; i++) {
            if (v[i] < min)min = v[i];
        }
        int max = 0;
        for (int i = med; i < fin; i++) {
            if (v[i] > max)max = v[i];
        }
        int i = med;
        while (i<fin && v[i]>=min)i++;
        if (i < fin)return false;
        else {
            int j = ini;
            while (j < med && v[j] <= max)j++;
            if (j < med)return false;
            else {
                bool der = false;
                bool s= resolver(v, ini, med);
                if(s)
               der= resolver(v, med, fin);
                return (der && s);
            }
        }
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int caso;
    cin >> caso;
    if (caso==0)
        return false;
    vector<int>s;

    while (caso != 0) {
    
        s.push_back(caso);

        cin >> caso;
    }

    if (resolver(s, 0, s.size()))cout << "SI" << endl;
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
