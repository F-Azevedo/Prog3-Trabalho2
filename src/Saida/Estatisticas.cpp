//
// Created by fernando on 02/05/2021.
//

#include "Estatisticas.h"

void Estatisticas::imprimeNumVagas(const Eleicao& e) {
    cout << "Número de vagas: " << e.qtdEleitos() << endl;
}

void Estatisticas::imprimeEleitos(const Eleicao& e) {
    int i = 0;

    cout << "Vereadores eleitos:" << endl;

    // Vereadores eleitos já foram armazenados ordenadamente pelos mais votados de maneira decrescente.

    for (Candidato eleito : *e.getEleitos()) {
        Partido aux = e.getPartidos()->find(eleito.getNumPartido())->second;
        cout << (++i) << " - " << eleito.simpleString(aux.getSigla_partido()) << endl;
    }
    cout << endl;
}

void Estatisticas::imprimeMaisVotados(const Eleicao& e) {

}

void Estatisticas::imprimePrejudicados(const Eleicao& e) {

}

void Estatisticas::imprimeBeneficiados(const Eleicao& e) {

}

void Estatisticas::imprimePartidosMaisVotados(const Eleicao& e) {

}

void Estatisticas::imprimeMelhorPiorCandidatoPorPartido(const Eleicao& e) {

}

void Estatisticas::imprimeIdade(const Eleicao& e) {
    int total = e.qtdEleitos();
    int menor30 = 0, menor40 = 0, menor50 = 0, menor60 = 0, maior60 = 0;

    //Verifica a quantidade de vereadores eleitos em cada faixa etária.
    for (Candidato& i : *e.getEleitos()) {
        int idade = i.getIdade();
        if (idade < 30) menor30++;
        else if (idade < 40) menor40++;
        else if (idade < 50) menor50++;
        else if (idade < 60) menor60++;
        else maior60++;
    }

    cout << "Eleitos, por faixa etária (na data da eleição):" << endl;
    cout << "\t  Idade < 30: "   << menor30 << " (" << ((float)menor30 / (float)total) * 100 << "%)" << endl;
    cout << "30 <= Idade < 40: " << menor40 << " (" << ((float)menor40 / (float)total) * 100 << "%)" << endl;
    cout << "40 <= Idade < 50: " << menor50 << " (" << ((float)menor50 / (float)total) * 100 << "%)" << endl;
    cout << "50 <= Idade < 60: " << menor60 << " (" << ((float)menor60 / (float)total) * 100 << "%)" << endl;
    cout << "60 <= Idade\t\t: "  << maior60 << " (" << ((float)maior60 / (float)total) * 100 << "%)" << endl;
    cout << endl;
}

void Estatisticas::imprimeSexo(const Eleicao& e) {
    int total = e.qtdEleitos();
    int fem = 0, masc = 0;

    //Verifica quantos dos vereadores eleitos são homens e quantos são mulheres.
    for (Candidato& i : *e.getEleitos()) {
        if (i.getSexo() == 'F')
            fem++;
        else
            masc++;
    }

    cout << "Eleitos, por sexo:" << endl;
    cout << "Feminino:\t"  << fem  << " (" << ((float)fem / (float)total) * 100 << "%)" << endl;
    cout << "Masculino:\t" << masc << " (" <<((float)masc / (float)total) * 100 << "%)" << endl;
    cout << endl;
}

void Estatisticas::imprimeTotalVotos(const Eleicao& e) {
    int legenda = e.get_total_votos_legenda();
    int nominal = e.get_total_votos_nominais();
    int total = legenda + nominal;

    cout << "Total de votos válidos: \t"   << total << endl;
    cout << "Total de votos nominais:\t"   << nominal << " (" << ((float)nominal / (float)total) * 100 << "%)" << endl;
    cout << "Total de votos de Legenda:\t" << legenda << " (" << ((float)legenda / (float)total) * 100 << "%)" << endl;
}
