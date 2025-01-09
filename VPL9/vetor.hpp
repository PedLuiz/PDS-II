#ifndef VETOR_H
#define VETOR_H

#include <iostream>

using namespace std;

template <typename T>

class Vetor {
private:
    T* vetor;
    int capacity;
    int size;

public:
    Vetor(int n) : capacity(n) {
        vetor = new T[n];
        size = 0;
    }

    Vetor (const Vetor<T>& source) : Vetor(source.capacity) {
        this->size = source.size;

        for (int i = 0; i < this->size; i++) {
            this->vetor[i] = source.vetor[i];
        } 
    }

    void SetElemento(int index, T x) {
        if (index >= capacity || index < 0) {
            perror("Posicao invalida");
            return;
        }
        vetor[index] = x;
    }

    T GetElemento(int index) {
        if (index >= capacity || index < 0) {
            perror("Posicao invalida");
            return {};
        }
        return vetor[index];
    }

    void AdicionaElemento(T x) {
        if (size == capacity) {
            perror("Limite de capacidade do vetor ja atingido");
            return;
        }
        vetor[size] = x;
        size++;
    }

    void Imprime() {
        for (int i = 0; i < capacity; i++) {
            cout << vetor[i] << " ";
        }
        cout << endl;
    }

    ~Vetor() {
        delete[] vetor;
    }

};


#endif