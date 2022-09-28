#include "Consultorio.h"


Consultorio::Consultorio(){
}

void Consultorio::nuevoMedico(medico med)
{
	if (!consult.count(med))
		consult[med];
}

void Consultorio::pideConsulta(paciente p, medico m, fecha f)
{
	if (!consult.count(m))throw invalid_argument("Medico no existente");
	else {
		if (consult[m].count(f))throw invalid_argument("Fecha ocupada");
		else consult[m][f] = p;
	}
}

paciente Consultorio::siguientePaciente(medico m){
	if (!consult.count(m))throw invalid_argument("Medico no existente");
	else
		if (consult[m].size() == 0)
			throw invalid_argument("No hay pacientes");
		else {
			map<fecha, paciente>::iterator it = consult[m].begin();
			return it->second;
		}
}

void Consultorio::atiendeconsulta(medico m)
{
	if (!consult.count(m))throw invalid_argument("Medico no existente");
	else {
		if (consult[m].size() == 0) {
			throw invalid_argument("No hay pacientes");
		}
		else {
			fecha menor;

			map<fecha, paciente>::iterator il= consult[m].begin();

			il = consult[m].erase(il);
			

		}
	}
}

map<fecha, paciente> Consultorio::listaPacientes(medico m, fecha d)
{
	map<fecha, paciente> mi;
	if(!consult.count(m))throw invalid_argument("Medico no existente");
	else {

		for (map<fecha, paciente>::iterator il = consult[m].begin(); il != consult[m].end(); ++il) {
			fecha f = il->first;
			if (f.dia() == d.dia()) {
				mi.insert({ f,il->second });
			}
		}
	}
	return mi;
}
