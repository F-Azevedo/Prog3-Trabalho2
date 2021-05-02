//
// Created by fernando on 02/05/2021.
//

#ifndef INC_4_PERIODO_PROGRAMACAO3_TRABALHO2_ESTATISTICAS_H
#define INC_4_PERIODO_PROGRAMACAO3_TRABALHO2_ESTATISTICAS_H

#include <iostream>

#include "../Eleicoes/Eleicao.h"

using namespace std;

class Estatisticas
{
public:
    void imprimeNumVagas(const Eleicao& e);
    void imprimeEleitos(Eleicao& e);
    void imprimeMaisVotados(Eleicao& e);
    void imprimePrejudicados(Eleicao& e);
    void imprimeBeneficiados(Eleicao& e);
    void imprimePartidosMaisVotados(Eleicao& e);
    void imprimeMelhorPiorCandidatoPorPartido(Eleicao& e);
    void imprimeIdade(Eleicao& e);
    void imprimeSexo(Eleicao& e);
    void imprimeTotalVotos(Eleicao& e);
};

#endif //INC_4_PERIODO_PROGRAMACAO3_TRABALHO2_ESTATISTICAS_H
