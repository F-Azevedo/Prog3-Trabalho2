//
// Created by fernando on 10/05/2021.
//

#ifndef INC_4_PERIODO_PROGRAMACAO3_TRABALHO2_COMPARAPARTIDO_H
#define INC_4_PERIODO_PROGRAMACAO3_TRABALHO2_COMPARAPARTIDO_H

#include "partido.h"

class comparaPartido{
public:
    inline bool operator()(Partido* esse, Partido* outro){
        return outro->votosTotais() < esse->votosTotais();
    }
};

#endif //INC_4_PERIODO_PROGRAMACAO3_TRABALHO2_COMPARAPARTIDO_H
