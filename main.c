#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "FilaPrioridade.h"

int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL,"Portuguese");
	
	char *ERetirado;
	
	char elemRetirado[50];							//Declara��o de vari�veis
	char aggingRetirado[50];
	
	TFilaPri filaP;
	
	char nomeElem[50];
	
	int indMenu,prioridade;
	
	//MENU INICIAL
	
	printf("\n\n\n===========================|Bem Vindo � Fila de atendimento|===========================");
	
	inicializaFilaPri(&filaP);
				
	do{
	
		
		//OP��ES DO MENU
		
		printf("\n\nServi�os dispon�veis:\n"
				"1 - Inserir elemento na fila\n"
				"2 - Retirar elemento da fila\n"
				"3 - Retirar elemento e exib�-lo\n"
				"4 - Exibir fila atual\n"
				"0 - Sair do programa\n");
				
		printf("\n\nPor favor, digite o servi�o que necessita: ");			
		scanf("%d", &indMenu);
		
		if(indMenu < 0 || indMenu > 4){
		
			do{
				
				printf("\n\nERRO: n�mero inv�lido!"
				"Por favor, digite o servi�o que necessita baseado no menu apresentado: ");	//Verifica a integridade do scanf dentro dos padr�es apresentados
				scanf("%d", &indMenu);
				
			}while(indMenu < 0 || indMenu > 4);
			
		}
		
		//EXECU��O
	
		switch(indMenu){		//Verifica a integridade da escolha do usu�rio dentro dos padr�es apresentados
			
			case 0:		//Caso 0 ele fecha o programa
				
				printf("\nVoc� optou por sair do programa!"); 
				return 0;
				
			break;
			
			case 1:				//Caso 1 ele insere um elemento na fila da prioridade lida pelo usu�rio
				
				printf("\n\nPor favor, digite o nome do indiv�duo a ser acrescentado na fila: ");
				gets(nomeElem);
				scanf("%[^\n]", nomeElem);
				
				printf("\n\nPor favor, digite a prioridade do indiv�duo a ser acrescentado na fila: ");
				scanf("%d", &prioridade);
				
				if(prioridade < 0 || prioridade >3){	//Verifica a integridade da prioridade lida pelo usu�rio
		
					do{
						
						printf("\n\nERRO: prioridade inv�lida!"
						"\nPoss�veis prioridades: 0 - IDOSO, 1 - ESPECIAL, 2 - COMUM"
						"\n\nPor favor, digite a prioridade do indiv�duo a ser acrescentado na fila: ");
						scanf("%d", &prioridade);
						
					}while(prioridade < 0 || prioridade >2);
			
				}
				
				insereElementoFilaPri(&filaP, nomeElem, prioridade);	//Chama a fun��o de inserir
				
				printf("\n\nOpera��o conclu�da!");
				printf("\n\n=====================================================================");
				
			break;
			
			case 2:		//Caso 2 ele somente retira um elemento da fila
				
				ERetirado = retiraElementoFilaPri(&filaP);
				
				if(ERetirado != NULL)
					printf("\n\nOpera��o conclu�da, elemento retirado com sucesso!");
				else
					printf("\n\nERRO: Ocorreu underflow na fila, N�o existe elementos em nenhuma fila para ser retirado!");

				if((filaP.tempo[0] >= 3) || (filaP.tempo[1] >= 3))			//Verifica se o contador atingiu um limite de 3 vezes e caso sim chama o agging
					AcionarAgging(&filaP);		 

				printf("\n\n=====================================================================");
				
			break;
			
			case 3:		//Caso 3 ele retira e imprime o elemento subseguinte
				
				ERetirado = retiraElementoFilaPri(&filaP);
				
				if(ERetirado != NULL){			//Verifica se o retorno da fun��o n�o � nulo para entrar no if
				
					strcpy(elemRetirado, ERetirado);	//faz o elemRetirado receber o retorno da fun��o
					printf("\n\nOpera��o conclu�da, elemento retirado com sucesso!"
					"\n\nO nome do indiv�duo removido �: %s", elemRetirado);
					
				}else	
					printf("\n\nERRO: Ocorreu underflow na fila, N�o existe elementos em nenhuma fila para ser retirado!");
					
				if((filaP.tempo[0]) || (filaP.tempo[1]) >= 3)			//Verifica se o contador atingiu um limite de 3 vezes e caso sim chama o agging
					AcionarAgging(&filaP);
					
				printf("\n\n=====================================================================");
				
			break;
			
			case 4: //Exibe a fila de elementos como um todo

				exibeFilaPri(filaP);
			
			break;
		}
	
	}while(indMenu != 0);

	
	return 0;
}
