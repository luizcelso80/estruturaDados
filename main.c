#include <stdio.h>
#include <stdlib.h>
#include "api.h"


int main(void){
	No* l = inicia();

	/*l = insere(l,23);
	l = insere(l,45);
	l = insere(l,56);
	l = insere(l,78);

	imprime(l);
	printf("\n\n");

	l = retira(l,23);
	l = retira(l,56);

	imprime(l);
	printf("\n\n");*/


	l = insereCircular(l,23);
	l = insereCircular(l,45);
	l = insereCircular(l,56);
	l = insereCircular(l,78);

	imprimeCircular(l);
	printf("\n\n");

	l = retiraCircular2(l,23);
	l = retiraCircular2(l,56);

	imprimeCircular(l);
	printf("\n\n");
	
	return 0;
}