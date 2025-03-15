/*
  necessário criar o .h
  passar os principais, círculo, ponto e retângulo  

  clientes tem acessos apenas à forma abstrata do TAD

  Um TAD é implementado usando estruturas (structs) para representar os dados e funções que realizam operações sobre esses dados.

  Alocação dinâmica: A memória é alocada em tempo de execução usando funções 
  como malloc(), calloc() ou realloc(). Ela é liberada com free().

  ponteiros são usados para referenciar diretamente o endereço de variáveis.
  são necessários para trabalhar com alocação dinâmica de memória, 
  já que as funções como malloc() retornam o endereço da memória alocada.
*/

//Exemplo de TAD círculo:
//.c
#include <stdlib.h>
#include <stdio.h>
#include "TADCirculo.h"
#define PI 3.14159

struct circulo {
 Ponto *p;
 float r;
} ;

void circSetRaio(tCirculo * c, float r){
    c->r=r;
}
tCirculo * circCria(int x,int y, float r){
  tCirculo * c=(tCirculo*)malloc(sizeof(tCirculo));
  c->p=pto_cria(x,y);
  //pto_atribui(&c->p,x,y);
  circSetRaio(c,r);
  return c;
}
float circGetRaio(tCirculo *c){
    return c->r;
}
float circArea(tCirculo *c){
    return PI*c->r*c->r;
}
float circComprimento(tCirculo *c){
    return 2*PI*c->r;
}
int circCompara(tCirculo *c1, tCirculo *c2){
    if(circComprimento(c1)>circComprimento(c2)){
        printf("Primeiro circulo maior que o segundo");
        return 1;
    }
    else {
        if(circComprimento(c1)==circComprimento(c2)){
            printf("Circulos iguais");
            return -1;
        }
        else {
            printf("Segundo circulo maior que o primeiro");
            return 0;
        }
    }
}
char* circ_getCirculo(tCirculo* p){

    char* pt = (char*)malloc(sizeof(*p) + 8);

    sprintf(pt, "(centro:%s , raio:%.2f )", pto_getPonto(p->p), p->r);

    return pt;

}
void circ_exibe(tCirculo* p){

     pto_exibe(p->p)
     printf("%.2f",p->r)
    //printf("(centro: %s, raio: % .2f)",pto_getPonto(p->p), p->r);

}
//Círculo puro:
tCirculo * circCria(int x,int y, float r){
  tCirculo * c=(tCirculo*)malloc(sizeof(tCirculo));
  ptoAtribui(&c->p,x,y);
  circSetRaio(c,r);
  return c;
}

float circGetRaio(tCirculo *c){
 return c->r;
}

float circArea(tCirculo *c){
 return PI*c->r*c->r;
}

float circComprimento(tCirculo *c){
return 2*PI*c->r;
}

int circCompara(tCirculo *c1, tCirculo *c2){
if(circComprimento(c1)>circComprimento(c2)){
    printf("Primeiro circulo maior que o segundo");
    return 1;
}
else {
    if(circComprimento(c1)==circComprimento(c2)){
    printf("Circulos iguais");
    return -1;
    }
    else {
    printf("Segundo circulo maior que o primeiro");
    return 0;
}
}
}
//.h
// typedef struct circulo tCirculo;

//retângulo
struct retangulo {
  Ponto* vie;
  float altura,base;
};
Retangulo* ret_cria(float x, float y, float altura, float base){
  Retangulo* c = (Retangulo*)malloc(sizeof(Retangulo));
  c->vie = pto_cria(x,y);
  c->altura = altura;
  c->base = base;
  return c;
}
void ret_libera(Retangulo* c){
  pto_libera(c->vie);
  free(c);
}
float ret_area(Retangulo* c){
  return c->altura*c->base;
}
int ret_interior(Retangulo* c, Ponto* p){
  float d = pto_distancia(c->vie,p);
  return (d<c->base);
}
void ret_exibe(Retangulo* c){
  float x,y;
  pto_acessa(c->vie,&x,&y);
  printf("\n Base:%f  Altura:%f Vértice:(%f,%f)", c->base,c->altura,x,y);
  return;
}
float ret_base(Retangulo* c){
  return c->base;
}
float ret_altura(Retangulo* c){
  return c->altura;
}
Ponto*  ret_vertice(Retangulo* c){
  return c->vie;
}
Retangulo* ret_copia(Retangulo*r){
  float x,y;
  pto_acessa(r->vie,&x,&y);
  Retangulo* c = (Retangulo*)malloc(sizeof(Retangulo));
  c->vie = pto_cria(x,y);
  c->altura = r->altura;
  c->base = r->base;
  return c;
}
void ret_troca(Retangulo**r1, Retangulo**r2){
  Retangulo * aux;
  Ponto *p;
  aux = *r1;
  printf("\naux");
  ret_exibe(aux);
  *r1=*r2;
  (*r2)=aux;

  return ;
}
//ponto
Ponto* pto_cria(float x, float y){
   Ponto* p = (Ponto*) malloc(sizeof(Ponto));
   if (p == NULL) {
      printf("Memória insuficiente!\n");
      exit(1);
   }
   p->x = x;
   p->y = y;
   return p;
}
void pto_libera(Ponto* p) {
  free(p);
}
void pto_acessa(Ponto* p, float* x, float* y) {
  *x=p->x;
  *y=p->y;
}
void pto_atribui(Ponto* p, float x, float y) {
  p->x=x;
  p->y=y;
}

float pto_distancia(Ponto* p1, Ponto* p2) {
  float dx = p2->x - p1->x;
  float dy = p2->y - p1->y;
  return sqrt(dx*dx + dy*dy);

  
}
/* Função getPonto - Retorna uma string com os valores do ponto formato(x,y)*/
char* pto_getPonto(Ponto* p1) {
  char* pt;
  int tam = sizeof(*p1)+ 8;
  pt = (char*)malloc(tam);
  sprintf(pt,"( %.2f , %.2f )", p1->x, p1->y);
  return pt;

}
void pto_exibe(Ponto* p) {
  printf(" (%f,%f) ",p->x,p->y);
}
int pto_compara(Ponto* pt1,Ponto* pt2){
/* Função menorque -recebe dois pontos e retorna 1 se o pt1 está mais pr´ximo da origem, 0 cc*/
  Ponto * origem=pto_cria(0,0);
  float distpt1_Orig=pto_distancia(pt1,origem);
  float distpt2_Orig=pto_distancia(pt2,origem);
  pto_libera(origem);

return distpt1_Orig-distpt2_Orig;
}

//Tad cubo
stuct cubo {
    float a;
};

Cubo* cubo_cria(float a)
{
    Cubo* c =(Cubo*) malloc(sizeof(Cubo));

    if(c!=NULL)
    {
        c->a = a;
    }
    return c;
}

float cubo_acessa(Cubo* c)
{
    return c->a;
}

cubo_atribui(Cubo* c, float a)
{
    c->a = a;
}

float cubo_area(Cubo* c)
{
    float area = 6 * c->a * c->a;
    return area;
}

float cubo_volume(Cubo *c)
{
    float volume = c->a * c->a * c->a;
    return volume;
}

void main()
{
    float area, volume;
    Cubo* c1;
    c1= cubo_cria(2,0);

    printf("A area do cubo e: %f\n", area);

    volume = cubo_volume(c1);

    printf("O volume do cubo e: %f\n");
}

//TAD retângulo com base no TAD círculo:
//.h
#ifndef TADRETANGULO_H
#define TADRETANGULO_H

#include "TADPonto.h"

typedef struct retangulo tRetangulo;

// Cria um novo retângulo com as coordenadas do ponto inferior esquerdo (pie) e do ponto superior direito (psd)
tRetangulo* retCria(int xPie, int yPie, int xPsd, int yPsd);

// Libera a memória alocada para o retângulo
void retLibera(tRetangulo* r);

// Retorna a área do retângulo
float retArea(tRetangulo* r);

// Exibe as informações do retângulo (os quatro pontos, base e altura)
void retExibe(tRetangulo* r);

// Retorna uma string com as informações do retângulo
char* retGetRetangulo(tRetangulo* r);

#endif

#include <stdio.h>
#include <stdlib.h>
#include "TADRetangulo.h"
#include "TADPonto.h"

struct retangulo {
    Ponto *pie, *psd;
    Ponto *pse, *pid; // Ponto superior esquerdo e ponto inferior direito
    float base;
    float altura;
};

// Função para criar um novo retângulo
tRetangulo* retCria(int xPie, int yPie, int xPsd, int yPsd) {
    tRetangulo* r = (tRetangulo*) malloc(sizeof(tRetangulo));

    r->pie = pto_cria(xPie, yPie);
    r->psd = pto_cria(xPsd, yPsd);

    // Calculando os outros pontos
    r->pse = pto_cria(xPie, yPsd); // Ponto superior esquerdo
    r->pid = pto_cria(xPsd, yPie); // Ponto inferior direito

    // Calculando base e altura
    r->base = abs(xPsd - xPie);
    r->altura = abs(yPsd - yPie);

    return r;
}

// Função para liberar a memória do retângulo
void retLibera(tRetangulo* r) {
    pto_libera(r->pie);
    pto_libera(r->psd);
    pto_libera(r->pse);
    pto_libera(r->pid);
    free(r);
}

// Função para calcular a área do retângulo
float retArea(tRetangulo* r) {
    return r->base * r->altura;
}

// Função para exibir as informações do retângulo
void retExibe(tRetangulo* r) {
    printf("Pontos do retângulo:\n");
    printf("PIE: ");
    pto_exibe(r->pie);
    printf("\nPSD: ");
    pto_exibe(r->psd);
    printf("\nPSE: ");
    pto_exibe(r->pse);
    printf("\nPID: ");
    pto_exibe(r->pid);
    printf("\nBase: %.2f, Altura: %.2f\n", r->base, r->altura);
}

// Função para obter uma string com as informações do retângulo
char* retGetRetangulo(tRetangulo* r) {
    char* retInfo = (char*)malloc(256 * sizeof(char));
    char pieInfo[64], psdInfo[64], pseInfo[64], pidInfo[64];

    sprintf(pieInfo, "(PIE: %s)", pto_getPonto(r->pie));
    sprintf(psdInfo, "(PSD: %s)", pto_getPonto(r->psd));
    sprintf(pseInfo, "(PSE: %s)", pto_getPonto(r->pse));
    sprintf(pidInfo, "(PID: %s)", pto_getPonto(r->pid));

    sprintf(retInfo, "%s %s %s %s - Base: %.2f, Altura: %.2f", pieInfo, psdInfo, pseInfo, pidInfo, r->base, r->altura);

    return retInfo;
}

#include <stdio.h>
#include <stdlib.h>
#include "TADRetangulo.h"

int main() {
    // Criação de um retângulo com coordenadas do ponto inferior esquerdo (PIE) e superior direito (PSD)
    int xPie = 1, yPie = 1;
    int xPsd = 5, yPsd = 4;

    printf("Criando um retângulo com PIE(%d, %d) e PSD(%d, %d)\n", xPie, yPie, xPsd, yPsd);
    tRetangulo* ret = retCria(xPie, yPie, xPsd, yPsd);

    // Exibindo o retângulo
    printf("\nInformações do retângulo:\n");
    retExibe(ret);

    // Calculando a área do retângulo
    float area = retArea(ret);
    printf("\nÁrea do retângulo: %.2f\n", area);

    // Obtendo as informações do retângulo como string
    char* retInfo = retGetRetangulo(ret);
    printf("\nInformações detalhadas do retângulo: %s\n", retInfo);
    free(retInfo); // Liberando a memória da string alocada

    // Liberando a memória do retângulo
   
 retLibera(ret);

    return 0;
}

//TAD para pilha
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int topo;
    int capacidade;
    int* dados;
} Pilha;

// Função para criar uma pilha (alocação dinâmica)
Pilha* cria_pilha(int capacidade) {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    if (p == NULL) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    p->topo = -1;
    p->capacidade = capacidade;
    p->dados = (int*) malloc(capacidade * sizeof(int));
    if (p->dados == NULL) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    return p;
}

// Função para verificar se a pilha está vazia
int pilha_vazia(Pilha* p) {
    return p->topo == -1;
}

// Função para verificar se a pilha está cheia
int pilha_cheia(Pilha* p) {
    return p->topo == p->capacidade - 1;
}

// Função para adicionar um elemento à pilha
void push(Pilha* p, int valor) {
    if (pilha_cheia(p)) {
        printf("Pilha cheia\n");
        return;
    }
    p->dados[++p->topo] = valor;
}

// Função para remover um elemento da pilha
int pop(Pilha* p) {
    if (pilha_vazia(p)) {
        printf("Pilha vazia\n");
        return -1;
    }
    return p->dados[p->topo--];
}

// Função para liberar a memória da pilha
void libera_pilha(Pilha* p) {
    free(p->dados);  // Libera os dados
    free(p);         // Libera a pilha
}

int main() {
    Pilha* p = cria_pilha(5);
    
    push(p, 10);
    push(p, 20);
    push(p, 30);

    printf("Elemento removido: %d\n", pop(p));
    printf("Elemento removido: %d\n", pop(p));

    libera_pilha(p);
    return 0;
}

//TAD Lista de contatos
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    char telefone[15];
    char email[50];
} Contato;

typedef struct {
    Contato* contatos;
    int tamanho;
    int capacidade;
} ListaContatos;

// Função para criar uma lista de contatos
ListaContatos* cria_lista(int capacidade) {
    ListaContatos* lista = (ListaContatos*) malloc(sizeof(ListaContatos));
    if (lista == NULL) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    lista->contatos = (Contato*) malloc(capacidade * sizeof(Contato));
    if (lista->contatos == NULL) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    lista->tamanho = 0;
    lista->capacidade = capacidade;
    return lista;
}

// Função para adicionar um contato à lista
void adiciona_contato(ListaContatos* lista, char* nome, char* telefone, char* email) {
    if (lista->tamanho == lista->capacidade) {
        printf("Lista cheia\n");
        return;
    }
    strcpy(lista->contatos[lista->tamanho].nome, nome);
    strcpy(lista->contatos[lista->tamanho].telefone, telefone);
    strcpy(lista->contatos[lista->tamanho].email, email);
    lista->tamanho++;
}

// Função para exibir todos os contatos
void exibe_contatos(ListaContatos* lista) {
    for (int i = 0; i < lista->tamanho; i++) {
        printf("Contato %d:\n", i + 1);
        printf("Nome: %s\n", lista->contatos[i].nome);
        printf("Telefone: %s\n", lista->contatos[i].telefone);
        printf("Email: %s\n\n", lista->contatos[i].email);
    }
}

// Função para liberar a memória da lista de contatos
void libera_lista(ListaContatos* lista) {
    free(lista->contatos); // Libera o array de contatos
    free(lista);           // Libera a estrutura da lista
}

int main() {
    ListaContatos* lista = cria_lista(3);

    adiciona_contato(lista, "Alice", "12345", "alice@email.com");
    adiciona_contato(lista, "Bob", "67890", "bob@email.com");

    exibe_contatos(lista);

    libera_lista(lista);
    return 0;
}


//QUESTIONÁRIO DE TAD:

/*

  1. O que é um Tipo Abstrato de Dados (TAD) e qual a característica fundamental na sua utilização?
Um Tipo Abstrato de Dados (TAD) é um modelo que define um conjunto de dados e as operações permitidas 
sobre esses dados, sem se preocupar com a implementação interna. A característica fundamental do TAD 
é a abstração, que permite que o usuário do TAD interaja com os dados através de funções bem definidas, 
sem precisar conhecer os detalhes de como esses dados são armazenados ou manipulados internamente.

  2. Quais as vantagens de se programar com TADs?
  As vantagens de se programar com TADs incluem:
  Modularidade: O código fica mais organizado, facilitando o desenvolvimento e a manutenção.
  Reutilização: Um TAD pode ser reutilizado em diferentes partes do programa ou em outros projetos, já que é independente 
  da implementação.
  Abstração: Permite ocultar a complexidade da implementação, apresentando uma interface simples e clara para o usuário do TAD.

  3 Especificação de um sistema de controle de reservas de um clube que aluga quadras poliesportivas usando TAD
  typedef struct {
    int quadra_id;
    char cliente_nome[50];
    char data[11];  // formato: "dd/mm/aaaa"
    char hora[6];   // formato: "hh:mm"
} Reserva;

Reserva* criar_reserva(int quadra_id, const char* cliente_nome, const char* data, const char* hora);
void cancelar_reserva(Reserva* r);
int verificar_disponibilidade(Reserva* reservas, int n, int quadra_id, const char* data, const char* hora);
void listar_reservas(Reserva* reservas, int n);

4. TAD para números complexos
c
Copiar código
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float real;
    float imaginaria;
} Complexo;

// (a) Criar um número complexo
Complexo* criar_complexo(float x, float y) {
    Complexo* c = (Complexo*) malloc(sizeof(Complexo));
    c->real = x;
    c->imaginaria = y;
    return c;
}

// (b) Destruir um número complexo
void destruir_complexo(Complexo* c) {
    free(c);
}

// (c) Soma de dois números complexos
Complexo* soma_complexo(Complexo* c1, Complexo* c2) {
    return criar_complexo(c1->real + c2->real, c1->imaginaria + c2->imaginaria);
}

// (d) Subtração de dois números complexos
Complexo* subtrai_complexo(Complexo* c1, Complexo* c2) {
    return criar_complexo(c1->real - c2->real, c1->imaginaria - c2->imaginaria);
}

// (e) Multiplicação de dois números complexos
Complexo* multiplica_complexo(Complexo* c1, Complexo* c2) {
    float real = c1->real * c2->real - c1->imaginaria * c2->imaginaria;
    float imag = c1->real * c2->imaginaria + c1->imaginaria * c2->real;
    return criar_complexo(real, imag);
}

// (f) Divisão de dois números complexos
Complexo* divide_complexo(Complexo* c1, Complexo* c2) {
    float denominador = c2->real * c2->real + c2->imaginaria * c2->imaginaria;
    float real = (c1->real * c2->real + c1->imaginaria * c2->imaginaria) / denominador;
    float imag = (c1->imaginaria * c2->real - c1->real * c2->imaginaria) / denominador;
    return criar_complexo(real, imag);
}
5. TAD para conjunto de inteiros
c
Copiar código
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* elementos;
    int tamanho;
    int capacidade;
} Conjunto;

// (b) Criar um conjunto vazio
Conjunto* cria_conjunto(int capacidade) {
    Conjunto* c = (Conjunto*) malloc(sizeof(Conjunto));
    c->elementos = (int*) malloc(capacidade * sizeof(int));
    c->tamanho = 0;
    c->capacidade = capacidade;
    return c;
}

// (c) Inserir um elemento no conjunto
void insere(Conjunto* c, int valor) {
    if (c->tamanho < c->capacidade) {
        c->elementos[c->tamanho++] = valor;
    }
}

// (d) Remover um elemento do conjunto
void remove_elemento(Conjunto* c, int valor) {
    for (int i = 0; i < c->tamanho; i++) {
        if (c->elementos[i] == valor) {
            c->elementos[i] = c->elementos[--c->tamanho];
            break;
        }
    }
}

// (a) União de dois conjuntos
Conjunto* uniao(Conjunto* c1, Conjunto* c2) {
    Conjunto* uniao = cria_conjunto(c1->tamanho + c2->tamanho);
    for (int i = 0; i < c1->tamanho; i++) {
        insere(uniao, c1->elementos[i]);
    }
    for (int i = 0; i < c2->tamanho; i++) {
        insere(uniao, c2->elementos[i]);
    }
    return uniao;
}

// (e) Interseção de dois conjuntos
Conjunto* intersecao(Conjunto* c1, Conjunto* c2) {
    Conjunto* intersecao = cria_conjunto(c1->tamanho < c2->tamanho ? c1->tamanho : c2->tamanho);
    for (int i = 0; i < c1->tamanho; i++) {
        for (int j = 0; j < c2->tamanho; j++) {
            if (c1->elementos[i] == c2->elementos[j]) {
                insere(intersecao, c1->elementos[i]);
            }
        }
    }
    return intersecao;
}

// (f) Diferença entre dois conjuntos
Conjunto* diferenca(Conjunto* c1, Conjunto* c2) {
    Conjunto* dif = cria_conjunto(c1->tamanho);
    for (int i = 0; i < c1->tamanho; i++) {
        int encontrado = 0;
        for (int j = 0; j < c2->tamanho; j++) {
            if (c1->elementos[i] == c2->elementos[j]) {
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            insere(dif, c1->elementos[i]);
        }
    }
    return dif;
}

6. TAD para números racionais
c
Copiar código
typedef struct {
    int numerador;
    int denominador;
} Racional;

Racional* cria_racional(int num, int den);
Racional* soma_racional(Racional* r1, Racional* r2);
Racional* multiplica_racional(Racional* r1, Racional* r2);
int sao_iguais(Racional* r1, Racional* r2);

TAD ESFERA:
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float raio;
} Esfera;

// Função para criar uma esfera
Esfera* cria_esfera(float raio) {
    Esfera* e = (Esfera*) malloc(sizeof(Esfera));
    if (e != NULL) {
        e->raio = raio;
    }
    return e;
}

// Função para calcular a área da esfera
float area_esfera(Esfera* e) {
    if (e == NULL) return -1;  // Erro
    return 4 * M_PI * e->raio * e->raio;
}

// Função para calcular o volume da esfera
float volume_esfera(Esfera* e) {
    if (e == NULL) return -1;  // Erro
    return (4.0 / 3.0) * M_PI * pow(e->raio, 3);
}

// Função para destruir a esfera (liberar memória)
void destroi_esfera(Esfera* e) {
    free(e);
}

int main() {
    Esfera* e = cria_esfera(5.0);
    printf("Área da esfera: %.2f\n", area_esfera(e));
    printf("Volume da esfera: %.2f\n", volume_esfera(e));
    destroi_esfera(e);
    return 0;
}

TAD CILINDRO:
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float raio;
    float altura;
} Cilindro;

// Função para criar um cilindro
Cilindro* cria_cilindro(float raio, float altura) {
    Cilindro* c = (Cilindro*) malloc(sizeof(Cilindro));
    if (c != NULL) {
        c->raio = raio;
        c->altura = altura;
    }
    return c;
}

// Função para calcular a área do cilindro
float area_cilindro(Cilindro* c) {
    if (c == NULL) return -1;  // Erro
    return 2 * M_PI * c->raio * (c->raio + c->altura);
}

// Função para calcular o volume do cilindro
float volume_cilindro(Cilindro* c) {
    if (c == NULL) return -1;  // Erro
    return M_PI * c->raio * c->raio * c->altura;
}

// Função para destruir o cilindro (liberar memória)
void destroi_cilindro(Cilindro* c) {
    free(c);
}

int main() {
    Cilindro* c = cria_cilindro(3.0, 7.0);
    printf("Área do cilindro: %.2f\n", area_cilindro(c));
    printf("Volume do cilindro: %.2f\n", volume_cilindro(c));
    destroi_cilindro(c);
    return 0;
}

TAD CUBO:
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float lado;
} Cubo;

// Função para criar um cubo
Cubo* cria_cubo(float lado) {
    Cubo* c = (Cubo*) malloc(sizeof(Cubo));
    if (c != NULL) {
        c->lado = lado;
    }
    return c;
}

// Função para calcular a área do cubo
float area_cubo(Cubo* c) {
    if (c == NULL) return -1;  // Erro
    return 6 * c->lado * c->lado;
}

// Função para calcular o volume do cubo
float volume_cubo(Cubo* c) {
    if (c == NULL) return -1;  // Erro
    return c->lado * c->lado * c->lado;
}

// Função para destruir o cubo (liberar memória)
void destroi_cubo(Cubo* c) {
    free(c);
}

int main() {
    Cubo* c = cria_cubo(4.0);
    printf("Área do cubo: %.2f\n", area_cubo(c));
    printf("Volume do cubo: %.2f\n", volume_cubo(c));
    destroi_cubo(c);
    return 0;
}


*/