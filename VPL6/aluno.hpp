/* 
    Classe aluno:
        - nome(string)
        - matricula(int)
        - notas(vector(int))

        calcula media(-> double)
        get max(nota) (-> int)
        get min(nota) (-> int)

 */
#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <vector>


using namespace std;

class Aluno {
    private:
        string nome;
        int matricula;
        vector<int> notas;

    public:
        Aluno();
        Aluno(string nome, int matricula, vector<int> notas);

        void setNome(string nome);
        string getNome() const;

        void setMatricula(int matricula);
        int getMatricula() const;

        void setNotas(const vector<int>& notas);
        vector<int> getNotas() const;

        double calcularMedia();
        int getMaxNota();
        int getMinNota();
        
};

#endif