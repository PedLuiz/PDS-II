#include <iostream>
#include <algorithm>
#include "aluno.hpp"


using namespace std;

void printVector(const vector<int> v) {
    for (auto& i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<Aluno> alunos;

    while (true) {
        string nome; cin >> nome;
        if (nome == "END") {
            break;
        }

        int matricula; cin >> matricula;

        vector<int> notas;
        while (true) {
            int nota; cin >> nota;
            if (nota == -1) {
                break;
            }
            notas.push_back(nota);
        }

        Aluno aluno(nome, matricula, notas);
        alunos.push_back(aluno);
    }

    sort(alunos.begin(), alunos.end(), [](const Aluno& a, const Aluno& b){
        return a.getNome() < b.getNome();
    });

    for (auto& i : alunos) {
        int matricula = i.getMatricula();
        string nome = i.getNome();
        vector<int> notas = i.getNotas(); 

        cout << matricula << " " << nome << " ";
        printVector(notas);
        
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << i.calcularMedia() << " " << i.getMaxNota() << " " << i.getMinNota() << endl;
    }

    return 0;
}