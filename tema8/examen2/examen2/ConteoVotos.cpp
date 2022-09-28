#include "ConteoVotos.h"


void ConteoVotos::nuevo_estado(const Estado& nombre, int num_compromisarios)
{
	if (!est.count(nombre)) {
		est[nombre] = num_compromisarios;
	}
	else throw domain_error("Estado ya existente");

}

void ConteoVotos::sumar_votos(const Estado& estado, const Partido& partido, int num_votos)
{
	if (est.count(estado)) {
		int vots = 0;
		if (vot.count(estado)) {
		vots = vot[estado][partido];	
		}
		vot[estado][partido] = vots + num_votos;
		if (gana.count(estado)) {
			map<string, int>::const_iterator it = gana[estado].begin();
			if (it->second < num_votos + vots) {
				it = gana[estado].erase(it);
				gana[estado][partido] = num_votos + vots;
			}
		}
		else gana[estado][partido]=num_votos+vots;
	}
	else throw domain_error("Estado no encontrado");

}

Partido ConteoVotos::ganador_en(const Estado& estado)
{
	if (vot.count(estado)) {

		return  gana[estado].begin()->first;
	}
	else {
		throw domain_error("Estado no encontrado");
	}

}

vector<pair<Partido, int>> ConteoVotos::resultados()
{
	gan ganado;
	vector<pair<Partido, int>>hey;
	for (map<Estado, int>::iterator it = est.begin(); it != est.end(); ++it) {
		string s = ganador_en(it->first);
		int l = 0;
		if (ganado.count(s)) {
			l = ganado[s];
		}
		ganado[s] = it->second + l;
	}
	for (map<Partido, int>::iterator it = ganado.begin(); it != ganado.end(); ++it) {
		hey.push_back({ it->first, it->second });
	}
	return hey;
}
