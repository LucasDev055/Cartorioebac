#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação do espaço de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro()// Função responável por cadastrar os usuários no sistema
{
	
	//início criação de variáveis/strings
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//final criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado:");//coleta de informações do usuário
	scanf("%s", cpf);//"%s" se refere às strings
	
	strcpy(arquivo, cpf); //responsável por copiar os arquivos das strings
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file, cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");// "a" para atualizar o arquivo 
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o nome a ser cadastrado:");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado:");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system ("pause");
	
	
	
	}

int consulta()
{
	setlocale(LC_ALL, "portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //"r" para ler o conteúdo do arquivo
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado! /n");
	}
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");	
	}
			system("pause");	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema! \n");
		system("pause");
	}	
}

int main(){
	
	int opcao=0; //Defindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;) 
	{
	
		system("cls");//responsável por limpar a tela
		
		setlocale(LC_ALL, "portuguese");//Definindo linguagens
	
		printf("##Cartório da EBAC##\n\n Escolha a opção desejada do menu:\n\n");//início do menu
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");//Fim do menu
		printf("\t4 - Sair do sistema\n");
		printf("opção: ");//armazenando a escolha do usuário
	
		scanf("%d", &opcao);
		
		system("cls");
		
		switch(opcao)//início da seleção do menu
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
			printf("Obrigado por utilizar o sistema!");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponivel! /n");
			system("pause");
		}
	}
	}
