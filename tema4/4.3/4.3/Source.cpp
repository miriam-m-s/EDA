// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<math.h>
#include<set>
using namespace std;
int sumeleva(int l) {
    int suma = 0;
    while (l != 0) {
        int num = l % 10;
        l /= 10;
        suma += pow(num, 2);
    }
    return suma;
}
void numerofeliz(int l) {
    set<int>s;
    
    while (!s.count(l)) {
        cout << l << " ";
        s.insert(l);
        l = sumeleva(l);
    }
    cout << l;
    if (l != 1)cout << " 0";
    cout << endl;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int l;
    cin >> l;
    if (!std::cin)
        return false;
    numerofeliz(l);
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