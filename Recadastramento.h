/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Recadastramento.h
 * Author: Eduarda
 *
 * Created on 15 de Julho de 2017, 15:05
 */

#ifndef RECADASTRAMENTO_H
#define RECADASTRAMENTO_H

#include <string>
#include <map>
#include <list>

#include "Regras.h"
#include "Docente.h"
#include "Veiculo.h"
#include "Publicacao.h"
#include "Qualis.h"
#include "Periodico.h"
#include "Conferencia.h"

using namespace std;

class Recadastramento
{
	private:
		map<string, Docente*> docentes;
		map<string, Veiculo*> veiculos;
		list<Publicacao> publicacoes;
		map<string, Qualis> qualis;
                list<Regras*> regras;
		//Regras *regra;
	public:
        Recadastramento();
        Docente *retornaDocentePorCodigo(string codigo);
        Veiculo *retornaVeiculoPorSigla(string sigla);
        Qualis *retornaQualis(string qualis);

        void adicionaMapaDocentes(map<string, Docente*> mapa);

        void adicionaMapaVeiculos(map<string, Veiculo*> mapa);
        void adicionaListaPublicacoes(list<Publicacao*> lista);
        void adicionaMapaQualis(map<string, Qualis*> mapa);
        // verifica se ja existe uma qualis para o veiculo procurado, se existir retorna 1 senão retorna
        int verificaSeJaExisteQualisParaVeiculo(string nomeVeiculo);
        list<PublicacaoEQualis*> geraRelatoriodePublicacoes();
        void geraEstatisticasdePublicacoes(list<PublicacaoEQualis*> PQ);
        void gerarRecredenciamento(int ano);
        Regras* getRegraDoAno(int ano);
        //void adicionaRegras(Regras *regra);

};

class PublicacaoEQualis
{
private:
	Qualis* qualis;
	Publicacao* publicacao;
public:
	PublicacaoEQualis(Publicacao* publicacao, Qualis* qualis);

	Publicacao getPublicacao();

	Qualis getQualis();
	bool compara_publicacaoEqualis(PublicacaoEQualis* ant,PublicacaoEQualis* pos);

};

#endif /* RECADASTRAMENTO_H */

