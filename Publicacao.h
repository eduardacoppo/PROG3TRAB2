/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Publicacao.h
 * Author: Eduarda
 *
 * Created on 15 de Julho de 2017, 15:04
 */

#ifndef PUBLICACAO_H
#define PUBLICACAO_H

#include <string>
#include <list>
#include "Docente.h"
#include "Veiculo.h"
#include "Qualis.h"

using namespace std;

class Publicacao
{
    private:
        int ano;
        Veiculo* veiculo;
        string titulo;
        list<Docente*> autores;
        int numero;
        int paginaInicial;
        int paginaFinal;
    public:
        Publicacao(int ano, Veiculo* veiculo, string titulo, list<Docente*> autores,
                   int numero, int paginaInicial, int paginaFinal);
        void adicionarAutor(Docente* autor);
        string getTitulo();
        list<Docente*> getListaDocentes();
        int getNumAutores();
        bool contemAutor(string codigo);

        Veiculo* retornaVeiculo();
        string verificaNomeQualis(Qualis* qualis);
        bool comparaPublicacao(Publicacao* ant,Publicacao* pos);
        double calcula_pontuacao(Qualis* qualis,Regras* regras);
        int getAno();
};

#endif /* PUBLICACAO_H */

