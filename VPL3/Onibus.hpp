#ifndef ONIBUS_H
#define ONIBUS_H

#include <string>

struct Onibus {
    std::string placa;
    int CAPACITY;
    int current_size;

    Onibus();
    Onibus(std::string placa, int CAPACITY); 
    void subir_passageiros(int num_passageiros); 
    void descer_passageiros(int num_passageiros);
    void transfere_passageiros(Onibus* onibus_destino, int num_passageiros);
    void imprimir_estado();
};

#endif
