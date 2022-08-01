#include <locale.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "FilaPrioridade.h"

void inicializaFilaPri(TFilaPri *FP){	//Inicializa a fila com Nulo e o contador com 0
	
	int i;
	FP->tempo[0] = 0;
	FP->tempo[1] = 0;
	for(i=0;i<3;i++)
		inicializaFila(&FP->prioridades[i]);
}

/*int filaPriVazia(TFilaPri *FP){
	
	int i,cont;
	
	for(i=0;i<3;){
		if(filaVazia(&FP->prioridades[i]))
			cont++;
		else
			i++;
	}
	
	if(cont == 3)
		return 1;	//Todas as filas estão vazias
	else
		return 0;	//Nem todas estão vazias
}*/

void insereElementoFilaPri(TFilaPri *FP, char elemNome[], int P){	//Insere o elemento na fila com prioridade desejada
	
	return insereElemento(&FP->prioridades[P], elemNome);
}

char *retiraElementoFilaPri(TFilaPri *FP){	//Retira um elemento da fila

	
	int i;
	
	for(i=0;i<3;){	//controle de fluxo pra percorrer as filas de 1 a 3
			
		if(!filaVazia(&FP->prioridades[i])){	//Verifica se a fila i não está vazia
			
			switch(i){
				
				case 0: 	//Se o i for 0 ele incrementa o contador da 2º e 3º fila
				
					if(!filaVazia(&FP->prioridades[1]))	//O conjunto de IF's verifica qual fila não está vazia para incrementar o contador
						FP->tempo[0]++;
					else
						FP->tempo[0] = 0;
						
					if(!filaVazia(&FP->prioridades[2]))
						FP->tempo[1]++;
					else
						FP->tempo[1] = 0;
					
					
				break;
				
				case 1:		//Se o i for 1 ele incrementa somente a 3º fila 
						
					if(!filaVazia(&FP->prioridades[2]))	//Verifica se a 3º fila não está vazia para incrementar o contador
						FP->tempo[1]++;
					else
						FP->tempo[1] = 0;		
					
				break;
			}
			
			return retiraElemento(&FP->prioridades[i]);	
			
		}else
			i++;	
		
	}		//Retorna a função de retirar e seu conteudo ou nulo caso esteja vazia
	
	return NULL;
}

void exibeFilaPri(TFilaPri FP){		//Exibe a fila através da função pronta
	
	int i;
	
	for(i=0;i<3;i++){
		printf("\n\n===========================|FILA DE PRIORIDADE %d|===========================\n\n", i);
		exibeFila(FP.prioridades[i]);
		printf("\n============================================================================\n\n");
	}
}

void AcionarAgging(TFilaPri *FP){
	
	char *ERetirado;
	
	char aggingRetirado[50];
	
	if(FP->tempo[1] >= 3){								//Se passar por todas e não achar quer dizer que o limite estorou na ultima então ele aciona o agging nela
					
		ERetirado = retiraElemento(&FP->prioridades[2]);
		insereElementoFilaPri(FP, ERetirado, 1);
		FP->tempo[1] = 0;

	}

	if(FP->tempo[0] >= 3){		//Se não, se estiver atingido o limite somente na fila respectiva ele aciona o agging nela
					
		ERetirado = retiraElemento(&FP->prioridades[1]);
		insereElementoFilaPri(FP, ERetirado, 0);
		FP->tempo[0] = 0;
					
	}
	printf("\n\n=====================================================================");
}

