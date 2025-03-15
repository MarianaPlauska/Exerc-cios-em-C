/*construir as funções preenche, exibe e ordena(bolha) que recebem um vetor de nomes e a quantidade de elementos. Os nomes armazenados no vetor devem ser dinamicamente alocados
A main de teste deve criar o vNomes de 2 formas diferentes: estática e dinâmica*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void preenche(char **vNomesD, int quant, int tam)
{
    int i;

    for (i=0; i< quant; i++)
    {
        vNomesD = (char *)malloc(tam * sizeof(char));

        if(vNomesD[i] == NULL)
        {
            printf("erro");
        }

        printf("Entre com o %d nome: ", i + 1);
        scanf("%s", vNomesD[i]);
    }
}

void exibe(char **vNomesD, int quant)
{
    int i;

    for(i=0; i<quant; i++)
    {
        printf("\n%s\n", vNomesD[i]);
    }
}

void ordena(char **vNomesD, int quant)
{
    int i, j;
    char aux[20];

    for (i=0; i<quant - 1; i++)
    {
        for (j= i+ 1; j< quant; j++)
        {
            if ()
        }
    }
}