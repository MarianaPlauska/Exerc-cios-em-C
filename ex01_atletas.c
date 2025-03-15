/*faça um programa em C simples seguindo o pedido abaixo, explicando cada detalhe:

1
atleta:
nome (alocado dinaminacamente)
matriz com 3 tempos de qualificação de cada campeonato que participou
número de campeonatos

2
cosntruir um programa que:
pergunte o número de atletas de um clbue
preencha um vetor de atletas do clube (uma função para)
nome: perguntado ao usuário 
número campeonato: perguntado ao usuário
matriz: valores aleatórios (ou 0 nulo)

exiba o vetor de atletas (função)

construa um novo vetor de atletas só com atletas cujo nome inicia com a letra M*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char *nome;
    int numCamp;
    float **temposPole;
} Atleta;

void preencheAtleta(Atleta *atleta)
{
    int i;

    printf ("Digite o nome do atlteta: ");

    atleta->nome = (char *)malloc (50 * sizeof(char));
    scanf ("%s", atleta->nome);

    printf ("Digite o numero de campeonatos disputados: ");
    scanf ("%d", &atleta->numCamp);

    atleta->temposPole = (float **)malloc(atleta->numCamp * sizeof(float *));

    for (i=0; i< atleta->numCamp; i++)
    {
        atleta->temposPole[i] = (float *)malloc(3 * sizeof(float));
    }

    preencheAleatorio (atleta->temposPole, atleta->numCamp, 3);

}

void preencheAleatorio (float **matriz, int l, int c)
{
   int i, j;

   for (i=0; i<l; i++)
   {
        for (j=0; j<c; j++)
        {
            matriz[i][j] = (float)(rand() % 301);
        }
   }
}

void exibe (Atleta *atletas, int numAtletas)
{
    int i, j;

    printf("\nAtletas: ");

    for (i=0; i< numAtletas; i++)
    {
        printf ("Atleta %d:\n", i+1);

        printf ("Nome: %s\n", atletas[i].nome);

        printf ("Numero de campeonatos: %d\n", atletas[i].numCamp);

        printf ("Tempos de pole position: \n");

        for (j=0; j<atletas[i].numCamp; j++)
        {
            printf("Campeonato %d: %.2f %.2f %.2f\n", j+1, atletas[i].temposPole[j][0], atletas[i].temposPole[j][1], atletas[i].temposPole[j][2]);
        }

        printf ("\n");
    }
}

float** atletasComM (Atleta *atletas, int numAtletas, int *numAtletasComM)
{
    int i, j, k;
    float **matrizM = NULL;
    *numAtletasComM = 0;

    printf ("\n -------------------\n");

    for (i=0; i< numAtletas; i++)
    {
        if (atletas[i].nome[0] == 'M' || atletas[i].nome[0] == 'm')
        {
            matrizM = realloc (matrizM, (*numAtletasComM + 1) * sizeof(float *));

            matrizM[*numAtletasComM] = malloc (atletas[i].numCamp * 3 * sizeof(float));

            for (j=0; j < atletas[i].numCamp; j++)
            {
                for (k=0; k<3; k++)
                {
                    matrizM[*numAtletasComM][j*3 + k] = atletas[i].temposPole[j][k];
                }
            }
            (*numAtletasComM)++;
        }
    }


    return matrizM;
}

void exibeMatrizComM(float **matrizAtletasComM, int numAtletasComM, Atleta *atletas) {
    int i, j, k;

    printf("\nMatriz de Atletas com M: \n");

    for (i = 0; i < numAtletasComM; i++) {
        printf("Atleta %d:\n", i + 1);

        for (j = 0; j < atletas[i].numCamp; j++) {
            printf("Campeonato %d: ", j + 1);
            for (k = 0; k < 3; k++) {
                printf("%.2f ", matrizAtletasComM[i][j * atletas[i].numCamp + k]);
            }
            printf("\n");
        }

        printf("\n");
    }
}



void main ()
{
    srand(time(NULL));

    int numAtletas, numAtletasComM, i, j;

    printf ("Digite o numero de atletas: ");
    scanf ("%d", &numAtletas);

    Atleta *atletas = (Atleta *)malloc(numAtletas * sizeof(Atleta));

    for (i=0; i<numAtletas; i++)
    {
        printf ("\nDados atleta %d:\n", i+1);
        preencheAtleta(&atletas[i]);
    }

    exibe(atletas, numAtletas);

    float **matrizAtletasComM = atletasComM(atletas, numAtletas, &numAtletasComM);
    printf ("\nAtletas com M: %d\n", numAtletasComM);

    exibeMatrizComM(matrizAtletasComM, numAtletasComM, atletas);


    //liberar memória

    for(i=0; i<numAtletas; i++)
    {
        free(atletas[i].nome);

        for(j=0; j<atletas[i].numCamp; j++)
        {
            free(atletas[i].temposPole[j]);
        }
        free(atletas[i].temposPole);
    }
    free(atletas);

    for (i=0; i<numAtletasComM; i++)
    {
        free(matrizAtletasComM[i]);
    }
    free(matrizAtletasComM);
}





// typedef struct {
//     char nome[50];             
//     int *tempoPole;            
//     int num_campeonatos;    
// } Atleta;

// void preencheAtleta (Atleta *atletas, int numAtleta)
// {
//     int i, j;

//     for (i=0; i<numAtleta; i++)
//     {
//         printf("\nDigite o nome do atleta %d: ", i+1);
//         scanf("%s", atletas[i].nome);

//         printf ("Digite o numero de campeonatos do atleta %d: ", i+1);
//         scanf ("%d", &atletas[i].num_campeonatos);

//         atletas[i].tempoPole = (int *)malloc(atletas[i].num_campeonatos * sizeof(int));

//     }
// }

// void preencheAleatorio(Atleta *atleta) 
// {
//     int i;

//     srand(time(NULL)); 
    
//     for (i=0; i<atleta->num_campeonatos; i++)
//     {
//         atleta->tempoPole[i] = rand() % 100;
//     }
// }


// void exibeAtletas (Atleta *atletas, int numAtletas)
// {
//     int i, campeonatos;

//     printf("\nAtletas do clube e seus tempos: \n");

//     for (campeonatos=0; campeonatos<3; campeonatos++)
//     {
//         printf("Campeonato %d: \n", campeonatos+1);

//         for (i=0; i<numAtletas; i++)
//         {
//             printf("%s: ", atletas[i].nome);

//             if(campeonatos < atletas[i].num_campeonatos)
//             {
//                 printf(" %d", atletas[i].tempoPole[campeonatos]);
//             }

//             else
//             {
//                 printf("Nao participou");
//             }
//             printf("\n");
//         }
//         printf ("\n");
//     }
// }

// void atletasComM (Atleta *atletas, int numAtletas)
// {
//     int i, j, achou = 0;
    
//     printf("-------------------\n");

//     printf("\nAtletas que comecam com M: \n");

//     for (i=0; i<numAtletas; i++)
//     {
//         if (atletas[i].nome[0] == 'M' || atletas[i].nome[0] == 'm')
//         {
//             printf ("Nome: %s\n", atletas[i].nome);

//             printf ("Numero de campeonatos: %d\n", atletas[i].num_campeonatos);

//             for (j = 0; j < atletas[i].num_campeonatos; j++) 
//             {
//                 printf("\tCampeonato %d: %d\n", j + 1, atletas[i].tempoPole[j]);
//             }
//             printf("\n");
//             achou++;
//         }
//     }

//     if (!achou)
//     {
//         printf("Nenhum atleta com com M.\n");
//     }
// }

// void main()
// {
//     int numAtletas, i;

//     printf ("Digite o numero de atletas: ");
//     scanf ("%d", &numAtletas);

//     Atleta *atletas = (Atleta *)malloc(numAtletas * sizeof(Atleta));

//     preencheAtleta(atletas, numAtletas);

//     for (i=0; i<numAtletas; i++)
//     {
//         preencheAleatorio(&atletas[i]);
//     }

//     exibeAtletas(atletas, numAtletas);

//     atletasComM(atletas, numAtletas);

//     //liberar memória

//     for (i=0; i<numAtletas; i++)
//     {
//         free(atletas[i].tempoPole);
//     }
//     free(atletas);
// }




// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <time.h>

// // Estrutura para representar um atleta
// typedef struct {
//     char nome[50];              // Nome do atleta
//     int **tempoPole;            // Matriz dinâmica de tempos de qualificação
//     int num_campeonatos;        // Número de campeonatos que o atleta participou
// } Atleta;

// // Função para preencher os dados dos atletas com valores aleatórios
// void preencheAtletaAleatorio(Atleta *atleta) {
//     srand(time(NULL)); // Inicializando a semente do gerador de números aleatórios

//     // Preenchendo os tempos de pole position com valores aleatórios
//     for (int campeonato = 0; campeonato < atleta->num_campeonatos; campeonato++) {
//         for (int tempo = 0; tempo < 3; tempo++) { // Cada campeonato tem 3 tempos de qualificação
//             atleta->tempoPole[campeonato][tempo] = rand() % 100;
//         }
//     }
// }

// // Função para exibir os dados dos atletas
// void exibeAtletas(Atleta *atletas, int numAtletas) {
//     printf("\nAtletas do clube:\n");

//     for (int i = 0; i < numAtletas; i++) {
//         printf("Nome: %s\n", atletas[i].nome);
//         printf("Número de campeonatos: %d\n", atletas[i].num_campeonatos);
//         printf("Tempos de pole position:\n");

//         for (int campeonato = 0; campeonato < atletas[i].num_campeonatos; campeonato++) {
//             printf("Campeonato %d:\n", campeonato + 1);

//             for (int tempo = 0; tempo < 3; tempo++) {
//                 printf("%d\t", atletas[i].tempoPole[campeonato][tempo]);
//             }
//             printf("\n");
//         }
//         printf("\n");
//     }
// }

// // Função para exibir apenas os atletas cujos nomes começam com "M" ou "m"
// void atletasComM(Atleta *atletas, int numAtletas) {
//     printf("\nAtletas que começam com M:\n");

//     int encontrou = 0;
//     for (int i = 0; i < numAtletas; i++) {
//         if (atletas[i].nome[0] == 'M' || atletas[i].nome[0] == 'm') {
//             printf("Nome: %s\n", atletas[i].nome);
//             printf("Número de campeonatos: %d\n", atletas[i].num_campeonatos);
//             printf("Tempos de pole position:\n");

//             for (int campeonato = 0; campeonato < atletas[i].num_campeonatos; campeonato++) {
//                 printf("Campeonato %d:\n", campeonato + 1);

//                 for (int tempo = 0; tempo < 3; tempo++) {
//                     printf("%d\t", atletas[i].tempoPole[campeonato][tempo]);
//                 }
//                 printf("\n");
//             }

//             printf("\n");
//             encontrou = 1;
//         }
//     }

//     if (!encontrou) {
//         printf("Nenhum atleta com nome iniciando com M encontrado.\n");
//     }
// }

// // Função para preencher os dados dos atletas
// void preencheAtleta(Atleta *atletas, int numAtletas) {
//     for (int i = 0; i < numAtletas; i++) {
//         printf("\nDigite o nome do atleta %d: ", i + 1);
//         scanf("%s", atletas[i].nome);

//         printf("Digite o número de campeonatos do atleta %d: ", i + 1);
//         scanf("%d", &atletas[i].num_campeonatos);

//         // Alocando memória para a matriz de tempos de pole position
//         atletas[i].tempoPole = malloc(atletas[i].num_campeonatos * sizeof(int *));
//         if (atletas[i].tempoPole == NULL) {
//             printf("Erro ao alocar memória para os tempos de pole position do atleta %s.\n", atletas[i].nome);
//             exit(1);
//         }

//         for (int j = 0; j < atletas[i].num_campeonatos; j++) {
//             atletas[i].tempoPole[j] = malloc(3 * sizeof(int)); // Cada campeonato tem 3 tempos de qualificação
//             if (atletas[i].tempoPole[j] == NULL) {
//                 printf("Erro ao alocar memória para os tempos de pole position do atleta %s.\n", atletas[i].nome);
//                 exit(1);
//             }
//         }
//     }
// }

// int main() {
//     int numAtletas;

//     printf("Digite o número de atletas do clube: ");
//     scanf("%d", &numAtletas);

//     // Alocando memória para o vetor de atletas
//     Atleta *atletas = malloc(numAtletas * sizeof(Atleta));
//     if (atletas == NULL) {
//         printf("Erro ao alocar memória para os atletas.\n");
//         return 1;
//     }

//     // Preenche os dados dos atletas
//     preencheAtleta(atletas, numAtletas);

//     // Preenche os tempos de pole position aleatoriamente para cada atleta
//     for (int i = 0; i < numAtletas; i++) {
//         preencheAtletaAleatorio(&atletas[i]);
//     }

//     // Exibe os dados dos atletas
//     exibeAtletas(atletas, numAtletas);

//     // Exibe os atletas cujos nomes começam com "M" ou "m"
//     atletasComM(atletas, numAtletas);

//     // Libera a memória alocada
//     for (int i = 0; i < numAtletas; i++) {
//         for (int j = 0; j < atletas[i].num_campeonatos; j++) {
//             free(atletas[i].tempoPole[j]);
//         }
//         free(atletas[i].tempoPole);
//     }
//     free(atletas);

//     return 0;
// }
