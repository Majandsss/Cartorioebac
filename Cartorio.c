#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h>//biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro () //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf ("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo,cpf); //Respons�vel por o copiar os valores das string
	FILE *file; //cria o arquivo no banco de dados
	
	file = fopen(arquivo, "w"); //cria o arquivo (write)
	fprintf(file,"\n\nCPF:  ");
	fprintf(file,cpf); //salvo valor da vari�vel
	fclose(file); //fecha o arquivo

	file = fopen(arquivo, "a"); // atualiza o arquivo
	fprintf(file,",\nNOME: "); 
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando info do usu�rio
	scanf("%s", nome); // salvando string
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file,nome);  // salvo valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file,"\nSOBRENOME: ");
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando info do usu�rio
	scanf("%s", sobrenome); //armazenando string
	
	file = fopen(arquivo, "a");  //atualiza o arquivo
	fprintf(file,sobrenome);  // salvo valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file,"\nCARGO: ");
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo  a ser cadastrado: "); //coletando info do usu�rio
	scanf("%s",cargo); //armazenando string
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file,cargo); // salvo valor da vari�vel
	fprintf(file,"\n\n");
	fclose(file); //fecha o arquivo
	
	system("pause");
	
}

int consulta () //Fun��o respons�vel por consultar os usu�rios no sistema

{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//in�cio consulta de vari�veis/string	
	char cpf [40];
	char conteudo [200];
	//Final da consulta de vari�veis/string
	
	printf("Digite o CPF a ser consultado: "); //consulta valor da vari�vel
	scanf("%s",cpf); //busca string
	
	FILE *file; // arquivo no banco de dados
	file = fopen(cpf, "r"); //L� o arquivo (read)
	
	if(file == NULL) //SE a v�riavel for diferente do arquivo = NULO
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado! :( "); //Aviso ao nulo
	}
	
		printf("\nEssas s�o as informa��es do �suario: "); //mostra vari�veis
	
	while(fgets(conteudo, 200, file) != NULL) 
	{
		printf("%s",conteudo); //string
		
	}
	fclose(file);
	system("pause");
			
}

int deletar ()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
		
	}
	
}

int main ()
{
	int opcao = 0; //Definindo as vari�veis
	int laco=1;
	
	for (laco=1;laco=1;)
	{
	
		system ("cls"); //respons�vel por limpar a  tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
	printf("Escolha op��o desejada no menu: \n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar os nomes\n");
	printf("\t3 - Deletar nomes\n\n");
	printf("\t4 - Sair do sistema\n\n");
	printf("Op��o: ");//fim do menu

	scanf("%d", &opcao);
	
	system("cls");
	
	switch(opcao) //in�cio da sele��o do menu
	
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2: 
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			
			
			default:
			printf ("Essa op��o n�o est� dispon�vel!\n");
			system ("pause");
			break;
		//fim da sele��o
	}
				
  }	
}

