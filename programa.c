#include <stdio.h>
#include <stdlib.h>
#include <exclui_nodo.h>
/***********************************************/
/* Definição dos Registros                     */
/***********************************************/
#define N_MAX 20
typedef struct { //registro para uma pessoa
	int codigo;
	char nome[30];
}INFORMACAO;
typedef struct {//dados do registro
	INFORMACAO info[N_MAX];
	int f;//número de registro(s) ocupado(s) na estrutura
}NODO;//estrutura do tipo NODO

/***********************************************/
/* Programa Principal                          */
/***********************************************/
int main(void){
	NODO lista;//variável do tipo lista sequencial = vetor de registros
}

/*
https://www.google.com.br/search?safe=active&rlz=1C1GCEA_enBR781BR781&ei=t29sW42wA4b6wQTN4bjgAw&q=fun%C3%A7%C3%A3o+excluir+em+linguagem+c&oq=fun%C3%A7%C3%A3o+excluir+em+linguagem+c&gs_l=psy-ab.3..0i22i30k1.452113.460652.0.460861.19.15.0.0.0.0.522.1789.4-3j1.4.0....0...1c.1.64.psy-ab..15.4.1788...0j0i67k1j0i131i67k1j0i131k1.0.VIJAG_Da6S0

https://www.hardware.com.br/comunidade/cadastro-programa/1100702/

https://www.scriptbrasil.com.br/forum/topic/149429-excluir-registro-em-arquivo-c/

https://pt.stackoverflow.com/questions/138360/criar-fun%C3%A7%C3%A3o-de-excluir-em-projeto-em-c
*/