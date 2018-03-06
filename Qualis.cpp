/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Qualis.cpp
 * Author: Eduarda
 * 
 * Created on 15 de Julho de 2017, 15:04
 */

#include "Qualis.h"

using namespace std;

Qualis:: Qualis(int ano, Veiculo* veiculo, string qualis)
{
    this->ano = ano;
    QualisAux qualisAnoX = new QualisAux(ano,qualis);
    this -> listaDeQualis.push_back(qualisAnoX);
    this->veiculo = veiculo;
    this->qualis = qualis;
}

string Qualis:: getNomeQualis()
{
    return this->qualis;
}
int Qualis:: getAnoQualis()
{
    return this->ano;
}
void Qualis:: insere_lista(int ano,string qualis)
{
	QualisAux qualisaux = new QualisAux(ano,qualis);
	this -> listaDeQualis.push_back(qualisaux);
	this -> listaDeQualis.sort(QualisAux:: compara_QualisAux);
}
string Qualis:: retorna_nome_qualis(int ano)
{
	 list<QualisAux>:: iterator it = this -> listaDeQualis.begin();
	 while(it != listaDeQualis.end() )
	 {
		 if(it -> getAnoQualisAux() < ano)
			 return it -> retorna_nome_qualisAux();
		 it++;
	 }
	 return "C";
}

bool Qualis:: compara_qualis(Qualis* Qant,Publicacao* Pant,Qualis* Qpos,Publicacao* Ppos)
{
	string anterior = Pant -> verificaNomeQualis(Qant);
	string posterior = Ppos -> verificaNomeQualis(Qpos);
	if (anterior.compare(posterior) <= 0)
		return true;
	else
		return false;

}


QualisAux:: QualisAux(int ano,string qualis)
{
	this -> ano = ano;
	this -> qualis = qualis;
}

int QualisAux:: getAnoQualisAux()
{
	return this -> ano;
}

bool QualisAux:: compara_QualisAux(QualisAux* prim,QualisAux* sec)
{
	return prim -> ano > sec -> ano;
}
string QualisAux:: retorna_nome_qualisAux()
{
	return this -> qualis;
}
