#ifndef EMPRESA_H
#define EMPRESA_H

#include "Onibus.hpp"

using namespace std;

struct Empresa {
    int onibus_cadastrados;
    Onibus* onibus[20];

    Empresa();
    Onibus* adicionar_onibus(string placa, int capacidade);
    Onibus* busca_onibus(string placa);
    void imprimir_estado();
};

#endif
