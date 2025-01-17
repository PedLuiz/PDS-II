#include "Liga4.hpp"
#include <iostream>

using namespace std;

// Constructor: Initializes the board (7 rows, 6 columns)
Liga4::Liga4() : Jogo(7, 6) {}  // 7 rows, 6 columns

// Method to check the winner by checking rows, columns, and diagonals.
char Liga4::getVencedor() {
    // Check all positions for a potential winner
    for (int linha = 0; linha < 7; linha++) {  // Iterate through rows (0 to 6)
        for (int coluna = 0; coluna < 6; coluna++) {  // Iterate through columns (0 to 5)
            char jogador = tabuleiro[linha][coluna];  // Correct access [linha][coluna]
            if (jogador != ' ') {
                // Check horizontal
                if (coluna + 3 < 6 && jogador == tabuleiro[linha][coluna + 1] &&
                    jogador == tabuleiro[linha][coluna + 2] && jogador == tabuleiro[linha][coluna + 3]) {
                    return jogador;
                }
                // Check vertical
                if (linha + 3 < 7 && jogador == tabuleiro[linha + 1][coluna] &&
                    jogador == tabuleiro[linha + 2][coluna] && jogador == tabuleiro[linha + 3][coluna]) {
                    return jogador;
                }
                // Check diagonal descending
                if (linha + 3 < 7 && coluna + 3 < 6 && jogador == tabuleiro[linha + 1][coluna + 1] &&
                    jogador == tabuleiro[linha + 2][coluna + 2] && jogador == tabuleiro[linha + 3][coluna + 3]) {
                    return jogador;
                }
                // Check diagonal ascending
                if (linha - 3 >= 0 && coluna + 3 < 6 && jogador == tabuleiro[linha - 1][coluna + 1] &&
                    jogador == tabuleiro[linha - 2][coluna + 2] && jogador == tabuleiro[linha - 3][coluna + 3]) {
                    return jogador;
                }
            }
        }
    }
    return ' '; // No winner
}

// Method to check if the game has ended.
bool Liga4::isEstadoFinal() {
    if (getVencedor() != ' ') 
        return true;

    // Check if the board is full by checking the first row of each column
    for (int coluna = 0; coluna < 6; coluna++) {  // Iterate through columns
        if (tabuleiro[0][coluna] == ' ')  // Check if there's any space in the first row
            return false;
    }

    return true; // Board is full or there's a winner
}

// Method to get the current player's turn.
char Liga4::getTurno() {
    return turno_atual;
}

// Method to switch the turn after each valid move.
void Liga4::setTurno() {
    if (turno_atual == 'X')
        turno_atual = 'O';
    else if (turno_atual == 'O')
        turno_atual = 'X';
    else
        cerr << "Erro Inesperado: turno_atual possui um valor inválido (" << turno_atual << " )." << endl;
}

// Method to make a move based on the given pair (row, column).
void Liga4::fazerJogada(pair<int, int> jogada) {
    int coluna = jogada.first - 1;  // Convert from 1-based index to 0-based

    if (!isJogadaValida(jogada)) {
        return;  // If the move is invalid, don't proceed
    }

    // Check if the column is within valid range (0 to 5)
    if (coluna < 0 || coluna >= 6) {
        cerr << "ERRO: Coluna fora dos limites!" << endl;
        return;
    }

    // Loop from row 0 (top) to row 6 (bottom) to find the first available space
    for (int linhaIdx = 6; linhaIdx >= 0; linhaIdx--) {  // Iterate through rows (0 to 6)
        if (tabuleiro[linhaIdx][coluna] == ' ') {  // Check for an empty space
            tabuleiro[linhaIdx][coluna] = turno_atual;  // Place the current player's token
            setTurno();  // Switch turn
            return;
        }
    }
}

// Method to check if the move is valid (i.e., the column is not full).
bool Liga4::isJogadaValida(pair<int, int> jogada) {
    int coluna = jogada.first;

    // Check if the column is within valid range (1 to 6)
    if (coluna >= 1 && coluna <= 6) {
        if (tabuleiro[0][coluna - 1] == 'X' || tabuleiro[0][coluna - 1] == 'O') {  // Check if the column is full
            cout << "ERRO: Coluna escolhida já foi totalmente preenchida!" << endl;
            return false;
        } else {
            return true;
        }
    } else {
        cout << "ERRO: Coluna Inválida! Escolha entre 1 e 6" << endl;
        return false;
    }
}

// Method to print the board.
void Liga4::printTabuleiro() {
    // Loop through rows (7 rows) and columns (6 columns)
    for (int linha = 0; linha < 7; linha++) {  // Iterate through rows (0 to 6)
        for (int coluna = 0; coluna < 6; coluna++) {  // Iterate through columns (0 to 5)
            cout << "| " << tabuleiro[linha][coluna] << " ";  // Correct access [linha][coluna]
        }
        cout << "|" << endl << endl;
    }

    // Print column numbers
    cout << "  1   2   3   4   5   6" << endl;
    cout << "===========COLUNAS===========" << endl << endl; // To indicate the columns
}

// Destructor: Clean up if necessary.
Liga4::~Liga4() {}
