//
// Created by fernando on 02/05/2021.
//

#ifndef INC_4_PERIODO_PROGRAMACAO3_TRABALHO2_COMPARAMAISVOTADO_H
#define INC_4_PERIODO_PROGRAMACAO3_TRABALHO2_COMPARAMAISVOTADO_H

#include "partido.h"

class comparaMaisVotado
{
public:
    inline bool operator()(Partido* esse, Partido* outro) {
        //Trata casos de cantornos caso esse ou outro não tenha candidatos.
        bool vazioEsse = esse->getCandidatos()->empty(),
                vazioOutro = outro->getCandidatos()->empty();
        if (vazioEsse && vazioOutro) return false;
        else if (vazioEsse) return false;
        else if (vazioOutro) return true;

        //Após tratamentos dos casos de contornos faz a comparação real.
        int votos_outro = outro->getCandidatos()->front()->getVotos(),
                votos_esse = esse->getCandidatos()->front()->getVotos();

        if (votos_outro < votos_esse) return true;
        else if (votos_outro > votos_esse) return false;
        else if (esse->getNumero_partido() < outro->getNumero_partido()) return true;
        else if (esse->getNumero_partido() > outro->getNumero_partido()) return false;
        return false;
    }
};

#endif //INC_4_PERIODO_PROGRAMACAO3_TRABALHO2_COMPARAMAISVOTADO_H
