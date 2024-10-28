#include "Empresa.hpp"
#include "Onibus.hpp"
#include <iostream>

using namespace std;

Empresa::Empresa() {
    onibus_cadastrados = 0;
    Onibus* onibus[20] = {nullptr};
}

Onibus* Empresa::adicionar_onibus(string placa, int capacidade) {
    if (busca_onibus(placa) != nullptr) {
        cout << "ERRO : onibus repetido" << endl;
        return nullptr;
    }
    if (onibus_cadastrados > 20) {
        cout << "ERRO : limite de onibus excedido" << endl;
        return nullptr;
    }

    onibus_cadastrados++;
    int index = onibus_cadastrados - 1;

    onibus[index] = new Onibus(placa, capacidade);
    cout << "novo onibus cadastrado" << endl;

    return onibus[index];
}

Onibus* Empresa::busca_onibus(string placa) {
    for (int i = 0; i < onibus_cadastrados; i++) {
        if (onibus[i]->placa == placa) {
            return onibus[i];
        }
    }
    return nullptr;
}

void Empresa::imprimir_estado(){
    for (int i = 0; i < onibus_cadastrados; i++) {
        onibus[i]->imprimir_estado();
    }
    return;
}
