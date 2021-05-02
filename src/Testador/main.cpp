//
// Created by fernando on 29/04/2021.
//

#include "../Eleicoes/Eleicao.h"
#include "../Entrada/Leitor.h"
#include "../Saida/Estatisticas.h"

int main(int argc, char* argv[]){
    string arq_candidatos   = argv[1],
            arq_partidos 	= argv[2],
            data            = argv[3];

    Leitor leitor;
    //Lê a data de realização da eleição.
    cout << "Arquivo de candidatos " << arq_candidatos << endl;
    cout << "Arquivo de partidos " << arq_partidos << endl;
    cout << "Data da eleição inicialmente " << data << endl;
    vector<int> data_eleicao = leitor.leData(data);
    //Cria a estrutura da classe eleição.
    Eleicao eleicao = Eleicao(data_eleicao);

    //Lê os partidos.
    leitor.leTodosPartidos(arq_partidos, eleicao);
    leitor.leTodosCandidatos(arq_candidatos, data_eleicao, eleicao);

    Estatisticas estatisticas;
//    Imprime as estatísticas.
    estatisticas.imprimeNumVagas(eleicao);
    estatisticas.imprimeEleitos(eleicao);
    estatisticas.imprimeMaisVotados(eleicao);
    estatisticas.imprimePrejudicados(eleicao);
    estatisticas.imprimeBeneficiados(eleicao);
    estatisticas.imprimePartidosMaisVotados(eleicao);
//    estatisticas.imprimeMelhorPiorCandidatoPorPartido(eleicao);
    estatisticas.imprimeIdade(eleicao);
    estatisticas.imprimeSexo(eleicao);
    estatisticas.imprimeTotalVotos(eleicao);
}