#include "aluno.hpp"
#include <algorithm>

Aluno::Aluno() : Aluno("", 0, {}) {}

Aluno::Aluno(string nome, int matricula, vector<int> notas) : nome(nome), matricula(matricula){
    this->notas = notas;
}

void Aluno::setNome(string nome) {
    this->nome = nome;
    return;
}

string Aluno::getNome() const{
    return this->nome;
}

void Aluno::setMatricula(int matricula) {
    this->matricula = matricula;
    return;
}

int Aluno::getMatricula() const{
    return this->matricula;
}

void Aluno::setNotas(const vector<int>& notas) {
    this->notas = notas;
    return;
}

vector<int> Aluno::getNotas() const{
    return this->notas;
}

double Aluno::calcularMedia() {
if (this->notas.empty()){
    return 0;
}

    double soma = 0;
    vector<int> notas = this->notas;
    for (auto& i : notas) {
        soma += i;
    }

    int n = notas.size();
    double media = soma / n;

    return media;
}

int Aluno::getMinNota() {
    int min_nota = *min_element(notas.begin(), notas.end());
    return min_nota;
}

int Aluno::getMaxNota() {
    int max_nota = *max_element(notas.begin(), notas.end());
    return max_nota;
}

