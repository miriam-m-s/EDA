// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<list>
using namespace std;
// función que resuelve el problema
void resolver(list<char>& li, int tam, int pos,int anchura,int atras) {
    int posguardar = pos - atras;
    if (posguardar >= 0) {
        int i = 0;
        list<char>::iterator pguarda;
        for (list<char>::iterator il = li.begin(); il != li.end(); ) {
            if (i == posguardar) {
                pguarda = il;
                ++il;
            }
            else if (i >= pos && i < pos + anchura) {
                char valor = *il;
                il = li.erase(il);
                li.insert(pguarda, valor);
            }
            else ++il;
            i++;
        }
       
    }
   

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int tam,pos,anchura,atras;
    cin >> tam >> pos >> anchura >> atras;
    list<char>l;
    char h;
    for (int i = 0; i < tam; i++) {
        cin >> h;
        l.push_back(h);
    }
    if(!(anchura==0||atras==0))
    resolver(l, tam, pos, anchura, atras);
    for (list<char>::iterator il = l.begin(); il != l.end();++il ) {
        cout << *il << " ";
    }
    cout << endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}