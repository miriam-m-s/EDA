#include <iostream>
#include <fstream>
#include <string>
#include<map>
#include<vector>
using namespace std;
using Diccionario = map<string, int>;

void leerDiccionario(Diccionario& diccionario) {
    char c;
    string clave;
    int valor;
    cin.get(c);
    while (c != '\n') {
        cin.unget();
        cin >> clave >> valor;
        diccionario.insert({ clave,valor });
            cin.get(c);
    }
}

void resuelveCaso() 
{
    Diccionario antiguo;
    Diccionario nuevo;
    leerDiccionario(antiguo);
    leerDiccionario(nuevo);
    map<string, int>::iterator ant = antiguo.begin();
    map<string, int>::iterator nuev = nuevo.begin();
    vector<string>addd;
    vector<string>quitad;
    vector<string>cambiovalor;
    while (ant != antiguo.end() && nuev != nuevo.end()) {
        if (ant->first < nuev->first) {
            quitad.push_back(ant->first);
            ++ant;
        }
        else {
            if ((ant->first == nuev->first)) {
                if (ant->second != nuev->second) {
                    cambiovalor.push_back(ant->first);
                }
                ++nuev;
                ++ant;
            }
            else {
                addd.push_back(nuev->first);
                ++nuev;
            }
           
        }
    }
    if (ant == antiguo.end()) {
        for (map<string, int>::iterator it = nuev; it != nuevo.end(); ++it) {
            addd.push_back(it->first);
        }
    }
    else {
        for (map<string, int>::iterator it = ant; it != antiguo.end(); ++it) {
            quitad.push_back(it->first);
        }
    }
    if (addd.size() == 0 && quitad.size() == 0 && cambiovalor.size() == 0) {
        cout << "Sin cambios";
        cout << "\n";
    }
    else {
        if (addd.size() > 0) {
            cout << "+ ";
            for (int i = 0; i < addd.size(); i++) {
                cout << addd[i] << " ";
            }
            cout << "\n";
        }
        if (quitad.size() > 0) {
            cout << "- ";
            for (int i = 0; i < quitad.size(); i++) {
                cout << quitad[i] << " ";
            }
            cout << "\n";
        }
        if (cambiovalor.size()> 0) {
            cout << "* ";
            for (int i = 0; i < cambiovalor.size(); i++) {
                cout << cambiovalor[i] << " ";
            }
            cout << "\n";
        }
      
    }
    cout << "---" << "\n";
}

  
        



int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos; char c;
    std::cin >> numCasos;
    cin.get(c);
    for (int i = 0; i < numCasos; ++i) {
      
        resuelveCaso();
    }
        

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
