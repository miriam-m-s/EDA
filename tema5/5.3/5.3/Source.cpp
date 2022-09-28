// Nombre del alumno MIRIAM MARTIN .....
// Usuario del Juez  VJ34......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
#include <string>
#include<stack>
#include<queue>

using namespace std;
// función que resuelve el problema


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int s;
    cin >> s;
    if (s == 0)
        return false;
    queue<int> paren;
   stack<int> negatives;
    int h;
    for (int i = 0; i < s; i++) {
        cin >> h;
        if (h > 0)
            paren.push(h);
        else {
            negatives.push(h);
        }
     
    }
    int l = negatives.size();
    for (int i = 0; i < l; i++) {
        cout << negatives.top() << " ";
        negatives.pop();
    }
    int ns = paren.size();
    for (int l = 0; l < ns; l++) {
        cout << paren.front() << " ";
        paren.pop();
    }
     //resolver(paren,original, 0,s);
     
    
     cout << endl;
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