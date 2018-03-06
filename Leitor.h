/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Leitor.h
 * Author: Eduarda
 *
 * Created on 17 de Julho de 2017, 20:09
 */

#ifndef LEITOR_H
#define LEITOR_H

#include <map>
#include <list>
#include <string>
#include <iostream>
#include "Docente.h"
#include "Veiculo.h"
#include "Publicacao.h"
#include "Conferencia.h"
#include "Periodico.h"
#include "Qualis.h"
#include "Regras.h"
#include "Recadastramento.h"

using namespace std;

class Leitor
{
    private:
        FILE* file = NULL;
        const char split = ';';
        string dFile;
        string vFile;
        string pFile;
        string qFile;
        string rFile;
        int ano;
    public:
        Leitor(string d, string v, string p, string q, string r, int ano);
        void iniciarLeitura();
        map<string, Docente*> cadastrarDocentes(string file);
        map<string, Veiculo*> cadastrarVeiculos(string file);
        list<Publicacao*> cadastrarPublicacoes(string file, Recadastramento *sys);
        map<string, Qualis*> cadastrarQualis(string file, Recadastramento *sys);
        Regras* cadastrarRegras(string file);
        virtual ~Leitor();
};

#endif /* LEITOR_H */

