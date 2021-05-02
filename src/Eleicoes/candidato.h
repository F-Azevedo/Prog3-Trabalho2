//
// Created by fernando on 29/04/2021.
//

#ifndef INC_4_PERIODO_PROGRAMACAO3_TRABALHO2_CANDIDATO_H
#define INC_4_PERIODO_PROGRAMACAO3_TRABALHO2_CANDIDATO_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Candidato
{
    int idade;
    int votos;
    int numero;
    int num_partido;
    char sexo;
    string nome;
    string nasc;
    string status;
    string nome_urna;
public:
    Candidato(int numero,
              int votos,
              int num_partido,
              string& status,
              string& nome,
              string& nome_urna,
              string& nascimento,
              vector<int>& data_eleicao,
              char sexo);

    bool foiEleito() const;

    char getSexo() const;
    int getVotos() const;
    int getIdade() const;
    int getNumPartido() const;

    string simpleString(const string& sigla_partido);
    string toString();

    bool operator==(const Candidato&) const;
    bool operator>(const Candidato&) const;
    bool operator<(const Candidato&) const;
};

#endif //INC_4_PERIODO_PROGRAMACAO3_TRABALHO2_CANDIDATO_H
