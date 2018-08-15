#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "exclui_nodo.h"
/***********************************************/ 
/* Definição dos Registros                     */
/***********************************************/ 
#define N_MAX 20
typedef struct {			// registro para uma pessoa       
	int codigo;       
	char nome[30];
}INFORMACAO;       
typedef struct {       
	INFORMACAO info[N_MAX];	// dados do registro       
	int f;					// número de registro(s) ocupado(s) na estrutura
}NODO;						// estrutura do tipo NODO

void exclui_nodo (void);
 
/***********************************************/
/* Programa Principal                          */
/***********************************************/
int main(void){
	NODO *lista;			// variável do tipo lista sequencial = vetor de registros
	
	*//lista.info[0].codigo = 1;
	//lista.info[0].nome = "Joao";
	//lista.info[1].codigo = 2;
	//lista.info[1].nome  = "Jose";
	//lista.info[2].codigo= 3;
	//lista.info[2].nome = "Mario";
	
	exclui_nodo(*lista);
}

void exclui_nodo (NODO *lista){	
	int codExclusao;

	if(lista.f < 1){
		printf("A lista esta vazia, nao existem pacientes cadastrados.\n");
	}
	else{
		printf("Codigo - Paciente\n");
		for(int i = 0; i <= lista.info[N_MAX]; i++){
			printf("%d - %s\n", lista.info[i].codigo, lista.info[i].nome);
		}
		
		printf("Digite o codigo do paciente para a exclusao: ");
		scanf("%d", &codExclusao);
		
		if(codExclusao == ""){
			printf("Opcao invalida!!!\n");
			printf("Digite o codigo do paciente para a exclusao: ");
			scanf("%d", &codExclusao);
		}
		else{
			for(int j = 0; j <= lista.info[N_MAX]; j++){
				if(codExclusao == lista.info[j].codigo){
					lista.info[j].codigo = "";
					lista.info[j].nome = "";
				
					for (int m = j; m <= N_MAX; m++){
						lista.info[m].codigo = lista.info[m].codigo[m + 1];
						lista.info[m].nome = lista.info[m].nome[m + 1];
					}
				}
			}
		}
	}
}
