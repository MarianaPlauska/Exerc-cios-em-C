/*Desenvolver uma função que exiba os múltiplos
de N compreendidos no intervalo definido por
A e B.

múltiplo de 3 - que dividido por 3 tem resto 0

Exemplo:
n = 3
a = 10 e b = 20
i = a
10
10%3 = 3,3...
cont = 0
11%3 = 3,3...
cont = 0
i = 12
12%3 = 4
cont = 1
...
Resposta = 12, 15, 18

*/

#include <stdio.h>

void multiplos (int n, int a, int b)
{
    int i;
    for (i=a; i<=b; i++)
    {
        if (i%n==0)
        {
            printf("%d ", i);
        }
    }
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

    printf("Os multiplos de %d compreendidos entre %d e %d sao: ", n, a, b);
    multiplos(n, a, b);
}