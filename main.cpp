#include <iostream>
#include <limits>
#include "ControladorDeTransito.h"

using namespace std;

void exibirMenu() {
    cout << "\n=============================\n";
    cout << "  SISTEMA DE TRANSITO URBANO\n";
    cout << "=============================\n";
    cout << "1. Cadastrar Cidade\n";
    cout << "2. Consultar Cidades\n";
    cout << "3. Cadastrar Trajeto\n";
    cout << "4. Cadastrar Transporte\n";
    cout << "5. Cadastrar Passageiro\n";
    cout << "6. Cadastrar Viagem\n";
    cout << "0. Sair\n";
    cout << "=============================\n";
    cout << "Escolha uma opção: ";
}

int main() {
    ControladorDeTransito controlador;
    int opcao;

    do {
        exibirMenu();
        cin >> opcao;

        switch (opcao) {
            case 1: {
                string nome;
                cout << "Digite o nome da cidade: ";
                cin.ignore();
                getline(cin, nome);
                controlador.cadastrarCidade(nome);
                break;
            }
            case 2:
                controlador.consultarCidades();
                break;
            case 3: {
                string origem, destino;
                char tipo;
                int distancia;
                cout << "Digite a cidade de origem: ";
                cin.ignore();
                getline(cin, origem);
                cout << "Digite a cidade de destino: ";
                getline(cin, destino);
                cout << "Digite o tipo de trajeto (A para Aquático, T para Terrestre): ";
                cin >> tipo;
                cout << "Digite a distância: ";
                cin >> distancia;
                controlador.cadastrarTrajeto(origem, destino, tipo, distancia);
                break;
            }
            case 4: {
                string nome, local;
                char tipo;
                int capacidade, velocidade, descansoDistancia, descansoTempo;
                cout << "Digite o nome do transporte: ";
                cin.ignore();
                getline(cin, nome);
                cout << "Digite o tipo do transporte (A ou T): ";
                cin >> tipo;
                cout << "Digite a capacidade: ";
                cin >> capacidade;
                cout << "Digite a velocidade: ";
                cin >> velocidade;
                cout << "Digite a distância entre descansos: ";
                cin >> descansoDistancia;
                cout << "Digite o tempo de descanso: ";
                cin >> descansoTempo;
                cout << "Digite o nome da cidade do transporte: ";
                cin.ignore();
                getline(cin, local);
                controlador.cadastrarTransporte(nome, tipo, capacidade, velocidade, descansoDistancia, descansoTempo, local);
                break;
            }
            case 5: {
                string nome, local;
                cout << "Digite o nome do passageiro: ";
                cin.ignore();
                getline(cin, nome);
                cout << "Digite a cidade atual do passageiro: ";
                getline(cin, local);
                controlador.cadastrarPassageiro(nome, local);
                break;
            }
            case 6: {
                string nomeTransporte, origem, destino;
                int n;
                vector<string> nomesPassageiros;
                cout << "Digite o nome do transporte: ";
                cin.ignore();
                getline(cin, nomeTransporte);
                cout << "Digite a cidade de origem: ";
                getline(cin, origem);
                cout << "Digite a cidade de destino: ";
                getline(cin, destino);
                cout << "Digite o número de passageiros: ";
                cin >> n;
                cin.ignore();
                for (int i = 0; i < n; ++i) {
                    string nomePassageiro;
                    cout << "Digite o nome do passageiro " << i + 1 << ": ";
                    getline(cin, nomePassageiro);
                    nomesPassageiros.push_back(nomePassageiro);
                }
                controlador.cadastrarViagem(nomeTransporte, nomesPassageiros, origem, destino);
                break;
            }
            case 0:
                cout << "Saindo do sistema. Até mais!\n";
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
        }
    } while (opcao != 0);

    return 0;
}
