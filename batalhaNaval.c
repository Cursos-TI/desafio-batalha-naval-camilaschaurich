#include <stdio.h>
#include <stdlib.h>

// Função simples (verifica se posição está livre)
int podeColocar(int tabuleiro[10][10], int x, int y) {
    return tabuleiro[x][y] == 0;
}

int main() {

    // Tabuleiro 10x10 inicializado com 0
    int tabuleiro[10][10] = {0};

    // Matrizes das habilidades
    int cone[5][5] = {0};
    int cruz[5][5] = {0};
    int octaedro[5][5] = {0};

    // Cone
    for(int i = 0; i < 5; i++)
    {
       for(int j = 0; j < 5; j++)
       {
         if((i == 0 && j == 2) ||
           (i == 1 && j >= 1 && j <= 3) ||
           (i == 2 && j >= 0 && j <= 4))
        {
            cone[i][j] = 1;
        }
    }
}
    
    // Cruz
    for(int i = 0; i < 5; i++)
    {
       for(int j = 0; j < 5; j++)
       {
         if(i == 2 || j == 2)
         {
            cruz[i][j] = 1;
         }
    }
}

    // Octaedro
    for(int i = 0; i < 5; i++)
    {
       for(int j = 0; j < 5; j++)
       {
         if(abs(i - 2) + abs(j - 2) <= 2)
         {
            octaedro[i][j] = 1;
         }
    }
}
    
    // Navio vertical (3 partes)
    int x = 1;
    int y = 2;

    tabuleiro[x][y] = 3;
    tabuleiro[x+1][y] = 3;
    tabuleiro[x+2][y] = 3;
    
    //  Segundo Navio vertical
    int x1 = 3;
    int y1 = 4;

    if (podeColocar(tabuleiro, x1, y1)) tabuleiro[x1][y1] = 3;
    if (podeColocar(tabuleiro, x1+1, y1)) tabuleiro[x1+1][y1] = 3;
    if (podeColocar(tabuleiro, x1+2, y1)) tabuleiro[x1+2][y1] = 3;

    // Navio horizontal
    int x2 = 5;
    int y2 = 3;

    if (podeColocar(tabuleiro, x2, y2)) tabuleiro[x2][y2] = 3;
    if (podeColocar(tabuleiro, x2, y2+1)) tabuleiro[x2][y2+1] = 3;
    if (podeColocar(tabuleiro, x2, y2+2)) tabuleiro[x2][y2+2] = 3;

    // Navio horizontal (3 partes)
    int xNavio = 3;
    int yNavio = 0;
    
    // Diagonal 1
    int x3 = 1;
    int y3 = 1;

    tabuleiro[xNavio][yNavio] = 3;
    tabuleiro[xNavio][yNavio+1] = 3;
    tabuleiro[xNavio][yNavio+2] = 3;
    if (podeColocar(tabuleiro, x3, y3)) tabuleiro[x3][y3] = 3;
    if (podeColocar(tabuleiro, x3+1, y3+1)) tabuleiro[x3+1][y3+1] = 3;
    if (podeColocar(tabuleiro, x3+2, y3+2)) tabuleiro[x3+2][y3+2] = 3;

    // Diagonal 2
    int x4 = 1;
    int y4 = 8;

    if (podeColocar(tabuleiro, x4, y4)) tabuleiro[x4][y4] = 3;
    if (podeColocar(tabuleiro, x4+1, y4-1)) tabuleiro[x4+1][y4-1] = 3;
    if (podeColocar(tabuleiro, x4+2, y4-2)) tabuleiro[x4+2][y4-2] = 3;

    // Centro da habilidade Cone
    int linhaCone = 4;
    int colunaCone = 4;

    // Centro da habilidade Cruz
    int linhaCruz = 5;
    int colunaCruz = 5;

    // Centro da habilidade Octaedro
    int linhaOctaedro = 5;
    int colunaOctaedro = 2;

    // Sobrepor habilidade Cone no tabuleiro
    for(int i = 0; i < 5; i++)
    {
    for(int j = 0; j < 5; j++)
    {
        if(cone[i][j] == 1)
        {
            if(tabuleiro[linhaCone + i - 2][colunaCone + j - 2] == 0)
            {
                tabuleiro[linhaCone + i - 2][colunaCone + j - 2] = 5;
            }
        }
    }
}

    // Sobrepor habilidade Cruz no tabuleiro
    for(int i = 0; i < 5; i++)
    {
    for(int j = 0; j < 5; j++)
    {
        if(cruz[i][j] == 1)
        {
            if(linhaCruz + i - 2 >= 0 &&
            linhaCruz + i - 2 < 10 &&
            colunaCruz + j - 2 >= 0 &&
            colunaCruz + j - 2 < 10)
            {
                if(tabuleiro[linhaCruz + i - 2][colunaCruz + j - 2] == 0)
                {
                    tabuleiro[linhaCruz + i - 2][colunaCruz + j - 2] = 5;
                }
            }
        }
    }
}

    // Sobrepor habilidade Octaedro no tabuleiro
    for(int i = 0; i < 5; i++)
    {
    for(int j = 0; j < 5; j++)
    {
        if(octaedro[i][j] == 1)
        {
            if(linhaOctaedro + i - 2 >= 0 &&
            linhaOctaedro + i - 2 < 10 &&
            colunaOctaedro + j - 2 >= 0 &&
            colunaOctaedro + j - 2 < 10)
            {
                if(tabuleiro[linhaOctaedro + i - 2][colunaOctaedro + j - 2] == 0)
                {
                    tabuleiro[linhaOctaedro + i - 2][colunaOctaedro + j - 2] = 5;
                }
            }
        }
    }
}
    
    // Tabuleiro
    printf("\nTabuleiro:\n\n");

    for(int i = 0; i < 10; i++)
{
    for(int j = 0; j < 10; j++)
    {
        if(tabuleiro[i][j] == 0)
        {
            printf("~ ");
        }
        else if(tabuleiro[i][j] == 3)
        {
            printf("N ");
        }
        else if(tabuleiro[i][j] == 5)
        {
            printf("* ");
        }
    }

    printf("\n");
}

    return 0;
    }