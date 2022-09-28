// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
#include<stack>
#include<string>
using namespace std;




// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    string s;
   getline(cin, s);
    if (!std::cin)
        return false;
    bool hey = true;
    int i = 0;
    stack<char>pila;
    while (i < s.size() && hey) {
        if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
            pila.push(s[i]);
        }
        else if ((s[i] == '}' || s[i] == ')' || s[i] == ']')) {
            if (pila.empty())hey = false;
            else if ((pila.top() == '{'&&s[i]=='}')|| (pila.top() == '(' && s[i] == ')') || (pila.top() == '[' && s[i] == ']')) {
                pila.pop();
            }
            else {
                hey = false;
            }
        }
        i++;
    }
    if (hey&&pila.empty())cout << "SI";
    else cout << "NO";
    // escribir sol
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