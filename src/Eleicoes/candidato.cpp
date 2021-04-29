//
// Created by fernando on 29/04/2021.
//

#include "candidato.h"

//Construtor de Candidato.
Candidato::Candidato(int numero,
                     int votos,
                     int num_partido,
                     string& status,
                     string& nome,
                     string& nome_urna,
                     string& nascimento,
                     string& dia_da_eleicao,
                     char sexo){
    this->nome = nome;
    this->nome_urna = nome_urna;
    this->numero = numero;
    this->num_partido = num_partido;
    this->status = status;
    this->sexo = sexo;
    this->votos = votos;
    this->nasc = nascimento;
    this->idade = stoi(dia_da_eleicao) - stoi(nascimento);
}

bool Candidato::foiEleito() const {
    return this->status == "Eleito";
}

//Getters de Candidato.

int Candidato::getVotos() const {
    return this->votos;
}

int Candidato::getIdade() const {
    return this->idade;
}

int Candidato::getNumPartido() const {
    return this->num_partido;
}

char Candidato::getSexo() const {
    return this->sexo;
}

//Funções para imprimir o candidato.

string Candidato::simpleString(const string& sigla_partido) {
    string retorno = nome + " / " + nome_urna + " (" + sigla_partido + ", " + to_string(votos);
    if (votos > 1) retorno += " votos)";
    else retorno += " voto)";
    return retorno;
}

string Candidato::toString() {
    string retorno =  nome_urna + " (" + to_string(numero) + ", " + to_string(votos);
    if (votos > 1) retorno += " votos)";
    else retorno += " voto)";
    return retorno;
}

//Funções para comparar candidato.

bool Candidato::operator==(const Candidato &) const {
    return false;
}

bool Candidato::operator>(const Candidato &) const {
    return false;
}

bool Candidato::operator<(const Candidato &) const {
    return false;
}
