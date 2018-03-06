/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Docente.cpp
 * Author: Eduarda
 * 
 * Created on 15 de Julho de 2017, 15:04
 */

#include "Docente.h"
#include "Publicacao.h"

using namespace std;

Docente:: Docente(string codigo, string nome, string dataNascimento,
                  string dataIngresso, bool coordenador)
{
    this->codigo = codigo;
    this->nome = nome;
    this->dataNascimento = dataNascimento;
    this->dataIngresso = dataIngresso;
    this->coordenador = coordenador;
}

string Docente:: getDataIngresso()
{
    return this->dataIngresso;
}

string Docente:: getNascimento()
{
    return this->dataNascimento;
}

string Docente:: getNome()
{
    return this->nome;
}

string Docente:: getCodigo()
{
    return this->codigo;
}

bool Docente:: eCoordenador()
{
    return this->coordenador;
}
bool Docente:: comparaDocenteNome(Docente* ant,Docente* pos)
{
	if(ant -> nome.compare(pos -> nome) < 0)
		return true;
	else
		return false;
}
double Docente:: calcula_pontuacao_docente(Regras regras,list<Publicacao> pub,map<string,Qualis> mapQualis)
{
	double pontos = 0;
	list<Publicacao> itPub = pub.begin();
	Publicacao* publicacao;
	string sigla;
	Qualis* qualis;
	while(itPub != pub.end())
	{
		publicacao = itPub;
		if(publicacao -> contemAutor(this -> codigo))
		{
			sigla = publicacao -> retornaVeiculo() -> getSigla();
			qualis = mapQualis.find(sigla);
			pontos = pontos + publicacao->calcula_pontuacao(qualis,regras);
		}

	}
	return pontos;

}
/*
 	 dataNascimento;
        string dataIngresso;
 */
int Docente:: getAnoNascimento()
{
	string aux;
		int tam = this -> dataNascimento.size;
		aux = this -> dataNascimento.substr(tam-4,tam);
		int ano = atoi(aux.c_str());
		return ano;
}

int Docente:: getAnoIngresso()
{
	string aux;
		int tam = this -> dataIngresso.size;
		aux = this ->  dataIngresso.substr(tam-4,tam);
		int ano = atoi(aux.c_str());
		return ano;
}
int Docente:: maisde60oumenosde3(int ano)
{
	if((ano - this -> getAnoNascimento()) >= 60 )
		return 1;
	else
	if((ano - this -> getAnoIngresso()) <=3)
		return -1;
	return 0;
}

