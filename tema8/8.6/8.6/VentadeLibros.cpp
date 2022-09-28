#include "VentadeLibros.h"

void VentadeLibros::nuevoLibro(int n, string x)
{
	if (!libr.count(x)) {
		libr[x].num = n;
		libr[x].vendido = false;
		libr[x].numvend =0;
	}
	else {
		libr[x].num = libr[x].num+n;
	}

	
}

void VentadeLibros::comprar(string x)
{
	if (libr.count(x)) {
		if (libr[x].num >= 1) {
			if (!libr[x].vendido) {
				libr[x].vendido = true;
				bib[1].push_front(x);
				libr[x].il = bib[1].begin();
				libr[x].num--;
				libr[x].numvend = 1;
			}
			else {
				
				list<string>::iterator il = libr[x].il;
				il = bib[libr[x].numvend].erase(il);
				libr[x].num--;
				libr[x].numvend++;
				bib[libr[x].numvend].push_front(x);
				libr[x].il = bib[libr[x].numvend].begin();
			}
			
		}
	
		else throw out_of_range("No hay ejemplares");
	}
	else{
		throw invalid_argument("Libro no existente");
	}
}

bool VentadeLibros::estaLibro(string x)
{
	return libr.count(x);
}

void VentadeLibros::elimLibro(string x)
{
	if (libr.count(x)) {
		if (libr[x].numvend > 0) {
			list<string>::iterator il = libr[x].il;
			il = bib[libr[x].numvend].erase(il);
		}		
		libr.erase(x);
	}

}

int VentadeLibros::numEjemplares(string x)
{
	if (libr.count(x)) {

			return libr[x].num;

	}
	else {
		throw invalid_argument("Libro no existente");
	}
}

list<string> VentadeLibros::top10()
{
	list<string>m;
	int i = 0;
	map<int, list<string>>::reverse_iterator it = bib.rbegin();
	bool hey = true;
	while ( it != bib.rend() &&hey) {
		list<string>::iterator il = it->second.begin();
		while( il != it->second.end() && hey) {
			if (i < 10) {
				string s = "    " + *il;
				m.push_back(s);
				
			}
			else {
				hey = false;
			}
			il++;
			i++;
		}
		++it;
	}
	return m;
}
