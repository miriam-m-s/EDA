#pragma once

#include<map>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;
using Estado = string;
using Partido = string;
using estados = map<Estado, int>;
using votes = map < Estado, map<Partido, int>>;
using gan = map<Partido, int>;

class ConteoVotos
{


private:
    estados est;
    votes vot;
    map<Estado, map<string,int>>gana;

public:

    void nuevo_estado(const Estado& nombre, int num_compromisarios);

    void sumar_votos(const Estado& estado, const Partido& partido, int num_votos);

    Partido ganador_en(const Estado& estado);

    vector<pair<Partido, int>> resultados();


};

