#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream in("palavras.txt", fstream::in);
    string line;

    int n; in >> n;
    string words[n];

    for (int i = 0; i < n; i++) 
        in >> words[i];

    int choice; cin >> choice;
    string chave = words[choice-1];

    int map[26] = {0}; 
    for (int i = 0; i < 5; i++) 
        map[chave[i] - 'A']++;

    bool check = false;

    string erro = "";

    for (int i = 0; i < 5; i++) {
        string chute; cin >> chute;
        string wordle = "*****";
        for (int j = 0; j < 5; j++) {
            char c = chute[j];
            int index = c-'A';

            if (map[index] == 1) { // caractere esta presente na palavra
                if (chave[j] == c) { // posicao correta do caractere
                    wordle[j] = c;

                } else {
                    wordle[j] = c+32; // caractere minusculo;
                }

            } else { // caractere nao esta presente
                if (map[index] != -1) {
                    erro += c;
                    map[index]--;
                } 
            }
        }
        cout << wordle << " (" + erro + ")" << endl;

        if (chute == chave) {
            check = true;
            break;
        } 
    }

    check ? cout << "GANHOU!" : cout << "PERDEU!" << " " << chave;

    return 0;
}