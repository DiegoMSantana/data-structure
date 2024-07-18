/**
*
*   Linked List Library
*   @file main.c
*   @author Diego Santana
*   @date 17/07/2024
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int value;
    struct node *next;
} Node;

Node *insere_no_inicio(Node *head, int valor);
Node *insere_no_fim(Node *head, int valor);
Node *remove_do_inicio_da_lista(Node *inicio);
Node *remove_do_fim_da_lista(Node *fim);
Node *remove_primeiro_valor_encontrado(Node *node, int valor_deletar, bool *foi_deletado);
Node *remove_todos_valores_encontrados(Node *node, int valor_deletado, int *valor_deletar);
Node *remove_valores_encontrados_modo_eficiente(Node *node, int valor_deletar, int *num_deletado);

void imprime_lista(Node *head);
int quantidade_recursiva(Node *node);
bool is_member(Node *node, int valor);
int retorna_quantidade_encontrada(Node *node, int valor);
void substitui_valores(Node *node, int valor_encontrar, int novo_valor);


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

void imprime_lista(Node *head)
{

    Node *current;
    current = head;

    int numero = 0;
    while(current != NULL)
    {

        if(numero == 0)
        {
            printf("Inicio da lista - %d\n", current->value);
        }
        else if(numero > 0 && current->next != NULL)
        {
            printf("%d\n", current->value);
        }

        if(current->next == NULL)
        {
            printf("Fim da lista - %d\n\n\n", current->value);
        }

        numero++;
        current = current->next;

    }
}

int quantidade_recursiva(Node *node)
{

    if(node == NULL) return 0;
    else
    {
        return 1 + quantidade_recursiva(node->next);
    }
}

int retorna_quantidade_encontrada(Node *node, int valor)
{

    if(node == NULL) return 0;
    else if(node->value == valor)
        return 1 + retorna_quantidade_encontrada(node->next, valor);
    else
        return retorna_quantidade_encontrada(node->next, valor);

}

bool is_member(Node *node, int valor)
{

    if(node == NULL) return false;
    else if(node->value == valor) return true;
    else return is_member(node->next, valor);

}

void substitui_valores(Node *node, int valor_encontrar, int novo_valor)
{

    if(node != NULL)
    {

        if(node->value == valor_encontrar)
        {
            node->value = novo_valor;

            substitui_valores(node->next, valor_encontrar, novo_valor);
        }
    }

}

Node *insere_no_inicio(Node *head, int valor)
{

    Node *novo_valor = calloc(1, sizeof(Node));
    novo_valor->value = valor;

    if(head == NULL) return novo_valor;
    else
    {
        novo_valor->next = head;
        return novo_valor;
    }
}

Node *insere_no_fim(Node *head, int valor)
{

    Node *novo_valor = calloc(1, sizeof(Node));
    novo_valor->value = valor;

    if(head == NULL) return novo_valor;
    else
    {
        Node *current = head;
        while(current->next != NULL)
        {
            current = current->next;
        }

        current->next = novo_valor;
        return head;
    }

}

Node *remove_do_inicio_da_lista(Node *inicio)
{

    if(inicio == NULL) return NULL;
    else
    {
        printf("Removendo o valor: %d do inicio da lista...\n\n\n", inicio->value);
        Node *novo_inicio = inicio->next;
        free(inicio);

        return novo_inicio;
    }
}

Node *remove_do_fim_da_lista(Node *fim) {

    if(fim == NULL)
    {
        return NULL;
    }
    else if(fim->next == NULL)
    {
        free(fim);
        return NULL;
    }
    else
    {

        Node *atual = fim;
        Node *anterior = NULL;

        while (atual->next != NULL)
        {
            anterior = atual;
            atual = atual->next;
        }

        anterior->next = NULL;
        free(atual);

        return fim;
    }
}

Node *remove_primeiro_valor_encontrado(Node *node, int valor_deletar, bool *foi_deletado)
{

    if(node == NULL)
    {
        *foi_deletado = false;
        return NULL;
    }

    if(node->value == valor_deletar)
    {

        Node *temp = node->next;
        free(node);
        *foi_deletado = true;
        return temp;
    }

    Node *atual = node->next;
    Node *anterior = node;

    while(atual != NULL)
    {

        if(atual->value == valor_deletar)
        {
            anterior->next = atual->next;
            free(atual);
            *foi_deletado = true;
            return node;
        }

        anterior = atual;
        atual = atual->next;

    }

    *foi_deletado = false;
    return node;

}

Node *remove_todos_valores_encontrados(Node *node, int valor_deletado, int *numero_deletado){

    Node *atual = node;
    bool deletado = false;
    *numero_deletado = 0;

    do {
        atual = remove_primeiro_valor_encontrado(atual, valor_deletado, &deletado);
        if(deletado) *numero_deletado = *numero_deletado + 1;
    } while (deletado);

    return atual;
}

Node *remove_valores_encontrados_modo_eficiente(Node *node, int valor_deletar, int *num_deletado){

    if(node == NULL) return NULL;

    Node *atual, *temp, *novo_node;
    atual = node;
    *num_deletado = 0;

    while (atual->value == valor_deletar) {

        temp = atual;
        atual = atual->next;
        free(temp);
        *num_deletado = *num_deletado + 1;

        if(atual == NULL) return NULL;
    }

    novo_node = atual;

    while(atual->next != NULL) {

        if(atual->next->value == valor_deletar) {
            temp = atual->next;
            atual->next = atual->next->next;
            free(temp);
            *num_deletado = *num_deletado + 1;
        }
        else atual = atual->next;

    }

    return novo_node;
}

