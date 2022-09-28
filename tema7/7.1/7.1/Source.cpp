#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <list>
#include <cctype>
#include<vector>
using namespace std;
using TablaRefs =map<string,list<int>> ;
void referencias(int numLineas, TablaRefs& refs) {
    string palabra;
    char c;

    for (int numLinea = 1; numLinea <= numLineas; numLinea++) {
        cin.get(c);
        while (c != '\n') {
        
            cin.unget(); // Se vuelve a dejar c en cin (por si era la 1ª letra de la linea)
            cin >> palabra;
            if (palabra.length() > 2) {                
                for (int i = 0; i < palabra.size(); i++) {
                    palabra[i] = tolower(palabra[i]);
                }
                //Repetidas
           
                if (refs.count(palabra)) {
                   
                    if (refs[palabra].back() != numLinea) {
                        refs[palabra].push_back(numLinea);  
                    } 
                }
                else {
                    refs[palabra].push_back(numLinea);
                }       
            }
               cin.get(c);
        }
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    char c;

    cin >> n;
    cin.get(c); // Me salto el \n de detrás del N
    if (n == 0)
        return false;

    TablaRefs refs;
    referencias(n, refs);
    for (map<string, list<int>>::iterator it = refs.begin(); it != refs.end(); ++it) {
        cout << it->first << " ";
        for (list<int>::iterator il = it->second.begin(); il != it->second.end(); ++il) {
            cout << *il << " ";
        }
       /* for (int i = 0; i < it->second.size(); i++) {
            cout << it->second[i] << " ";
        }*/
        cout << "\n";
    }
    // escribir sol
    
        cout << "---\n";
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
#endif

    return 0;
}