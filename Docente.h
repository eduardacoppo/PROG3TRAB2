/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Docente.h
 * Author: Eduarda
 *
 * Created on 15 de Julho de 2017, 15:04
 */

#ifndef DOCENTE_H
#define DOCENTE_H

#include <string>
#include <list>
#include "Publicacao.h"
#include "Regras.h"
#include "Qualis.h"

using namespace std;

class Docente
{
    private:
        string codigo;
        string nome;
        string dataNascimento;
        string dataIngresso;
        bool coordenador;
    public:
        Docente(string codigo, string nome, string dataNascimento,
                string dataIngresso, bool coordenador);
        string getDataIngresso();
        string getNascimento();
        string getNome();
        string getCodigo();
        bool eCoordenador();
        bool comparaDocenteNome(Docente* ant,Docente* pos);
        double calcula_pontuacao_docente(Regras regras,list<Publicacao> pub,map<string,Qualis> mapQualis);
        int getAnoNascimento();
        int getAnoIngresso();
        int maisde60oumenosde3(int ano);
};

#endif /* DOCENTE_H */

