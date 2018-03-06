/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conferencia.cpp
 * Author: Eduarda
 * 
 * Created on 15 de Julho de 2017, 15:04
 */

#include "Conferencia.h"
#include "Publicacao.h"
#include "Veiculo.h"
#include "Docente.h"

using namespace std;

Conferencia:: Conferencia(int ano, Veiculo* veiculo, string titulo, list<Docente*> autores,
                          int numero, string local, int paginaInicial, int paginaFinal) :
Publicacao:: Publicacao(ano, veiculo, titulo, autores, numero, paginaInicial, paginaFinal)
{
	this->local = local;
}
