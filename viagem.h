#ifndef VIAGEM_H
#define VIAGEM_H

#include <vector>
#include "Transporte.h"
#include "Passageiro.h"
#include "Cidade.h"

class Viagem {
private:
    Transporte* transporte;
    std::vector<Passageiro*> passageiros;
    Cidade* origem;
    Cidade* destino;

public:
    Viagem(Transporte* transporte, std::vector<Passageiro*> passageiros, Cidade* origem, Cidade* destino);

    Transporte* getTransporte() const;
    std::vector<Passageiro*> getPassageiros() const;
    Cidade* getOrigem() const;
    Cidade* getDestino() const;
};

#endif
