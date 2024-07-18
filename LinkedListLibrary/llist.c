#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

void imprime_lista(Node *head)
{
    Node *current;
    current = head;

    int numero = 0;
    while(current != NULL) {

        if(numero == 0) {
            printf("Inicio da lista - %d\n", current->value);
        }
        else if(numero > 0 && current->next != NULL){
            printf("%d\n", current->value);
        }

        if(current->next == NULL){
            printf("Fim da lista - %d\n\n\n", current->value);
        }

        numero++;
        current = current->next;
    }
}

int quantidade_recursiva(Node *node) {
    if(node == NULL) return 0;
    else{
        return 1 + quantidade_recursiva(node->next);
    }
}

int retorna_quantidade_encontrada(Node *node, int valor){
    if(node == NULL) return 0;
    else if(node->value == valor)
        return 1 + retorna_quantidade_encontrada(node->next, valor);
    else
        return retorna_quantidade_encontrada(node->next, valor);
}

bool is_member(Node *node, int valor) {

    if(node == NULL) return false;
    else if(node->value == valor) return true;
    else return is_member(node->next, valor);
}

void substitui_valores(Node *node, int valor_encontrar, int novo_valor) {
    if(node != NULL){
        if(node->value == valor_encontrar){
           node->value = novo_valor;
           substitui_valores(node->next, valor_encontrar, novo_valor);
        }
    }
}

Node *insere_no_inicio(Node *head, int valor) {

    Node *novo_valor = calloc(1, sizeof(Node));
    novo_valor->value = valor;

    if(head == NULL) return novo_valor;
    else {
        novo_valor->next = head;
        return novo_valor;
    }
}

Node *insere_no_fim(Node *head, int valor) {

    Node *novo_valor = calloc(1, sizeof(Node));
    novo_valor->value = valor;

    if(head == NULL) return novo_valor;
    else {

        Node *current = head;
        while(current->next != NULL) {
            current = current->next;
        }

        current->next = novo_valor;
        return head;
    }
}

Node *remove_do_inicio_da_lista(Node *inicio) {

    if(inicio == NULL) return NULL;
    else {
        printf("Removendo o valor: %d do inicio da lista...\n\n\n", inicio->value);
        Node *novo_inicio = inicio->next;
        free(inicio);

        return novo_inicio;
    }
}

Node *remove_do_fim_da_lista(Node *fim) {

    if(fim == NULL) return NULL;
    else if(fim->next == NULL) {
        free(fim);
        return NULL;
    }
    else {

        Node *atual = fim;
        Node *anterior = NULL;

        while (atual->next != NULL) {
            anterior = atual;
            atual = atual->next;
        }

        anterior->next = NULL;
        free(atual);

        return fim;
    }
}

Node *remove_primeiro_valor_encontrado(Node *node, int valor_deletar, bool *foi_deletado) {

    if(node == NULL) {
        *foi_deletado = false;
        return NULL;
    }

    if(node->value == valor_deletar) {

        Node *temp = node->next;
        free(node);
        *foi_deletado = true;
        return temp;
    }

    Node *atual = node->next;
    Node *anterior = node;

    while(atual != NULL) {

        if(atual->value == valor_deletar) {
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

    while(atual->value == valor_deletar) {

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
