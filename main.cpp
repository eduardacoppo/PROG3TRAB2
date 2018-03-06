/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Eduarda
 *
 * Created on 15 de Julho de 2017, 14:53
 */

#include <cstdlib>
#include <iostream>
#include <string>

#include "Recadastramento.h"
#include "Docente.h"
#include "Leitor.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv)
{
	// Nome dos arquivos csv
    string dFile;
    string vFile;
    string pFile;
    string qFile;
    string rFile;
    int ano;

    // Itera pelos argumentos e vai adicionando o nome dos arquivos e o ano nas variaveis correspondentes
    for (int i = 1; i < argc; i++)
    {
        string aux = string(argv[i]);
    	if (aux == "-d")
    	{
			dFile = argv[i + 1];
    	}
    	else if (aux == "-v")
        {
			vFile = argv[i + 1];
        }
    	else if (aux == "-p")
        {
			pFile = argv[i + 1];
        }
    	else if (aux == "-q")
        {
			qFile = argv[i + 1];
        }
    	else if (aux == "-r")
        {
			rFile = argv[i + 1];
        }
    	else if (aux == "-a")
        {
    		ano = atoi(argv[i + 1]);
        }
        else
        {
        	continue;
        }
    }

    // Construtor do leitor. Cadastra os nomes dos arquivos e o ano
    Leitor leitor(dFile, vFile, pFile, qFile, rFile, ano);
    leitor.iniciarLeitura();

    return 0;
}

