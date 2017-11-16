#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#define ARQUIVO "dados.txt"

typedef struct {
	char nome[30];
	int matricula;
	float salario;
} Pessoal;

Pessoal pessoa;
char registro;
FILE *arquivo;

void exibirMenu();
void importar();
void alterar(Pessoal *);
void excluir(Pessoal *);
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
				//incluir();
				break;
			case 3:
				alterar(&pessoa.nome, &pessoa.matricula, &pessoa.salario);
				break;
			case 4:
				//excluir();
				break;
			case 0:
				close();
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
	int cont = 1;
	arquivo = fopen(ARQUIVO, "r");
	printf("============================\n");
	printf("%-30s %-6s %8s \n", "Nome", "Código", "Salário");
	while(!feof(arquivo)){
		fscanf(arquivo, "%s%d%f ", pessoa.nome, &pessoa.matricula, &pessoa.salario);
		printf("%-30s %-6d %8.2f \n", pessoa.nome, pessoa.matricula, pessoa.salario);
	}
	fclose(arquivo);
}

void alterar(Pessoal *pNome, Pessoal *pSalario){
	int matriculaRecuperada;
	importar();
	
	printf("Escolha o funcionário a alterar\n");
	printf("Digite a matricula: ");
	scanf("%i", &matriculaRecuperada);
}

void excluir(Pessoal *) {
	
	arquivo = fopen(ARQUIVO,"w");
	
	printf("===== Excluir Usuário\n");
	printf("Digite a matrícula: \n");
	scanf("%d", &pessoa.matricula);
	
	fclose(arquivo);
}

void incluir(){
	
	printf("===== Incluir:\n");
	arquivo = fopen(ARQUIVO,"a+");
	
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

#include <stdio.h>
typedef struct{
    char nome[30];
    int matricula;
    float salario;
} Pessoal;

Pessoal pessoa;

void alteraEstrutura(Pessoa *);
main() {
    pessoa.nome= "Fernando";
    pessoa.matricula= 12345;
    pessoa.salario= 1234.56;
    printf("%s %d %.2f \n", pessoa.nome, pessoa.matricula, pessoa.salario);
    Pessoa *pPessoa= &pessoa;
    alteraEstrutura(pPessoa);
    printf("%s %d %.2f \n", pPessoa->nome, pPessoa->matricula, pPessoa->salario);
}
void alteraEstrutura(Pessoa *pPessoa) {
    pPessoa->nome= "Rogerio";
    pPessoa->matricula= 98765;
    pPessoa->salario= 9876.54;
}