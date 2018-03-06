/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Recadastramento.cpp
 * Author: Eduarda
 * 
 * Created on 15 de Julho de 2017, 15:05
 */

#include "Recadastramento.h"
#include <fstream>

using namespace std;

Recadastramento:: Recadastramento()
{

}

Docente* Recadastramento:: retornaDocentePorCodigo(string codigo)
{
	return this->docentes.find(codigo)->second;
}

Veiculo* Recadastramento:: retornaVeiculoPorSigla(string sigla)
{
	return this->veiculos.find(sigla)->second;
}

Qualis* Recadastramento:: retornaQualis(string qualis)
{
	return this->qualis.find(qualis)->second;
}

void Recadastramento:: adicionaMapaDocentes(map<string, Docente*> mapa)
{
	this->docentes = mapa;
}

void Recadastramento:: adicionaMapaVeiculos(map<string, Veiculo*> mapa)
{
	this->veiculos = mapa;
}

void Recadastramento:: adicionaListaPublicacoes(list<Publicacao*> lista)
{
	this->publicacoes = lista;
}

void Recadastramento:: adicionaMapaQualis(map<string, Qualis*> mapa)
{
	this->qualis = mapa;
}
int Recadastramento::verificaSeJaExisteQualisParaVeiculo(string nomeVeiculo)
{
    if(this->qualis.find(nomeVeiculo) != this->qualis.end())
        return 1;
    else
        return 0;
}
list<PublicacaoEQualis*> Recadastramento:: geraRelatoriodePublicacoes()
{
	ofstream out("2-publicacoes.csv");
	//FILE* f = fopen("Publicacoes.csv","w");
	list<PublicacaoEQualis*> PQ;
	list<Publicacao>:: iterator itpub = this -> publicacoes.begin();
	list<PublicacaoEQualis>:: iterator itpubQ;
	Publicacao* pub;
	Veiculo* veiculo;
	string sigla;
	Qualis* qualis;
	PublicacaoEQualis* pq;
	list<Docente*> listdoc;
	list<Docente*>:: iterator itdoc;
	Docente* docente;
	int ano;
	if(!out.good)
	{
			while(itpub != this -> publicacoes.end())
			{
				sigla = itpub ->  retornaVeiculo() -> getSigla();
				qualis = this -> qualis.find(sigla);
				pq = new PublicacaoEQualis(itpub,qualis);
				PQ.push_back(pq);
			}
			PQ.sort(PublicacaoEQualis:: compara_publicacaoEqualis);
			//out.printf("\n");
			out << "Ano;Sigla Veículo;Veículo;Qualis;Fator de Impacto;Título;Docentes" << endl;
			itpubQ = PQ.begin();
			while(itpubQ != PQ.end())
			{
				qualis = itpubQ -> getQualis();
				pub = itpubQ -> getPublicacao();
				ano = pub -> getAno();
				out.precision(3);
				out << pub -> getAno() + ";" + pub -> retornaVeiculo() -> getSigla() + pub->retornaVeiculo()->getNome() + ";";
				//out <<  qualis -> retorna_nome_qualis(pub -> getAno) << endl;
				out <<  qualis -> retorna_nome_qualis(ano) + ";" + pub -> retornaVeiculo() -> getFatorImpactante() + ";" + pub -> getTitulo() + ";" ;
				listdoc = pub -> getListaDocentes();
				itdoc = listdoc.begin();
				while(itdoc != listdoc.end())
				{
					//itdoc -> getNome();
					docente = itdoc;
					out << docente -> getNome() ;
					itdoc++;
					if(itdoc != listdoc.end())
					out<<",";
				}
				out<<"\n";
				itpubQ++;
			}
			//fprintf(f,"Ano;Sigla Veículo;Veículo;Qualis;Fator de Impacto;Título;Docentes%n");
			/*

			  gravarArq.printf("%d;%s;%s;", publicacao.getAno(), publicacao.retornaVeiculo().getSigla(), publicacao.retornaVeiculo().getNome());
            gravarArq.printf("%s;%.3f;%s;", qualis.getNomeQualis(), publicacao.retornaVeiculo().getFatorDeImpacto(), publicacao.getTitulo());
            aux = "ano" + publicacao.getAno() + "sigla" + publicacao.retornaVeiculo().getSigla();
            docentes = publicacao.getListaDocentes();

            counter = 0;
            while (counter < docentes.size()) {
                docente = docentes.get(counter);
                gravarArq.printf("%s", docente.getNome());
                if ((counter + 1) < docentes.size()) {
                    gravarArq.printf(",");
                }

			 */
			return PQ;
	}
	else
	{
		cout << "Erro";
	}
	return NULL;
	//fclose(f);

}
void Recadastramento:: geraEstatisticasdePublicacoes(list<PublicacaoEQualis*> PQ)
{
	ofstream out("3-estatisticas.csv");
	list<PublicacaoEQualis>:: iterator itpubq;
	int num[8];
	vector<string> nomesQualis = {"A1", "A2", "B1", "B2", "B3", "B4", "B5", "C"};
	vector<int> numPub= {0,0,0,0,0,0,0,0};
	Publicacao* pub;
	Qualis* qualis;
	string nomeQualis;
	int ano,c;
	int counter = 0;
	double numAutores;
	if(!out.good)
	{
		out<< "Qualis;Qtd. Artigos;Média Artigos / Docente" << endl;
		itpubq = PQ.begin();
		while(itpubq != PQ.end())
		{
			pub = itpubq -> getPublicacao();
			qualis = itpubq -> getQualis();
			ano = pub -> getAno();
			nomeQualis = qualis -> retorna_nome_qualis(ano);
			for(c = 0;c < 9;c++)
			{
				if(nomeQualis.compare(nomesQualis[c]) == 0)
					numPub[c]++;
			}
			numAutores = 1 / (pub -> getNumAutores());
			out.precision(2);
			out<< nomesQualis[counter]+ ";" + numPub[counter] + ";" + numAutores << endl;
		}
	}
	else
	{
		cout << "erro";
	}
}
Regras* Recadastramento:: getRegraDoAno(int ano)
{
	list<Regras*>:: iterator it = this -> regras.begin();
	Regras* regra;
	while(it!= this -> regras.end())
	{
		regra = it;
		if(ano == regra -> getAnoInicio())
			return regra;
		it++;
	}
	return NULL;
}
void Recadastramento:: gerarRecredenciamento(int ano)
{
	//map<string,Docente>::iterator it = this->docentes.begin();
	map<string,Docente>::iterator it = this->docentes.begin();
	list<Docente*> listDoc;
	Docente* docente;
	ofstream out("1-recredenciamento.csv");
	if(!out.good)
	{
			while(it != docentes.end())
			{
				docente = it;
				listDoc.push_back(docente);
				it++;
			}
			listDoc.sort(Docente:: comparaDocenteNome);
			/*

			 Iterator<Docente> itList = ListaDocentes.iterator();
        Iterator<Publicacao> itPublicacao;
        String codigo;
        Publicacao publicacao;
        double pontos;
        Veiculo veiculo;
        int ponto;
        Integer qualquer;
        String nomeQualis;
        double pontosPublicacao;
        int counter;
        boolean aux;

			 */
			list<Docente>::iterator itdoc = listDoc.begin();
			list<Publicacao>::iterator itpub;
			string codigo;
			Publicacao publicacao;
			double pontos;
			Veiculo* veiculo;
			int ponto;
			string nomeQualis;
			double pontosPublicacao;
			Docente* doc;
			Regras* regra = getRegraDoAno(ano);
			int ano1 = regra -> getAnoInicio();
			while(itdoc != listDoc.end())
			{
				doc = itdoc;
				pontos = doc->calcula_pontuacao_docente(regra,this->publicacoes,this->qualis);
				out.precision(2);
				out << doc->getNome() + ";" + pontos + ";";
				if(doc -> eCoordenador())
					out << "Coordenador" << endl;
				else
				{
				if(doc -> maisde60oumenosde3(regra -> getAnoInicio()) < 0)
					out << "PPJ" << endl;
					else
					{
						if(doc -> maisde60oumenosde3(regra -> getAnoInicio()) > 0)
											out << "PPS" << endl;
						else
						{
							if(pontos >= regra -> getPontuacaoMinima())
								out << "SIM" << endl;
							else
								out << "NAO" << endl;
						}
					}
				}

				itdoc++;
			}
	}
	else
	cout << "Erro";


}
//void Recadastramento:: adicionaRegras(Regras *regra)
//{
//	this->regra = regra;
//}
PublicacaoEQualis:: PublicacaoEQualis(Publicacao* publicacao, Qualis* qualis) {
        this -> publicacao = publicacao;
        this -> qualis = qualis;
    }

     Publicacao PublicacaoEQualis:: getPublicacao() {
        return this -> publicacao;
    }

     Qualis PublicacaoEQualis:: getQualis() {
        return this -> qualis;
    }

     //comparaPublicacao(Publicacao* ant,Publicacao* pos)
    bool PublicacaoEQualis:: compara_publicacaoEqualis(PublicacaoEQualis* ant,PublicacaoEQualis* pos)
    {
    	Publicacao* pant = ant -> publicacao;
    	Qualis* qant = ant -> qualis;
    	Publicacao* ppos = pos -> publicacao;
    	Qualis* qpos = pos -> qualis;
    	if(qant -> compara_qualis(qant,pant,qpos,ppos) == true)
    	{
    		return true;
    	}
    	else
    	{
    		if(qant -> compara_qualis(qant,pant,qpos,ppos) == false)
    			return false;
    		else
    		{
    			return ant -> publicacao -> comparaPublicacao(ant -> publicacao,pos -> publicacao);
    		}
    	}
    }
