#include <stdio.h>

int main() {

    // Tabuleiro 10x10 inicializado com 0
    int tabuleiro[10][10] = {0};
    
    // Navio vertical (3 partes)
    int x = 1;
    int y = 2;

    tabuleiro[x][y] = 3;
    tabuleiro[x+1][y] = 3;
    tabuleiro[x+2][y] = 3;

    // Navio horizontal (3 partes)
    int x2 = 3;
    int y2 = 0;

    tabuleiro[x2][y2] = 3;
    tabuleiro[x2][y2+1] = 3;
    tabuleiro[x2][y2+2] = 3;

    // Mostrar coordenadas do navio vertical
    printf("Navio vertical:\n");
    printf("(%d,%d)\n", x, y);
    printf("(%d,%d)\n", x+1, y);
    printf("(%d,%d)\n", x+2, y);

    // Mostrar coordenadas do navio horizontal
    printf("\nNavio horizontal:\n");
    printf("(%d,%d)\n", x2, y2);
    printf("(%d,%d)\n", x2, y2+1);
    printf("(%d,%d)\n", x2, y2+2);

    // Mostrar o tabuleiro completo
    printf("\nTabuleiro:\n\n");

    for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
    printf("%d ", tabuleiro[i][j]);
    }
    printf("\n");
}

    return 0;
}