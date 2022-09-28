// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
#include<stack>
#include<vector>
using namespace std;
void resuelve(const vector<int>l,int num,int &sumatotal,int k,int &total) {
    if (sumatotal + l[k] < num) {
        sumatotal += l[k];
        if (k < l.size() - 1) {
            resuelve(l, num, sumatotal, k + 1, total);
        }
        sumatotal -= l[k];
    }
    else if (sumatotal + l[k] == num)total++;

    if (k < l.size() - 1) {
        resuelve(l, num, sumatotal, k + 1, total);
    }
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int size, num=0;
    cin >> size;
    cin >> num;
    if (!std::cin)
        return false;
    vector<int>l(size);
    int a;
    for (int i = 0; i < size; i++) {
        cin >> a;
        l[i]=a;
    }
    int sumatotal = 0;
    int total = 0;
    resuelve(l, num, sumatotal, 0, total);
    cout << total << endl;
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