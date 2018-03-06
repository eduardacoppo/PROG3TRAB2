/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Veiculo.cpp
 * Author: Eduarda
 * 
 * Created on 15 de Julho de 2017, 15:04
 */

#include "Veiculo.h"

Veiculo:: Veiculo(string sigla, string nome,
		string tipo, double fatorImpactante)
{
    this->sigla = sigla;
    this->nome = nome;
    this->tipo = tipo;
    this->fatorImpactante = fatorImpactante;
}

Veiculo:: Veiculo(string sigla, string nome, string tipo,
                  double fatorImpactante, string ISSN)
{
    this->sigla = sigla;
    this->nome = nome;
    this->tipo = tipo;
    this->fatorImpactante = fatorImpactante;
    this->ISSN = ISSN;
}

string Veiculo:: getSigla()
{
    return this->sigla;
}

string Veiculo:: getNome()
{
    return this->nome;
}

string Veiculo:: getTipo()
{
    return this->tipo;
}

double Veiculo:: getFatorImpactante()
{
    return this->fatorImpactante;
}

Veiculo:: ~Veiculo()
{

}

