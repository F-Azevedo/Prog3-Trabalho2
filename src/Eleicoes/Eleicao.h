//
// Created by fernando on 29/04/2021.
//

#ifndef INC_4_PERIODO_PROGRAMACAO3_TRABALHO2_ELEICAO_H
#define INC_4_PERIODO_PROGRAMACAO3_TRABALHO2_ELEICAO_H

#include <iostream>
#include <vector>
#include <map>

#include "candidato.h"
#include "partido.h"

using namespace std;

class Eleicao
{
    int total_votos_nominais = 0;
    int total_votos_legenda = 0;
    string data;
    map<int, Partido>* partidos   = new map<int, Partido>();
    vector<Candidato>* eleitos    = new vector<Candidato>();
    vector<Candidato>* candidatos = new vector<Candidato>();
public:
    Eleicao(string& dia);

    int qtdEleitos();
    int get_total_votos_legenda() const;
    int get_total_votos_nominais() const;
    map<int, Partido>* getPartidos();
    vector<Candidato>* getEleitos();
    vector<Candidato>* getCandidatos();
    void add_total_votos_legenda(int incremento);
    void add_total_votos_nominais(int incremento);
    void adicionaEleito(const Candidato& candidato);
    void addCandidatoEleicao(const Candidato& candidato);
    void addPartidoEleicao(int num_partido, const Partido& partido);

};
#endif //INC_4_PERIODO_PROGRAMACAO3_TRABALHO2_ELEICAO_H