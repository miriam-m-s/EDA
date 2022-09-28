// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
bool estabien( int azul, int roj, int verd) {
  
        if (roj >( azul +verd))return true;
        else return false;
    
   

}
bool comprueba(int k, vector<int>& sol,int azul,int roj,int verd,int a, int r ,int v) {
    bool c;
   
    if (sol[k] == 0 && a == -1 || sol[k] == 1 && r == -1|| sol[k] == 2 && v == -1)return true;
 
    if (k > 1 && sol[k] == 2) {
        if (sol[k - 1] == sol[k])c = true;
        else c = false;
    }
    else c=false;
    return c ;

}
bool masazules(int azu, int verd) {
    if (azu >= verd)return true;
    else return false;
}
// función que resuelve el problema , int a, int r, int v
void resolver(vector<int>& sol, int n, int m, int k,int& azu,int& roj,int& verd,int&a,int&r,int&v,bool &h) {

        if (k == 0) {
            sol[k] = 1;
            roj++;
            r--;
            k++;
        }
        for (int x = 0; x < m; x++) {
            sol[k] = x;
            if (x == 0) { 
                azu++; 
                a--;
            }
            else if (x == 1) { roj++; 
            r--;
            }
            else { verd++; 
            v--;
            }
            if (!comprueba(k, sol,  azu,  roj,  verd,a,r,v)&& masazules( azu,  verd)) {
                if (k == n - 1) {
                    if (estabien(azu, roj, verd)) {
                        h = true;
                        for (int i = 0; i < n; i++) {
                            if (sol[i] == 0)
                                cout << "azul";
                            else if (sol[i] == 1) cout << "rojo";
                            else  cout << "verde";
                            cout << " ";
                        }
                        cout << endl;
                    }
                }
                else {

                    resolver(sol, n, m, k + 1,azu,roj,verd,a,r,v,h);
                }
            }
            if (x == 0) {
                azu--;
                a++;
            }
            else if (x == 1) {
                roj--;
                r++;
            }
            else {
                verd--;
                v++;
            }
        }
    

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int n = 0, m = 3,a,v,r;
    cin >> n >> a >> r >> v;
    if (n == 0)
        return false;
    else {
        bool h = false;
        vector<int>sol(n);
        int ve = 0, ro = 0, az = 0;
        resolver(sol, n, m, 0,az,ro,ve, a, r, v,h);
        if(h==false)cout << "SIN SOLUCION"<<endl;
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
    //std::ifstream in("datos.txt");
    //auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
 /*  std::cin.rdbuf(cinbuf);
    system("PAUSE");*/
#endif

    return 0;
}