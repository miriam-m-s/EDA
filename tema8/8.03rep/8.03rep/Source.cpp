
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include<string>
#include<map>
#include<list>

using namespace std;
struct alum {
    string profe;
    map<string, int>::iterator il;
    int puntos;
};
using Alum = map<string, alum > ;
using Profe = map<string, map<string, int>>;

class Autoescuela {
    Alum alum;
    Profe prof;
public:
    Autoescuela() {

    }
    ~Autoescuela() {

    }
    void  alta(string A, string P) {
        if (!alum.count(A)) {
            alum[A].puntos = 0;
            alum[A].profe = P;
            prof[P][A] = 0;
            auto ia = prof[P].find(A);
            alum[A].il = ia;
        }
        else if(alum[A].profe!=P) {
            //antiguo profe
            string s = alum[A].profe;
            //asignamos profe
            alum[A].profe = P;
            //añadimos al prfe el alumno con sus puntos anteriores
            prof[P][A] = alum[A].puntos;
            //borramos el alumno
            prof[s].erase(alum[A].il);
            auto is = prof[P].find(A);
            alum[A].il = is;
        }
        
    }
    bool es_alumno(string A, string P) {
        if(alum.count(A))
        return alum[A].profe == P;
        else
        {
            return false;
        }
    }
    int puntuacion(string A) {
        if (alum.count(A)) {
            return alum[A].puntos;
        }
        else throw domain_error("El alumno A no esta matriculado");
    }
    void actualizar(string A,int  N) {
        if (alum.count(A)) {
            alum[A].puntos += N;
            prof[alum[A].profe][A] += N;
        }
        else throw domain_error("El alumno A no esta matriculado");
    }
    list<string> examen(string P,int N) {
        list<string>l;
        for (map<string, int>::iterator il = prof[P].begin(); il != prof[P].end(); ++il) {
            if (il->second >= N) {
                l.push_back(il->first);
            }
        }
        return l;
    }
    void aprobar(string A) {
        if (alum.count(A)) {
            prof[alum[A].profe].erase(alum[A].il);
            alum.erase(A);
        }
        else {
            throw domain_error("El alumno A no esta matriculado");
        }
    }
};

bool resuelveCaso() {
    std::string orden, alum, prof;
    int punt;
    std::cin >> orden;
    if (!std::cin)
        return false;

    Autoescuela escuela;

    while (orden != "FIN") {
        try {
            if (orden == "alta") {
                cin >> alum >> prof;
                escuela.alta(alum, prof);
            }
            else if (orden == "es_alumno") {
                cin >> alum >> prof;
                if (escuela.es_alumno(alum, prof))
                    cout << alum << " es alumno de " << prof << '\n';
                else
                    cout << alum << " no es alumno de " << prof << '\n';
            }
            else if (orden == "puntuacion") {
                cin >> alum;
                int puntos = escuela.puntuacion(alum);
                cout << "Puntuacion de " << alum << ": " << puntos << '\n';
            }
            else if (orden == "actualizar") {
                cin >> alum >> punt;
                escuela.actualizar(alum, punt);
            }
            else if (orden == "examen") {
                cin >> prof >> punt;
                cout << "Alumnos de " << prof << " a examen:\n";
                for (auto const& a : escuela.examen(prof, punt)) {
                    cout << a << '\n';
                }
            }
            else if (orden == "aprobar") {
                cin >> alum;
                escuela.aprobar(alum);
            }
        }
        catch (std::domain_error e) {
            std::cout << "ERROR\n";
        }
        std::cin >> orden;
    }
    std::cout << "---\n";
    return true;
}

int main() {

    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   // _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    //system("pause");
#endif
    return 0;
}
