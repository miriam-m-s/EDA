#pragma once
#include<vector>
#include "monomio.h"

#include <iostream>
using namespace std;
#include <string>  

class polinomio
{
private:
	int tama;
	vector<monomio>polim;
	int binSearchAux(int elem,int a,int b);
	void  buscaelem(monomio elem, bool &found, int &pos);

public:
	polinomio() {};
	polinomio(int tam);
	void add(monomio m);
	
};