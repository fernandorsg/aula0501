//trabalhoP2
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#define ARQUIVO "dados.txt"
#define ARQUIVOSAIDA "dados.dat"

typedef struct {
	char nome[30];
	int matricula;
	float salario;
} Pessoal;

Pessoal pessoa;
char registro;
FILE *arquivo;
FILE *arqSaida;

void exibirMenu();
void importar();
void excluir();
void alterar(Pessoal *);


void incluir(Pessoal *);

main(){
	setlocale(LC_ALL, "Portuguese");
	
	int opcaoMenu;
	
	do {
		exibirMenu();
		scanf("%i", &opcaoMenu);
		
		switch(opcaoMenu){
			case 1:
				importar();
				break;
			case 2:
				incluir();
				break;
			case 3:
				alterar(&pessoa);
				break;
			case 4:
				excluir();
				break;
			case 0:
				exit(0);
			default:
				printf("Opção inválida, digite novamente: ");
				scanf("%i", &opcaoMenu);
		}
	} while (opcaoMenu != 0);
}

void exibirMenu(){
	printf("===== Registro Pessoas =====\n\n");
	printf("\t1 - Importar Arquivo\n");
	printf("\t2 - Incluir Pessoa\n");
	printf("\t3 - Alterar Pessoa\n");
	printf("\t4 - Excluir Pessoa\n");
	printf("\t0 - SAIR\n\n");
	printf("============================\n");
	printf("Escolha uma opção: ");
}

void importar(){
	char linha[45], nomeAux[30], salAux[7], matAux[5];
	int i = 0, j = 0, k = 0;	
	
	arquivo = fopen(ARQUIVO, "r");
	fgets(linha, 50, arquivo);
	while(!feof(arquivo)){
		for (i=0;i<30; i++){
			nomeAux[i] = linha[i];
		}
		for (i=31;i<=36;i++){
			matAux[j] = linha[i];
			j++;
		}
		for (i=37;i<44;i++){
			salAux[k] = linha[i];
			k++;
		}
		printf("%s %s %s \n", nomeAux, matAux, salAux);
		fgets(linha, 50, arquivo);
		strcpy(pessoa.nome, nomeAux);
		pessoa.matricula = atoi(matAux);
		pessoa.salario = atof(salAux);
		
		arqSaida=fopen(ARQUIVOSAIDA, "w");
		for(l=0; l<=10; l++) {
			fwrite(&pessoa, sizeof(Pessoal), 1, arqSaida);
		}
	}
	fclose(arquivo);
	fclose(arqSaida);
}

void excluir()
{
	arquivo = fopen("dados.dat", "w");
	
	fclose(arquivo);
}

void alterar(Pessoal *pPessoa){
	arquivo = fopen(ARQUIVOSAIDA, "w");

	pPessoa->nome="Fernando";
	pPessoa->matricula=9876;
	pPessoa->salario=1010.10;
	
	fclose(ARQUIVOSAIDA);
}

void incluir(Pessoal *pessoa){
	arquivo = fopen(ARQUIVOSAIDA, "a");
	
	printf("Nome: ");
	scanf("%s", pessoa.nome);
	printf("Matrícula: ");
	scanf("%d", &pessoa.matricula);
	printf("Salário: ");
	scanf("%f", &pessoa.salario);
	
	fclose(ARQUIVOSAIDA);
}