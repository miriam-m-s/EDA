#include "carnet_puntos.h"

carnet_puntos::carnet_puntos()
{
	punt.resize(16);
}

void carnet_puntos::nuevo(string dni)
{
	
	if (!car.count(dni)) {
		car[dni].m=15;
		punt[15]++;
		m[15].push_front(dni);
		car[dni].it = m[15].begin();
	}
	else {
		throw domain_error("Conductor duplicado");
	}
}

void carnet_puntos::quitar(string dni, int puntos)
{
	if (car.count(dni)) {
		if (puntos != 0) {
			
			if (car[dni].m > puntos) {
				list<string>::iterator il;
				il = car[dni].it;
				il = m[car[dni].m].erase(il);
				punt[car[dni].m]--;
				car[dni].m -= puntos;
				punt[car[dni].m]++;
				m[car[dni].m].push_front(dni);
				car[dni].it = m[car[dni].m].begin();
			}
			else if (car[dni].m != 0) {
				list<string>::iterator il;
				il = car[dni].it;
				il = m[car[dni].m].erase(il);
				punt[car[dni].m]--;
				car[dni].m = 0;
				punt[0]++;
				m[0].push_front(dni);
				car[dni].it = m[0].begin();
			}
		}
		
		
	}
	else {
		throw domain_error("Conductor inexistente");
	}

}

void carnet_puntos::recuperar(string dni, int puntos)
{
	if (car.count(dni)) {
		if (puntos != 0) {
			
			if (car[dni].m + puntos < 15) {
				list<string>::iterator il;
				il = car[dni].it;
				il = m[car[dni].m].erase(il);
				punt[car[dni].m]--;
				car[dni].m += puntos;
				punt[car[dni].m]++;
				m[car[dni].m].push_front(dni);
				car[dni].it = m[car[dni].m].begin();
			}
			else if (car[dni].m!=15) {
				list<string>::iterator il;
				il = car[dni].it;
				il = m[car[dni].m].erase(il);
				punt[car[dni].m]--;
				car[dni].m = 15;
				punt[15]++;
				m[15].push_front(dni);
				car[dni].it = m[15].begin();
			}
			

		}
		
	}
	else {
		throw domain_error("Conductor inexistente");
	}
}

int carnet_puntos::consultar(string dni)
{
	if (car.count(dni)) {	
		return car[dni].m;		
	}
	else {
		throw domain_error("Conductor inexistente");
	}

}

list<string> carnet_puntos::lista_por_puntos(int puntos)
{
	if (puntos >= 0 && puntos <= 15)
	return m[puntos];
	else throw domain_error("Puntos no validos");
}

int carnet_puntos::cuantos_con_puntos(int puntos)
{
	if(puntos>=0&&puntos<=15)
	return punt[puntos];
	else {
		throw domain_error("Puntos no validos");
	}
}
