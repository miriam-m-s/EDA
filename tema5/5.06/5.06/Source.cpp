// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
#include<string.h>
using namespace std;
void fase1(list<char>& l) {
    for (list<char>::iterator it = l.begin(); it != l.end(); ) {
        char letra = *it;
        if (!(letra == 'a' || letra == 'A' || letra == 'e' || letra == 'U' || letra == 'O' || letra == 'E' || letra == 'I' || letra == 'i' || letra == 'o' || letra == 'u')) {
            list<char>::iterator init = it;
            list<char>::iterator fin = it;
            while (it != l.end()&&!((letra == 'a' || letra == 'A' || letra == 'e' || letra == 'U' || letra == 'O' || letra == 'E' || letra == 'I' || letra == 'i' || letra == 'o' || letra == 'u'))) {
                ++it;
                ++fin;
                if(it!=l.end())
                letra = *it;
            }
          
            while (init != fin) {
                char s = *init;
                init = l.erase(init);
                l.insert(fin, s);
                if(fin!=init)
                fin--;

            }
        }
        else {
            it++;
        }


    }
    for (list<char>::iterator it = l.begin(); it != l.end(); ++it) {
        cout << *it;
    }
    cout << endl;
}

void fase2(list<char>&l) {
    int i = 0;
    list<char>::iterator fin = l.end();
    int s = l.size();
    list<char>::iterator it = l.begin();
    while(i!=l.size()&& it != fin) {
        if (i % 2 != 0) {
            char s = *it;
            it = l.erase(it);
            l.insert(fin,s);
            fin--;
            
        }
        else {
            ++it;
        }
        i++;
    }
    for (list<char>::iterator it = l.begin(); it != l.end(); ++it) {
        cout << *it;
    }
    cout << endl;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    if (!std::cin)
        return false;
    list<char>li;
    string palabra;
    char c;

   
        cin.get(c);
        bool s = true;

        while (c != '\n'&&s) {

            cin.unget(); // Se vuelve a dejar c en cin (por si era la 1ª letra de la linea)
            cin >> palabra;
            
                for (int i = 0; i < palabra.size(); i++) {
                    c = palabra[i];
                    li.push_back(c);
                }
                //Repetidas
           
            cin.get(c);
           
            if (c != ' ')s = false;
            else {
                if (c != '\n') {
                    while (c == ' ') {
                        li.push_back(c);
                           cin.get(c);
                    }
                   
                }
                   
            }
       }
        for (list<char>::iterator it = li.begin(); it != li.end();++it ) {
            cout << *it;
        }
        cout << endl;
       
        fase1(li);
        fase2(li);
   
 

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