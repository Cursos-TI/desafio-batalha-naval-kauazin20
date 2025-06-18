#include <stdio.h>

#define TAM 10
#define NAVIO_TAM 3
#define OCUPADO 3

int pode_colocar(int tab[TAM][TAM], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < NAVIO_TAM; i++) {
        int l = linha, c = coluna;

        if (diagonal == 1) {
            l += i; c += i;
        } else if (diagonal == 2) {
            l += i; c -= i;
        } else if (direcao == 0) { // horizontal
            c += i;
        } else if (direcao == 1) { // vertical
            l += i;
        }

        if (l < 0 || l >= TAM || c < 0 || c >= TAM || tab[l][c] != 0) {
            return 0; // fora do limite ou ocupado
        }
    }
    return 1;
}

void posicionar_navio(int tab[TAM][TAM], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < NAVIO_TAM; i++) {
        int l = linha, c = coluna;

        if (diagonal == 1) {
            l += i; c += i;
        } else if (diagonal == 2) {
            l += i; c -= i;
        } else if (direcao == 0) {
            c += i;
        } else if (direcao == 1) {
            l += i;
        }

        tab[l][c] = OCUPADO;
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0};

    // Navio 1 - Horizontal
    int l1 = 1, c1 = 2;
    if (pode_colocar(tabuleiro, l1, c1, 0, 0))
        posicionar_navio(tabuleiro, l1, c1, 0, 0);

    int l2 = 4, c2 = 5;
    if (pode_colocar(tabuleiro, l2, c2, 1, 0))
        posicionar_navio(tabuleiro, l2, c2, 1, 0);

    int l3 = 0, c3 = 0;
    if (pode_colocar(tabuleiro, l3, c3, 0, 1))
        posicionar_navio(tabuleiro, l3, c3, 0, 1);

    int l4 = 0, c4 = 9;
    if (pode_colocar(tabuleiro, l4, c4, 0, 2))
        posicionar_navio(tabuleiro, l4, c4, 0, 2);

    printf("Tabuleiro Batalha Naval (0 = água, 3 = navio):\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}