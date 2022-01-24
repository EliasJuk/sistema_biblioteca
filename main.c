#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

#define max_livros 100

/*****************************EFECTS***************************************/
#define NONE        "\033[0m"
#define BOLD        "\033[1m"
/*****************************COLORS***************************************/
#define C_VERMELHO  "\x1b[31m"
#define C_YELLOW    "\033[33m"
#define C_VERDE     "\x1b[32m"
#define C_AZUL      "\x1b[34m"
#define C_MAGENTA   "\033[35m"
#define C_CYAN      "\033[36m"
#define C_GRAY      "\033[37m"
#define C_RESET     "\x1b[0m"

/**************************************************************************/



int id_livro; //ID do ultimo livro cadastrado
id_livro = 1;

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
	printf(C_MAGENTA"******************************************************************\n"C_RESET);
	printf(C_MAGENTA"****************      "C_RESET"BIBLIOTECA VIRTUAL"C_MAGENTA"      ********************\n"C_RESET);
	printf(C_MAGENTA"******************************************************************\n"C_RESET);
}


int menu(){
	int opcao_menu;
	system("cls"); //Limpa a tela
	cabecalho(); //Chama a função que printa o cabeçalho
	
	printf("\n1- CADASTRAR LIVRO");
	printf("\n2- LISTAR TODOS LIVRO");
	printf("\n3- BUSCAR LIVRO");
	printf("\n4- Sair\n");
	printf("\nESCOLHA UMA OPCAO: ");
	scanf("%d", &opcao_menu);
	
	if (opcao_menu >= 1 && opcao_menu <= 3){
		switch(opcao_menu){
			case 1: cadastroLivros(); break;
			case 2: listarLivros(); break;
			case 3: buscarLivro(); break;
			case 4: break;
			default: menu();
		}	
	}else{
		menu();
	}

}

int cadastroLivros(){	
	system("cls"); //Limpa a tela
	cabecalho(); //Chama a função que printa o cabeçalho
	
	printf("CADASTRO DE LIVROS\n\n");
	
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
	
	
	
	//ID	
	id_livro = id_livro + 1; //Gera um novo ID
	
	
	printf("\n\nLIVRO CADASTRADO COM SUCESSO!\n\n");
	system("pause");
	menu();
}

listarLivros(){
	int i;
	
	for (i = 1; i <= id_livro; i++){
		printf("\n========================================\n");
		printf("\nCOD: %d", cadLivro[i].cod);
		printf("\nNOME: %s", cadLivro[i].nome);
		printf("\nAUTOR: %s", cadLivro[i].autor);
		printf("\nEDITORA: %s", cadLivro[i].editora);
	}
	
	system("pause");
	menu();
}


buscarLivro(){		
	system("cls"); //Limpa a tela
	cabecalho(); //Chama a função que printa o cabeçalho
	
	int j;
	char buscarLivroNome[50];
	
	printf(C_YELLOW"\nQual o nome do livro: "C_RESET );
	fflush(stdin);
	gets(buscarLivroNome);
	printf("\n========================================");
	
	
	for(j = 1; j <= id_livro; j++){
		//strcmp - FUNÇÃO PARA COMPRAR STRING
		if(strcmp(cadLivro[j].nome, buscarLivroNome) == 0) {
			printf("\nCOD: %d", cadLivro[j].cod);
			printf("\nNOME: %s", cadLivro[j].nome);
			printf("\nAUTOR: %s", cadLivro[j].autor);
			printf("\nEDITORA: %s", cadLivro[j].editora);
			printf("\n========================================\n\n");
		}
	}
	

	system("pause");
	menu();	
}
