//
// Created by fernando on 29/04/2021.
//

#include "Eleicao.h"

Eleicao::Eleicao(string& dia) {
    this->data = dia;
}

int Eleicao::qtdEleitos() {
    return (int) this->eleitos->size();
}

int Eleicao::get_total_votos_legenda() const {
    return total_votos_legenda;
}

int Eleicao::get_total_votos_nominais() const {
    return this->total_votos_nominais;
}

map<int, Partido>* Eleicao::getPartidos() {
    return this->partidos;
}

vector<Candidato>* Eleicao::getEleitos() {
    return this->eleitos;
}

vector<Candidato>* Eleicao::getCandidatos() {
    return candidatos;
}

void Eleicao::add_total_votos_legenda(int incremento) {
    this->total_votos_legenda += incremento;
}

void Eleicao::add_total_votos_nominais(int incremento) {
    this->total_votos_nominais += incremento;
}

void Eleicao::adicionaEleito(const Candidato& candidato) {
    this->eleitos->push_back(candidato);

}

void Eleicao::addCandidatoEleicao(const Candidato& candidato) {
    this->candidatos->push_back(candidato);

    //Se o candidato foi eleito, adiciona o candidato ao set de eleitos.
    if (candidato.foiEleito()) adicionaEleito(candidato);

    //Adiciona os votos que o candidato recebeu ao total de votos nominais da eleição.
    this->add_total_votos_nominais(candidato.getVotos());

    //Determina a qual partido o candidato pertence.
    Partido aux = this->partidos->find(candidato.getNumPartido())->second;

    //Adiciona o candidato ao seu respectivo partido.
    aux.add_CandidatoPartido(candidato);
}

void Eleicao::addPartidoEleicao(int num_partido, const Partido& partido) {
    this->partidos->insert(make_pair(num_partido, partido));

    //Adicoina os votos de legenda recebidos pelo partido ao total de votos de legenda da eleição.
    this->add_total_votos_legenda(partido.getVotos_legenda());
}
