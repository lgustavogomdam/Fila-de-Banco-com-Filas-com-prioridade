#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "Fila.h"

typedef struct FilaPri{		//Define a struct FilaPri com um campo struct ja definido e um contador

	TFila prioridades[3];
	int tempo[2];
	
}TFilaPri;

void inicializaFilaPri(TFilaPri *filaPrioritaria); //-----------------------
																		// |
int filaPriVazia(TFilaPri *FP);											// |
																		// |
void insereElementoFilaPri(TFilaPri *FP, char elemNome[], int P);		// |
																		// |---------Chamada de função da biblioteca .c
char* retiraElementoFilaPri(TFilaPri *FP);										// |
																		// |
void exibeFilaPri(TFilaPri FP);											// |
																		// |
void AcionarAgging(TFilaPri *FP); //----------------------------------------
