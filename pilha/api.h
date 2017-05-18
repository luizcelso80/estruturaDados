#include <stdio.h>
#include <stdlib.h>

#define SIZE 50
typedef struct pilha Pilha;

Pilha* cria();
void push(Pilha* p, float valor);
float pop(Pilha* p);
