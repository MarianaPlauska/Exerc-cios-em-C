/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

ex1
typedef struct {
    char *nome;
    int respQuestionario[5]; // Tamanho do questionário fixo para 5 perguntas
} Pessoa;

void inicializarPessoas(Pessoa *pessoas, int numPessoas) {
    srand(time(NULL));
    for (int i = 0; i < numPessoas; i++) {
        pessoas[i].nome = malloc(sizeof(char) * 20);
        strcpy(pessoas[i].nome, vNomAux[rand() % NUM_NOMES]);
        for (int j = 0; j < 5; j++) { // Itera sobre as 5 perguntas
            pessoas[i].respQuestionario[j] = rand() % 10;
        }
    }
}
ex2
typedef struct {
    char *nome;
    int *respostas;
} Pessoa;

void inicializarPessoas(Pessoa *pessoas, int numPessoas, int numPerguntas) {
    const char *nomes[] = {
        "Bola", "Gigi", "Ana", "Luiz", "Carlos", "Maria", "Pedro", "Lucas",
        "Clara", "Julia", "Felipe", "Mariana", "Beatriz", "Gabriel", "Sofia", 
        "Joao", "Rafael", "Laura", "Renata", "Vinicius"
    };
    int totalNomes = sizeof(nomes) / sizeof(nomes[0]);

    for (int i = 0; i < numPessoas; i++) {
        // Atribuir um nome aleatório
        pessoas[i].nome = (char *)malloc(50 * sizeof(char));
        strcpy(pessoas[i].nome, nomes[rand() % totalNomes]);

        // Gerar respostas aleatórias
        pessoas[i].respostas = (int *)malloc(numPerguntas * sizeof(int));
        for (int j = 0; j < numPerguntas; j++) {
            pessoas[i].respostas[j] = rand() % 10;
        }
    }
}
const char *vNomAux[] = {"Bola", "Gigi", "Ana", "Pedro", "Maria", "João", "Carlos", "Fernanda", "Rafael", "Beatriz", "Gabriel", "Laura", "Lucas", "Sofia", "Eduardo", "Mariana", "Gustavo", "Isabela", "Arthur", "Alice"};
const int NUM_NOMES = sizeof(vNomAux) / sizeof(vNomAux[0]); // Calcula o número de nomes no vetor

ex1 
int calcularDistancia(Pessoa p1, Pessoa p2) {
    int distancia = 0;
    for (int i = 0; i < 5; i++) { // Itera sobre as 5 perguntas
        distancia += (p1.respQuestionario[i] - p2.respQuestionario[i]) * (p1.respQuestionario[i] - p2.respQuestionario[i]);
    }
    return distancia;
}

ex2
int calcularDistancia(int *respostas1, int *respostas2, int numPerguntas) {
    int soma = 0;
    for (int i = 0; i < numPerguntas; i++) {
        int diferenca = respostas1[i] - respostas2[i];
        soma += diferenca * diferenca;
    }
    int aproximacaoRaiz = 0;
    while (aproximacaoRaiz * aproximacaoRaiz <= soma) {
        aproximacaoRaiz++;
    }
    return aproximacaoRaiz - 1;
}

ex1
void encontrarCompatibilidade(char *nomePessoa, Pessoa *pessoas, int numPessoas, int limiar) {
    int i, j;
    for (i = 0; i < numPessoas; i++) {
        if (strcmp(pessoas[i].nome, nomePessoa) == 0) {
            for (j = 0; j < numPessoas; j++) {
                if (i != j && calcularDistancia(pessoas[i], pessoas[j]) <= limiar) {
                    printf("Compatível com: %s\n", pessoas[j].nome);
                }
            }
            break;
        }
    }
}

ex2
void encontrarCompatibilidade(Pessoa *pessoas, int numPessoas, int numPerguntas, char *nomeBase, int limiar) {
    Pessoa *pessoaBase = NULL;

    // Encontrar a pessoa pelo nome
    for (int i = 0; i < numPessoas; i++) {
        if (strcmp(pessoas[i].nome, nomeBase) == 0) {
            pessoaBase = &pessoas[i];
            break;
        }
    }

    if (pessoaBase == NULL) {
        printf("Pessoa com o nome %s não encontrada.\n", nomeBase);
        return;
    }

    printf("Pessoas compatíveis com %s:\n", nomeBase);
    for (int i = 0; i < numPessoas; i++) {
        if (pessoas[i].nome != pessoaBase->nome) {
            int distancia = calcularDistancia(pessoaBase->respostas, pessoas[i].respostas, numPerguntas);
            if (distancia < limiar) {
                printf("%s (Distância: %d)\n", pessoas[i].nome, distancia);
            }
        }
    }
}


int main() {
    int numPessoas, limiar;
    char nomePessoa[20];

    printf("Digite o número de pessoas: ");
    scanf("%d", &numPessoas);

    Pessoa *pessoas = malloc(sizeof(Pessoa) * numPessoas);
    inicializarPessoas(pessoas, numPessoas);

    printf("Digite o nome da pessoa para verificar a compatibilidade: ");
    scanf("%s", nomePessoa);

    printf("Digite o limiar de distância: ");
    scanf("%d", &limiar);

    encontrarCompatibilidade(nomePessoa, pessoas, numPessoas, limiar);

    for (int i = 0; i < numPessoas; i++) {
        free(pessoas[i].nome);
    }
    free(pessoas);

    return 0;
}*/