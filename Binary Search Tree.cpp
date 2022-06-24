#include<stdio.h>							   
#include<stdlib.h>
#include<string.h> //biblioteca para manipulação de strings
#include<locale.h> //biblioteca para utilização de acentuação

struct Cadastro { // criação da estrutura de dados
	char nome[30];
	char email[32];
	int ru;
	struct Cadastro* direita, * esquerda;
}*root;

void Inserir(Cadastro** ElementoVarredura, char* vetor_nome, char* vetor_email, int vetor_ru);
Cadastro* Buscar(Cadastro** ElementoVarredura, int num);

int  main() {
	Cadastro* ElementoBusca;
	ElementoBusca = (Cadastro*)malloc(sizeof(Cadastro));
	setlocale(LC_ALL, "Portuguese");
	int num = 1, c;

	/*Abaixo está o pré cadastro com os dados que serão inseridos na estrutura do tipo árvore*/
	char vetor_nome[10][30] = { "José da Silva", "João dos Santos", "Maria de Souza", "Ana Pereira", "Reginaldo G. Santos", "Isabella Ferraz", "Joaquim Sá", "Antônio Vargas", "Marcela Veiga", "Regina Freitas" };
	char vetor_email[10][32] = { "josedasilva@alunouninter.com", "joaosantos@alunouninter.com", "mariadesouza@alunouninter.com", "anapereira@alunouninter.com", "reginaldogalli@alunouninter.com",
								"isabellaferraz@alunouninter.com", "joaquimsa@alunouninter.com", "antoniovargas@alunouninter.com", "marcelaveiga@alunouninter.com", "reginafreitas@alunouninter.com" };
	int vetor_ru[11] = { 2483190, 3491222, 1579800, 2120099, 3573100, 1008076, 3234567, 1237885, 4679612, 3333331 };
	
	root = NULL;

	for (int i = 0; i < 10; i++){
		Inserir(&root, &vetor_nome[i - 1][30], &vetor_email[i - 1][32], int(vetor_ru[i]));// Este laço realiza utiliza a função Inserir para cadastrar os dados na estrutura do tipo árvore
	}
	while (num != 0) {
		system("Cls");
		printf("###	Sistema de busca de alunos no AVA	###\n\n");// Mensagem e menu inicial
		printf("Digite o número do RU para realizar a busca do aluno ou digite 0 para sair:");
		scanf_s("%d", &num);
		while ((c = getchar()) != '\n' && c != EOF) {} // limpeza do buffer do teclado
		
		if (num == 0) { // se o usuário digita 0, encerra o programa
			break;
		}

		ElementoBusca = Buscar(&root, num);
		if (ElementoBusca == 0) {
			system("cls");
			printf("RU não cadastrado!\n\n");
			system("pause");
		}
	}
}

void Inserir(Cadastro **ElementoVarredura, char* vetor_nome, char* vetor_email, int vetor_ru) { // Esta funcao realiza o armazenamento dos dados em uma estrutura do tipo árvore

	if (*ElementoVarredura == NULL){//SE ESTÁ VAZIO, COLOCA NA ÁRVORE
		Cadastro* NovoElemento = NULL;
		NovoElemento = (Cadastro*)malloc(sizeof(Cadastro));

		strcpy_s(NovoElemento->nome, vetor_nome);// relaciona os dados da estrutura com as variáveis inseridas externamente
		strcpy_s(NovoElemento->email, vetor_email);
		NovoElemento->ru = vetor_ru;

		NovoElemento->esquerda = NULL;
		NovoElemento->direita = NULL;
		*ElementoVarredura = NovoElemento;
		return;
	}

	if (vetor_ru < (*ElementoVarredura)->ru){
		Inserir(&(*ElementoVarredura)->esquerda, vetor_nome, vetor_email, vetor_ru);
	}
	else{
		if (vetor_ru > (*ElementoVarredura)->ru){
			Inserir(&(*ElementoVarredura)->direita, vetor_nome, vetor_email, vetor_ru);
		}
	}
}

Cadastro *Buscar(Cadastro **ElementoVarredura, int num){ // esta função realiza a busca do valor inserido pelo usuário na estrutura do tipo árvore
	if (*ElementoVarredura == NULL)
		return NULL;

	if (num < (*ElementoVarredura)->ru){
		Buscar(&((*ElementoVarredura)->esquerda), num);
	}
	else{
		if (num > (*ElementoVarredura)->ru){
			Buscar(&((*ElementoVarredura)->direita), num);
		}
		else{
			if (num == (*ElementoVarredura)->ru){
				system("Cls");
				printf("Cadastro do aluno encontrado:\n\n");
				printf("NOME			EMAIL				RU\n");
				printf("\n%s | %s | %d\n\n", (*ElementoVarredura)->nome, (*ElementoVarredura)->email, (*ElementoVarredura)->ru);
				system("pause");
				return *ElementoVarredura;
			}
		}
	}
}
