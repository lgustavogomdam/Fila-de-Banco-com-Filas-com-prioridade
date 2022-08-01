#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "Fila.h"

void inicializaFila(TFila *f){		//Inicializa a fila com Nulo
	
	f->inic = NULL;
	f->fim = NULL;
	
}

int filaVazia(TFila *f){	//Verifica se a fila est� vazia retornando 1 para sim e 0 para n�o
	
	if(f->inic == NULL)
		return 1;
	else
		return 0;
}

void insereElemento(TFila *f, char elemNome[]){		//Insere um elemento novo na fila
	
	TElemento *novo;
	
	novo = (TElemento *)malloc(sizeof(TElemento));
	strcpy(novo->nome, elemNome);
	novo -> prox = NULL;
	novo -> ant = NULL;
	
	if(filaVazia(f)){		//Se a fila estiver vazia o novo vai ser o inicio e fim da fila
		f->inic = novo;
		f->fim = novo;
	}else{					//Se n�o, insere o elemento no fim da fila
		f->fim->prox = novo;
		novo->ant = f->fim;
		f->fim = novo;
	}
}

void exibeFila(TFila f){		//Exibe a fila
	
	TElemento *atual;
	int contador = 0;
	
	//printf("\n\n\n===========================|IN�CIO DA FILA|===========================\n\n\n");
	
	atual = f.inic;
	
	while (atual != NULL){	//Imprimir enquanto o ponteiro for diferente de Nulo
		
		printf("\n\tO %d-�simo da fila �: %s\n", ++contador,atual->nome);
		atual = atual->prox;
	
	}
	
	//printf("\n\n\n===========================|FIM DA FILA|===========================\n\n\n");
	
}

char *retiraElemento(TFila *f){		//Retira um elemento da fila
	
	TElemento *retirado;
	char *elemRetirado = NULL;

	retirado = NULL;
	
	if(!filaVazia(f)){				//Se a fila n�o estiver vazia ele vai retirar o elemento e copi�-lo em um auxiliar para dps retorn�-lo
		
		elemRetirado = (char*)malloc(50*sizeof(char));
		
		retirado = f->inic;
		
		f->inic = f->inic->prox;
		
		if(f->inic == NULL)
			f->fim = NULL;
		else
			f->inic->ant = NULL;
		
		retirado->prox = NULL;
		
		strcpy(elemRetirado, retirado->nome);
	}else{
		
		printf("\n\nERRO: Ocorreu underflow na fila, N�o existe elementos em nenhuma fila para ser retirado!");
	}
	
	free(retirado); //Libera a mem�ria do 1� auxiliar
	
	return elemRetirado;
}


