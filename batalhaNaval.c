#include <stdio.h>

// Função simples (verifica se posição está livre)
int podeColocar(int tabuleiro[10][10], int x, int y) {
    return tabuleiro[x][y] == 0;
}

int main() {

    int tabuleiro[10][10] = {0};

    // Navio vertical
    int x = 3;
    int y = 4;

    if (podeColocar(tabuleiro, x, y)) tabuleiro[x][y] = 3;
    if (podeColocar(tabuleiro, x+1, y)) tabuleiro[x+1][y] = 3;
    if (podeColocar(tabuleiro, x+2, y)) tabuleiro[x+2][y] = 3;

    // Navio horizontal
    int x2 = 5;
    int y2 = 3;

    if (podeColocar(tabuleiro, x2, y2)) tabuleiro[x2][y2] = 3;
    if (podeColocar(tabuleiro, x2, y2+1)) tabuleiro[x2][y2+1] = 3;
    if (podeColocar(tabuleiro, x2, y2+2)) tabuleiro[x2][y2+2] = 3;

    // Diagonal 1
    int x3 = 1;
    int y3 = 1;

    if (podeColocar(tabuleiro, x3, y3)) tabuleiro[x3][y3] = 4;
    if (podeColocar(tabuleiro, x3+1, y3+1)) tabuleiro[x3+1][y3+1] = 4;
    if (podeColocar(tabuleiro, x3+2, y3+2)) tabuleiro[x3+2][y3+2] = 4;

    // Diagonal 2
    int x4 = 1;
    int y4 = 8;

    if (podeColocar(tabuleiro, x4, y4)) tabuleiro[x4][y4] = 4;
    if (podeColocar(tabuleiro, x4+1, y4-1)) tabuleiro[x4+1][y4-1] = 4;
    if (podeColocar(tabuleiro, x4+2, y4-2)) tabuleiro[x4+2][y4-2] = 4;

    // Coordenadas
    printf("Navio vertical:\n");
    printf("(%d,%d)\n(%d,%d)\n(%d,%d)\n", x,y,x+1,y,x+2,y);

    printf("\nNavio horizontal:\n");
    printf("(%d,%d)\n(%d,%d)\n(%d,%d)\n", x2,y2,x2,y2+1,x2,y2+2);

    printf("\nNavio diagonal 1:\n");
    printf("(%d,%d)\n(%d,%d)\n(%d,%d)\n", x3,y3,x3+1,y3+1,x3+2,y3+2);

    printf("\nNavio diagonal 2:\n");
    printf("(%d,%d)\n(%d,%d)\n(%d,%d)\n", x4,y4,x4+1,y4-1,x4+2,y4-2);

    // Tabuleiro
    printf("\nTabuleiro:\n\n");

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}