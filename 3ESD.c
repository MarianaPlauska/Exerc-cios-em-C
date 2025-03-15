// //empilhar pilha

// #include <stdio.h>

// typedef int tInf;

// typedef struct{
//     tInf *dados;
//     int topo;
//     int capacidade;
// } tPilha;

// //criar pilha
// void criaPilha (tPilha *p, int cap)
// {
//    p->dados = (tInf *)malloc(cap * sizeof(tInf));

//    p->topo = -1; //vazia
//    p->capacidade = cap;

// }

// //empilhar (push)
// int empilha(tPilha *p, tInf aux)
// {
//     if (p->topo == p->capacidade -1)
//     {
//         return 0; //pilha cheia
//     }
//     else
//     {
//        if (p->dados[++p->topo] = aux)
//        {
//         return 1;
//        }
//     }

// }

// //desempilhar (pop)
// int desempilha(tPilha *p, tInf *aux) 
// {
//     if (p->topo == -1) 
//     {
//         return 0; // Pilha vazia
//     } 
//     else 
//     {
//         *aux = p->dados[p->topo--];
//         return 1;
//     }
// }

// //verifica se tá vazia
// int pilhaVazia(tPilha *p)
// {
//     return p->topo == -1;
// }

// void main ()
// {
//     tInf elemento;
//     tPilha pilha;
//     criaPilha (&pilha, 10);

//     empilha(&pilha, 10);
//     empilha(&pilha, 20);
//     empilha(&pilha, 30);

//     while (!pilhaVazia(&pilha))
//     {
//         desempilha(&pilha, &elemento);
//         printf("Desempilhado: %d\n", elemento);

//     }
//     free(pilha.dados);
// }

//função que inverta uma fila F recebida, usando as operações dos TADS fornecidos. 

/*
    desemfileirar todos de F e empilhá-los em uma pilha P
    desempilhar todos de P e enfileirá-los em F

    pilha - LIFO - ao empihlar os elementos da fila e depois desempilhá-los, reveterá a ordem original da fila
    
*/

// #include <stdio.h>
// #include <stdlib.h>

// typedef int tInf;

// typedef struct{
//     tInf *dados;
//     int topo;
//     int capacidade;
// }tPilha;

// typedef struct{
//     tInf *dados;
//     int inicio;
//     int fim;
//     int tam;
//     int capacidade;
// }tFila;

// void criaPilha(tPilha *p, int capacidade) 
// {
//     p->dados = (tInf *)malloc(capacidade * sizeof(tInf));

//     p->topo = -1;
//     p->capacidade = capacidade;
// }

// int empilha (tPilha *p, tInf aux)
// {
//     if (p->topo == p->capacidade -1)
//      {
//          return 0; //pilha cheia
//      }
//      else
//      { 
//         p->dados[++p->topo] = aux;
//          return 1;
        
//      }
// }

// int desempilha(tPilha *p, tInf *aux) 
//  {
//      if (p->topo == -1) 
//      {
//          return 0; // Pilha vazia
//      } 
//      else 
//      {
//          *aux = p->dados[p->topo--];
//          return 1;
//      }
//  }

// int pilhaVazia(tPilha *p)
//  {
//      return p->topo == -1;
//  }

//  void criaFila (tFila *f, int cap)
//  {
//     f->dados = (tInf *)malloc(cap * sizeof(tInf));
//     f->inicio =0;
//     f->fim = 0;
//     f->tam = 0;
//     f->capacidade = cap;
//  }

//  int enfileira(tFila *f, tInf x)
//  {
//     if(f->tam == f->capacidade)
//     {
//         return 0; 
//     }
//     else
//     {
//         f->dados[f->fim] = x; //aray que armazena os elementos. f->fim é onde o próximo elemento vai ser inserido. x é colocado no final do array
//         f->fim = (f->fim + 1) & f->capacidade;//precisa atualizar o fim para apontar para a próxima posição livre. usa o módulo para garantir que volte ao início quando atingir o final (fila circular)
//         f->tam++;

//         return 1;
//     }
//  }

//  int desenfileira(tFila *f, tInf *x)
//  {
//     if (f->tam == 0)
//     {
//         return 0;
//     }
//     else
//     {
//         *x = f->dados[f->inicio];
//         f->inicio = (f->inicio +1) % f->capacidade;
//         f->tam--;
//         return 1;
//     }
//  }

//  int filaVazia (tFila *F) 
//  {
//     return F->tam == 0;
// }

// void inverteFila (tFila *f)
// {
//     tPilha p;
//     criaPilha(&p, f->capacidade);
//     tInf elemento;

//     //desenfileirar e empilhar
//     while(!filaVazia(f))
//     {
//         desenfileira(f, &elemento);
//         empilha(&p, elemento);
//     }

//     //desempilha os elementos da pilha e enfileira na fila
//     while(!filaVazia(&p))
//     {
//         desempilha(&p, &elemento);
//         enfileira(f, elemento);
//     }

//     free(p.dados);
// }

// int main() {
//     tFila f;
//     criaFila(&f, 10);

//     // Adiciona alguns elementos à fila
//     enfileira(&f, 1);
//     enfileira(&f, 2);
//     enfileira(&f, 3);
//     enfileira(&f, 4);
//     enfileira(&f, 5);

//     // Inverte a fila
//     inverteFila(&f);

//     // Desenfileira e imprime os elementos para verificar a inversão
//     tInf elemento;
//     while (!filaVazia(&f)) {
//         desenfileira(&f, &elemento);
//         printf("%d ", elemento);
//     }

//     free(f.dados); // Libera a memória alocada para a fila

//     return 0;
// }


/*
Questão 3) (2.0 pontos)-Considere o tipo LSE definido abaixo,
typedef struct no_lista (
int vi
struct no lista *proxi
typedef struct tiista
TNO *prim
int qtNos;
Construa uma função (como desenvolvedor do TAD) que receba esta lista e exiba a última metade da lista.

*/

// typedef struct no_lista{
//     int valor;
//     struct no_lista *prox;
// }TNo;

// //definição da lista
// typedef struct lista{
//     TNo *prim;
//     int qntNos;
// }TLista;

// //exibir a última metade da lista
// void exibeUltimaMetade(TLista *lista)
// {
//     int i;
//     TNo *atual = lista->prim;
//     int meio = lista->qntNos /2;

//     if(lista == NULL || lista->prim == NULL)
//     {
//         printf("A lista esta vazia\n");
//     }

//     //percorrendo metade da lista
//     for (i=0; i<meio;i++)
//     {
//         if(atual!=NULL)
//         {
//             atual=atual->prox;
//         }
//     }

//     //exibindo
//     while (atual!=NULL)
//     {
//         printf("%d ", atual->valor);
//         atual=atual->prox;
//     }
//     printf("\n");

// }

// //adicionar novo nó
// void adicionaNovoNo(TLista *lista, int valor)
// {
//     TNo *novo = criaNo(valor);

//     if (lista->prim == NULL)
//     {
//         lista->prim = novo;
//     }
//     else
//     {
//         TNo *atual = lista->prim;

//         while (atual->prox != NULL)
//         {
//             atual= atual->prox;
//         }
//         atual->prox = novo;
//     }
//     lista->qntNos++;
// }

// //exibir toda a lista
// void exibeLista(TLista *lista)
// {
//     TNo *atual = lista->prim;

//     while (atual!=NULL)
//     {
//         printf("%d ", atual->valor);
//         atual= atual->prox;
//     }
//     printf("\n");
// }

/* 
Escreva uma função recursiva que conta o número de nós em uma árvore binária de busca 
que possuam exatamente dois filhos. Esta função recebe a raiz de uma árvore e retorna a quantidade 
de nós que satisfazem a condição (ter exatamente 2 filhos)

*/
// #include <stdio.h>
// #include <stdlib.h>

// typedef struct no_arvore{
//     int valor;
//     struct no_arvore *esq;
//     struct no_arvore *dir;
// }TNo;

// //função recursiva
// int contaNo(TNo *raiz)
// {
//     int cont = 0;

//     //caso base
//     if(raiz==NULL)
//     {
//         return 0;
//     }

//     //verifica se o nó tem dois filhos
//     if(raiz->esq != NULL && raiz->dir != NULL)
//     {
//         cont = 1;
//     }

//     return cont + contaNo(raiz->esq) + contaNo(raiz->dir);

// }

// //funções auxiliares
// TNo* criaNo(int valor)
// {
//     TNo *novo = (TNo*)malloc(seizof(TNo));

//     novo->valor = valor;
//     novo->esq= NULL;
//     novo->dir = NULL;

//     return novo;
// }

// //função para inserir um valor novo na árvore
// TNo* insereNo(TNo *raiz, int valor)
// {
//     if (raiz == NULL)
//     {
//         return criaNo(valor);
//     }

//     if(valor < raiz->valor)
//     {
//         raiz->esq = insereNo(raiz->esq, valor);
//     }
//     else
//     {
//         if (valor > raiz->valor)
//         {
//             raiz->dir = insereNo(raiz->valor, valor);
//         }
//     }
//     return raiz;
// }