#include <stdio.h>
#include <stdlib.h>
#include "api.h"

struct simples
{
	int info;
	struct simples *prox;
};
struct no{
	int info;
	struct no *prox;
	struct no *ant;
};

No* inicia(void){
	return NULL;
}

No* insereFinal(No* l, int v){
	No* n = (No*) malloc(sizeof(No));
	if(l == NULL){
		n->info = v;
		n->prox = NULL;
		n->ant = NULL;
		l = n;
	}
	No* tmp = l;
	while(tmp != NULL){
		if(tmp->prox == NULL){
			n->info = v;
			n->prox = NULL;
			n->ant = tmp;
			tmp->prox = n;
		}
	}
	return l;
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

void imprimeCircular(No* l){
	No* p = l;
	if(p){
		do{
			printf("%d\n", p->info);
			p = p->ant;
		}while(p != l);
	}
}

No* insereCircular(No* l, int v){
	No* n = (No*) malloc(sizeof(No));
	n->info = v;
	if(l == NULL){
		n->prox = n;
		n->ant = n;
		l = n;
	}else{
		n->prox = l->prox;
		l->prox->ant = n;
		n->ant = l;
		l->prox = n;
	}
	return l;
}

No* retiraCircular(No* l, int v){
	No* tmp = l;
	if(l == NULL) return l;

	do{
		if(tmp->info == v){
			tmp->ant->prox = tmp->prox;
			tmp->prox->ant = tmp->ant;
			l = tmp->prox;
			break;
		}
		tmp = tmp->prox;
	}while(tmp != l);
	free(tmp);
	return l;
}

No* retiraCircular2(No* l, int v){
	No* tmp = l;

	if(tmp == NULL) return l;

	do{
		tmp = tmp->prox;
	}while(tmp != l && tmp->info != v);

	if(tmp->info != v) return l;

	if(tmp == l) l = tmp->prox;
	tmp->prox->ant = tmp->ant;
	tmp->ant->prox = tmp->prox;
	free(tmp);
	return l;
}

char * josephus(No* l, int corte){
	No* tmp = l;
	int conta = 1;
	
}