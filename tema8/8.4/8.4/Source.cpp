
#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>
#include <fstream>
#include <list>
#include "iPud.h"
using namespace std;

using cancion = std::string;
using artista = std::string;


bool resuelve() {
    string operacion;
    cin >> operacion;
    if (!cin)
        return false;
    cancion tit; artista aut; int dur;
    iPud ipud;
    while (operacion != "FIN") {
        try {
            if (operacion == "addSong") {
                cin >> tit >> aut >> dur;
                ipud.addSong(tit, aut, dur);
            }
            else if (operacion == "addToPlaylist") {
                cin >> tit;
                ipud.addToPlaylist(tit);
            }
            else if (operacion == "current") {
                tit = ipud.current(); // aunque no se hace nada, puede producir error
            }
            else if (operacion == "play") {
                try {
                    string tocando = ipud.current(); // para saber si la lista es vac�a
                    ipud.play();
                    cout << "Sonando " << tocando << '\n';
                }
                catch (invalid_argument e) {
                    cout << "No hay canciones en la lista\n";
                }
            }
            else if (operacion == "totalTime") {
                cout << "Tiempo total " << ipud.totalTime() << '\n';
            }
            else if (operacion == "recent") {
                int N;
                cin >> N;
                auto lista = ipud.recent(N);
                if (lista.empty())
                    cout << "No hay canciones recientes\n";
                else {
                    cout << "Las " << lista.size() << " mas recientes\n";
                    for (auto const& s : lista)
                        cout << "    " << s << '\n';
                }
            }
            else if (operacion == "deleteSong") {
                cin >> tit;
                ipud.deleteSong(tit);
            }
            else { // operacion desconocida
                assert(false);
            }
        }
        catch (invalid_argument e) {
            cout << "ERROR " << e.what() << '\n';
        }
        cin >> operacion;
    }
    cout << "---\n";
    return true;
}

int main() {
#ifndef DOMJUDGE
    // _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelve());

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    //system("pause");
#endif
    return 0;
  
}
