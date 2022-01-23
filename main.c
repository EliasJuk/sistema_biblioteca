#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

#define max_livros 100

int id_livro; //ID do ultimo livro cadastrado

struct Livros{
	int cod;
	char nome[50];
	char autor[50];
	char editora[50];
};
struct Livros cadLivro[max_livros];


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
	system("cls"); //Limpa a tela
	cabecalho(); //Chama a função que printa o cabeçalho
	
	printf("\n1- CADASTRAR LIVRO");
	printf("\n2- BUSCAR LIVRO");
	printf("\n2- LISTAR TODOS LIVRO\n");
	printf("\nESCOLHA UMA OPCAO: ");
	scanf("%d", &opcao_menu);
	
	switch(opcao_menu){
		case 1: cadastroLivros(); break;
		case 2: buscarLivros(); break;
		default: menu();
	}
}

int cadastroLivros(){	
	system("cls"); //Limpa a tela
	cabecalho(); //Chama a função que printa o cabeçalho
	
	printf("CADASTRO DE LIVROS\n\n");
	
	//ID	
	id_livro = id_livro + 1; //Gera um novo ID
	printf("Livro: %d\n\n",id_livro);
		
	//COD
	cadLivro[id_livro].cod = id_livro; 
	
	//NOME
	printf("Nome do Livro: ");
	fflush(stdin);
	gets(cadLivro[id_livro].nome);
	
	//AUTOR
	printf("Nome Autor: ");
	fflush(stdin);
	gets(cadLivro[id_livro].autor);
	
	//EDITORA
	printf("Nome Editora: ");
	fflush(stdin);
	gets(cadLivro[id_livro].editora);
	
	printf("\n========================================\n");
	printf("\nCOD: %d", cadLivro[id_livro].cod);
	printf("\nNOME: %s", cadLivro[id_livro].nome);
	printf("\nAUTOR: %s", cadLivro[id_livro].autor);
	printf("\nEDITORA: %s", cadLivro[id_livro].editora);
	
	
	
	printf("\n\nLIVRO CADASTRADO COM SUCESSO!\n\n");
	system("pause");
	menu();
}

buscarLivros(){
	int i;
	
	for (i = 1; i <= id_livro; i++){
		printf("\n========================================\n");
		printf("\nCOD: %d", cadLivro[i].cod);
		printf("\nNOME: %s", cadLivro[i].nome);
		printf("\nAUTOR: %s", cadLivro[i].autor);
		printf("\nEDITORA: %s", cadLivro[i].editora);
	}
}
