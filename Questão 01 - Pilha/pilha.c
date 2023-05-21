#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct pilha{
	int limite;
	int contador;
	int* dados;
};

Pilha* create(int n) {
	Pilha* pi = (Pilha*) malloc(sizeof(Pilha)); // 1 | Y
	
	if(pi == NULL) {
		return NULL;
	}
	else {
		pi->dados = (int*) malloc(n * sizeof(int)); // 1 | n
		pi->limite = n;
		pi->contador = 0;
		return pi;
	}
	
	// O(c) | O(n)
}

int add(Pilha* pi, int e) {
	if(pi!=NULL && pi->contador < pi->limite) {
		int posicaoDaInsercao = pi->contador;
		pi->dados[posicaoDaInsercao] = e;
		pi->contador++;
		return 1;
	}
	else {
		return 0;
	}
	
	// O(c) | O(c)
}

int pop(Pilha* pi) {
	if(pi!=NULL && !isEmpty(pi)) {
		int i = 0;
		int k = 0;
		
		int * novoVetor = (int*) malloc(pi->limite * sizeof(int)); // 1 | limite
		
		for (i = 0; i < pi->contador; i++) { // 1 | contador
			novoVetor[k] = pi->dados[i];
			k++;
		}
		
		pi->contador--;
		free(pi->dados);
		pi->dados = novoVetor;
		
		return 1;
	}
	else {
		return 0;
	}
	
	// O(c) | O(n)
}

int size(Pilha* pi) {
	if(pi!=NULL && !isEmpty(pi)) {
		return pi->contador;
	}
	else {
		return 0;
	}
	
	// O(c) | O(c)
}

int top(Pilha* pi) {
	if(pi!=NULL && !isEmpty(pi)) {
		return pi->dados[pi->contador-1];
	}
	else {
		return -1;
	}
	
	// O(c) | O(c)
}

int bottom(Pilha* pi) {
	if(pi!=NULL && !isEmpty(pi)) {
		return pi->dados[0];
	}
	else {
		return -1;
	}
	
	// O(c) | O(c)
}

int find(Pilha* pi, int ps) {
	if(pi!=NULL && !isEmpty(pi)) {
		int aux;
		int i = 0;
		for(i = 0; i < pi->contador; i++) { // 1 | contador
			if(pi->dados[i] == ps) {
				aux=i;	
			}
		}
		
		if(aux > pi->contador) {
			return -1;
		}
		else {
			return aux;
		}
	}
	else {
		return 0;
	}
	
	// O(c) | O(n)
}

int isFull(Pilha* pi) {
	if(pi == NULL) {
		return 0;
	}
	else {
		if(pi->contador >= pi->limite) {
			return 1;
		}
		else {
			return 0;
		}
	}
	
	// O(c) | O(c)
}

int isEmpty(Pilha* pi) {
	if(pi == NULL) {
		return 0;
	}
	else {
		if(pi->contador <= 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	
	// O(c) | O(c)
}

int clear(Pilha* pi) {
	int i = 0;
	for(i = 0; i <= pi->contador; i++) { // 1 | contador
		pop(pi);
	}
	pi->contador = 0;
	
	// O(c) | O(n)
}
