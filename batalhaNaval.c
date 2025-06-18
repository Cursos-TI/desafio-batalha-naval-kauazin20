#include <stdio.h>

#define TAMANHO 10
#define TAMANHO_NAVIO 3

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0}; 

    // Navios
    int navio1[TAMANHO_NAVIO] = {3, 3, 3}; 
    int navio2[TAMANHO_NAVIO] = {3, 3, 3}; 
    
    int linha_h = 2, coluna_h = 4;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_h][coluna_h + i] = navio1[i];
    }

    int linha_v = 5, coluna_v = 7;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_v + i][coluna_v] = navio2[i];
    }

    printf("Tabuleiro Batalha Naval:\n\n");

    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}