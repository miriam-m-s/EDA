// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;
struct song {
   
public:
    int time;
    int likes;
    song(int h, int l) :time(h), likes(l) {
    }
    song() {

    }
  
};

// función que resuelve el problema
void resolver(int &gusto,int&maxgusto,int k, vector<song>&canciones, vector<int>&cinta, int tiempocinta) {

    
    if (cinta[0] + canciones[k].time <= tiempocinta) {
        gusto += canciones[k].likes;
        cinta[0] += canciones[k].time;
        if (k == canciones.size() - 1) {
            if (gusto > maxgusto)maxgusto = gusto;
        }
        else {
            resolver(gusto, maxgusto, k + 1, canciones, cinta, tiempocinta);
        }
        gusto -= canciones[k].likes;
        cinta[0] -= canciones[k].time;
    }
    if (cinta[1] + canciones[k].time <= tiempocinta) {
        gusto += canciones[k].likes;
        cinta[1] += canciones[k].time;
        if (k == canciones.size() - 1) {
            if (gusto > maxgusto)maxgusto = gusto;
        }
        else {
            resolver(gusto, maxgusto, k + 1, canciones, cinta, tiempocinta);
        }
        gusto -= canciones[k].likes;
        cinta[1] -= canciones[k].time;
    }
  

    if (k < canciones.size() - 1) {
        resolver(gusto, maxgusto, k + 1, canciones, cinta, tiempocinta);
    }
    else {
        if (gusto > maxgusto)maxgusto = gusto;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numcanciones;
    cin >> numcanciones;
    if (numcanciones==0)
        return false;
    int tiempocinta;
    cin >> tiempocinta;
    vector<int>cinta(2,0);
    vector<song>canciones(numcanciones);
    int h, l;
    for (int i = 0; i < canciones.size(); i++) {
        cin >> h >> l;
        canciones[i]=song(h, l);
    }
    int gusto = 0;
    int maxgusto = 0;

    resolver(gusto, maxgusto, 0, canciones, cinta, tiempocinta);
    cout << maxgusto << endl;
    // escribir sol

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
