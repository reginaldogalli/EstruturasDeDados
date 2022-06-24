#include<stdio.h>							   
#include<stdlib.h>
#include<string.h> //biblioteca para manipulação de strings
#include<locale.h> //biblioteca para utilização de acentuação


int menu();
void Inserir(char titulo[30], char artista[20], int duracao);
void Listar();

struct Musica { // criação da estrutura de dados
	char tit[30];
	char art[30];
	int dura;
	struct Musica* prox;
} *Head;

int  main() {
	int op, c;
	char titulo[30];
	char artista[30];
	int duracao;
	Head = NULL;
	setlocale(LC_ALL, "Portuguese");

	while (1) {
		op = menu();
		switch (op) { // utilização de switch case de acordo com as opções do menu

		case 1: // opção 1 para cadastrar música

			printf("\nDigite o nome da música: ");
			gets_s(titulo);
			printf("\nDigite o nome do artista: ");
			gets_s(artista);
			printf("\nDigite a duração da música em segundos: ");
			scanf_s("%d", &duracao);
			while ((c = getchar()) != '\n' && c != EOF) {} // limpeza do buffer do teclado
			Inserir(titulo, artista, duracao);
			break;

		case 2: // opção 2 para listar as músicas cadastradas

			Listar();

			break;

		case 3: // opção 3 encerra o programa

			return 0;

		default: // em caso do usuário digitar valor inválido

			printf("Invalido\n");
		}
	}
	return 0;
}

int menu() {
	int op, c;
	system("Cls"); // limpa a tela

	printf("\n###	Playlist musical	###\n\n");// Mensagem e menu inicial

	printf("[1].Inserir música na playlist;\n");
	printf("[2].Listar músicas da playlist;\n");
	printf("[3].Encerrar\n");
	printf("\n\nDigite a opção desejada:");

	scanf_s("%d", &op);
	while ((c = getchar()) != '\n' && c != EOF) {} // limpeza do buffer do teclado

	system("Cls");
	return op;
}

void Inserir(char titulo[30], char artista[30], int duracao) //funcao inserir
{
	Musica* NovoElemento; //cria novo elemento do tipo ponteiro dentro da struct
	NovoElemento = (struct Musica*)malloc(sizeof(struct Musica)); //aloca o novo elemento na memória

	strcpy_s(NovoElemento->tit, titulo);// relaciona os dados da estrutura com as variáveis inseridas externamente
	strcpy_s(NovoElemento->art, artista);
	NovoElemento->dura = duracao;

	if (Head == NULL) // verifica se a estrutura está vazia ou já contem elementos
	{
		Head = NovoElemento;
		Head->prox = NULL;
	}
	else
	{
		NovoElemento->prox = Head;
		Head = NovoElemento;
	}
}

void Listar()
{
	Musica* ElementoVarredura;
	ElementoVarredura = (struct Musica*)malloc(sizeof(struct Musica));

	ElementoVarredura = Head;


	if (ElementoVarredura == NULL) { // verifica se a estrutura está vazia
		printf("A lista está vazia!\n");
		system("pause");
		return;
	}
	printf("\n				LISTAGEM DAS MÚSICAS:\n\n|Título|		|Artista|		|Duração|\n\n");
	while (ElementoVarredura != NULL) { // caso contenha elementos, faz a impressao, linha a linha na tela
		printf("\n%s          %s          %d segundos\n", ElementoVarredura->tit, ElementoVarredura->art, ElementoVarredura->dura);
		ElementoVarredura = ElementoVarredura->prox;
	}
	printf("\n");

	system("pause");
	return;
}
