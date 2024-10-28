#include <iostream>
#include "Onibus.hpp"
#include "Empresa.hpp"
using namespace std;

int main() {
    Empresa* empresa = new Empresa();
    string placa;
    int capacidade, num_pessoas;
    Onibus* temp;

    char comando; cin >> comando;

    while (comando != 'F') {
        if (comando == 'C') {
            cin >> placa >> capacidade;
            empresa->adicionar_onibus(placa, capacidade);
        } else if (comando == 'S') {
            cin >> placa >> num_pessoas;
            temp = empresa->busca_onibus(placa);
            if (temp == nullptr) {
                cout << "ERRO : onibus inexistente" << endl;
            } else {
                temp->subir_passageiros(num_pessoas);
            }
        } else if (comando == 'D') {
            cin >> placa >> num_pessoas;
            temp = empresa->busca_onibus(placa);
            if (temp == nullptr) {
                cout << "ERRO : onibus inexistente" << endl;
            } else {
                temp->descer_passageiros(num_pessoas);
            }
        } else if (comando == 'T') {
            string placaA, placaB;
            cin >> placaA >> placaB >> num_pessoas;

            Onibus* onibusA = empresa->busca_onibus(placaA);
            Onibus* onibusB = empresa->busca_onibus(placaB);
            if ((onibusA == nullptr) || (onibusB == nullptr)) {
                cout << "ERRO : onibus inexistente" << endl; 
            } else {
                onibusA->transfere_passageiros(onibusB, num_pessoas);
            }
        } else if (comando == 'I') {
            empresa->imprimir_estado();

        } 

        cin >> comando;
    }

    return 0;
}
