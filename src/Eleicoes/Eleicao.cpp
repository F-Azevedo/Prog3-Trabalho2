//
// Created by fernando on 29/04/2021.
//

#include "Eleicao.h"

Eleicao::Eleicao(vector<int>& dia) {
    this->data = dia;
}

int Eleicao::qtdEleitos() const {
    return (int) this->eleitos->size();
}

int Eleicao::get_total_votos_legenda() const {
    return total_votos_legenda;
}

int Eleicao::get_total_votos_nominais() const {
    return this->total_votos_nominais;
}

map<int, Partido*>* Eleicao::getPartidos() const {
    return this->partidos;
}

vector<Candidato*>* Eleicao::getEleitos(){
    return this->eleitos;
}

vector<Candidato*>* Eleicao::getCandidatos(){
    return candidatos;
}

void Eleicao::add_total_votos_legenda(int incremento) {
    this->total_votos_legenda += incremento;
}

void Eleicao::add_total_votos_nominais(int incremento) {
    this->total_votos_nominais += incremento;
}

void Eleicao::adicionaEleito(Candidato* candidato) {
    this->eleitos->push_back(candidato);

}

void Eleicao::addCandidatoEleicao(Candidato* candidato) {
    this->candidatos->push_back(candidato);

    //Se o candidato foi eleito, adiciona o candidato ao set de eleitos.
    if (candidato->foiEleito()) adicionaEleito(candidato);

    //Adiciona os votos que o candidato recebeu ao total de votos nominais da eleição.
    this->add_total_votos_nominais(candidato->getVotos());

    //Determina a qual partido o candidato pertence.
    Partido* aux = this->partidos->at(candidato->getNumPartido());

    //Adiciona o candidato ao seu respectivo partido.
    aux->add_CandidatoPartido(candidato);
}

void Eleicao::addPartidoEleicao(int num_partido, Partido* partido) {
    this->partidos->insert(make_pair(num_partido, partido));

    //Adicoina os votos de legenda recebidos pelo partido ao total de votos de legenda da eleição.
    this->add_total_votos_legenda(partido->getVotos_legenda());
}

Eleicao::~Eleicao() {
    delete this->eleitos;

    Candidato* c;

    for(auto & it : *this->getCandidatos()){
        c = it;
        delete c;
    }
    delete this->candidatos;

    Partido* p;

    for(auto & it : *this->getPartidos()){
        p = it.second;
        delete p;
    }
    delete this->partidos;

}