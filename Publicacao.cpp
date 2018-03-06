/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Publicacao.cpp
 * Author: Eduarda
 * 
 * Created on 15 de Julho de 2017, 15:04
 */

#include "Publicacao.h"
//#include "Qualis.h"

using namespace std;

Publicacao:: Publicacao(int ano, Veiculo* veiculo, string titulo, list<Docente*> autores,
		                int numero, int paginaInicial, int paginaFinal)
{
    this->ano = ano;
    this->veiculo = veiculo;
    this->titulo = titulo;
    this->numero = numero;
    this->paginaInicial = paginaInicial;
    this->paginaFinal = paginaFinal;
}

void Publicacao:: adicionarAutor(Docente* autor)
{
    this->autores.push_front(autor);
}

string Publicacao:: getTitulo()
{
    return this->titulo;
}

list<Docente*> Publicacao:: getListaDocentes()
{
    return this->autores;
}

int Publicacao:: getNumAutores()
{
    return this->autores.size();
}

bool Publicacao:: contemAutor(string codigo)
{
	list<Docente>:: iterator it = this -> autores.begin();
	Docente* doc;
	while(it != autores.end())
	{
		doc = it;
		if(doc->getCodigo().compare(codigo) == 0)
			return true;
		it++;
	}
    return false;
}

Veiculo* Publicacao:: retornaVeiculo()
{
    return this->veiculo;
}

int Publicacao:: getAno()
{
    return this->ano;
}
string Publicacao:: verificaNomeQualis(Qualis* qualis)
{
	return qualis->retorna_nome_qualis(this-> ano);
}
bool Publicacao:: comparaPublicacao(Publicacao* ant,Publicacao* pos)
{
	if(ant -> ano > pos -> ano)
		return true;
	else
	{
		if(ant -> ano < pos -> ano)
			return false;
			else
			{
				if(ant -> retornaVeiculo() -> getSigla().compare(pos ->retornaVeiculo()-> getSigla()) < 0)
					return true;
				else
				{
					if(ant -> retornaVeiculo() -> getSigla().compare(pos ->retornaVeiculo()-> getSigla()) > 0)
						return false;
					else
					{
						if(ant -> titulo.compare(pos -> titulo) < 0)
						{
							return true;
						}
						else
							return false;
					}
				}
			}
	}
}
double Publicacao:: calcula_pontuacao(Qualis* qualis,Regras* regras)
{
	int ano = this -> ano;
	int anoInicioRegras = regras -> getAnoInicio();
	int duracao = regras -> getQtdAnos();
	int anoConsiderado = anoInicioRegras -(anoInicioRegras - duracao);
	if(ano < anoConsiderado)
		return 0;
	string aux = qualis -> retorna_nome_qualis(ano);
	return regras -> retorna_pontuacao(aux);
}

