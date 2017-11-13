#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
	char nome[30];
	int matricula;
	float salario;
} Pessoal;

char registro;
FILE *arquivo;

void alterar(Pessoal *);
void excluir(Pessoal *);
void exibirMenu();
void importar();
void incluir(Pessoal *);
void localizar();

main(){
	localizar();
	
	int opcaoMenu = 0;
	
	do {
		exibirMenu();
		scanf("%d", &opcaoMenu);
		
		switch (opcao){
			case 1:
				importar();
				break;
			case 2:
				incluir();
				break;
			case 3:
				alterar();
				break;
			case 4:
				excluir();
				break;
			case 0:
				close();
			default:
				printf("Opção inválida, digite novamente: ");
				scanf("%d", &opcaoMenu);
		}
	} while (opcao != 0);
}

void importar(){
	Pessoal pessoa;
	arquivo = fopen("dados.txt", "r");
	
	if (arquivo == NULL) {
		printf("Erro ao importar o arquivo.");
	} else {
		printf("==== Arquivo: %s importado com exito.\n", arquivo);
		printf("%30s %5s %s\n", Nome, Matricula, Salario);
		while (!feof(arquivo)) {
			fscanf(arquivo, "%s %d %f", pessoa.nome, &pessoa.matricula, &pessoa.salario);
			printf("%30s %5d %.2f\n", pessoa.nome, pessoa.matricula, pessoa.salario);
		}
	}
}

void alterar(Pessoal *){
	Pessoal pessoa;
	
	arquivo = fopen("dados.txt","r");
	
	printf("===== Alterar Dados do Usuário\n");
	printf("\tDigite a matrícula: \n");
	scanf("%d", &pessoa.matricula);
	
	fclose(arquivo);
}

void excluir(Pessoal *) {
	Pessoal pessoa;
	
	arquivo = fopen("dados.txt","w");
	
	printf("===== Excluir Usuário\n");
	printf("Digite a matrícula: \n");
	scanf("%d", &pessoa.matricula);
	
	fclose(arquivo);
}

void exibirMenu(){
	localizar();
	printf("===== Registro Pessoas =====\n");
	printf("\t1 - Importar Arquivo\n");
	printf("\t2 - Incluir Pessoa\n");
	printf("\t3 - Alterar Pessoa\n");
	printf("\t4 - Excluir Pessoa\n");
	printf("\t0 - SAIR\n");
	printf("======================\n");
	printf("Escolha uma opção: ");
}

void incluir(){
	Pessoal pessoa;
	
	printf("===== Incluir:\n");
	arquivo = fopen("dados.txt","a+");
	
	if (arquivo == NULL) {
		printf("Erro ao abrir o arquivo.");
	} else {
		printf("Digite o nome: ");
		fgets(pessoa.nome);
		printf("Digite a matrícula: ");
		fgets(pessoa.matricula);
		printf("Digite o salário: ");
		fgets(pessoa.salario);
	}
}

void localizar(){
	setlocale(LC_ALL, "Portuguese");
}