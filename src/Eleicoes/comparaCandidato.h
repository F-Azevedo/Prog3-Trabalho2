//
// Created by fernando on 10/05/2021.
//

#ifndef INC_4_PERIODO_PROGRAMACAO3_TRABALHO2_COMPARACANDIDATO_H
#define INC_4_PERIODO_PROGRAMACAO3_TRABALHO2_COMPARACANDIDATO_H

#include "candidato.h"

class comparaCandidato
{
public:
    inline bool operator()(Candidato* esse, Candidato* outro) {
        if(outro->getVotos() == esse->getVotos()){
            if(outro->getIdade() > esse->getIdade())
                return true;
            else if(outro->getIdade() < esse->getIdade())
                return false;
            return false;
        }
        return outro->getVotos() < esse->getVotos();
    }
};

#endif //INC_4_PERIODO_PROGRAMACAO3_TRABALHO2_COMPARACANDIDATO_H
