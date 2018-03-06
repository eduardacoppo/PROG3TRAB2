/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Leitor.cpp
 * Author: Eduarda
 * 
 * Created on 17 de Julho de 2017, 20:09
 */

#include <iostream>
#include <cstdlib>
#include <fstream> // Stream class to both read and write from/to files.
#include <string>
#include <vector>
#include <map>
#include <locale>
#include <cstring>
#include <sstream>

#include "Regras.h"
#include "Leitor.h"
#include "Recadastramento.h"
#include "Docente.h"
#include "Veiculo.h"
#include "Publicacao.h"
#include "Qualis.h"
#include "StringUtils.h"
#include "Tokenizer.h"

using namespace std;
using namespace cpp_util;

/* Construtor
 * Inicializa os arquivos que serao lidos e o ano
 */
Leitor:: Leitor(string d, string v, string p, string q, string r, int ano)
{
	this->dFile = d;
	this->vFile = v;
	this->pFile = p;
	this->qFile = q;
	this->rFile = r;
	this->ano = ano;
}
const locale loc = locale("pt_BR.UTF8");

/* Inicia a leitura dos arquivos
 * Le um por um e adiciona os mapas e as listas no objeto Recredenciamento
 * Ao final das leituras, gera os relatorios
 */
void Leitor:: iniciarLeitura()
{
	Recadastramento *sys = new Recadastramento();

	// Le cada arquivo e adiciona os mapas, listas e regras ao objeto sys
	map<string, Docente*> mapaDocentes = cadastrarDocentes(dFile);
	sys->adicionaMapaDocentes(mapaDocentes);

    map<string, Veiculo*> mapaVeiculos = cadastrarVeiculos(vFile);
    sys->adicionaMapaVeiculos(mapaVeiculos);

    list<Publicacao*> listaPublicacoes = cadastrarPublicacoes(pFile, sys);
    sys->adicionaListaPublicacoes(listaPublicacoes);

    map<string, Qualis*> mapaQualis = cadastrarQualis(qFile, sys);
    sys->adicionaMapaQualis(mapaQualis);

//    Regras *regra = cadastrarRegras(rFile);
//    sys->adicionaRegras(regra);

    // Gera os relatorios
}

map<string, Docente*> Leitor:: cadastrarDocentes(string file)
{
    ifstream dFile(file); // Prepara-se para ler o arquivo de docentes
    string linha; // auxiliar que vai ler linha por linha do arquivo
    Tokenizer *token; // Criando um tokenizer
    vector<string> elem; // Vetor de string usado para guardar os elementos da linha depois que ela for separada pelo tokenizer
    map<string, Docente*> mapaDocentes; // Mapa de docentes
    
    // Variaveis para guardar os dados do arquivo
    Docente *docente;
    string codigo;
    string nome;
    string dataNascimento;
    string dataIngresso;
    bool coordenador;

    getline(dFile, linha); // Primeira linha

    if (dFile.is_open())
    {
    	while (getline(dFile, linha))
    	{
    		token = new Tokenizer(linha, split); // separa a linha lida pelo caractere ';' (const char split definido em Leitor)
    		elem = token->remaining();

    		// Tira espacos desnecessarios
    		for (string &e : elem)
			{
				trim(e);
			}

    		codigo = elem[0];
    		nome = elem[1];
    		dataNascimento = elem[2];
    		dataIngresso = elem[3];

    		if (elem[4].size() != 0) // Contem o X que indica que eh coordenador
    		{
    			coordenador = true;
    		}
    		else
    		{
    			coordenador = false;
    		}

    		docente = new Docente(codigo, nome, dataNascimento, dataIngresso, coordenador);
    		mapaDocentes.insert(pair<string, Docente*>(codigo, docente));
    	}
    }

    else
    {
    	cout << "Erro de I/O" << endl;
    }

    return mapaDocentes;
}

map<string, Veiculo*> Leitor:: cadastrarVeiculos(string file)
{
	ifstream vFile(file);
	string linha;
	Tokenizer *token;
	vector<string> elem;
	map<string, Veiculo*> mapaVeiculos;

	// Variaveis para guardar os dados do arquivo
	Veiculo *veiculo;
	string sigla;
	string nome;
	string tipo;
	double fatorImpactante;
	string ISSN;

	getline(vFile, linha); // Primeira linha

	if (vFile.is_open())
	{
		while (getline(vFile, linha))
		{
			token = new Tokenizer(linha, split);
			elem = token->remaining();

			for (string &e : elem)
			{
				trim(e);
			}

			sigla = elem[0];
			nome = elem[1];
			tipo = elem[2];
			//fatorImpactante = stod(elem[3]);
                       // fatorImpactante = parseDouble(elem[3]);
                        
                        
			if (elem[4].size() != 0) // Contem ISSN
			{
				ISSN = elem[4];
				veiculo = new Veiculo(sigla, nome, tipo, fatorImpactante, ISSN);
				mapaVeiculos.insert(pair<string, Veiculo*>(sigla, veiculo));
			}
			else
			{
				veiculo = new Veiculo(sigla, nome, tipo, fatorImpactante);
				mapaVeiculos.insert(pair<string, Veiculo*>(sigla, veiculo));
			}
		}
	}

	else
	{
		cout << "Erro de I/O" << endl;
	}

	return mapaVeiculos;
}

list<Publicacao*> Leitor:: cadastrarPublicacoes(string file, Recadastramento *sys)
{
	ifstream pFile(file);
	string linha;
	Tokenizer *token;
	vector<string> elem;
	list<Publicacao*> listaPublicacoes;

	// Variaveis para guardar os dados do arquivo
	Docente *autor;
	string aux;
	Periodico *periodico;
	Conferencia *conferencia;
	int ano;
	Veiculo *veiculo;
	string titulo;
	list<Docente*> autores;
	int numero;
	bool publicacaoEmPeriodico = false;
	int volume;
	string local;
	int paginaInicial;
	int paginaFinal;

	getline(pFile, linha); // Primeira linha

	if (pFile.is_open())
	{
		while (getline(pFile, linha))
		{
			token = new Tokenizer(linha, split);
			elem = token->remaining();

			for (string &e : elem)
			{
				trim(e);
			}

			// ANO
			stringstream(elem[0]) >> ano;

			// VEICULO
			aux = elem[1];
			veiculo = sys->retornaVeiculoPorSigla(aux);

			// TITULO
			titulo = elem[2];

			// AUTORES
			vector<string> codigo; // vetor que vai guardar o(s) codigo(s) do(s) autor(es) da publicacao
			aux = elem[3];
			Tokenizer *tk = new Tokenizer(aux, ',');
			codigo = tk->remaining();
			for (string &cod : codigo)
			{
				autor = sys->retornaDocentePorCodigo(cod);
				autores.push_front(autor);
			}

			// NUMERO
			stringstream(elem[3]) >> numero;

			// VOLUME: PARA PERIODICOS
			aux = elem[4];
			if (aux.size() > 0)
			{
				//volume = stoi(aux);
                            //volume = (int)parseDouble(elem[4]);
                            stringstream(elem[4]) >> volume;
                            
				publicacaoEmPeriodico = true;
			}

			//LOCAL: PARA CONFERENCIAS
			local = elem[5];

			// PAGINA INICIAL
			stringstream(elem[6]) >> paginaInicial;

			// PAGINA FINAL
			stringstream(elem[7]) >> paginaFinal;

			if (publicacaoEmPeriodico)
			{
				periodico = new Periodico(ano, veiculo, titulo, autores, numero, volume, paginaInicial, paginaFinal);
				listaPublicacoes.push_front(periodico);
			}
			else
			{
				conferencia = new Conferencia(ano, veiculo, titulo, autores, numero, local, paginaInicial, paginaFinal);
				listaPublicacoes.push_front(conferencia);
			}

		}
	}

	else
	{
		cout << "Erro de I/O" << endl;
	}

	return listaPublicacoes;
}

map<string, Qualis*> Leitor:: cadastrarQualis(string file, Recadastramento *sys)
{
	ifstream qFile(file);
	string linha;
	Tokenizer *token;
	vector<string> elem;
	map<string, Qualis*> mapaQualis;

	// Variaveis para guardar os dados do arquivo
	Qualis *qualis;
	string chave;
	string sigla;
	int ano;
	Veiculo *veiculo;
	string nomeQualis;
	vector<string> nomesQualis = {"A1", "A2", "B1", "B2", "B3", "B4", "B5", "C"};
        Qualis *auxQualis; // sera usado para comparar duas qualis
	getline(qFile, linha); // Primeira linha

	if (qFile.is_open())
	{
		while (getline(qFile, linha))
		{
			token = new Tokenizer(linha, split);
			elem = token->remaining();

			for (string &e : elem)
			{
				trim(e);
			}

			stringstream(elem[0]) >> ano; // converte uma string (no caso elem[0]) para um inteiro e joga em uma variavel (no caso, ano)

			sigla = elem[1]; // sigla do veiculo
			veiculo = sys->retornaVeiculoPorSigla(sigla);

			nomeQualis = elem[2];

			//qualis = new Qualis(ano, veiculo, nomeQualis);

			//chave = sigla + to_string(ano); // concatena a sigla do veiculo com o ano da qualis
                        if(mapaQualis.find(sigla) != mapaQualis.end())
                        {
                            auxQualis = mapaQualis.find(sigla);//verifica qual é o qualis que deve ser usado
                            auxQualis -> insere_lista(ano,nomeQualis);
                           // insere_lista(int ano,string qualis);
                            mapaQualis.insert(pair<string, Qualis*>(chave, qualis));
                        }
                        else
                        {
                        	mapaQualis.insert(pair<string, Qualis*>(chave, qualis));
                        	qualis = new Qualis(ano, veiculo, nomeQualis);
                        }
		}
	}

	else
	{
		cout << "Erro de I/O" << endl;
	}

	return mapaQualis;
}

Regras* Leitor:: cadastrarRegras(string file)
{
        ifstream qFile(file);
        string linha;
        list<Regras*> regras;
        Tokenizer *token;
        vector<string> elem;
        vector<string> nomesQualis = {"A1", "A2", "B1", "B2", "B3", "B4", "B5", "C"};
        getline(qFile, linha); // Primeira linha
        string dataInicio;
        string dataFim;
        map <string, int> mapaPontuacaoQualis;
        int qtdAnos;
        double pontuacaoMinima;
        double fatorMultiplicador;
        vector<string> Lqualis;
        vector<string> pontos;
        int pontosAux[4];
        int c;
        int aux;
        Regras* regra;
        if (qFile.is_open())
        {
            while (getline(qFile, linha))
            {
                token = new Tokenizer(linha, split);
			elem = token->remaining();
                for (string &e : elem)
			{
				trim(e);
			}
                dataInicio = elem[0];
                dataFim = elem[1];
                token = new Tokenizer(elem[2],','); //divide as qualis por virgula
                Lqualis = token->remaining();
                token = new Tokenizer(elem[3],',');//divide os pontos por virgula
                pontos = token->remaining();
               // qtdAnos = elem[4];
                for(c = 0;c < 4;c++)//
                {
                     stringstream(pontos[c]) >> pontosAux[c];
                }
                for(c = 0;c < 9;c++)
                {
                   // if((nomesQualis[c].compare(Lqualis[0]) > 0) )&& (nomesQualis.compare(Lqualis[0]) < 0)) || (nomesQualis.compare(Lqualis[0]) == 0)) {
                     //   mapaPontuacaoQualis.insert((pair<string,int>)(nomesQualis[c],pontosAux[0]));
                    //}/*
                //aux = (nomesQualis[0].compare(Lqualis[0]));
                		if((((nomesQualis[c].compare(Lqualis[0])) > 0) && (nomesQualis[c].compare(Lqualis[1]) < 0)) || (nomesQualis[c].compare(Lqualis[0]) == 0))
                			mapaPontuacaoQualis.insert((pair<string,int>)(nomesQualis[c],pontosAux[0]));

                		if((((nomesQualis[c].compare(Lqualis[1])) > 0) && (nomesQualis[c].compare(Lqualis[2]) < 0)) || (nomesQualis[c].compare(Lqualis[1]) == 0))
                		    mapaPontuacaoQualis.insert((pair<string,int>)(nomesQualis[c],pontosAux[1]));

                		if((((nomesQualis[c].compare(Lqualis[2])) > 0) && (nomesQualis[c].compare(Lqualis[3]) < 0)) || (nomesQualis[c].compare(Lqualis[2]) == 0))
                		    mapaPontuacaoQualis.insert((pair<string,int>)(nomesQualis[c],pontosAux[2]));

                		if((nomesQualis[c].compare(Lqualis[3]) == 0))
                		    mapaPontuacaoQualis.insert((pair<string,int>)(nomesQualis[c],pontosAux[3]));
            		}

                //if((nomesQualis[0].compare(Lqualis[0]) > 0) ))
				//fatorMultiplicador = parseDouble(elem[4],loc);
					//compare


                /*
                if ((aux.compareTo(qualisRegra[1]) > 0) && (aux.compareTo(qualisRegra[2]) < 0) || (aux.compareTo(qualisRegra[1]) == 0)) {
                    mapQualis.put(aux, Integer.parseInt(pontos[1]));
                }
                if ((aux.compareTo(qualisRegra[2]) > 0) && (aux.compareTo(qualisRegra[3]) < 0) || (aux.compareTo(qualisRegra[2]) == 0)) {
                    mapQualis.put(aux, Integer.parseInt(pontos[2]));
                }
                if ((aux.compareTo(qualisRegra[3]) == 0)) {
                    mapQualis.put(aux, Integer.parseInt(pontos[3]));
                }*/
                //}    
                fatorMultiplicador = parseDouble(elem[4],loc);
                 stringstream(elem[5]) >> qtdAnos;
                 pontuacaoMinima = parseDouble(elem[6],loc);
               /* string dataInicio;
                string dataFim;
                map <string, int> mapaPontuacaoQualis;
                double fatorMultiplicador;
                int qtdAnos;
                double pontuacaoMinima;*/
                regra = new Regras(dataInicio,dataFim,mapaPontuacaoQualis,fatorMultiplicador,qtdAnos,pontuacaoMinima);
                regras.push_back(regra);
                
                 
            }
        }
        else
	{
		cout << "Erro de I/O" << endl;
	}

        return NULL;
}

// Destrutor
Leitor:: ~Leitor()
{

}

