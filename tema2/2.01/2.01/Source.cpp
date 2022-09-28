// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<string>
#include<vector>
#include <math.h>
using namespace std;
// función que resuelve el problema
int complementario(int num0,string &numstr) {

    int num1 = num0;
    int numfinal = 0;
    if (num1 == 0) {
        numfinal = 9;
        numstr = "9";
    }
    else {
        int i = 0;
        string cero = "";
        while (num1 > 0) {
            int num2 = num1 % 10;//2  1
            num1 = num1 / 10;//1 0
            num2 = 9 - num2;//7 8
            numfinal = num2 * (pow(10, i)) + numfinal;//7
            numstr = to_string(int(num2)) + numstr;
            i++;
        }
    }
    
    
    return numfinal;
}
string inverse(string& num,int ini,int fin) {
    int n = fin - ini;
    if (n <=1)return num;
    else {
        char last = num[fin-1];
        num[fin - 1] = num[ini];
        num[ini] = last;
        return inverse(num, ini + 1, fin - 1);
    }
}
void inverso(string nums) {
    
    int n = nums.size();
    cout << stoi(inverse(nums, 0, n))<<endl;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int num0;
    cin >> num0;
    string s = "";
    int i = complementario(num0, s);
    int l = stoi(s);
    cout << l << " ";
    inverso(s);

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
//#ifndef DOMJUDGE
//    std::ifstream in("datos.txt");
//    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
//#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//    std::cin.rdbuf(cinbuf);
//    system("PAUSE");
//#endif

    return 0;
}