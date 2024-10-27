#include "Onibus.hpp"
#include <iostream>
using namespace std;

Onibus::Onibus(string placa, int CAPACITY) {
    this->placa = placa;
    this->CAPACITY = CAPACITY;
    this->current_size = 0;
}

void Onibus::subir_passageiros(int qtd_passageiros) {
    if (CAPACITY - current_size >= qtd_passageiros) {
        current_size += qtd_passageiros;
        cout << "passageiros subiram com sucesso" << endl;
    } else {
        cout << "ERRO: onibus lotado" << endl;
    }

    return;
}

void Onibus::descer_passageiros(int qtd_passageiros) {
    if (current_size >= qtd_passageiros) {
        current_size -= qtd_passageiros;
        cout << "passageiros desceram com sucesso" << endl;
    } else {
        cout << "ERRO: faltam passageiros" << endl;
    }

    return;
}

void Onibus::transfere_passageiros(Onibus* onibus_destino, int qtd_passageiros) {
    int vagas_onibus_destino = onibus_destino->CAPACITY - onibus_destino->current_size;
    if ((this->current_size < qtd_passageiros) || (vagas_onibus_destino < qtd_passageiros)){
        cout << "ERRO: transferencia cancelada" << endl;
        return;
    }

    this->current_size -= qtd_passageiros;
    onibus_destino->current_size += qtd_passageiros;
    cout << "tranferencia de passageiros efetuada" << endl;
    return;
}

void Onibus::imprimir_estado() {
    cout << placa << " (" << current_size << "/" << CAPACITY << ")" << endl; 
}