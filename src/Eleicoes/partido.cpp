//
// Created by fernando on 29/04/2021.
//

#include "partido.h"

Partido::Partido(int numero_partido,
                 int votos_legenda,
                 string& nome_partido,
                 string& sigla_partido) {
    this->nome_partido = nome_partido;
    this->sigla_partido = sigla_partido;
    this->numero_partido = numero_partido;
    this->votos_legenda = votos_legenda;
}

int Partido::votosTotais() const {
    return this->votos_legenda + this->votos_nominais;
}

int Partido::getQtdEleitos() const {
    return this->qtdCandidatosEleitos;
}

int Partido::getVotos_legenda() const {
    return this->votos_legenda;
}

int Partido::getVotos_nominais() const {
    return this->votos_nominais;
}

int Partido::getNumero_partido() const {
    return this->numero_partido;
}

string Partido::getSigla_partido() const {
    return this->sigla_partido;
}

vector<Candidato*>* Partido::getCandidatos() {
    return this->candidatos;
}

void Partido::add_Votos_nominais(int incremento) {
    this->votos_nominais += incremento;
}

void Partido::add_CandidatoPartido(Candidato* candidato) {

    this->add_Votos_nominais(candidato->getVotos());

    this->candidatos->push_back(candidato);

    if(candidato->foiEleito())   this->qtdCandidatosEleitos++;
}

Partido::~Partido() {
    delete this->candidatos;
}