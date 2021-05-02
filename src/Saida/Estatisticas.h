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
    void imprimeEleitos(const Eleicao& e);
    void imprimeMaisVotados(const Eleicao& e);
    void imprimePrejudicados(const Eleicao& e);
    void imprimeBeneficiados(const Eleicao& e);
    void imprimePartidosMaisVotados(const Eleicao& e);
    void imprimeMelhorPiorCandidatoPorPartido(const Eleicao& e);
    void imprimeIdade(const Eleicao& e);
    void imprimeSexo(const Eleicao& e);
    void imprimeTotalVotos(const Eleicao& e);
};

#endif //INC_4_PERIODO_PROGRAMACAO3_TRABALHO2_ESTATISTICAS_H
