
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include<map>
#include<list>
using namespace std;
struct us {
    int points = 0;
    list<string>::iterator it;
};

using Usuario = map<string, us>;
using Points = map<int, list<string>>;

class carnet_puntos {
    Usuario user;
    Points puntos;
public:
    carnet_puntos(){}
    ~carnet_puntos() {

    }
   void nuevo(string dni) {
       if (!user.count(dni)) {
           user[dni].points = 15;
          puntos[15].push_front(dni);

          list<string>::iterator s = puntos[15].begin();
          user[dni].it = s;
       }
       else {
           throw domain_error("Conductor duplicado");
       }
    }
   void quitar(string dni,int punts) {
       if (user.count(dni)) {
           if (user[dni].points != 0) {
               auto it = user[dni].it;
               it = puntos[user[dni].points].erase(it);

               if (user[dni].points - punts < 0)user[dni].points = 0;
               else user[dni].points -= punts;
               puntos[user[dni].points].push_front(dni);

               list<string>::iterator s = puntos[user[dni].points].begin();

               user[dni].it = s;
           }
          
       }
       else {
           throw domain_error("Conductor inexistente");
       }
   }
   void recuperar(string dni, int punts)
   {
       if (user.count(dni)) {
           if (user[dni].points != 15) {
               auto il = user[dni].it;
               il = puntos[user[dni].points].erase(il);
               if (user[dni].points + punts >= 15)user[dni].points = 15;
               else user[dni].points += punts;

               puntos[user[dni].points].push_front(dni);
               list<string>::iterator s = puntos[user[dni].points].begin();
               user[dni].it = s;
           }
          
       }
       else {
           throw domain_error("Conductor inexistente");
       }
   }
   int consultar(string dni) {
       if(user.count(dni))
       return user[dni].points;
       else throw domain_error("Conductor inexistente");
   }
   int cuantos_con_puntos(int punts) {
       if (punts >= 0 && punts <= 15) {
           if (puntos.count(punts)) {
               return puntos[punts].size();
           }
           else return 0;
       }
       else  throw domain_error("Puntos no validos");
   }
   list<string>lista_por_puntos(int punts) {
      
       if (punts >= 0 && punts <= 15) {
           if (puntos.count(punts))
               return puntos[punts];
           else return {};
       }
       else  throw domain_error("Puntos no validos");
   }
};

bool resuelveCaso() {
    std::string orden, dni;
    int punt;
    std::cin >> orden;
    if (!std::cin)
        return false;

    carnet_puntos dgt;

    while (orden != "FIN") {
        try {
            if (orden == "nuevo") {
                cin >> dni;
                dgt.nuevo(dni);
            }
            else if (orden == "quitar") {
                cin >> dni >> punt;
                dgt.quitar(dni, punt);
            }
            else if (orden == "recuperar") {
                cin >> dni >> punt;
                dgt.recuperar(dni, punt);
            }
            else if (orden == "consultar") {
                cin >> dni;
                punt = dgt.consultar(dni);
                cout << "Puntos de " << dni << ": " << punt << '\n';
            }
            else if (orden == "cuantos_con_puntos") {
                cin >> punt;
                int cuantos = dgt.cuantos_con_puntos(punt);
                cout << "Con " << punt << " puntos hay " << cuantos << '\n';
            }
            else if (orden == "lista_por_puntos") {
                cin >> punt;
                auto const& lista = dgt.lista_por_puntos(punt);
                cout << "Tienen " << punt << " puntos:";
                for (auto const& dni : lista)
                    cout << ' ' << dni;
                cout << '\n';
            }
            else
                cout << "OPERACION DESCONOCIDA\n";
        }
        catch (std::domain_error e) {
            std::cout << "ERROR: " << e.what() << '\n';
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
