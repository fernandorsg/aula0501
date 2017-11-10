#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

struct typedef {
	char nome[30];
	int matricula;
	float salario;
} Pessoal;

char registro;
FILE *arquivo;

void alterar();
void excluir();
void exibirMenu();
void importar();
void incluir();
void localizar();
void limparTela();

main(){
	localizar();
	
	int opcaoMenu = 0;
	
	do {
		exibirMenu();
		scanf("%d", &opcaoMenu);
		
		switch (opcao){
			case 1:
				limparTela();
				importar();
				break;
			case 2:
				limparTela();
				incluir();
				break;
			case 3:
				limparTela();
				alterar();
				break;
			case 4:
				limparTela();
				excluir();
				break;
			default:
				close();
		}
	} while (opcao != 0);
}

void importar(){
	int opcao = 0;
	printf("===== Importação de Arquivo\n");
	printf("\t1 - Importar\n");
	printf("\t0 - Retornar\n");
	printf("======================\n");
	printf("Escolha uma opção: ");
	scanf("%d", &opcao);
	
	switch(opcao){
		case 1:
			arquivo = fopen("dados.txt", "r");
	
			if (arquivo == NULL) {
				printf("Erro ao importar o arquivo.");
			}
			else {
				while ((registro = fgetc(arquivo)) != EOF) {
					putchar(registro);
				}
			printf("Arquivo %s importado com exito!", arquivo);
			}
	}
	//fclose(arquivo);
	return 0;
}

void incluir(){
	printf("===== Incluir:\n");
	arquivo = fopen("dados.txt","a");
	
	if (arquivo == NULL) {
		printf("Erro ao importar o arquivo.");
	}
	else {
		printf("Digite o nome: ");
		fgets(Pessoa.nome);
		printf("Digite a matrícula: ");
		fgets(Pessoa.matricula);
		printf("Digite o salário: ");
		fgets(Pessoa.salario);
	}
}

void exibirMenu(){
	localizar();
	printf("===== Registro Pessoas\n");
	printf("\t1 - Importar Arquivo\n");
	printf("\t2 - Incluir Pessoa\n");
	printf("\t3 - Alterar Pessoa\n");
	printf("\t4 - Excluir Pessoa\n");
	printf("\t0 - SAIR\n");
	printf("======================\n");
	printf("Escolha uma opção: ");
}

void localizar(){
	setlocale(LC_ALL, "Portuguese");
}

void limparTela(){
	system("clear || cls");
}