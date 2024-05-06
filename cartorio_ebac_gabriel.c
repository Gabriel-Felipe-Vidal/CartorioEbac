#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das Strings

int registro()//Fun��o respons�vel por cadastrar usu�rios no Sistema
{
	setlocale(LC_ALL, "Portuguese");
	
	//Inic�o de Cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser Cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das Strings
	
	FILE *file; //Cria o Arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo
	fprintf(file,cpf); //Salva o Valor da Vari�vel
	fclose(file); //Fecha o Arquivo
	
	file = fopen(arquivo, "a"); //Atualiza o Arquivo
	fprintf(file,","); //Separa o arquivo por virgula
	fclose(file);
	
	printf("Digite o nome a ser Cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Sobrenome a ser Cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Cargo a ser Cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	 
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser Consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, arquivo n�o localizado. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do Usu�rio a ser Deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O Usu�rio n�o se encontra no Sistema.\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //Definindo as Vari�veis.
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo as Linguagens.
	
		printf("Cart�rio do Gabriel \n\n");//Inicio do Menu.
		printf("Escolha a op��o desejada no Menu\n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n");
		printf("\t4 - Sair do Sistema\n\n");//Fim do Menu.
		printf("Op��o: ");

		scanf("%d", &opcao);//Armazenando as Escolhas do Usu�rio.

		system("cls");
		
		switch(opcao)
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por Utilizar o Sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa op��o N�o Est� Dispon�vel!\n");
			system("pause");
			break;
			
		}
    }
}

