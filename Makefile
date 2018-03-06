COMPILADOR := g++ -std=c++11

all: programa

programa: Leitor.o Docente.o Veiculo.o Publicacao.o Periodico.o Conferencia.o Quali.o Regras.o Recadastramento.o StringUtils.o DateUtils.o NumberUtils.o NumPunctPTBR.o Tokenizer.o
	$(COMPILADOR) -o programa main.cpp Leitor.o Docente.o Veiculo.o Publicacao.o Periodico.o Conferencia.o Quali.o Regras.o Recadastramento.o StringUtils.o DateUtils.o NumberUtils.o NumPunctPTBR.o Tokenizer.o

-include subdir.mk

clean:
	@rm -f programa *.o
