// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
bool dospiezasverdes(const vector<int>& sol,int k) {
    if (k > 2) 
        if (sol[k] == 2 && sol[k - 1] == 2)return false;
    return true;
}
bool masazulesqueverdes(vector<int>& piezasquellevo) {
    if (piezasquellevo[0] == 0 && piezasquellevo[2] == 0)return true;
    if(piezasquellevo[0] < piezasquellevo[2])return false;
        return true;

}
// función que resuelve el problema , int a, int r, int v
void resolver(vector<int>& sol, int alturatorre, int k,int&azules,int&rojas,int &verdes,bool &hey,vector<int>&piezasquellevo,bool&solu) {
    if (k == 0) {

        if (rojas > 0) {
            sol[k] = 1;
            rojas--;
            k++;
            piezasquellevo[1]++;
        }
        else hey = false;
    }
    if(hey)
    for (int i = 0; i < 3; i++) {
        sol[k] = i;
        piezasquellevo[i]++;
        if (i == 0)azules--;
        else if (i == 1)rojas--;
        else verdes--;
        if (azules>=0&&verdes>=0&&rojas>=0&&dospiezasverdes(sol, k)&& masazulesqueverdes( piezasquellevo)) {
            if (k == alturatorre - 1) {
              if (piezasquellevo[1] > piezasquellevo[0] + piezasquellevo[2]) {
                solu = true;
                for (int i = 0; i < alturatorre; i++) {

                    if (sol[i] == 1)cout << "rojo ";
                    else if (sol[i] == 0)cout << "azul ";
                    else cout << "verde ";
                }
                cout << endl;
             }
                
            }
            else {
                resolver(sol, alturatorre, k+1, azules, rojas, verdes, hey,piezasquellevo,solu);
            }
        }
        if (i == 0)azules++;
        else if (i == 1)rojas++;
        else verdes++;
        piezasquellevo[i]--;
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int n = 0, a, v, r;
    cin >> n >> a >> r >> v;
    if (n == 0)
        return false;
    else {
      
        vector<int>sol(n);
        bool hey = true;
        bool solu = false;
        vector<int>piezasquellevo(3);
     
        resolver(sol, n, 0, a, r, v, hey, piezasquellevo, solu);
        if (solu== false)cout << "SIN SOLUCION" << endl;
        cout << endl;
    }

    return true;


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