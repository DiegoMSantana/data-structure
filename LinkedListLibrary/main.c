#include <stdio.h>
#include <stdlib.h>
#include "llist.h"


int main()
{
    Node *lista = NULL;

    /*Node a,b,c;
    a.value = 5;
    b.value = 6;
    c.value = 7;

    a.next = &b;
    b.next = &c;

    c.next = NULL;*/

    //Insere no inicio
    lista = insere_no_inicio(lista, 7);
    lista = insere_no_inicio(lista, 15);
    lista = insere_no_inicio(lista, 16);
    lista = insere_no_inicio(lista, 17);
    lista = insere_no_inicio(lista, 18);

    //Insere no fim
    lista = insere_no_fim(lista, 23);
    lista = insere_no_fim(lista, 7);
    lista = insere_no_fim(lista, 18);
    lista = insere_no_fim(lista, 16);
    lista = insere_no_fim(lista, 50);

    imprime_lista(lista);

    //Remove do inicio
    //lista = remove_do_inicio_da_lista(lista);

    //imprime_lista(lista);

    //Remove do fim da lista
    //lista = remove_do_fim_da_lista(lista);

    //imprime_lista(lista);

    //bool deletado;
    //lista = remove_primeiro_valor_encontrado(lista, 50, &deletado);

    int num_deletado;
    lista = remove_valores_encontrados_modo_eficiente(lista, 7, &num_deletado);

    imprime_lista(lista);

    //printf("Your boolean variable is: %s\n", deletado ? "true" : "false");
    printf("A quantidade de elementos no array eh: %d\n", quantidade_recursiva(lista));
    printf("O numero %d aparece %d na lista\n", 7, retorna_quantidade_encontrada(lista, 7));

    return 0;
}


