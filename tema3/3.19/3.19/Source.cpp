// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>

using namespace std;

// función que resuelve el problema
void resolver(int numcasos,int k, vector<int>&duracion, vector<int>&gusta,int & maxpuntuacion,int & puntuacion,vector<int>&caset,int tiempo,vector<int>&optim) {

    
            int duration = duracion[k]; ;
          
            if (caset[0] + duration <= tiempo) {
               
                puntuacion += gusta[k];
                caset[0] += duration;
                if (k == numcasos - 1) {
                    if (puntuacion > maxpuntuacion) {
                        maxpuntuacion = puntuacion;
                    }
                }
                else {
                    if(puntuacion+optim[k+1]>=maxpuntuacion)
                    resolver(numcasos, k + 1, duracion, gusta, maxpuntuacion, puntuacion, caset, tiempo, optim);
                    
                }
                caset[0] -= duration;
                puntuacion -= gusta[k];
              
            }
            if (caset[1] + duration <= tiempo) {
              
                puntuacion += gusta[k];
                caset[1] += duration;
                if (k == numcasos - 1) {
                    if (puntuacion > maxpuntuacion) {
                        maxpuntuacion = puntuacion;
                    }
                }
                else {
                    if (puntuacion + optim[k + 1] >= maxpuntuacion)
                    resolver(numcasos, k + 1, duracion, gusta, maxpuntuacion, puntuacion, caset, tiempo, optim);
               
                }
                caset[1] -= duration;
                puntuacion -= gusta[k];
                
            }
           
            if (k == numcasos - 1) {
                if (puntuacion > maxpuntuacion) {
                    maxpuntuacion = puntuacion;
                }
            }
            else{
                if (puntuacion + optim[k + 1] >= maxpuntuacion)
                resolver(numcasos, k + 1, duracion, gusta, maxpuntuacion, puntuacion, caset, tiempo, optim);
               
            }
        
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numcasos;
    cin >> numcasos;

    if (numcasos==0)
        return false;
    int tiempo;
    cin >> tiempo;
    vector<int>duracion(numcasos);
    vector<int>gusta(numcasos);
    for (int i = 0; i <numcasos; i++) {
        cin >> duracion[i];
       
        cin >> gusta[i];
    }
    int maxpuntuacion = 0;
    int puntuacion = 0;
    vector<int>rep(numcasos);
    int optimist=0;
    for (int i = 0; i < numcasos;i++) {
        optimist+=gusta[i];
    }
    int resta = 0;
    for (int i = 0; i < numcasos; i++) {
        optimist -= resta;
        rep[i] = optimist;
        resta = gusta[i];
        
    }
    int cara = 0;
    vector<int>caset(2);
    resolver(numcasos, 0, duracion, gusta, maxpuntuacion, puntuacion, caset, tiempo,rep);
    cout << maxpuntuacion<<endl;
   // resolver(datos);

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
