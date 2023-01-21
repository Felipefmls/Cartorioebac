#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca responsável pela alocação de memória no computador
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//Criação das variáveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim das variáveis
	
	//Pedindo para o usuário adicionar o CPF a ser consultado
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file, cpf); //salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo para a adição de dados
	fprintf(file, ","); //adiciona uma vírgula para a separação dos dados adicionados
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //inclusão do nome pelo usuário
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //inclusão do nome no arquivo
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //inclusão da vírgula no arquivo
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //inclusão do sobrenome pelo usuário
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); //inclusão do sobrenome no arquivo
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //inclusão do cargo pelo usuário
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a"); //inclusão do sobrenome no arquivo
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

int consulta() //Inicio da função responsável por consultar os dados dos usuários
{
	setlocale(LC_ALL, "Portuguese");
	
	//criação das variáveis
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	//Abertura do arquivo para leitura
	FILE *file;
	file = fopen(cpf, "r");
	
	//Condição se o dado indicado pelo usuário não existir
	if(file == NULL)
	{
		printf("\nNão foi possível abrir o arquivo, não localizado! \n\n");	
	}
	
	//laço para mostrar todos caracteres disponiévsi no arquivo selecionado pelo usuário
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEstas são as informações do usuário com cpf, nome, sobrenome e cargo, respectivamente: \n\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file); //Fechando o arquivo aberto anteriormente
	
	system("pause"); //Deixando o sistema pausado para que o usuário consiga ler os retornos do programa
}

int deletar() //início da função responsável por deletar os dados dos usuários
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	//remove(cpf); //removendo o CPF escrito pelo usuário
	
	FILE *file;
	file = fopen(cpf, "r");
		
	//Confirmando se o usuário foi mesmo excluido e/ou não pertence mais ao banco de dados
	if(file == NULL)
	{
		printf("\nO usuário não se encontra no sistema! \n\n");
	}
	else
	{
		printf("\nO usuário foi apagado com sucesso! \n\n");
	}
	
	fclose(file);
	
	remove(cpf);
	
	system("pause");
}

int main() //criação da função principal
{
	//Definições das variáveis
	int opcao = 0;
	int laco = 1;
	
	//Inicíio da repetição
	for(laco=1;laco=1;)
	{
		//Deletar todas as mensagens anteriores para não poluir a tela
		system("cls");
		
		//reconhecimento do idioma dos textos que serão inseridos pelo usuário
		setlocale(LC_ALL, "Portuguese");
	
		//Início do menu
		printf("### Cartório da EBAC ### \n \n");
		printf("Bem-vindo(a) à base de dados da EBAC\n \n");
		printf("Escolha a opção desejada do menu: \n \n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: ");
		//Fim do menu
	
		//Resposta do usuário
		scanf("%d", &opcao);
	
		//Deletar todas as mensagens anteriores para não poluir a tela
		system("cls");
	
		//Condições da resposta do menu
		switch(opcao)
		{
			case 1:
				registro(); //chamada das funções
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
				printf("\nEsta opção não esta disponível\n \n");
				system("pause");
			break;
		}//Fim das condições de resposta

	}//Fim da repetição
}//Fim da função principal
