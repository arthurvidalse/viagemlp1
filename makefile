# Nome do programa final
PROG = programa

# Compilador
CC = g++

# Flags do compilador
CPPFLAGS = -Wall -O0 -g -pedantic

# Lista de objetos
OBJS = main.o cidade.o controladordetransito.o passageiro.o trajeto.o transporte.o viagem.o

# Regra padrão que será executada por padrão
all: $(PROG)

# Regra para criar o executável final
$(PROG): $(OBJS)
	$(CC) $(CPPFLAGS) -o $(PROG) $(OBJS)

# Regras de compilação de objetos
main.o: main.cpp cidade.h controladordetransito.h passageiro.h trajeto.h transporte.h viagem.h
	$(CC) $(CPPFLAGS) -c main.cpp -o main.o

cidade.o: cidade.cpp cidade.h
	$(CC) $(CPPFLAGS) -c cidade.cpp -o cidade.o

controladordetransito.o: controladordetransito.cpp controladordetransito.h cidade.h trajeto.h transporte.h passageiro.h viagem.h
	$(CC) $(CPPFLAGS) -c controladordetransito.cpp -o controladordetransito.o

passageiro.o: passageiro.cpp passageiro.h
	$(CC) $(CPPFLAGS) -c passageiro.cpp -o passageiro.o

trajeto.o: trajeto.cpp trajeto.h
	$(CC) $(CPPFLAGS) -c trajeto.cpp -o trajeto.o

transporte.o: transporte.cpp transporte.h
	$(CC) $(CPPFLAGS) -c transporte.cpp -o transporte.o

viagem.o: viagem.cpp viagem.h
	$(CC) $(CPPFLAGS) -c viagem.cpp -o viagem.o

# Regra de limpeza (make clean)
clean:
	del /Q core $(PROG) $(OBJS) *.o 2>nul || rm -f core $(PROG) $(OBJS) *.o