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
