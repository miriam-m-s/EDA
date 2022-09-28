// Plantilla para el ejercicio de Venta de libros

#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <map>
#include <unordered_map>
#include <utility>
#include <list>
#include "VentadeLibros.h"

using namespace std;

// Muestra el contenido de una lista
template <class T>
void mostrar(list<T> const& l) {
    for (auto const& e : l) {
        cout << e << '\n';
    }
}

bool resuelveCaso() {
    int numOp;

    cin >> numOp;
    if (!cin) return false;

    VentadeLibros amazon;

    string operacion, titulo;

    for (int i = 0; i < numOp; ++i) {
        cin >> operacion;
        cin.ignore(1); // saltar blanco
        if (operacion == "nuevoLibro") {
            int unidades;
            cin >> unidades;
            cin.ignore(1);
            getline(cin, titulo);
            amazon.nuevoLibro(unidades, titulo);
        }
        else if (operacion == "comprar") {
            getline(cin, titulo);
            try {
                amazon.comprar(titulo);
            }
            catch (out_of_range const& e) {
                cout << e.what() << '\n';
            }
            catch (invalid_argument const& e) {
                cout << e.what() << '\n';
            }
        }
        else if (operacion == "estaLibro") {
            getline(cin, titulo);
            if (amazon.estaLibro(titulo)) {
                cout << "El libro " << titulo << " esta en el sistema\n";
            }
            else {
                cout << "No existe el libro " << titulo << " en el sistema\n";
            }
        }
        else if (operacion == "elimLibro") {
            getline(cin, titulo);
            amazon.elimLibro(titulo);
        }
        else if (operacion == "numEjemplares") {
            getline(cin, titulo);
            if (amazon.estaLibro(titulo)) {
                cout << "Existen " << amazon.numEjemplares(titulo) << " ejemplares del libro " << titulo << '\n';
            }
            else {
                cout << "No existe el libro " << titulo << " en el sistema\n";
            }
        }
        else if (operacion == "top10") {
            cout << "TOP10\n";
            mostrar(amazon.top10());
        }
    }
    // fin del caso
    cout << "---\n";
    return true;

}

int main() {



    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   // _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    //system("pause");
#endif
    return 0;
}
