// Plantilla para el ejercicio del Consultorio Médico

#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <cassert>
#include<map>
#include<string>
#include<vector>

using namespace std;
struct fecha {
public:
    int dia;
    int hora;
    int minuto;
    fecha(){}
    fecha(int dia, int hora, int min) :dia(dia), hora(hora), minuto(min) {};
    bool operator<(const fecha& t)const {
        if (dia < t.dia) {
            return true;
        }
        else if (dia == t.dia) {
            if (hora < t.hora)return true;
            else if (hora == t.hora) {
                if (minuto < t.minuto)return true;
                else return false;
            }
            else return false;
        }
        else return false;
     
    }
    friend ostream& operator<<(ostream& out, const fecha& d) {
        string h = to_string(d.hora);
        string m = to_string(d.minuto);

        if (d.hora < 10)h = "0" + to_string(d.hora);
        if (d.minuto < 10)m = "0" + to_string(d.minuto);
       
        out << h << ":" << m;
        return out;
    }
private:
   
};
using Consult = map < string, map<fecha, string>>;
class Consultorio {
    Consult consul;
public:
    Consultorio() {

    }
    ~Consultorio() {

    }
    void nuevoMedico(string m) {
        consul[m];
    }
    void pideConsulta(string p, string m,fecha f) {
        if (consul.count(m)) {
            if(consul[m].count(f))throw invalid_argument(" Fecha ocupada");
            else {
                consul[m][f] = p;
            }
        }
        else throw invalid_argument("Medico no existente");
    }
    string siguientePaciente(string m) {
        if (consul.count(m)) {
            map<fecha, string>::iterator il= consul[m].begin();
            if (il != consul[m].end()) {
                return il->second;
            }
            else throw invalid_argument("No hay pacientes");

        }
        else throw invalid_argument("Medico no existente");

    }
    void atiendeConsulta(string m) {
        if (consul.count(m)) {
            map<fecha, string>::iterator il = consul[m].begin();
            if (il != consul[m].end()) {
              il = consul[m].erase(il);
            }
            else throw invalid_argument("No hay pacientes");

        }
        else throw invalid_argument("Medico no existente");
    }
    vector<pair<fecha,string>>listaPacientes(string m, fecha d) {
        if (consul.count(m)) {
            vector < pair<fecha, string>>s;
            map<fecha, string>::iterator il = consul[m].begin();
                bool hey = true;
            while( il != consul[m].end()&&hey) {
                if (il->first.dia == d.dia) {
                    s.push_back(make_pair(il->first, il->second));
                }
                else if (il->first.dia > d.dia) {
                    hey = false;
                }
                ++il;
            }
            return s;

        }
        else throw invalid_argument("Medico no existente");
    }
};

int casos = 0;
bool resuelve() {

    int N;
    cin >> N;
    if (!cin) return false;

    string inst; string med; string pac; int d, h, m; char c;
    Consultorio con;

    for (int i = 0; i < N; ++i) {
        try {
            cin >> inst;
            if (inst == "nuevoMedico") {
                cin >> med;
                con.nuevoMedico(med);
            }
            else if (inst == "pideConsulta") {
                cin >> pac >> med >> d >> h >> c >> m;
                con.pideConsulta(pac, med, fecha(d, h, m));
            }
            else if (inst == "siguientePaciente") {
                cin >> med;
                pac = con.siguientePaciente(med);
                cout << "Siguiente paciente doctor " << med << '\n';
                cout << pac << '\n';
            }
            else if (inst == "atiendeConsulta") {
                cin >> med;
                con.atiendeConsulta(med);
            }
            else if (inst == "listaPacientes") {
                cin >> med >> d;
                auto vec = con.listaPacientes(med, fecha(d, 0, 0));
                cout << "Doctor " << med << " dia " << d << '\n';
                for (auto p : vec) {
                    cout << p.second << ' ' << p.first << '\n';
                }
            }
            else
                assert(false);
        }
        catch (invalid_argument e) { cout << e.what() << '\n'; }
    }
    cout << "---\n";

    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 
    while (resuelve());
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
