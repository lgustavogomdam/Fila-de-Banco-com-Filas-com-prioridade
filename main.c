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
	
	char elemRetirado[50];							//Declaração de variáveis
	char aggingRetirado[50];
	
	TFilaPri filaP;
	
	char nomeElem[50];
	
	int indMenu,prioridade;
	
	//MENU INICIAL
	
	printf("\n\n\n===========================|Bem Vindo à Fila de atendimento|===========================");
	
	inicializaFilaPri(&filaP);
				
	do{
	
		
		//OPÇÕES DO MENU
		
		printf("\n\nServiços disponíveis:\n"
				"1 - Inserir elemento na fila\n"
				"2 - Retirar elemento da fila\n"
				"3 - Retirar elemento e exibí-lo\n"
				"4 - Exibir fila atual\n"
				"0 - Sair do programa\n");
				
		printf("\n\nPor favor, digite o serviço que necessita: ");			
		scanf("%d", &indMenu);
		
		if(indMenu < 0 || indMenu > 4){
		
			do{
				
				printf("\n\nERRO: número inválido!"
				"Por favor, digite o serviço que necessita baseado no menu apresentado: ");	//Verifica a integridade do scanf dentro dos padrões apresentados
				scanf("%d", &indMenu);
				
			}while(indMenu < 0 || indMenu > 4);
			
		}
		
		//EXECUÇÃO
	
		switch(indMenu){		//Verifica a integridade da escolha do usuário dentro dos padrões apresentados
			
			case 0:		//Caso 0 ele fecha o programa
				
				printf("\nVocê optou por sair do programa!"); 
				return 0;
				
			break;
			
			case 1:				//Caso 1 ele insere um elemento na fila da prioridade lida pelo usuário
				
				printf("\n\nPor favor, digite o nome do indivíduo a ser acrescentado na fila: ");
				gets(nomeElem);
				scanf("%[^\n]", nomeElem);
				
				printf("\n\nPor favor, digite a prioridade do indivíduo a ser acrescentado na fila: ");
				scanf("%d", &prioridade);
				
				if(prioridade < 0 || prioridade >3){	//Verifica a integridade da prioridade lida pelo usuário
		
					do{
						
						printf("\n\nERRO: prioridade inválida!"
						"\nPossíveis prioridades: 0 - IDOSO, 1 - ESPECIAL, 2 - COMUM"
						"\n\nPor favor, digite a prioridade do indivíduo a ser acrescentado na fila: ");
						scanf("%d", &prioridade);
						
					}while(prioridade < 0 || prioridade >2);
			
				}
				
				insereElementoFilaPri(&filaP, nomeElem, prioridade);	//Chama a função de inserir
				
				printf("\n\nOperação concluída!");
				printf("\n\n=====================================================================");
				
			break;
			
			case 2:		//Caso 2 ele somente retira um elemento da fila
				
				ERetirado = retiraElementoFilaPri(&filaP);
				
				if(ERetirado != NULL)
					printf("\n\nOperação concluída, elemento retirado com sucesso!");
				else
					printf("\n\nERRO: Ocorreu underflow na fila, Não existe elementos em nenhuma fila para ser retirado!");

				if((filaP.tempo[0] >= 3) || (filaP.tempo[1] >= 3))			//Verifica se o contador atingiu um limite de 3 vezes e caso sim chama o agging
					AcionarAgging(&filaP);		 

				printf("\n\n=====================================================================");
				
			break;
			
			case 3:		//Caso 3 ele retira e imprime o elemento subseguinte
				
				ERetirado = retiraElementoFilaPri(&filaP);
				
				if(ERetirado != NULL){			//Verifica se o retorno da função não é nulo para entrar no if
				
					strcpy(elemRetirado, ERetirado);	//faz o elemRetirado receber o retorno da função
					printf("\n\nOperação concluída, elemento retirado com sucesso!"
					"\n\nO nome do indivíduo removido é: %s", elemRetirado);
					
				}else	
					printf("\n\nERRO: Ocorreu underflow na fila, Não existe elementos em nenhuma fila para ser retirado!");
					
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
