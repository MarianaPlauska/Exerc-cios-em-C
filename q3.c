/*Considere que um arquivo mantenha os dados (código,
descrição e preço) de seus produtos em um arquivo
texto, conforme o exemplo a seguir:

Pede-se uma função que, dado um código, recupere do
arquivo a descrição e o preço associados, caso o código
exista. Se o código dado não for encontrado, a função
retornará o valor 0; caso contrário, 1.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TProduto {
    int codigo;
    char descricao[50];
    float preco;
} TProduto;

int recupera_dados(int codigo, char *descricao, float *preco) {
    FILE *arq;
    TProduto produto;

    arq = fopen("arquivo", "rb");  // Alteração no modo de abertura
    if (arq == NULL) {
        perror("Erro ao abrir o arquivo");
        return 0;
    }

    while (fread(&produto, sizeof(TProduto), 1, arq) == 1) {
        if (produto.codigo == codigo) {
            strcpy(descricao, produto.descricao);
            *preco = produto.preco;
            fclose(arq);
            return 1;
        }
    }

    fclose(arq);
    return 0;
}

int main() {
    int codigo = 123;
    char descricao[50];
    float preco;

    if (recupera_dados(codigo, descricao, &preco)) {
        printf("Descricao: %s\n", descricao);
        printf("Preco: %.2f\n", preco);
    } else {
        printf("Codigo nao encontrado.\n");
    }

    return 0;
}
