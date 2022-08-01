#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct Elemento{		//Define a struct Elemento com um campo char para o nome e um ponteiro para elementos anteriores e próximos
	
	char nome[50];
	struct Elemento *ant,*prox;
	
}TElemento;

typedef struct Fila{			//Define a struct Fila com um ponteiro para elemento inicial e final
	
	TElemento *inic, *fim;
	
}TFila;

void inicializaFila(TFila *f);	//------------------
												// |
int filaVazia(TFila *f);						// |
												// |
void insereElemento(TFila *f, char *elemNome);	// |---------Chamada de função da biblioteca .c
												// |
void exibeFila(TFila f);						// |
												// |
char *retiraElemento(TFila *f);	//------------------
