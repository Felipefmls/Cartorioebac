#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca respons�vel pela aloca��o de mem�ria no computador
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//Cria��o das vari�veis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim das vari�veis
	
	//Pedindo para o usu�rio adicionar o CPF a ser consultado
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file, cpf); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo para a adi��o de dados
	fprintf(file, ","); //adiciona uma v�rgula para a separa��o dos dados adicionados
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //inclus�o do nome pelo usu�rio
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //inclus�o do nome no arquivo
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //inclus�o da v�rgula no arquivo
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //inclus�o do sobrenome pelo usu�rio
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); //inclus�o do sobrenome no arquivo
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //inclus�o do cargo pelo usu�rio
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a"); //inclus�o do sobrenome no arquivo
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

int consulta() //Inicio da fun��o respons�vel por consultar os dados dos usu�rios
{
	setlocale(LC_ALL, "Portuguese");
	
	//cria��o das vari�veis
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	//Abertura do arquivo para leitura
	FILE *file;
	file = fopen(cpf, "r");
	
	//Condi��o se o dado indicado pelo usu�rio n�o existir
	if(file == NULL)
	{
		printf("\nN�o foi poss�vel abrir o arquivo, n�o localizado! \n\n");	
	}
	
	//la�o para mostrar todos caracteres disponi�vsi no arquivo selecionado pelo usu�rio
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEstas s�o as informa��es do usu�rio com cpf, nome, sobrenome e cargo, respectivamente: \n\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file); //Fechando o arquivo aberto anteriormente
	
	system("pause"); //Deixando o sistema pausado para que o usu�rio consiga ler os retornos do programa
}

int deletar() //in�cio da fun��o respons�vel por deletar os dados dos usu�rios
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	//remove(cpf); //removendo o CPF escrito pelo usu�rio
	
	FILE *file;
	file = fopen(cpf, "r");
		
	//Confirmando se o usu�rio foi mesmo excluido e/ou n�o pertence mais ao banco de dados
	if(file == NULL)
	{
		printf("\nO usu�rio n�o se encontra no sistema! \n\n");
	}
	else
	{
		printf("\nO usu�rio foi apagado com sucesso! \n\n");
	}
	
	fclose(file);
	
	remove(cpf);
	
	system("pause");
}

int main() //cria��o da fun��o principal
{
	//Defini��es das vari�veis
	int opcao = 0;
	int laco = 1;
	
	//Inic�io da repeti��o
	for(laco=1;laco=1;)
	{
		//Deletar todas as mensagens anteriores para n�o poluir a tela
		system("cls");
		
		//reconhecimento do idioma dos textos que ser�o inseridos pelo usu�rio
		setlocale(LC_ALL, "Portuguese");
	
		//In�cio do menu
		printf("### Cart�rio da EBAC ### \n \n");
		printf("Bem-vindo(a) � base de dados da EBAC\n \n");
		printf("Escolha a op��o desejada do menu: \n \n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: ");
		//Fim do menu
	
		//Resposta do usu�rio
		scanf("%d", &opcao);
	
		//Deletar todas as mensagens anteriores para n�o poluir a tela
		system("cls");
	
		//Condi��es da resposta do menu
		switch(opcao)
		{
			case 1:
				registro(); //chamada das fun��es
			break;
				
			case 2:
				consulta();
			break;
			
			case 3:
				deletar();				
			break;
			
			case 4:
				printf("Obrigado por utilizar o nosso sistema!\n");
				return 0;
			break;
						
			default:
				printf("\nEsta op��o n�o esta dispon�vel\n \n");
				system("pause");
			break;
		}//Fim das condi��es de resposta

	}//Fim da repeti��o
}//Fim da fun��o principal
