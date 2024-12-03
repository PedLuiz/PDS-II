#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <sstream>

using namespace std;


int main() {
    string nome_arquivo; cin >> nome_arquivo;

    ifstream in(nome_arquivo, fstream::in);

    string texto = "";
    string palavra; 

    while(in >> palavra) {
        texto += " " + palavra;
    }
    int txt_size = texto.size();
    for(int i = 0; i < txt_size; i++) {
        texto[i] = tolower(texto[i]);
        if (!isalnum(texto[i])){
            texto[i] = ' ';
        }
        
    }

    map<string,int> counter; 
    istringstream buffer(texto);

    while (buffer >> palavra){
        counter[palavra]++;
    }

    return 0;
}