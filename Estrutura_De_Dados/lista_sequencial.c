#include <stdlib.h>
#include <stdio.h>
#include "lista_sequencial.h"

struct lista 
{
    int quantidade;
    struct sistema sis[MAX];
};

Lista* cria_lista ()
{
    Lista *li;
    li = (Lista*) malloc(sizeof(struct lista));
    if (li != NULL)
    {
        li->quantidade = 0;
    }
    return 0;
}
void libera_lista (Lista* li)
{
    free(li);
}
int tamanho_lista(Lista* li)
{
    if(li == NULL)
    {
        return -1;
    }
    else
    {
        return li->quantidade;
    }
}
int lista_cheia (Lista* li)
{
    if (li == NULL)
    {
        return -1;
    }
    return (li->quantidade == MAX);
}
int lista_vazia (Lista* li)
{
    if (li == NULL)
    {
        return -1;
    }
    return (li->quantidade == 0);
}
int insere_lista_final (Lista* li, struct sistema sus)
{
    if (li == NULL)
    {
        return 0;
    }
    if (lista_cheia(li))
    {
        return 0;
    }

    li->sis[li->quantidade] = sus;
    li->quantidade++;
    return 1;
}
int insere_lista_inicio (Lista* li, struct sistema sus)
{
    if (li == NULL)
    {
        return 0;
    }

    if (lista_cheia(li))
    {
        return 0;
    }

    for(int i = li->quantidade -1; i >= 0; i--)
    {
        li->sis[i+1] = li->sis[i];
    }
    li->sis[0] = sus;
    li->quantidade++;
    return 1;
}
int insere_lista_ordenada (Lista* li, struct sistema sus)
{
    if(li == NULL)
    {
        return 0;
    }
    
    if (lista_cheia(li))
    {
        return 0;
    }

    int a, i = 0;

    while(i < li->quantidade && li->sis [i].n < sus.n )
    {
        i++;
    }

    for(a = li->quantidade -1; a >= i; a--)
    {
        li->sis[a+1] = li->sis[a];
    }

    li->sis [i] = sus;
    li->quantidade++;

    return 1;
}
int remove_lista_final (Lista* li)
{
    if(li == NULL)
    {
        return 0;
    }

    if(li->quantidade == 0)
    {
        return 0;
    }

    li->quantidade --;

    return 1;
}
int remove_inicio (Lista* li)
{
    if (li == NULL)
    {
        return 0;
    }

    if (li->quantidade == 0)
    {
        return 0;
    }

    for (int i = 0; i < li->quantidade; i-- )
    {
        li->sis[i] = li->sis[i+1];
    }

    li->quantidade --;
    return 1;
}   
int remove_meio (Lista* li, int num)
{
    if(li == NULL)
    {
        return 0;
    }

    if(li->quantidade == 0)
    {
        return 0;
    }

    int i = 0;
    while (num != li->sis[i].n && i < li->quantidade)
    {
        i++;
    }

    if(i == li->quantidade)
    {
        return 0;
    }

    for (int b = i; b < li->quantidade-1; b++)
    {
        li->sis[b] = li->sis[b+1];
    }

    li->quantidade --;
    return 1;
}
int consulta_lista_posicao (Lista* li, int num, struct sistema *sus)
{
    if(num <= 0 || num > li->quantidade || li == NULL)
    {
        return 0;
    }

    *sus = li->sis[num -1];
    return 1;
}
int consulta_num (Lista* li, int num, struct sistema *sus)
{
    if(li == NULL)
    {
        return 0;
    }

    int a,i = 0;

    while(i < li->quantidade && li->sis[i].n != num)
    {
        i++;
    }

    if (i == li->quantidade)
    {
        return 0;
    }

   *sus = li->sis[i];
}