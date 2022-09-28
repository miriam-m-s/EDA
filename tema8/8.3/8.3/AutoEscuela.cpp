#include "AutoEscuela.h"

void AutoEscuela::alta(alumno A, profe P)
{
	if (consult.count(A)) {
		
		map<profe,int>::iterator il = consult[A].begin();
		int punt = il->second;
		
		consult.erase(A);
		consult[A][P] = punt;
	}
	else {
		consult[A][P] = 0;
	}

	/*bool hey = false;
	int punt;
	map<profe, map<alumno, int>>::iterator il = consult.begin();
	while( il != consult.end()&&!hey) {
		if (il->first != P) {
			map<alumno, int>::iterator is = il->second.begin();
			while (is != il->second.end() && !hey) {
				if (is->first == A) {
					punt = is->second;
					hey = true;
					is = consult[il->first].erase(is);
				}
				else
					++is;
			}
		}
		
		++il;
	}
	if (hey) {
		consult[P][A] = punt; 
	}
	else
	{
		consult[P][A] = 0;
	}*/
}

bool AutoEscuela::es_alumno(alumno A, profe P)
{
	if (consult[A].count(P))return true;
	return false;
}

int AutoEscuela::puntuacion(alumno A)
{
	/*bool hey = false;
	int punt;
	map<profe, map<alumno, int>>::iterator il = consult.begin();
	while (il != consult.end() && !hey) {
		map<alumno, int>::iterator is = il->second.begin();
		while (is != il->second.end() && !hey) {
			if (is->first == A) {
				punt = is->second;
				hey = true;
			}
			++is;
		}
		++il;
	}
	if (hey)
		return punt;*/

	if (consult.count(A)) {

		map<profe, int>::iterator il = consult[A].begin();
		return il->second;

		
	}
	
	else throw domain_error("El alumno A no esta matriculado");
}

void AutoEscuela::actualizar(alumno A, int N)
{
	/*int punt;
	bool hey = false;
	string prof;
	map<profe, map<alumno, int>>::iterator il = consult.begin();
	while (il != consult.end() && !hey) {
		map<alumno, int>::iterator is = il->second.begin();
		while (is != il->second.end() && !hey) {
			if (is->first == A) {
				punt = is->second;
				prof = il->first;
				hey = true;
			}
			++is;
		}
		++il;
	}
	if (hey) {
		consult[prof][A] = punt+N;
	}*/
	if (consult.count(A)) {

		map<profe, int>::iterator il = consult[A].begin();
		string prof = il->first;
		int punt= il->second;
		consult[A][prof] = punt + N;

	}
	else
	{
		throw domain_error("El alumno A no esta matriculado");
	}
}

list<string> AutoEscuela::examen(profe P, int N)
{
	list<string>s;
	for (map<alumno, map<profe, int>>::iterator il = consult.begin(); il != consult.end(); ++il) {
		for (map<profe, int>::iterator is = il->second.begin(); is != il->second.end(); ++is) {
			if (is->first==P&&is->second >= N) {
				s.push_back(il->first);
			}
		}
	}
	return s;
}

void AutoEscuela::aprobar(alumno A)
{
	if (consult.count(A)) {

		consult.erase(A);
		

	}
	else
	{
		throw domain_error("El alumno A no esta matriculado");
	}

	/*int punt;
	bool hey = false;
	string prof;
	map<profe, map<alumno, int>>::iterator il = consult.begin();
	while (il != consult.end() && !hey) {
		map<alumno, int>::iterator is = il->second.begin();
		while (is != il->second.end() && !hey) {
			if (is->first == A) {
				is= consult[il->first].erase(is);
				hey = true;
			}
			else
			++is;
		}
		++il;
	}*/
}
