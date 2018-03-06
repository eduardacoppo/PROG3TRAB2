/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Veiculo.h
 * Author: Eduarda
 *
 * Created on 15 de Julho de 2017, 15:04
 */

using namespace std;

#ifndef VEICULO_H
#define VEICULO_H

#include <string>

class Veiculo
{
    private:
        string sigla;
        string nome;
        string tipo;
        double fatorImpactante;
        string ISSN;
    public:
        Veiculo();
        Veiculo(string sigla, string nome, string tipo, double fatorImpactante);
        Veiculo(string sigla, string nome, string tipo, double fatorImpactante, string ISSN);
        string getSigla();
        string getNome();
        string getTipo();
        double getFatorImpactante();
        virtual ~Veiculo();
};

#endif /* VEICULO_H */

