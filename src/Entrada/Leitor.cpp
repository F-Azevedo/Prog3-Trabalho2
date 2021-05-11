//
// Created by fernando on 29/04/2021.
//

#include "Leitor.h"
#include <iostream>
#include <string>

#include <exception>

vector<int> Leitor::leData(const string& dataStr) {
    //Data da eleicao.
    stringstream aux(dataStr);
    locale brasilLocale("pt_BR.utf8");
    aux.imbue(brasilLocale);
    string info;

    vector<int> data;

    getline(aux, info, '/');
    data.push_back(stoi(info));
    getline(aux, info, '/');
    data.push_back(stoi(info));
    getline(aux, info, '/');
    data.push_back(stoi(info));
    return data;
}

Candidato* Leitor::leCandidato(const string& linha, vector<int> &dia_eleicao) {

    stringstream aux(linha);
    locale brasilLocale("pt_BR.utf8");
    aux.imbue(brasilLocale);
    string info;

    getline(aux, info, ',');
    int numero = stoi(info);

    getline(aux, info, ',');
    int votos = stoi(info);

    getline(aux, info, ',');
    string situacao = info;

    getline(aux, info, ',');
    string nome_candidato = info;

    getline(aux, info, ',');
    string nome_urna = info;

    getline(aux, info, ',');
    char sexo = info.at(0);

    getline(aux, info, ',');
    string nascimento = info;

    //Para pegar o válido;
    getline(aux, info, ',');

    getline(aux, info, ',');
    int numero_partido = stoi(info);
    return new Candidato(numero, votos, numero_partido, situacao, nome_candidato, nome_urna, nascimento, dia_eleicao, sexo);
}

void Leitor::leTodosCandidatos(string& nome_arq_entrada, vector<int>& dia_eleicao, Eleicao& eleicao) {
    //Cria o scanner e abre o arquivo.
    ifstream candidatos;
    locale brasilLocale("pt_BR.utf8");
    candidatos.imbue(brasilLocale);
    string linha;

    candidatos.exceptions (std::ifstream::badbit | std::ifstream::failbit | std::ifstream::eofbit);
    try{
        candidatos.open(nome_arq_entrada);

        // Pega a linha de cabeçalho
        getline(candidatos, linha);

        while(getline(candidatos, linha)){
            //Checa se o candidato é válido, caso não seja ignora.
            if (linha.find("Válido") == string::npos ) continue;

            Candidato* novo_candidato = leCandidato(linha, dia_eleicao);
            eleicao.addCandidatoEleicao(novo_candidato);
        }
    }
    catch(ifstream::failure e){
        if(!candidatos.eof()){
            cerr << "Erro ao abrir/ler/fechar o arquivo" << nome_arq_entrada << endl;
            exit(1);
        }
    }
}

Partido* Leitor::lePartido(const string& linha) {
    vector<string> informacoes;
    string inf;

    stringstream aux(linha);
    locale brasilLocale("pt_BR.utf8");
    aux.imbue(brasilLocale);

    while(getline(aux, inf, ',')){
        informacoes.push_back(inf);
    }

    //Lê as informações, cria e retorna um partido.
    return new Partido(stoi(informacoes[0]), stoi(informacoes[1]), informacoes[2], informacoes[3]);
}

void Leitor::leTodosPartidos(const string& nome_arq_entrada, Eleicao& eleicao) {
    //Cria o scanner e abre o arquivo.
    ifstream partidos;
    locale brasilLocale("pt_BR.utf8");
    partidos.imbue(brasilLocale);
    string linha;

    partidos.exceptions (std::ifstream::badbit | std::ifstream::failbit | std::ifstream::eofbit);
    try{
        partidos.open(nome_arq_entrada);

        // Pega a linha de cabeçalho
        getline(partidos, linha);

        while(getline(partidos, linha)){
            Partido* novo_partido = lePartido(linha);

            //Adicona o partido ao conjunto de partidos da eleição.
            eleicao.addPartidoEleicao(novo_partido->getNumero_partido(), novo_partido);

        }
        partidos.close();
    }
    catch(ifstream::failure e){
        if(!partidos.eof()){
            cerr << "Erro ao abrir/ler/fechar o arquivo" << nome_arq_entrada << endl;
            exit(1);
        }
    }
}