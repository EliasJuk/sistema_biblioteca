#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	menu();
}

int cabecalho() {	
	printf("******************************************************************\n");
	printf("****************      BIBLIOTECA VIRTUAL      ********************\n");
	printf("******************************************************************\n");
}


int menu(){
	int opcao_menu;
	cabecalho(); //Chama a função que printa o cabeçalho
	
	printf("\n1- CADASTRAR LIVRO");
	printf("\n2- BUSCAR LIVRO");
	printf("\n2- LISTAR TODOS LIVRO\n");
	printf("\nESCOLHA UMA OPCAO: ");
	scanf("%d", &opcao_menu);
	
	switch(opcao_menu){
		case 1: cadLivros(); break;
		case 2: cadLivros(); break;
		default: menu();
	}
}

int cadLivros(){
	system("cls"); //Limpa a tela
	cabecalho(); //Chama a função que printa o cabeçalho
	
	printf("CADASTRO DE LIVROS");	
}
