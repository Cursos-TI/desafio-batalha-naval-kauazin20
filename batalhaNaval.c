#include <stdio.h>

#define TAMANHO 10
#define TAMANHO_NAVIO 3

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0}; // Inicializa tudo com 0

    // Navios
    int navio1[TAMANHO_NAVIO] = {3, 3, 3}; // Navio horizontal
    int navio2[TAMANHO_NAVIO] = {3, 3, 3}; // Navio vertical

    // Posição inicial do navio horizontal (linha, coluna)
    int linha_h = 2, coluna_h = 4;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_h][coluna_h + i] = navio1[i];
    }

    // Posição inicial do navio vertical (linha, coluna)
    int linha_v = 5, coluna_v = 7;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_v + i][coluna_v] = navio2[i];
    }

    // Impressão do tabuleiro
    printf("Tabuleiro Batalha Naval:\n\n");

    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}