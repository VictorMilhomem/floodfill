#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./headers/floodfill.h"

void run(char *filename)
{
    int pos[2]; char change[2]; int numbers_of_lines_col[2];

    printf("Digite a posição do pixel (x, y);\nO caractere a ser substituido;\nO caractere a ser preenchido:\nOBS:(caracter ' ' , digite E)\n");
    scanf("%d %d %c %c", &pos[0], &pos[1], &change[0], &change[1]);
    if (change[0] == 'E')
        change[0] = ' ';
    if (change[1] == 'E')
        change[1] = ' ';

    read(filename);
    floodFill(pos[0], pos[1], change[0], change[1]);
    saveFile();

}

void help()
{
    printf("Como usar:");
    printf("\nfloodfill -[opções]");
    printf("\nOpções:");
    printf("\n-r: Opção para ler o arquivo na CLI");
    printf("\n-h: Ajuda");
}