// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;
struct obje {
    int benef = 0;
    int volume = 0;
};
void resolve(int& maxbenf, int& benef, vector<obje>& obj,int espuma,int& capacidad,int &capacity,int k,int objetos) {
   
    if (capacidad + obj[k].volume <= capacity) {
        benef += obj[k].benef;
        capacidad += obj[k].volume;
        if (k >= objetos - 1) {
            int espuma1 = (capacity - capacidad) * espuma;
            if (benef-espuma1 > maxbenf) {
                
                maxbenf = benef-espuma1; 
            }
        }
        else {
            resolve(maxbenf, benef, obj, espuma, capacidad, capacity, k + 1, objetos);
        }
        capacidad -= obj[k].volume;
        benef -= obj[k].benef;
    }

    if (k >= objetos - 1) {
        int espuma1 = (capacity - capacidad) * espuma;
        if (benef - espuma1 > maxbenf) {

            maxbenf = benef - espuma1;
        }
    }
    else {
        resolve(maxbenf, benef, obj, espuma, capacidad, capacity, k + 1, objetos);
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int capacida, espuma, objetos;
    cin >> capacida >> espuma >> objetos;
    if (capacida==0&&espuma==0&&objetos==0)
        return false;
    vector<obje>obj(objetos);
    for (int i = 0; i < objetos; i++) {
        cin >> obj[i].benef >> obj[i].volume;
    }
    int maxbenef = 0;
    int benef = 0;
    int capacidad = 0;
    resolve(maxbenef, benef, obj, espuma, capacidad, capacida,0, objetos);
    // escribir sol
    cout << maxbenef << endl;
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
