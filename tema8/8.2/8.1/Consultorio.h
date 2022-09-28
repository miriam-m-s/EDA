#pragma once
#include<vector>
#include <iostream>
using namespace std;
#include <string>  
using medico = string;
using paciente = string;
#include <map>;
#include "fecha.h";
#include<vector>
#include<unordered_map>
using pac = map<fecha, paciente>;
using tabla = unordered_map<medico, pac>;
class Consultorio
{
private:
	;
	tabla consult;
	
public:
	Consultorio();
	void nuevoMedico(medico med);
	void pideConsulta(paciente p, medico m, fecha f);
	paciente siguientePaciente(medico m);
	void atiendeconsulta(medico m);
	map<fecha,paciente> listaPacientes(medico m,fecha d);
};

