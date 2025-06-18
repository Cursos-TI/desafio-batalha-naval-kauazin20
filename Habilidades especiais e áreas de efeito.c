#include <stdio.h>

#define TAM 10
#define TAM_HAB 5

void imprimir_matriz(const char* nome, int matriz[TAM_HAB][TAM_HAB]) {
    printf("\nMatriz de Habilidade: %s\n\n", nome);
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int tabuleiro[TAM][TAM] = {0};

    int cone[TAM_HAB][TAM_HAB] = {0};
    int meio = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = meio - i; j <= meio + i; j++) {
            if (j >= 0 && j < TAM_HAB) {
                cone[i][j] = 1;
            }
        }
    }

    int cruz[TAM_HAB][TAM_HAB] = {0};
    for (int i = 0; i < TAM_HAB; i++) {
        cruz[i][meio] = 1;        
        cruz[meio][i] = 1;        
    }
    int octaedro[TAM_HAB][TAM_HAB] = {0};
    for (int i = 0; i <= meio; i++) {
        for (int j = meio - i; j <= meio + i; j++) {
            octaedro[i][j] = 1;
            octaedro[TAM_HAB - i - 1][j] = 1;
        }
    }
    imprimir_matriz("Cone", cone);
    imprimir_matriz("Cruz", cruz);
    imprimir_matriz("Octaedro", octaedro);

    return 0;
}