#ifndef CIDADE_H
#define CIDADE_H

#include <string>

class Cidade {
private:
    std::string nome;

public:
    Cidade(std::string nome) : nome(nome) {}
    std::string getNome() const; 
};

#endif
