// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include<set>
#include<algorithm>
#include<vector>
#include <fstream>
#include <math.h>
using namespace std;

struct Monomio {
public:
    Monomio() {};
    Monomio(int c, int e) :coef_(c), exp_(e) {};
    int coef_;
    int exp_;
    bool operator <(const Monomio m)const {
        if (exp_ < m.exp_)return true;
        else return false;
    }
};
bool orden(const Monomio a, const Monomio b) {
    return a < b;
}
class Polinomio {
private:
    vector<Monomio>pol;
    set<int>exp;
public:
    Polinomio() {

    }
    ~Polinomio(){}
   
    void add(Monomio m) {
        if (exp.count(m.exp_)) {            
            int i = 0;
            vector<Monomio>::iterator il = pol.begin();
            while (i != pol.size() && pol[i].exp_ != m.exp_) { i++; ++il; }
            if (i != pol.size()) {
                pol[i].coef_ += m.coef_; 
                if (pol[i].coef_ == 0) {
                    pol.erase(il);
                }
                            
            }
        }
        else {
            if (m.coef_ != 0) {
                pol.push_back(m);
                sort(pol.begin(), pol.end(), orden);
            }
            
        }
    }
    int suma(int s) {
        int suma=0;
        for (int i = 0; i < pol.size(); i++) {
            suma += pol[i].coef_ * (pow(s, pol[i].exp_));
        }
        return suma;
    }
};
// función que resuelve el problema


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int c, e;
    cin >>c >> e;
    if (!std::cin)
        return false;
    Polinomio p;
    while (c != 0 || e != 0) {
        p.add(Monomio(c, e));
        cin >> c >> e;
    }
    int n;
    cin >> n;
    int l;
    for (int i = 0; i < n; i++) {
        cin >> l;
        cout << p.suma(l) << " ";
    }
    cout << endl;




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
