#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct fila {
	int limite;
	int contador;
	int* dados;
};

Fila* create(int n) { 
	Fila* fi = (Fila*) malloc(sizeof(Fila)); // 1 | Y
	
	if(fi == NULL) { 
		return NULL; 
	}
	else {
		fi->dados = (int*) malloc(n * sizeof(int)); // 1 | n
		fi->limite = n; 
		fi->contador = 0; 
		return fi; 
	}
	
	// O(c) | O(n)
}

int add(Fila* fi, int e) { 
	if(fi!=NULL && fi->contador < fi->limite) { 
		int posicaoDaInsercao = fi->contador; 
		fi->dados[posicaoDaInsercao] = e; 
		fi->contador++; 
		return 1;
	}
	else { 
		return 0;
	}
	
	// O(c) | O(c)
}

int pop(Fila* fi) {
	if(fi!=NULL && fi->contador < fi->limite) {
		int i = 0;
		int k = 0;
		
		int * novoVetor = (int*) malloc(fi->limite * sizeof(int)); // 1 | limite
		
		for(i = 1; i < fi->contador; i++) { // 1 | contador
			novoVetor[k] = fi->dados[i];
			k++;
		}
		
		fi->contador--;
		free(fi->dados);
		fi->dados = novoVetor;
		
		return 1;
	}
	else {
		return 0;
	}
	return 0;
	
	// O(c) | O(n)
}

int size(Fila* fi) {
	if(fi!=NULL && !isEmpty(fi)) {
		return fi->contador;
	}
	else {
		return 0;
	}
	
	// O(c) | O(c)
}

int first(Fila* fi) {
	if(fi!=NULL && !isEmpty(fi)) {
		return fi->dados[0];
	}
	else {
		return -1;
	}
	
	// O(c) | O(c)
}

int last(Fila* fi) {
	if(fi!=NULL && !isEmpty(fi)) {
		int posicaoDoUltimoInserido = fi->contador-1;
		return fi->dados[posicaoDoUltimoInserido];
	}
	else {
		return -1;
	}
}

int find(Fila* fi, int ps) {
	if(fi!=NULL && !isEmpty(fi)) {
		int i = 0, aux;
		for(i = 0; i < fi->contador; i++) { // 1 | contador
			if(fi->dados[i] == ps) {
				aux=i;	
			}
		}
		
		if(aux > fi->contador) {
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

int isFull(Fila* fi) {
	if(fi == NULL) {
		return 0;
	}
	else {
		if(fi->contador >= fi->limite) {
			return 1;
		}
		else {
			return 0;
		}
	}
	
	// O(c) | O(c)
}

int isEmpty(Fila* fi) {
	if(fi == NULL) {
		return 0;
	}
	else {
		if(fi->contador <= 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	
	// O(c) | O(c)
}

int clear(Fila* fi) {	
	int i = 0;
	int aux = fi->contador;
	for(i = 0; i < aux; i++) { // 1 | contador
		pop(fi);
	}
	fi->contador=0;
	
	// O(c) | O(n)
}


