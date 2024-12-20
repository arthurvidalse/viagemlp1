#include "Transporte.h"

Transporte::Transporte(std::string nome, char tipo, int capacidade, int velocidade, int descansoDistancia, int descansoTempo, Cidade* localAtual)
    : nome(nome), tipo(tipo), capacidade(capacidade), velocidade(velocidade),
      descansoDistancia(descansoDistancia), descansoTempo(descansoTempo), localAtual(localAtual) {}

std::string Transporte::getNome() const {
    return nome;
}

char Transporte::getTipo() const {
    return tipo;
}

int Transporte::getCapacidade() const {
    return capacidade;
}

int Transporte::getVelocidade() const {
    return velocidade;
}

Cidade* Transporte::getLocalAtual() const {
    return localAtual;
}
