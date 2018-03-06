/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Periodico.cpp
 * Author: Eduarda
 * 
 * Created on 15 de Julho de 2017, 15:04
 */

#include "Periodico.h"
#include "Publicacao.h"
#include "Docente.h"
#include "Veiculo.h"

using namespace std;

Periodico:: Periodico(int ano, Veiculo* veiculo, string titulo, list<Docente*> autores,
                      int numero, int volume, int paginaInicial, int paginaFinal) :
Publicacao:: Publicacao(ano, veiculo, titulo, autores, numero, paginaInicial, paginaFinal)
{
	this->volume = volume;
}

