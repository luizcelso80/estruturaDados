#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0

struct  soldado{  
	char nome[50];
    struct soldado *next;
    struct soldado *prev;
} ;

struct  soldado *inicio;

void inicializa(){ 
	inicio = NULL; 
}

// insere um registro na lista.
int insereNaLista(struct soldado *v){ 
	struct soldado *andarilho=inicio;

    if (inicio==NULL){ 
		inicio = v; 
		v->next = v;
		v->prev = v; 
		return TRUE; 
    }

    do{
		if (andarilho->next == inicio){
			andarilho->next = v; 
			v->next=inicio;
			v->prev=andarilho;
			inicio->prev = v; 
			return TRUE;
		}else{  
			andarilho=andarilho->next;
		}
	} 
	while(andarilho != inicio);

	return TRUE;
}

int empty(){ 
	if (inicio==NULL){ 
		return TRUE;
	}
    return FALSE;
}

void imprime(){ 
	struct soldado *andarilho;
	andarilho=inicio;
	if (empty()){
		printf("\n--> Ninguem no Circulo!"); 
		return;
	}
	printf("\n\n--> Soldados do Circulo:");
	do {
       	printf("\nNome: %s",andarilho->nome);
       	andarilho=andarilho->next;
    }while (andarilho != inicio);
    printf("\n");
}

int lerArquivo(){ 
	FILE *fp;
	struct soldado *novo;
	inicializa();
	fp = fopen("josephus.txt","r");
	if ( fp == NULL){
		printf("\nERRO: Nao foi possivel abrir o arquivo ");
		printf("'josephus.txt' !\n");
		return FALSE; 
	}
	while (!feof(fp)){
		novo = (struct soldado *) malloc(sizeof(struct soldado));
		if(fscanf(fp,"\n%s",novo->nome)){
			insereNaLista(novo);
		}
	}
	fclose(fp);
	return TRUE;
}

int getQuantidade(struct soldado *lista){ 
	int saida = 1;
	struct soldado *c=lista;
	while(c->next != lista) {
		saida++; 
		c=c->next;
	}
	return saida;
}

void josephus(int lim){
	int c = 1;
	struct soldado *tmp = inicio;
	while(inicio->next != inicio){
		if(c == lim){
			c = 1;
			struct soldado *ret = tmp;
			
			tmp->prev->next = tmp->next;

			tmp->next->prev = tmp->prev;
			if(inicio == tmp) inicio = tmp->next;
			printf("O soldado %s vai esperar ajuda!\n", tmp->nome );
			tmp = tmp->next;
			free(ret);
		}else{
			
			tmp = tmp->next;
			c++;
		}
	}
	printf("O soldado %s foi buscar ajuda!!\n", inicio->nome );
}



int main(){
	inicializa();
	lerArquivo();
	imprime();  
	josephus(3);
	
 
  return TRUE;
}