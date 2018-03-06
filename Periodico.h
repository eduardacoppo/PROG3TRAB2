/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Periodico.h
 * Author: Eduarda
 *
 * Created on 15 de Julho de 2017, 15:04
 */

#ifndef PERIODICO_H
#define PERIODICO_H

#include <string>
#include "Docente.h"
#include "Publicacao.h"
#include "Veiculo.h"
#include "Qualis.h"

using namespace std;

class Periodico : public Publicacao
{
    private:
        int volume;
    public:
        Periodico(int ano, Veiculo* veiculo, string titulo, list<Docente*> autores,
                  int numero, int volume, int paginaInicial, int paginaFinal);
};

#endif /* PERIODICO_H */

