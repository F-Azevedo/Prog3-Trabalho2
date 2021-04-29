//
// Created by fernando on 29/04/2021.
//

#ifndef INC_4_PERIODO_PROGRAMACAO3_TRABALHO2_LEITOR_H
#define INC_4_PERIODO_PROGRAMACAO3_TRABALHO2_LEITOR_H

#include "../Eleicoes/Eleicao.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Leitor
{
public:
    string leData(const string& dataStr);
    Candidato* leCandidato(const string& linha, string& dia_eleicao);
    void leTodosCandidatos(string& nome_arq_entrada, string& dia_eleicao, Eleicao& eleicao);
    Partido* lePartido(const string& linha);
    void leTodosPartidos(const string& nome_arq_entrada, Eleicao& eleicao);
};

#endif //INC_4_PERIODO_PROGRAMACAO3_TRABALHO2_LEITOR_H
