#pragma once

#include<string>
#include <iostream>
#include <vector>
#include <map>;
#include<list>

using namespace std;
struct diegui {
	int m;
	list<string>::iterator it;
};
using Diccionario = map<string, diegui>;
using Lst = map<int, list<string>>;

class carnet_puntos
{
private:
	Diccionario car;
	vector<int>punt;
	Lst m;
public:
	carnet_puntos();
	~carnet_puntos() {};
	void nuevo(string dni);
	void quitar(string dni, int puntos);
	void recuperar(string dni,int  puntos);
	int consultar(string dni);
	list<string> lista_por_puntos(int puntos);
	int cuantos_con_puntos(int puntos);
};

