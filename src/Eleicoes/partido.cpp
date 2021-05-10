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

vector<Candidato>* Partido::getCandidatos() {
    return this->candidatos;
}

void Partido::add_Votos_nominais(int incremento) {
    this->votos_nominais += incremento;
}

void Partido::add_CandidatoPartido(const Candidato& candidato) {

    this->add_Votos_nominais(candidato.getVotos());

    this->candidatos->push_back(candidato);

    if(candidato.foiEleito())   this->qtdCandidatosEleitos++;
}

bool Partido::operator<(const Partido & outro) const {
    return outro.votosTotais() < this->votosTotais();
}

bool compare::operator()(Partido &esse, Partido &outro) {
    //Trata casos de cantornos caso esse ou outro não tenha candidatos.
    bool vazioEsse = esse.getCandidatos()->empty(),
            vazioOutro = outro.getCandidatos()->empty();
    if (vazioEsse && vazioOutro) return false;
    else if (vazioEsse) return false;
    else if (vazioOutro) return true;

    //Após tratamentos dos casos de contornos faz a comparação real.
    int votos_outro = outro.getCandidatos()->front().getVotos(),
            votos_esse = esse.getCandidatos()->front().getVotos();

    if (votos_outro < votos_esse) return true;
    else if (votos_outro > votos_esse) return false;
    else if (esse.getNumero_partido() < outro.getNumero_partido()) return true;
    else if (esse.getNumero_partido() > outro.getNumero_partido()) return false;
    return false;
}
