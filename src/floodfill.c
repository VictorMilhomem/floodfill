#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100
char matrix[MAX][MAX];

void read(char* filename)
{
    char c; int cont = 0;

    FILE *fp;
    if ((fp = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr,  "Erro arquivo inexistente\n");
        exit(1);
    }
    else
    {
        fp = fopen(filename, "r");
        int i = 0;
        int j = 0;
        while (!feof(fp))
        {
            c = getc(fp);
            if(c == '\n'){
                cont++;
                i++;
                j = 0;
            }

            if (cont < MAX){ 
                matrix[i][j] = c;
                    j++;
            }
        }
    }
    fclose(fp);
}

int valid(int i,int j)
{
    if(i<0 || i>=MAX || j<0 || j>=MAX)
        return 0;
    else
        return 1;
}

void floodFill(int x, int y, int prev, int newValue)
{
    if(valid(x,y) == 0)
        return;
    if(matrix[x][y] != prev)
        return;
    if(matrix[x][y] == newValue)
        return;
    if(matrix[x][y] == prev)
        matrix[x][y] = newValue;
    floodFill(x-1,y,prev,newValue);
    floodFill(x+1,y,prev,newValue);
    floodFill(x,y-1,prev,newValue);
    floodFill(x,y+1,prev,newValue);
    floodFill(x-1,y-1,prev,newValue);
    floodFill(x-1,y+1,prev,newValue);
    floodFill(x+1,y-1,prev,newValue);
    floodFill(x+1,y+1,prev,newValue);
}

void saveFile()
{
    FILE *fp;
    fp = fopen("../result/final.txt", "w");
    for (int i = 0; i <= MAX-1; i++)
    {
        for (int j = 0; j < MAX; j++)
            fputc(matrix[i][j], fp);
        fputc('\n', fp);
    }
    fflush(fp);
    fclose(fp);
}