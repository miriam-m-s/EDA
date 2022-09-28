#include "polinomio.h"


void polinomio::buscaelem(monomio elem, bool& found, int& pos)
{
    int i = 0;
    bool hey = false;
    bool mover = false;
    bool iguales = false;
    while (i < polim.size() && !hey) {
        if (polim[i].getexp() >= elem.getexp()) {
            if (polim[i].getexp() == elem.getexp()) {
                pos = i;
                iguales = true;
            }
            else {
                pos = i;
                mover = true;
            }
            hey = true;
        }
       
        i++;
    }
    if (iguales) {
        polim[i] = polim[i] + elem;
    }
    if (mover) {
        i = i - 1;
        monomio m;
        m = monomio(polim[i].getbase(), polim[i].getexp());
        polim[i] = elem;
        for (int j = i; j < polim.size(); j++) {
           m = monomio(polim[i - 1].getbase(), polim[i - 1].getexp());
        }
    }
   
   
}
int polinomio::binSearchAux(int elem, int ini, int fin) {
    //int n = fin - ini;
    //if (n==1)return fin;
    //else {
    //    int m = (fin + ini) / 2;
    //    if (elem < polim[m].getexp())//busca izq 
    //    {
    //        return  binSearchAux(elem, ini, m);
    //    }
    //    else if (elem==polim[m].getexp()) {
    //        
    //        return m;
    //    }
    //    else {//busca derecha
    //        return  binSearchAux(elem, m, fin);
    //       
    //    }
    //}

}
polinomio::polinomio(int tam) :tama(tam)
{
	polim.resize(tam);
}

void polinomio::add(monomio m)
{
        bool found;
        int pos;
        buscaelem(m.getbase(), found, pos);
        if (!found) {
         
           /* polim[pos + 1] = m;
            ++nelems;
            if (nelems == capacidad)
                amplia();*/
        }
	
}
