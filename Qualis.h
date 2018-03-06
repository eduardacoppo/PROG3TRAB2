/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Qualis.h
 * Author: Eduarda
 *
 * Created on 15 de Julho de 2017, 15:04
 */

#ifndef QUALIS_H
#define QUALIS_H

#include <string>
#include "Veiculo.h"
#include "Publicacao.h"

using namespace std;

class Qualis
{
    private:
        int ano;
        list<QualisAux> listaDeQualis;
        Veiculo* veiculo;
        string qualis;
    public:
        Qualis(int ano, Veiculo* veiculo, string qualis);
        string getNomeQualis();
        //retorna o ano da qualis
        int getAnoQualis();
        //insere na lista de todas as qualis para um veiculo
        void insere_lista(int ano,string qualis);
        string retorna_nome_qualis(int ano);
        bool compara_qualis(Qualis* Qant,Publicacao* Pant,Qualis* Qpos,Publicacao* Ppos);
};

class QualisAux
{
private:
	int ano;
	string qualis;
public:
	QualisAux(int ano,string qualis);
	int getAnoQualisAux();
	bool compara_QualisAux(QualisAux* prim,QualisAux* sec);
	string retorna_nome_qualisAux();
};

#endif /* QUALIS_H */

