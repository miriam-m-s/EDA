#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include<map>
#include<algorithm>
using namespace std;


using Pelicula = string;
using Actor = string;
using RepartosPeliculas=  map<Pelicula, map<Actor, int>>;
struct pelis {
    int num=0;
    map<int, string>::iterator is;
};
void leerRepartos(int numPeliculas, RepartosPeliculas& peliculas) {
    Pelicula peli; int numActores;
    Actor actor; int minutos;
    for (int i = 0; i < numPeliculas; ++i) {
        cin >> peli; cin >> numActores;
        peliculas[peli];
            for (int j = 0; j < numActores; ++j) {
                cin >> actor >> minutos;
                peliculas[peli][actor] = minutos;
            }
    }
}
bool orden(pair<string, int>& A, pair<string, int>& B) {
    if (A.second == B.second)return A.first < B.first;
    else return A.second > B.second;
}

void procesarEmisiones(RepartosPeliculas & repartos, vector<string> const& secEmisiones) {
    map<string, int>actor;
    map<string, pelis>pelis;
    map<int, string>ganapelis;
    for (int i = 0; i < secEmisiones.size(); i++) {
        pelis[secEmisiones[i]].num++;
        ganapelis[pelis[secEmisiones[i]].num] = secEmisiones[i];
        if (repartos.count(secEmisiones[i])) {
            for (map<Actor, int>::iterator il = repartos[secEmisiones[i]].begin(); il != repartos[secEmisiones[i]].end(); ++il) {
                if (!actor.count(il->first)) {
                    actor[il->first] = il->second;
                }
                else actor[il->first] += il->second;
            }
        }
    }
    vector<pair<string, int>>v;
    for(map<string, int>::iterator il=actor.begin();il!=actor.end();++il)
    {
        v.push_back(make_pair(il->first, il->second));
    }
    sort(v.begin(), v.end(), orden);
    map<int, string>::iterator is = ganapelis.end();
    --is;
    cout << is->first << " " << is->second<<endl;
    int i = 1;
    int s = v[0].second;
    cout << v[0].second << " " << v[0].first << " ";
    while (i != v.size() && v[i].second == s) {
        cout << v[i].first << " ";
        i++;
    }
    cout << endl;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numPelis, numEmisiones;
    cin >> numPelis;
    if (numPelis == 0)
        return false;

    // Lectura de los repartos de las peliculas
    RepartosPeliculas repartos;
    leerRepartos(numPelis, repartos);

    // Lectura de la secuencia de peliculas emitidas en vector<string>
    cin >> numEmisiones;
    vector<string> secEmisiones(numEmisiones);
    for (string& s : secEmisiones) cin >> s;

    procesarEmisiones(repartos, secEmisiones);

    return true;
}


//#define DOMJUDGE
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