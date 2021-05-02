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

int Partido::getVotos_legenda() const {
    return this->votos_legenda;
}

int Partido::getNumero_partido() const {
    return this->numero_partido;
}

string Partido::getSigla_partido() {
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

string Partido::toString() {
    return this->sigla_partido + " - " + to_string(this->numero_partido);
}

string Partido::simplesString() {
    string s = sigla_partido + " - " + to_string(numero_partido) + ", " + to_string(votosTotais());
    if(votosTotais() == 0)
        s += " voto (" + to_string(votos_nominais);
    else
        s += " votos (" + to_string(votos_nominais);

    if(votos_nominais == 0)
        s += " nominal e " + to_string(votos_legenda) + " de legenda), " + to_string(qtdCandidatosEleitos);
    else
        s += " nominais e " + to_string(votos_legenda) + " de legenda), " + to_string(qtdCandidatosEleitos);

    if(qtdCandidatosEleitos < 2)
        s += " candidato eleito";
    else
        s += " candidatos eleitos";

    return s;
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

    if (votos_outro > votos_esse) return true;
    else if (votos_outro < votos_esse) return false;
    else if (esse.getNumero_partido() > outro.getNumero_partido()) return true;
    else if (esse.getNumero_partido() < outro.getNumero_partido()) return false;
    return false;
}
