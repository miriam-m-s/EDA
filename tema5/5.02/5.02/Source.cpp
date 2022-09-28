// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<string>
#include<stack>
using namespace std;
struct date {
    int day;
    int month;
    int year;
    int accidentes;
    date(int day, int m, int y,int acciden) :day(day), month(m), year(y),accidentes(acciden) {

    }
    date() {};
    friend istream& operator>>(istream& out, date& d) {
        int h, m, s,accd;
        char separar = '/';
       
        out >> h >> separar >> m >> separar >> s>>accd;
        d = date(h, m, s,accd);
        return out;
    }
    friend ostream& operator<<(ostream& out, const date& d) {
        string h = to_string(d.day);
        string m = to_string(d.month);
        string s = to_string(d.year);
        if (d.day < 10)h = "0" + to_string(d.day);
        if (d.month < 10)m = "0" + to_string(d.month);
        if (d.year < 1000) {
            if (d.year < 10) {
                s = "000" + to_string(d.month);
            }
            else if (d.year < 100) {
                s = "00" + to_string(d.month);
            }
            else  s = "0" + to_string(d.month);
        }
        out << h << "/" << m << "/" << s;
        return out;
    }
};
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int num;
    cin >> num;
    if (!std::cin)
        return false;
    stack<date>plain;
    for (int i = 0; i < num; i++) {    
        date ds;
        cin >> ds;   
            int j = 0;
            int size = plain.size();
            while(j<size&&plain.top().accidentes <= ds.accidentes) {
                plain.pop();
                j++;
            }
            if (j< size) {
                cout << plain.top() << endl;   
            }
            else {
                cout << "NO HAY" << endl;
            }
        
        plain.push(ds);
    }
    cout << "---" << endl;
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
