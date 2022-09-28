#pragma once
#include<vector>
#include <iostream>
using namespace std;
#include <string>  
#include <list>  
using profe = string;
using alumno = string;
using puntuacion = int;
#include <map>;
using tabla = map<alumno,map<profe,int>>;
class AutoEscuela
{
private:
	tabla consult;
public:
	void alta(alumno A, profe P);
	bool es_alumno(alumno A, profe P);
	int puntuacion(alumno A);
	void actualizar(alumno A, int N);
	list<string> examen(profe P, int N);
	void aprobar(alumno A);
};

