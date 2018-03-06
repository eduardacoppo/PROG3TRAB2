Docente.o: Docente.cpp Docente.h
	$(COMPILADOR) -o Docente.o -c Docente.cpp

Veiculo.o: Veiculo.cpp Veiculo.h
	$(COMPILADOR) -o Veiculo.o -c Veiculo.cpp

Leitor.o: Leitor.cpp Leitor.h
	$(COMPILADOR) -o Leitor.o -c Leitor.cpp

Publicacao.o: Publicacao.cpp Publicacao.h
	$(COMPILADOR) -o Publicacao.o -c Publicacao.cpp

Periodico.o: Periodico.cpp Periodico.h
	$(COMPILADOR) -o Periodico.o -c Periodico.cpp

Conferencia.o: Conferencia.cpp Conferencia.h
	$(COMPILADOR) -o Conferencia.o -c Conferencia.cpp

Qualis.o: Qualis.cpp Qualis.h
	$(COMPILADOR) -o Qualis.o -c Qualis.cpp

Regras.o: Regras.cpp Regras.h
	$(COMPILADOR) -o Regras.o -c Regras.

Recadastramento.o: Recadastramento.cpp Recadastramento.h
	$(COMPILADOR) -o Recadastramento.o -c Recadastramento.cpp

DateUtils.o: DateUtils.cpp DateUtils.h
	$(COMPILADOR) -o DateUtils.o -c DateUtils.cpp

NumberUtils.o: NumberUtils.cpp NumberUtils.h
	$(COMPILADOR) -o NumberUtils.o -c NumberUtils.cpp

NumPunctPTBR.o: NumPunctPTBR.cpp NumPunctPTBR.h
	$(COMPILADOR) -o NumPunctPTBR.o -c NumPunctPTBR.cpp

StringUtils.o: StringUtils.cpp StringUtils.h
	$(COMPILADOR) -o StringUtils.o -c StringUtils.cpp

Tokenizer.o: Tokenizer.cpp Tokenizer.h
	$(COMPILADOR) -o Tokenizer.o -c Tokenizer.cpp
