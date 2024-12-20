#ifndef TRANSPORTE_H
#define TRANSPORTE_H

#include "Cidade.h"
#include <string>

class Transporte {
private:
    std::string nome;
    char tipo;
    int capacidade;
    int velocidade;
    int descansoDistancia;
    int descansoTempo;
    Cidade* localAtual;

public:
    Transporte(std::string nome, char tipo, int capacidade, int velocidade, int descansoDistancia, int descansoTempo, Cidade* localAtual);

    std::string getNome() const;
    char getTipo() const;
    int getCapacidade() const;
    int getVelocidade() const;
    Cidade* getLocalAtual() const;
};

#endif
