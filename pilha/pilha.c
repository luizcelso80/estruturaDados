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

struct pilha
{
	int topo;
	float vet[SIZE];
};

Pilha* cria()
{
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->topo = 0;
	return p;
}

void push(Pilha* p, float valor)
{
	if(p == NULL) return;
	if(p->topo == SIZE)
	{
		printf("A pilha esta cheia\n");
		return;
	}
	p->vet[p->topo] = valor;
	p->topo++;
}

float pop()
{
	if(p == NULL) return;
	if(p->topo <= 0)
	{
		printf("A pilha esta vazia!!\n");
		return;
	}
	p->topo--;
	return p->vet[p->topo];
}