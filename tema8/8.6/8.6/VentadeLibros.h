#pragma once

#include <string>
#include <map>
#include <list>
#include <stdexcept>
using namespace std;
struct dd {
	
	int num;
	list<string>::iterator il;
	bool vendido;
	int numvend;
};
using Vent= map<string, dd>;
using Lib = map<int, list<string>>;

class VentadeLibros
{
	Vent libr;
	Lib bib;
public:
	VentadeLibros(){}
	void nuevoLibro(int n, string x);
	void comprar(string x);
	bool estaLibro(string x);
	void elimLibro(string x);
	int numEjemplares(string x);
	list<string>top10();
};

