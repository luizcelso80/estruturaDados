#include <stdio.h>
#include <stdlib.h>

#define SIZE 50
typedef struct no No;
typedef struct pilha Pilha;

Pilha* cria();
No* inserir(No* l, float valor);
No* retirar(No* l);
void push(Pilha* p, float valor);
float pop(Pilha* p);
