#include <stdio.h>

int operacoes (float a, float b, int op) 
{
    int resultado;

    switch (op) 
    {
        case 1:
            resultado = a + b;
            break;
        case 2:
            resultado = a - b;
            break;
        case 3:
            resultado = a * b;
            break;
        case 4:
            resultado = a / b;
            break;
        default:
            printf("Operacao invalida \n");
            break;
    }
    return resultado;
}

void main ()
{
    int op;
    float a, b, resultado;
    
    printf ("Digite o primeiro numero: \n");
    scanf ("%f", &a);

    printf ("Digite o segundo numero: \n");
    scanf ("%f", &b);

    printf ("\t\t Menu de opcoes: \n");
    printf ("\t \t 1 - Soma \n");
    printf ("\t \t 2 - Subtracao \n");
    printf ("\t \t 3 - Multiplicacao \n");  
    printf ("\t \t 4 - Divisao \n");

    printf ("\nDigite a opcao desejada: ");
    scanf ("%d", &op);

    resultado = operacoes (a, b, op);

    printf ("%1.f \n", resultado);
}
