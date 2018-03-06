/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Regras.cpp
 * Author: Eduarda
 * 
 * Created on 15 de Julho de 2017, 15:04
 */

#include "Regras.h"
#include "stdlib.h"

using namespace std;

Regras:: Regras(string dataInicio, string dataFim, map<string, int> mapaPontuacaoQualis,
                double fatorMultiplicador, int qtdAnos, double pontuacaoMinima)
{
    this->dataInicio = dataInicio;
    this->dataFim = dataFim;
    this->fatorMultiplicador = fatorMultiplicador;
    this->qtdAnos = qtdAnos;
    this->pontuacaoMinima = pontuacaoMinima;
    this->mapaPontuacaoQualis = mapaPontuacaoQualis;
}

void Regras:: putMapaPontuacaoQualis(string Qualis, int num)
{
    this->mapaPontuacaoQualis.insert(pair<string, int>(Qualis, num));
}

string Regras:: getDataInicio()
{
    return this->dataInicio;
}

int Regras:: getInteiro(string Qualis)
{
    return 0;
}
        
double Regras:: getMultiplicador()
{
    return this->fatorMultiplicador;
}
        
int Regras:: getQtdAnos()
{
    return this->qtdAnos;
}
        
double Regras:: getPontuacaoMinima()
{
    return this->pontuacaoMinima;
}
int Regras:: retorna_pontuacao(string qualis)
{
	return this -> mapaPontuacaoQualis(qualis);
}
int Regras:: getAnoInicio()
{
	string aux;
	int tam = this -> dataInicio.size;
	aux = this -> dataInicio.substr(tam-4,tam);
	int ano = atoi(aux.c_str());
	return ano;
}

