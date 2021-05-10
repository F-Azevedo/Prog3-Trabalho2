//
// Created by fernando on 29/04/2021.
//

#include "candidato.h"
#include <algorithm>

//Construtor de Candidato.
Candidato::Candidato(int numero,
                     int votos,
                     int num_partido,
                     string& status,
                     string& nome,
                     string& nome_urna,
                     string& nascimento,
                     vector<int>& data_eleicao,
                     char sexo){
    this->nome = nome;
    this->nome_urna = nome_urna;
    this->numero = numero;
    this->num_partido = num_partido;
    this->status = status;
    this->sexo = sexo;
    this->votos = votos;
    this->nasc = nascimento;

    //Data do candidato.
    stringstream aux(nascimento);
    string info;

    getline(aux, info, '/');
    int dia_nas = stoi(info);
    getline(aux, info, '/');
    int mes_nas = stoi(info);
    getline(aux, info, '/');
    int ano_nas = stoi(info);

    this->idade = data_eleicao[2] - ano_nas;
    if(data_eleicao[1] < mes_nas)
        this->idade--;
    else if(data_eleicao[1] == mes_nas){
        if(data_eleicao[0] < dia_nas)
            this->idade--;
    }
}

bool Candidato::foiEleito() const {
    return this->status == "Eleito";
}

//Getters de Candidato.

char Candidato::getSexo() const {
    return this->sexo;
}

int Candidato::getVotos() const {
    return this->votos;
}

int Candidato::getIdade() const {
    return this->idade;
}

int Candidato::getNumero() const {
    return this->numero;
}

int Candidato::getNumPartido() const {
    return this->num_partido;
}

string Candidato::getNome() const {
    return this->nome;
}

string Candidato::getNomeUrna() const {
    return this->nome_urna;
}

bool Candidato::operator<(const Candidato &outro) const {
    if(outro.votos == this->votos){
        if(outro.getIdade() > this->getIdade())
            return true;
        else if(outro.getIdade() < this->getIdade())
            return false;
        return false;
    }
    return outro.votos < this->votos;
}

bool Candidato::operator==(const Candidato &outro) const {
    if( this->getNome() == outro.getNome() &&
        this->getNomeUrna() == outro.getNomeUrna() &&
        this->getNumero() == outro.getNumero())
        return true;
    else
        return false;
}
