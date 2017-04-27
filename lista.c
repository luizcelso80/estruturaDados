#include <stdio.h>
#include <stdlib.h>
#include "api.h"

struct no{
	int info;
	struct no *prox;
	struct no *ant;
};

No* inicia(void){
	return NULL;
}

No* insere(No* l, int v){
	No* n = (No*) malloc(sizeof(No));
	n->info = v;
	n->prox = l;
	n->ant = NULL;
	if(l != NULL) l->ant = n;
	return n;
}

void imprime(No* l){
	if(l == NULL) return;

	printf("%d\n", l->info);
	imprime(l->prox);
}

No* buscar(No* l, int v){
	No* tmp = l;
	while(tmp != NULL){
		if(tmp->info == v){
			return tmp;
		}
		tmp = tmp->prox;
	}
	return NULL;
}

No* retira(No* l, int v){
	No* n = buscar(l,v);
	if(n == NULL) return l;
	if(n == l){
		n->prox->ant = NULL;
		l = n->prox;
	}else if(n->prox == NULL){
		n->ant->prox = NULL;
	}else{
		n->ant->prox = n->prox;
		n->prox->ant = n->ant;
	}
	free(n);
	return l;
}