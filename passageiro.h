#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H

#include <string>
#include "Cidade.h" // Add this line

class Passageiro {
private:
    std::string nome;
    std::string documento;
    Cidade* localAtual; // Make sure this matches your implementation

public:
    Passageiro(std::string nome, std::string documento);
    Passageiro(std::string nome, Cidade* localAtual); // Declare the appropriate constructor
    std::string getNome() const;
    Cidade* getLocalAtual() const;
    void setLocalAtual(Cidade* local);
};

#endif
