/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Regras.h
 * Author: Eduarda
 *
 * Created on 15 de Julho de 2017, 15:04
 */

#ifndef REGRAS_H
#define REGRAS_H
#include<stdlib.h>
#include <map>
#include <string>

using namespace std;

class Regras
{
    private:
        string dataInicio;
        string dataFim;
        map <string, int> mapaPontuacaoQualis;
        double fatorMultiplicador;
        int qtdAnos;
        double pontuacaoMinima;
    public:
        Regras(string dataInicio, string dataFim, map<string, int> mapaPontuacaoQualis,
               double fatorMultiplicador, int qtdAnos, double pontuacaoMinima);
        void putMapaPontuacaoQualis(string Qualis, int num);
        string getDataInicio();
        int getInteiro(string Qualis);
        double getMultiplicador();
        int getQtdAnos();
        double getPontuacaoMinima();
        int retorna_pontuacao(string qualis);
        int getAnoInicio();
        //int qtdAnos();
};

#endif /* REGRAS_H */

