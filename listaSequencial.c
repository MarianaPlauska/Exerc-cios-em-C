#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int inf;
} tNo;

typedef struct {
    tNo *vnos;
    int qtNos;
    int qtBuffer;
    int ehClassif;
    int comRep;
} tLista;

tLista *cria_listaVazia(tLista *pl, int qtBuffer, int ehClassif, int comRep) 
{
    pl = (tLista *)malloc(sizeof(tLista));

    pl->vnos = (tNo *)malloc(sizeof(tNo) * qtBuffer);

    pl->qtNos = 0;
    pl->qtBuffer = qtBuffer;
    pl->ehClassif = ehClassif;
    pl->comRep = comRep;

    return pl;
}

int listaVazia(const tLista *pl) 
{
    return (pl->qtNos == 0);
}

int listaCheia(const tLista *pl) 
{ 
    return (pl->qtNos == pl->qtBuffer);
}

int listaRepet(const tLista *pl) 
{ 
    return (pl->comRep);
}

int listaClassif(const tLista *pl) 
{ 
    return (pl->ehClassif == 1);
}

void percorreLista(const tLista *pl) 
{
    for (int i = 0; i < pl->qtNos; i++)
    {
        printf("%d -> ", pl->vnos[i].inf);

    }
}

int buscaSeq(tLista *pl, int valor) 
{
    int i;
    
    for (i = 0; i < pl->qtNos; i++)
    {
        if (pl->vnos[i].inf == valor)
        {
            return i;
        }
    }
    
    return -1;
}

int buscaBina(tLista *pl, int valor) 
{
    int fim = pl->qtNos - 1;
    int inicio = 0;
    int meio;

    while (inicio <= fim) 
    {
        meio = (inicio + fim) / 2;

        if (pl->vnos[meio].inf == valor) 
        {
            return meio;
        } 
        else 
        {
            if (pl->vnos[meio].inf < valor) 
            {
                inicio = meio + 1;
        } 
        else 
        {
            fim = meio - 1;
        }
        }
    }
    return -1;
}

tLista insereLista(tLista *pl, int valor) 
{
    int i = pl->qtNos - 1;

    if (lista_cheia(pl)) 
    {
        printf("Lista Cheia\n");

        return *pl;
    }

    if (listaClassif(pl)) 
    {
        if (listaRepet(pl) || buscaBina(pl, valor) == -1) 
        {
            while (i >= 0 && pl->vnos[i].inf > valor) 
            {
                pl->vnos[i + 1] = pl->vnos[i];
                i--;
            }
            pl->vnos[i + 1].inf = valor;
            pl->qtNos++;
        } 
        else 
        {
            printf("O valor já existe\n");
        }
    } 
    else 
    {
        if (listaRepet(pl) || buscaSeq(pl, valor) == -1) 
        {
            pl->vnos[pl->qtNos].inf = valor;
            pl->qtNos++;
        } 
        else 
        {
            printf("O valor já existe\n");
        }
    }
    return *pl;
}

tLista removeLista(tLista *pl, int valor) 
{
    int qt = 0;
    int posicao = buscaBina(pl, valor);
    int posIni = posicao;
    int posicao = buscaSeq(pl, valor);

    if (listaVazia(pl)) 
    {
        printf("Lista Vazia\n");
        return *pl;
    }

    if (listaClassif(pl)) 
    {
        if (posicao != -1) 
        {
            if (!listaRepet(pl)) 
            {
                while (posIni >= 0 && pl->vnos[posIni].inf == valor) 
                {
                    posIni--;
                }
                posIni++;

                while (posicao < pl->qtNos && pl->vnos[posicao].inf == valor) 
                {
                    posicao++;
                    qt++;
                }

                memcpy(pl->vnos + posIni, pl->vnos + posicao, (pl->qtNos - posicao) * sizeof(tNo));
                pl->qtNos -= qt;
            } 
            else 
            {
                memcpy(pl->vnos + posicao, pl->vnos + posicao + 1, (pl->qtNos - posicao - 1) * sizeof(tNo));
                pl->qtNos--;
            }
        } 
        else 
        {
            printf("Valor não existe\n");
        }
    } 
    else 
    {
        if (posicao != -1) {
            memcpy(pl->vnos + posicao, pl->vnos + posicao + 1, (pl->qtNos - posicao - 1) * sizeof(tNo));
            pl->qtNos--;
        } 
        else 
        {
            printf("Valor não existe\n");
        }
    }
    return *pl;
}