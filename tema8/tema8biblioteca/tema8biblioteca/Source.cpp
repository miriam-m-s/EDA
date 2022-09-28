// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<string>
#include<unordered_map>
#include<map>
using namespace std;
struct libro {
    bool have;
    int usuario;
};
struct user {
    int numlibros;
    map<int, int>::iterator il;
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numlibros, casosprocesar;
    cin >> numlibros >> casosprocesar;
    if (numlibros==0&&casosprocesar==0)
        return false;
    unordered_map<int, libro> libros;
    int h;
    for (int i = 0; i < numlibros; i++) {
        cin >> h;
        libros[h].have = false;
    } 
    string hey;
    int i = 0;
    bool hy = true;
    int nmlibros = 0;
   
    map<int, int>process;
    while ( i < casosprocesar&&hy) {
        cin >> hey;
       
        if (hey == "PRESTAR") {
            int usuario, libro;
            cin >> usuario >> libro;
            if (libros.count(libro)&&libros[libro].have==false) {
                libros[libro].have = true;
                libros[libro].usuario = usuario;
                nmlibros++;
                if (process.count(usuario)) {
                    process[usuario]++;
                }
                else process[usuario] = 1;
                
            }
            else {
                hy = false;
            }
            
        }
        else {
            int usuario, libro;
            cin >> usuario >> libro;
            if (libros.count(libro) && libros[libro].usuario == usuario&& libros[libro].have==true) {
                libros[libro].have = false;
                libros[libro].usuario = 0;
                nmlibros--;
                if (process.count(usuario)) {
                    process[usuario]--;
                }
            }
            else {
                hy = false;
            }
        }
        i++;
    }
    if (hy) {
        cout << "Biblioteca -> " << nmlibros << endl;
        for (map<int, int>::iterator il = process.begin(); il != process.end(); ++il) {
            cout << il->first << " -> " << il->second << endl;
        }
    }
    else cout << "ERROR" << endl;
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
