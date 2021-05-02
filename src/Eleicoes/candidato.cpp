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

bool Candidato::operator<(const Candidato &outro) {
    if(outro.votos == this->votos){
        if(outro.getIdade() > this->getIdade())
            return true;
        else if(outro.getIdade() < this->getIdade())
            return false;
        return false;
    }
    return outro.votos < this->votos;
}

bool Candidato::operator==(const Candidato &outro) {
    if( this->nome == outro.nome &&
        this->nome_urna == outro.nome_urna &&
        this->numero == outro.numero)
        return true;
    else
        return false;
}
