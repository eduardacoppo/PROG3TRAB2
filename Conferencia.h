/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conferencia.h
 * Author: Eduarda
 *
 * Created on 15 de Julho de 2017, 15:04
 */

#ifndef CONFERENCIA_H
#define CONFERENCIA_H

#include <string>
#include "Publicacao.h"
#include "Docente.h"
#include "Docente.h"

class Conferencia: public Publicacao
{
    private:
        string local;
    public:
        Conferencia(int ano, Veiculo* veiculo, string titulo, list<Docente*> autores,
                    int numero, string local, int paginaInicial, int paginaFinal);

};

#endif /* CONFERENCIA_H */

