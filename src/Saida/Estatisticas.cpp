//
// Created by fernando on 02/05/2021.
//

#include "Estatisticas.h"
#include <algorithm>

// Funções para impressão de Candidato. -----------------------------------------------------------------

ostream& operator<<(ostream& strm, const Candidato& c){
    string retorno =  c.getNomeUrna() + " (" + to_string(c.getNumero()) + ", " + to_string(c.getVotos());
    if (c.getVotos() > 1) retorno += " votos)";
    else retorno += " voto)";
    return strm << retorno;
}

string simpleStringCandidato(const Candidato& c, const string& sigla_partido) {
    string retorno = c.getNome() + " / " + c.getNomeUrna() + " (" + sigla_partido + ", " + to_string(c.getVotos());
    if (c.getVotos() > 1) retorno += " votos)";
    else retorno += " voto)";
    return retorno;
}

//Funções para impressão de partido. --------------------------------------------------------------------

ostream& operator<<(ostream& strm, const Partido& p){
    return strm << p.getSigla_partido() + " - " + to_string(p.getNumero_partido());
}

string simplesStringPartido(const Partido& p) {
    string s = p.getSigla_partido() + " - " + to_string(p.getNumero_partido()) + ", " + to_string(p.votosTotais());
    if(p.votosTotais() == 0)
        s += " voto (" + to_string(p.getVotos_nominais());
    else
        s += " votos (" + to_string(p.getVotos_nominais());

    if(p.getVotos_nominais() == 0)
        s += " nominal e " + to_string(p.getVotos_legenda()) + " de legenda), " + to_string(p.getQtdEleitos());
    else
        s += " nominais e " + to_string(p.getVotos_legenda()) + " de legenda), " + to_string(p.getQtdEleitos());

    if(p.getQtdEleitos() < 2)
        s += " candidato eleito";
    else
        s += " candidatos eleitos";

    return s;
}

// Funções da classe estatística. -----------------------------------------------------------------------

void Estatisticas::imprimeNumVagas(const Eleicao& e) {
    cout << "Número de vagas: " << e.qtdEleitos() << endl;
    cout << endl;
}

void Estatisticas::imprimeEleitos(Eleicao& e) {
    int i = 0;

    cout << "Vereadores eleitos:" << endl;

    sort(e.getEleitos()->begin(), e.getEleitos()->end(), comparaCandidato());

    for (Candidato* eleito : *e.getEleitos()) {
        Partido* aux = e.getPartidos()->find(eleito->getNumPartido())->second;
        cout << (++i) << " - " << simpleStringCandidato(*eleito, aux->getSigla_partido()) << endl;
    }
    cout << endl;
}

void Estatisticas::imprimeMaisVotados(Eleicao& e) {
    int i = 0;

    cout << "Candidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):" << endl;

    sort(e.getCandidatos()->begin(), e.getCandidatos()->end(), comparaCandidato());

    for (Candidato* maior: *e.getCandidatos()){
        Partido* aux = e.getPartidos()->find(maior->getNumPartido())->second;
        cout << (++i) << " - " + simpleStringCandidato(*maior, aux->getSigla_partido()) << endl;
        if (i >= e.qtdEleitos()) break;
    }
    cout << endl;
}

void Estatisticas::imprimePrejudicados(Eleicao& e) {
    int pos = 1;

    cout << "Teriam sido eleitos se a votação fosse majoritária, e não foram eleitos:\n" <<
                       "(com sua posição no ranking de mais votados)" << endl;

    // Percorre os candidatos da eleição até o número de candidatos que foi eleito.
    // Se o candidato não estiver dentro da lista dos que foram eleitos, como a lista de candidatos
    // esta ordenada de maneira decrescente por votos, podemos afirmar que ele foi prejudicado pela votação.

    vector<Candidato*>* eleitos = e.getEleitos();
    for(Candidato* i : *e.getCandidatos()){
        if (find(eleitos->begin(), eleitos->end(), i) == eleitos->end()) {
            Partido* aux = e.getPartidos()->find(i->getNumPartido())->second;
            cout << (pos) << " - " + simpleStringCandidato(*i, aux->getSigla_partido()) << endl;
        }
        pos++;
        if(pos > e.qtdEleitos()) break;
    }
    cout << endl;
}

void Estatisticas::imprimeBeneficiados(Eleicao& e) {
    int totalEleitos = e.qtdEleitos();
    int qtdEleitos = 0, pos = 0;

    cout << "Eleitos, que se beneficiaram do sistema proporcional:\n" <<
                       "(com sua posição no ranking de mais votados)" << endl;

    // Percorre a os candidatos da eleição, como a lista de candidatos esta ordenada, a partir do candidato de numero N,
    // N sendo o numero de candidatos eleitos, se ele foi eleito significa que ele foi beneficiado, ja que não estava entre
    // os N candidatos mais votados.
    vector<Candidato*>* eleitos = e.getEleitos();
    for(Candidato* i : *e.getCandidatos()){
        pos++;
        if(find(eleitos->begin(), eleitos->end(), i) != eleitos->end()){
            qtdEleitos++;
            if(pos > totalEleitos){
                Partido* aux = e.getPartidos()->find(i->getNumPartido())->second;
                cout << (pos) << " - " + simpleStringCandidato(*i, aux->getSigla_partido()) << endl;
            }
        }
        if(qtdEleitos == totalEleitos)  break;
    }
    cout << endl;
}

void Estatisticas::imprimePartidosMaisVotados(Eleicao& e) {
    int i = 0;

    cout << "Votação dos partidos e número de candidatos eleitos:" << endl;

    // Cria uma cópia dos partidos em forma de lista, para que seja possível efetuar a ordenação.
    vector<Partido*> partidos;

    auto it = e.getPartidos()->begin();
    auto end = e.getPartidos()->end();

    for(; it != end; ++it) {
        partidos.push_back(it->second);
    }

    // Ordena a lista a partir do numero de votos totais do partido de forma decrescente.
    sort(partidos.begin(), partidos.end(), comparaPartido());

    for(Partido* p : partidos){
        cout << ++i << " - " << simplesStringPartido(*p) << endl;
    }
    cout << endl;
}

void Estatisticas::imprimeMelhorPiorCandidatoPorPartido(Eleicao& e) {
    int i=0;

    cout << "Primeiro e último colocados de cada partido:" << endl;

    // Cria uma cópia dos partidos em forma de lista, para que seja possível efetuar a ordenação.
    vector<Partido*> partidos;

    auto it = e.getPartidos()->begin();
    auto end = e.getPartidos()->end();

    // Ordena os valores no map e insere na lista.
    for(; it != end; ++it) {
        sort(it->second->getCandidatos()->begin(), it->second->getCandidatos()->end(), comparaCandidato());
        partidos.push_back(it->second);
    }

    sort(partidos.begin(), partidos.end(), comparaPartido());
    // Ordena a lista de partidos a partir do numero de votos do candidato com mais votos de forma decrescente.
    sort(partidos.begin(), partidos.end(), comparaMaisVotado());

    for(Partido* p: partidos){
        if (p->getCandidatos()->empty() || p->votosTotais() <= 0) continue;
        cout << ++i << " - " << *p << ", " << *p->getCandidatos()->front() << " / " << *p->getCandidatos()->back() << endl;
    }
    cout << endl;
}

void Estatisticas::imprimeIdade(Eleicao& e) {
    int total = e.qtdEleitos();
    int menor30 = 0, menor40 = 0, menor50 = 0, menor60 = 0, maior60 = 0;

    //Verifica a quantidade de vereadores eleitos em cada faixa etária.
    for (const Candidato* i : *e.getEleitos()) {
        int idade = i->getIdade();
        if (idade < 30) menor30++;
        else if (idade < 40) menor40++;
        else if (idade < 50) menor50++;
        else if (idade < 60) menor60++;
        else maior60++;
    }

    cout.precision(2);

    cout << "Eleitos, por faixa etária (na data da eleição):" << endl << fixed;
    cout << "      Idade < 30: " << menor30 << " (" << ((float)menor30 / (float)total) * 100 << "%)" << endl << fixed;
    cout << "30 <= Idade < 40: " << menor40 << " (" << ((float)menor40 / (float)total) * 100 << "%)" << endl << fixed;
    cout << "40 <= Idade < 50: " << menor50 << " (" << ((float)menor50 / (float)total) * 100 << "%)" << endl << fixed;
    cout << "50 <= Idade < 60: " << menor60 << " (" << ((float)menor60 / (float)total) * 100 << "%)" << endl << fixed;
    cout << "60 <= Idade     : " << maior60 << " (" << ((float)maior60 / (float)total) * 100 << "%)" << endl << fixed;
    cout << endl;
}

void Estatisticas::imprimeSexo(Eleicao& e) {
    int total = e.qtdEleitos();
    int fem = 0, masc = 0;

    //Verifica quantos dos vereadores eleitos são homens e quantos são mulheres.
    for (const Candidato* i : *e.getEleitos()) {
        if (i->getSexo() == 'F')
            fem++;
        else
            masc++;
    }

    cout << "Eleitos, por sexo:" << endl;
    cout << "Feminino:  " << fem  << " (" << ((float)fem / (float)total) * 100 << "%)" << endl << fixed;
    cout << "Masculino: " << masc << " (" <<((float)masc / (float)total) * 100 << "%)" << endl << fixed;
    cout << endl;
}

void Estatisticas::imprimeTotalVotos(Eleicao& e) {
    int legenda = e.get_total_votos_legenda();
    int nominal = e.get_total_votos_nominais();
    int total = legenda + nominal;

    cout << "Total de votos válidos:    " << total << endl;
    cout << "Total de votos nominais:   " << nominal << " (" << ((float)nominal / (float)total) * 100 << "%)" << endl << fixed;
    cout << "Total de votos de Legenda: " << legenda << " (" << ((float)legenda / (float)total) * 100 << "%)" << endl << fixed;
    cout << endl;
}