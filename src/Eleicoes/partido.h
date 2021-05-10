//
// Created by fernando on 29/04/2021.
//

#ifndef INC_4_PERIODO_PROGRAMACAO3_TRABALHO2_PARTIDO_H
#define INC_4_PERIODO_PROGRAMACAO3_TRABALHO2_PARTIDO_H

#include <iostream>
#include <vector>
#include "candidato.h"

using namespace std;

class Partido
{
    int votos_legenda;
    int numero_partido;
    int votos_nominais = 0;
    int qtdCandidatosEleitos = 0;
    string nome_partido;
    string sigla_partido;
    vector<Candidato>* candidatos = new vector<Candidato>();
public:
    Partido(int numero_partido,
            int votos_legenda,
            string& nome_partido,
            string& sigla_partido);

    int votosTotais() const;
    int getQtdEleitos() const;
    int getVotos_legenda() const;
    int getVotos_nominais() const;
    int getNumero_partido() const;
    string getSigla_partido() const;
    vector<Candidato>* getCandidatos();
    void add_Votos_nominais(int incremento);
    void add_CandidatoPartido(const Candidato& candidato);

    bool operator<(const Partido&) const;
};

struct compare{
    bool operator()(Partido& esse, Partido& outro);
};
#endif //INC_4_PERIODO_PROGRAMACAO3_TRABALHO2_PARTIDO_H
