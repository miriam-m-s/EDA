#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue.h"
using namespace std;
//coste el algoritmo :n

template <class T>
class queue_plus : public queue<T> {
    using Nodo = typename queue<T>::Nodo;

public:
    void cuela(const T& a, const T& b) {
        if (this->size() != 0) {
            Nodo* aux = this->prim;
            bool h = true;
            Nodo* pr = nullptr;
            while (aux != nullptr && h) {
                if (aux->elem == a) {
                    h = false;
                    pr = aux;
                }
                else
                aux = aux->sig;
            }
            if (pr != nullptr) {
                h = true;
                if (pr->sig != nullptr) {
                    Nodo* aux2 = pr->sig;
                    Nodo* seg = nullptr;
                    while (aux2 != nullptr && h) {
                        if (aux2->elem == b) {
                            h = false;
                            seg = aux2;

                        }
                        else {
                            aux = aux->sig;
                            aux2 = aux2->sig;
                        }

                    }
                    if (seg != nullptr) {
                        if (seg->sig == nullptr) {
                            this->ult = aux;
                            aux->sig = nullptr;
                            
                        }
                        else {
                            aux->sig = seg->sig;

                        }
                        Nodo* c = pr->sig;
                        pr->sig = seg;
                        seg->sig = c;

                    }
                }
                
            }

        }
        
    }
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, a, b;
    queue_plus<int> q;
    cin >> n;
    if (n == -1) return false;
    while (n != -1) {
        q.push(n);
        cin >> n;
    }
    cin >> a >> b;

    // llamada a metodo
    q.cuela(a, b);

    // escribir sol (pero antes dar una vuelta para comprobar que la cola está bien formada)
    for (int i = 0; i < q.size(); ++i) {
        n = q.front();
        q.pop();
        q.push(n);
    }
    // Ahora imprimimos la cola y de paso la dejamos vacía
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
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
    //system("PAUSE");
#endif

    return 0;
}
