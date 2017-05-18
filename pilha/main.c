#include "api.h"

/**
 * Pilha:
 * E uma das mais simples e mais utilizadas estrutura de dados.
 * A ideia fundamental da pilha e:Todo acesso a seus elementos
 * e feito por meio do seu topo.Assim quando um novo elemento e inserido na pilha,
 * ele passa a ser o topo e quando se quer retirar um elemento da pilha ,
 * e do topo que o fazemos.
 * A estrategia de movimentacao de elementos em uma pilha e' conhecida como LIFO
 * last in - first out. Em alusao ao fato de o ultimo elemento inserido
 * na pilha e sempre o primeiro a sair.
 * Para melhor entender uma pilha , pense em uma pilha de pratos ou
 * saco de cimentos.Em ambas as pilhas, inserimos e retiramos novos elementos sempre 
 * do topo.
 *                          ------
 *                 --------|      |
 *                 |        ------
 *                 V
 *               ------
 *              |      |
 *               ------
 *              |      |
 *               ------
 *              |      |
 *               ------
 *              |      |
 *               ------
 */

int main(void){
	Pilha* p = cria();
	push(p, 3.14159);
	push(p, -52);
	push(p, 25);

	printf("%f\n", pop(p) );
	return 0;
}