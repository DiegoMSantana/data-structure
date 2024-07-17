#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int value;
    struct node *next;
} Node;

void imprime_lista(Node *head);
Node *insere_no_inicio(Node *head, int valor);
Node *insere_no_fim(Node *head, int valor);
Node *remove_do_inicio_da_lista(Node *inicio);
Node *remove_do_fim_da_lista(Node *fim);
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

    //Insere no fim
    lista = insere_no_fim(lista, 23);
    lista = insere_no_fim(lista, 7);
    lista = insere_no_fim(lista, 50);

    imprime_lista(lista);

    //Remove do inicio
    lista = remove_do_inicio_da_lista(lista);

    imprime_lista(lista);

    //Remove do fim da lista
    lista = remove_do_fim_da_lista(lista);

    imprime_lista(lista);

    printf("A quantidade de elementos no array eh: %d\n", quantidade_recursiva(lista));
    //printf("A quantidade de elementos no array eh: %d", quantidade_recursiva(lista));
    printf("O numero %d aparece %d na lista\n", 7, retorna_quantidade_encontrada(lista, 7));

    return 0;
}

void imprime_lista(Node *head){

    Node *current;
    current = head;

    int numero = 0;
    while(current != NULL) {

        if(numero == 0){
            printf("Inicio da lista - %d\n", current->value);
        } else if(numero > 0 && current->next != NULL){
            printf("%d\n", current->value);
        }

        if(current->next == NULL) {
            printf("Fim da lista - %d\n\n\n", current->value);
        }

        numero++;
        current = current->next;

    }
}

int quantidade_recursiva(Node *node) {

    if(node == NULL) return 0;
    else {
        return 1 + quantidade_recursiva(node->next);
    }
}

int retorna_quantidade_encontrada(Node *node, int valor) {

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

    if(fim == NULL) {
        return NULL;
    } else if(fim->next == NULL) {
        free(fim);
        return NULL;
    } else {

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
