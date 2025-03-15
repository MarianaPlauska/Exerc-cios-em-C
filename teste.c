/*Construir o TAD quadrado definido como: lado ( número inteiro), vértice inferior esquerdo ( Ponto)
além das operações usuais( quad_cria, quad_libera; quad_getQuadrado; quad_exibe,quad_clona; quad_atribui; quad_acessa;)
construir:
quad_compara: recebe dois quadrados e em função da área, compara os dois quadrados;
quad_getVSD: retorna  uma string, equivalente ao ponto do vértice superior direito
quad_getVSE:  retorna  uma string, equivalente ao ponto do vértice superior esquerdo
quad_getVID: retorna  uma string, equivalente ao ponto do vértice inferior direito
quad_getVIE: retorna  uma string, equivalente ao ponto do vértice inferior esquerdo*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ponto.h"

typedef struct quadrado Quadrado;

Quadrado* quad_cria(int lado, Ponto* p);
void quad_libera(Quadrado* q);
void quad_getQuadrado(Quadrado* q, int* lado, Ponto* p);
void quad_exibe(Quadrado* q);
Quadrado* quad_clona(Quadrado* q);
void quad_atribui(Quadrado* q1, Quadrado* q2);
Ponto* quad_acessa(Quadrado* q);
int quad_compara(Quadrado* q1, Quadrado* q2);
char* quad_getVSD(Quadrado* q);
char* quad_getVSE(Quadrado* q);
char* quad_getVID(Quadrado* q);
char* quad_getVIE(Quadrado* q);

struct quadrado{
    int lado;
    Ponto* p;
    Ponto* verticeSuperiorDireito;
    Ponto* verticeSuperiorEsquerdo;
    Ponto* verticeInferiorDireito;
    Ponto* verticeInferiorEsquerdo;
};

Quadrado* quad_cria(int lado, Ponto* p){
    Quadrado* q = (Quadrado*) malloc(sizeof(Quadrado));
    if(q != NULL){
        q->lado = lado;
        q->verticeSuperiorDireito = ponto_cria(ponto_getX(p) + lado, ponto_getY(p) + lado);
}

void quad_libera(Quadrado* q){
    free(q);
}

//use sprintf 
char*

void quad_exibe(Quadrado* q){
    printf("Lado: %d\n", q->lado);
    printf("Ponto: ");
    ponto_exibe(q->p);
}

Quadrado* quad_clona(Quadrado* q){
    Quadrado* q2 = (Quadrado*) malloc(sizeof(Quadrado));
    if(q2 != NULL){
        q2->lado = q->lado;
        q2->p = ponto_clona(q->p);
    }
    return q2;
}

void quad_atribui(Quadrado* q1, Quadrado* q2){
    q1->lado = q2->lado;
    ponto_atribui(q1->p, q2->p);
}

Ponto* quad_acessa(Quadrado* q){
    return q->p;
}

int quad_compara(Quadrado* q1, Quadrado* q2){
    int area1 = q1->lado * q1->lado;
    int area2 = q2->lado * q2->lado;
    if(area1 > area2){
        return 1;
    }else if(area1 < area2){
        return -1;
    }else{
        return 0;
    }
}

char* quad_getVSD(Quadrado* q){
    Ponto* p = q->p;
    //str é 
    char* str = (char*) malloc(100 * sizeof(char));
    sprintf(str, "(%d, %d)", ponto_getX(p) + q->lado, ponto_getY(p) + q->lado);
    return str;
}

char* quad_getVSE(Quadrado* q){
    Ponto* p = q->p;
    char* str = (char*) malloc(100 * sizeof(char));
    sprintf(str, "(%d, %d)", ponto_getX(p), ponto_getY(p) + q->lado);
    return str;
}

char* quad_getVID(Quadrado* q){
    Ponto* p = q->p;
    char* str = (char*) malloc(100 * sizeof(char));
    sprintf(str, "(%d, %d)", ponto_getX(p) + q->lado, ponto_getY(p));
    return str;
}

char* quad_getVIE(Quadrado* q){
    Ponto* p = q->p;
    char* str = (char*) malloc(100 * sizeof(char));
    sprintf(str, "(%d, %d)", ponto_getX(p), ponto_getY(p));
    return str;
}

int main(){
    Ponto* p = ponto_cria(1, 2);
    Quadrado* q = quad_cria(3, p);
    quad_exibe(q);
    printf("\n");
    Quadrado* q2 = quad_clona(q);
    quad_exibe(q2);
    printf("\n");
    Ponto* p2 = ponto_cria(4, 5);
    Quadrado* q3 = quad_cria(6, p2);
    quad_atribui(q2, q3);
    quad_exibe(q2);
    printf("\n");
    printf("Comparação: %d\n", quad_compara(q, q2));
    printf("VSD: %s\n", quad_getVSD(q));
    printf("VSE: %s\n", quad_getVSE(q));
    printf("VID: %s\n", quad_getVID(q));
    printf("VIE: %s\n", quad_getVIE(q));
    quad_libera(q);
    quad_libera(q2);
    quad_libera(q3);
    ponto_libera(p);
    ponto_libera(p2);
    return 0;
}
