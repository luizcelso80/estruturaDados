#include "api.h"
/**
 * Existem duas operacoes basicas que devem
 * ser implementadas em uma estrutura de plilha:
 *
 * -Operacao de empilhar no topo da pilha
 *  push()
 *
 * -Operacao de retirar um elemento do topo da pilha
 *  pop()
 *                push(A)       push(B)        push(C)         pop()
 *               ------        ------          ------         ------          ------      
 *              |      |      |      |        |      |       |      |        |      |     
 *               ------        ------          ------         ------          ------      
 *              |      |      |      | topo   |      |       |      |        |      |     
 *               ------        ------          ------         ------          ------      
 *              |      | topo |      |        |  C   | topo  |      |        |      |     
 *               ------        ------          ------         ------          ------      
 *        topo  |      |      |  B   |        |  B   |       |  B   |        |      |     
 *               ------        ------          ------         ------          ------ 
 *              |  A   |      |  A   |        |  A   |       |  A   |        |      |
 *               ------        ------          ------         ------          ------       
 */
struct no
{
	float valor;
	struct no* prox;
};

struct pilha
{
	int topo;
	float vet[SIZE];
};

Pilha* cria()
{
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->topo = NULL;
	return p;
}

No* inserir(No* l, float valor)
{
	No* novo = (No*) malloc(sizeof(No));
	novo->valor = valor;
	if(l == NULL) return novo;
	novo->prox = l;
	return novo;
}

No* retirar(No* l)
{
	No* tmp = l->prox;
	free(l);
	return tmp;
}

void push(Pilha* p, float valor)
{
	p->topo = inserir(p->topo, valor);
}

float pop(Pilha* p)
{
	if(p->topo == NULL)
	{
		printf("A pilha esta vazia!!\n");
		exit(1);
	}
	float valor = p->topo->valor;
	p->topo = retirar(p->topo);
	return valor;
}