#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista {
	int limite;
	int contador;
	int* dados;
};

Lista* create(int n) {
	Lista* li = (Lista*) malloc(sizeof(Lista)); // 1 | Y
	
	if(li == NULL) {
		return NULL;
	}
	else {
		li->dados = (int*) malloc(n * sizeof(int)); // 1 | n
		li->limite = n;
		li->contador = 0;
		return li;
	}
	
	// O(c) | O(n)
}

int add(Lista* li, int e) {
	if(li!=NULL && li->contador < li->limite) {
		int posicaoDaInsercao = li->contador;
		li->dados[posicaoDaInsercao] = e;
		li->contador++;
		return 1;
	}
	else {
		return 0;
	}
	
	// O(c) | O(c)
}

int pop(Lista* li, int e) {
	if(li!=NULL && !isEmpty(li)) {
		int i = 0;
		int k = 0;
		int j = -1;
		
		for(i = 0; i < li->contador; i++) { // 1 | contador
			if(li->dados[i] == e) {
				j = i;
				break;
			}
		}
		
		if(j!=-1) {
			int * novoVetor = (int*) malloc(li->limite * sizeof(int)); // 1 | limite
			
			for(i = 0; i < li->contador; i++) { // 1 | contador
				if(i != j) {
					novoVetor[k] = li->dados[i];
					k++;
				}
			}
			
			li->contador--;
			free(li->dados);
			li->dados = novoVetor;
			
			return 1;
		}
		
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
	
	// O(c) | O(n)
}

int size(Lista* li) {
	if(li!=NULL && !isEmpty(li)) {
		return li->contador;
	}
	else {
		return 0;
	}
	
	// O(c) | O(c)
}

int find(Lista* li, int ps) {
	if(li!=NULL && !isEmpty(li)) {
		int i = 0, aux;
		for(i = 0; i < li->contador; i++) { // 1 | contador
			if(li->dados[i] == ps) {
				aux=i;	
			}
		}
		
		if(aux > li->contador) {
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

int isFull(Lista* li) {
	if(li == NULL) {
		return 0;
	}
	else {
		if(li->contador >= li->limite) {
			return 1;
		}
		else {
			return 0;
		}
	}
	
	// O(c) | O(c)
}

int isEmpty(Lista* li) {
	if(li == NULL) {
		return 0;
	}
	else {
		if(li->contador <= 0) {
			return 1;
		}
		
		else {
			return 0;
		}	
	}
	
	// O(c) | O(c)
}

int clear(Lista* li) {
	int i = 0;
	
	for(i = 0; i < li->contador; i++) { // 1 | contador
		pop(li, i);
	}
	li->contador = 0;
	
	// O(c) | O(n)
}
