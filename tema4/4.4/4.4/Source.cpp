// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include<string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
class Horas {
public :
    int s, m, h;
    Horas(){}
    ~Horas(){}
    Horas(int hour,int min,int se):h(hour),m(min),s(se){}
    friend ostream& operator << (ostream& out,const Horas &ot) {
        string ho = to_string(ot.h);
        string mi = to_string(ot.m);
        string se = to_string(ot.s);
        if (ot.h < 10)ho = "0" + to_string(ot.h);
        if (ot.m < 10)mi = "0" + to_string(ot.m);
        if (ot.s < 10)se = "0" + to_string(ot.s);
        out << ho << ":" << mi << ":" << se;
        return out;
    }
    friend istream& operator >>(istream& out, Horas& hor) {
        char separado = ':';
        int h, m, s;
        out >> h >> separado >> m >> separado >> s;
        hor = Horas(h, m, s);
        return out;
    }
    bool operator <(const Horas &other)const {
        if (h < other.h) return true;
        else {
            if (h == other.h) {
                if (m< other.m)return true;
                else {
                    if (m == other.m) {
                        if (s < other.s)return true;
                        else return false;
                    }
                    else return false;
                }
            }
            else return false;
        }
    }
    bool operator ==(const Horas& other)const {
       
        if (h == other.h && m == other.m && s == other.s)return true;
        return false;
                
       
    }
    Horas operator +(const Horas &other) {
        Horas nuevo;
       int sec = s + other.s;
       nuevo.m = 0;
       nuevo.h = 0;
       if (sec >= 60) {
           nuevo.s = sec - 60;
           nuevo.m = 1;
       }
       else nuevo.s = sec;
       int min = nuevo.m + m + other.m;
       if (min >= 60) {
           nuevo.m = min - 60;
           nuevo.h = 1;
       }
       else nuevo.m = min;
        int horas =nuevo.h+ h + other.h;
        if (horas >= 24) {
           throw exception();
        }
        else nuevo.h = horas;
      
        
        return nuevo;
    }
};
class Pelicula {
    
public:
    Horas h;
    string peli;
    Pelicula(){}
    ~Pelicula(){}
    Pelicula(Horas h, string peli):h(h),peli(peli){}
    bool operator <(const Pelicula& other)const {
        if (h < other.h)return true;
        else if (h == other.h) {
            return peli < other.peli;
        }
        return false;
    }
};
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool orden(Pelicula& a, Pelicula& b) {
    if (a < b)return true;
    return false;
}
bool resuelveCaso() {
    // leer los datos de la entrada
    int tam;
    cin >> tam;
    if (tam==0)
        return false;
    Horas p, h;
        string n;
    vector<Pelicula>pel(tam);
    for (int i = 0; i < tam; i++) {
        cin >> p >> h;
        getline(cin,n);
        Pelicula ss=Pelicula(p+h,n);
        pel[i] = ss;
    }
   
    sort(pel.begin(), pel.end(), orden);
    for (auto u : pel) {
        cout << u.h << " "<<u.peli<<endl;
    }
    // escribir sol
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
