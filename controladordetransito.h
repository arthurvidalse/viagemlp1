#ifndef CONTROLADOR_DE_TRANSITO_H
#define CONTROLADOR_DE_TRANSITO_H

#include "Cidade.h"
#include "Trajeto.h"
#include "Transporte.h"
#include "Passageiro.h"
#include "Viagem.h"
#include <vector>
#include <string>

class ControladorDeTransito {
private:
    std::vector<Cidade*> cidades;
    std::vector<Trajeto*> trajetos;
    std::vector<Transporte*> transportes;
    std::vector<Passageiro*> passageiros;
    std::vector<Viagem*> viagens;

public:
    ControladorDeTransito();

    void cadastrarCidade(std::string nome);
    void consultarCidades() const;

    void cadastrarTrajeto(std::string origemNome, std::string destinoNome, char tipo, int distancia);
    void cadastrarTransporte(std::string nome, char tipo, int capacidade, int velocidade, int descansoDistancia, int descansoTempo, std::string localNome);
    void cadastrarPassageiro(std::string nome, std::string localNome);
    void cadastrarViagem(std::string nomeTransporte, std::vector<std::string> nomesPassageiros, std::string origemNome, std::string destinoNome);

    ~ControladorDeTransito();
};

#endif
