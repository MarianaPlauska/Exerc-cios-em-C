/*Implementar uma função que, dado um
número inteiro n, e o intervalo definido pelos
números a e b, determine quantos valores do
intervalo possuem divisores (sendo estes
diferentes de 1) que também sejam divisores
de n.
Exemplo:
n = 6
a = 10 e b = 20
Resposta = 7 (pois os números 10, 12, 14,
15, 16, 18 e 20 possuem divisores em
comum com o número 6). */   

#include <stdio.h>

int divisores (int n, int a, int b)
{
    int i, j, cont=0, cnt=0;

    for (i=a; i<=b;i++)
    {
        cont=0; //zera o contador a cada iteração
        for (j=2; j<=i; j++)
        {
            if (i%j==0 && n%j==0)
            {
                cont++;
            }
        }
        if (cont>0)
        {
            cnt++;
        }
    }
    
    return cnt;
}


void main()
{
    int n, a, b;
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    printf("Digite o valor de a: ");
    scanf("%d", &a);

    printf("Digite o valor de b: ");
    scanf("%d", &b);

    printf("A quantidade de numeros que possuem divisores em comum com %d e: %d", n, divisores(n, a, b));
    
}