#include <iostream>

using namespace std;
// 0) Crie uma função que receba três variveis inteiras como parâmetro, da seguinte forma:
//    - A primeira deve ser passada por valor
//    - A segunda deve ser passada por referência 
//    - A terceira deve ser passada "por referência" usando apontadores (passagem "por referência" disponível em C)
//    A função deverá somar 1 ao valor de cada uma das 3 variáveis e retornar.
void soma3 (int a, int &b, int* c) {
    a++; b++; *(c)++;
    return;
}


int main(){

    // 1) Declare uma variável do tipo inteiro e preencha com o valor informado na entrada
    int a; cin >> a;
    
    // 2) Declare um ponteiro para inteiros e inicialize com valor nulo
    int* b = nullptr; 

    // 3) Declare um vetor de inteiros com tamanho informado na entrada e preencha com dados lidos da entrada
    int n; cin >> n;
    int vetor[n];
    for (int i = 0; i < n; i++) {
        cin >> vetor[i];
    } 

    // 4) Imprima o ENDEREÇO da variável declarada em (1)
    cout << &a << endl;

    // 5) Imprima o VALOR da variável declarada em (1)
    cout << a << endl; 

    // 6) Imprima o ENDEREÇO da variável declarada em (2)
    cout << &b << endl;
    
    // 7) Imprima o VALOR da variável declarada em (2)
    cout << b << endl;

    // 8) Imprima o ENDEREÇO da variável declarada em (3)
    cout << &n << endl; 

    // 9) Imprima o ENDEREÇO da primeira posição da variável declarada em (3)
    cout << &vetor[0] << endl;

    // 10) Imprima o VALOR da primeira posição da variável declarada em (3)
    cout << vetor[0] << endl;

    // 11) Atribua o ENDEREÇO da variável declarada em (1) à variável declarada em (2)
    b = &a;

    // 12) Imprima o VALOR da variável declarada em (2)
    cout << b << endl;

    // 13) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *b << endl;

    // 14) Coloque o VALOR '5' no ENDEREÇO apontado por (2)
    *b = 5;

    // 15) Imprima o VALOR da variável declarada em (1)
    cout << a << endl;

    // 16) Atribua o VALOR da variável (3) à variável declarada em (2)
    *b = vetor[0];

    // 17) Imprima o VALOR da variável declarada em (2)
    cout << b << endl;

    // 18) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *b << endl; 

    // 19) Atribua o ENDEREÇO da primeira posição de (3) à variável declarada em (2)
    b = &vetor[0];

    // 20) Compare o valor variáveis (2) e (3), imprimindo 'S' se forem iguais e 'N' se forem diferentes
    *b == vetor[0] ? cout << "S" : cout << "N";
    cout << endl;

    // 21) Imprima o VALOR da variável declarada em (2)
    cout << b << endl;

    // 22) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *b << endl;

    // 23) Multiplique todos os valores do vetor declarado em (3) por '10', porém manipulando apenas a variável (2)
    for (int i = 0; i < n; i++) {
        *(b+i) *= 10;
    }

    // 24) Imprima os elementos de (3) a partir variável do vetor utilizando a notação [] (colchetes)
    cout << vetor[0];
    for (int i = 1; i < n; i++) {
        cout << " " << vetor[i] ;
    }
    cout << endl;
    // 25) Imprima os elementos de (3) a partir variável do vetor utilizando a notação ponteiro/deslocamento
    // Ou seja, você NÃO deve efetivamente alterar o valor do ponteiro inicial de (3)
    cout << *(vetor);
    for (int i = 1; i < n; i++) {
        cout << " " << *(vetor+i);
    }
    cout << endl;
    // 26) Imprima os elementos de (3) utilizando a variável (2) e a notação ponteiro/deslocamento
    // Ou seja, você NÃO deve efetivamente alterar o valor do ponteiro inicial de (2)
    cout << *b;
    for (int i = 0; i < n; i++) {
        cout << " " << *(b + i);
    }
    cout << endl;
    // 27) Atribua o ENDEREÇO da última posição de (3) à variável declarada em (2)
    b = &vetor[n-1];

    // 28) Imprima o VALOR da variável declarada em (2)
    cout << b << endl; 

    // 29) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *b << endl; 

    // 30) Declare um ponteiro para ponteiro e o inicialize com o ENDEREÇO da variável (2)
    int** pp = &b;

    // 31) Imprima o VALOR da variável declarada em (30)
    cout << pp << endl;

    // 32) Imprima o ENDEREÇO da variável declarada em (30)
    cout << &pp << endl;

    // 33) Imprima o VALOR guardado no ENDEREÇO apontado por (30)
    cout << *pp << endl; 

    // 34) Imprima o VALOR guardado no ENDEREÇO do ponteiro apontado por (30)
    cout << **pp << endl; 

    // 35) Crie 3 variáveis interiras e leia o valor delas da entrada
    int var1, var2, var3;
    cin >> var1 >> var2 >> var3;

    // 36) Chame a função criada em (0) passando as 3 variáveis criadas em (35) como parâmetro.
    soma3(var1, var2, &var3);
    
    // 37) Imprima o valor das 3 variáveis criadas em (35)
    cout << var1 << " " << var2 << " " << var3 << endl;
    return 0;
}