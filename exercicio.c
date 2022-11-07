/* Uma empresa quer transmitir mensagns sigilosas a seus diretores e precisa de um programa para codificar suas mensagens.
A regra de criptografia deve substituir o código ASCII de cada caractere que compõe a mensagem por (5*código_ASCII+100) %256
A mensagens deverão terminar com "."*/

#include <stdio.h>
#include <string.h>
#define MAX 100
//. condição de parada
//unsigned = para aumentar os valores - todos os valores estarão dentro da tabela

unsigned char criptografa(unsigned char c)
{
    return (5*c+100)%256;
}

void main ()
{
    unsigned char msg[MAX], msg_cod[MAX];
    int i, aux=0;

    for (i=0;i<MAX;i++)
    {
        scanf("%c", &msg[i]);
        if (msg[i]=='.')
        {
            break;
        }
    }
    aux=i;
    msg[i]='\0';

    printf ("\nMensagem original: %s", msg);
    //printf ("\nMensagem criptografada: ");

    for (i=0;i<aux;i++)
    {
        msg_cod[i]=criptografa(msg[i]);
        //printf ("%c", msg_cod[i]);
    }

    printf ("\nMensagem codificada: ");
    printf ("%s", msg_cod);
}