typedef struct no No;

No* inicia(void);
No* insere(No* l, int v);
void imprime(No* l);
No* buscar(No* l, int v);
No* retira(No* l, int v);
void imprimeCircular(No* l);
No* insereCircular(No* l, int v);
No* retiraCircular(No* l, int v);
No* retiraCircular2(No* l, int v);