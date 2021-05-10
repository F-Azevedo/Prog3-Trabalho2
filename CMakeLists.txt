cmake_minimum_required(VERSION 3.19)
project(4_Periodo_Programacao3_Trabalho2)

set(CMAKE_CXX_STANDARD 14)

add_executable(4_Periodo_Programacao3_Trabalho2
        src/Testador/main.cpp
        src/Eleicoes/candidato.cpp
        src/Eleicoes/candidato.h
        src/Eleicoes/partido.cpp
        src/Eleicoes/partido.h
        src/Eleicoes/Eleicao.cpp
        src/Eleicoes/Eleicao.h
        src/Eleicoes/comparaPartido.h
        src/Eleicoes/comparaCandidato.h
        src/Eleicoes/comparaMaisVotado.h
        src/Entrada/Leitor.cpp
        src/Entrada/Leitor.h
        src/Saida/Estatisticas.cpp
        src/Saida/Estatisticas.h
)
