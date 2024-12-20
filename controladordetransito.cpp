#include "ControladorDeTransito.h"
#include <iostream>

ControladorDeTransito::ControladorDeTransito() {}

void ControladorDeTransito::cadastrarCidade(std::string nome) {
    cidades.push_back(new Cidade(nome));
    std::cout << "Cidade cadastrada: " << nome << std::endl;
}

void ControladorDeTransito::consultarCidades() const {
    if (cidades.empty()) {
        std::cout << "Nenhuma cidade cadastrada." << std::endl;
    } else {
        std::cout << "Cidades cadastradas:" << std::endl;
        for (const Cidade* cidade : cidades) {
            std::cout << "- " << cidade->getNome() << std::endl;
        }
    }
}

void ControladorDeTransito::cadastrarTrajeto(std::string origemNome, std::string destinoNome, char tipo, int distancia) {
    Cidade* origem = nullptr;
    Cidade* destino = nullptr;

    for (Cidade* cidade : cidades) {
        if (cidade->getNome() == origemNome) origem = cidade;
        if (cidade->getNome() == destinoNome) destino = cidade;
    }

    if (origem && destino) {
        trajetos.push_back(new Trajeto(origem, destino, tipo, distancia));
        std::cout << "Trajeto cadastrado com sucesso." << std::endl;
    } else {
        std::cout << "Erro: Cidade de origem ou destino não encontrada." << std::endl;
    }
}

void ControladorDeTransito::cadastrarTransporte(std::string nome, char tipo, int capacidade, int velocidade, int descansoDistancia, int descansoTempo, std::string localNome) {
    Cidade* local = nullptr;

    for (Cidade* cidade : cidades) {
        if (cidade->getNome() == localNome) {
            local = cidade;
            break;
        }
    }

    if (local) {
        transportes.push_back(new Transporte(nome, tipo, capacidade, velocidade, descansoDistancia, descansoTempo, local));
        std::cout << "Transporte cadastrado com sucesso." << std::endl;
    } else {
        std::cout << "Erro: Cidade não encontrada." << std::endl;
    }
}

void ControladorDeTransito::cadastrarPassageiro(std::string nome, std::string localNome) {
    Cidade* local = nullptr;

    for (Cidade* cidade : cidades) {
        if (cidade->getNome() == localNome) {
            local = cidade;
            break;
        }
    }

    if (local) {
        passageiros.push_back(new Passageiro(nome, local));
        std::cout << "Passageiro cadastrado com sucesso." << std::endl;
    } else {
        std::cout << "Erro: Cidade não encontrada." << std::endl;
    }
}

void ControladorDeTransito::cadastrarViagem(std::string nomeTransporte, std::vector<std::string> nomesPassageiros, std::string origemNome, std::string destinoNome) {
    Transporte* transporte = nullptr;
    Cidade* origem = nullptr;
    Cidade* destino = nullptr;
    std::vector<Passageiro*> viagemPassageiros;

    for (Transporte* t : transportes) {
        if (t->getNome() == nomeTransporte) {
            transporte = t;
            break;
        }
    }

    for (Cidade* cidade : cidades) {
        if (cidade->getNome() == origemNome) origem = cidade;
        if (cidade->getNome() == destinoNome) destino = cidade;
    }

    for (const std::string& nome : nomesPassageiros) {
        for (Passageiro* p : passageiros) {
            if (p->getNome() == nome) {
                viagemPassageiros.push_back(p);
                break;
            }
        }
    }

    if (transporte && origem && destino && !viagemPassageiros.empty()) {
        viagens.push_back(new Viagem(transporte, viagemPassageiros, origem, destino));
        std::cout << "Viagem cadastrada com sucesso." << std::endl;
    } else {
        std::cout << "Erro: Dados inválidos para cadastro da viagem." << std::endl;
    }
}

ControladorDeTransito::~ControladorDeTransito() {
    for (Cidade* cidade : cidades) delete cidade;
    for (Trajeto* trajeto : trajetos) delete trajeto;
    for (Transporte* transporte : transportes) delete transporte;
    for (Passageiro* passageiro : passageiros) delete passageiro;
    for (Viagem* viagem : viagens) delete viagem;
}
