#include "Viagem.h"
#include "Transporte.h"
#include "Passageiro.h"
#include "Cidade.h"

Viagem::Viagem(Transporte* transporte, std::vector<Passageiro*> passageiros, Cidade* origem, Cidade* destino)
    : transporte(transporte), passageiros(passageiros), origem(origem), destino(destino) {}

Transporte* Viagem::getTransporte() const {
    return transporte;
}

std::vector<Passageiro*> Viagem::getPassageiros() const {
    return passageiros;
}

Cidade* Viagem::getOrigem() const {
    return origem;
}

Cidade* Viagem::getDestino() const {
    return destino;
}
