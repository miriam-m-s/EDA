// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<map>
#include<unordered_map>
using namespace std;

struct pos {
    int posini;
    int posfinal;
};
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
//void resuelveCaso() {
//    // leer los datos de la entrada
//    int tam;
//    cin >> tam;
//    map<int,pos>l;
//    int h;
//    int dias = 0;
//    int maxdias = 0;
//    int rep=0;
//    for (int i = 0; i < tam; i++) {
//        cin >> h;
//        if (!l.count(h)) { 
//            l[h].posini = i;
//            dias++;
//            if (dias > maxdias)maxdias = dias;
//        }
//        else {
//           
//            
//            if (l[h].posini >= rep) {
//                dias = i - l[h].posini;
//                rep = l[h].posini+1;
//            }
//           
//            l[h].posini = i;
//      
// 
//        }
//    }
//    if (dias>maxdias)cout << dias << endl;
//    else
//    cout << maxdias << endl;
//
//
//}
void resuelveCaso() {
    int nCaps = 0, topeComprobacion = 1;
    long long int distance = 0, distanceMax = 0;
    cin >> nCaps;
    unordered_map<int, int> capitulos;
    int cap = 0;
    for (int i = 1; i <= nCaps; ++i) {
        cin >> cap;
        //Aqui hay un matiz, y es que si no lo contiene, suma distancia. Pero tendria que sumar distancia tambien cuando
        //lo contiene y el comprobado esta por debado del tope. Con este codigo del if comentado, solo suma cuando no lo contiene
        /*if (capitulos.contains(cap)) {
            if (capitulos.at(cap) >= topeComprobacion) {
                topeComprobacion = capitulos.at(cap) + 1;
                distance = i - capitulos.at(cap);
            }
        }*/
        if (capitulos.count(cap) && capitulos.at(cap) >= topeComprobacion) {
            topeComprobacion = capitulos.at(cap) + 1;
            distance = i - capitulos.at(cap);
        }
        else {
            ++distance;
            if (distance > distanceMax) distanceMax = distance;
        }
        capitulos[cap] = i;
    }
    // escribir sol
    cout << distanceMax << endl;
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