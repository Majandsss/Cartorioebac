#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h>//biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro () //Função responsável por cadastrar os usuários no sistema
{
	//início criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf ("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo,cpf); //Responsável por o copiar os valores das string
	FILE *file; //cria o arquivo no banco de dados
	
	file = fopen(arquivo, "w"); //cria o arquivo (write)
	fprintf(file,"\n\nCPF:  ");
	fprintf(file,cpf); //salvo valor da variável
	fclose(file); //fecha o arquivo

	file = fopen(arquivo, "a"); // atualiza o arquivo
	fprintf(file,",\nNOME: "); 
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando info do usuário
	scanf("%s", nome); // salvando string
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file,nome);  // salvo valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file,"\nSOBRENOME: ");
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando info do usuário
	scanf("%s", sobrenome); //armazenando string
	
	file = fopen(arquivo, "a");  //atualiza o arquivo
	fprintf(file,sobrenome);  // salvo valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file,"\nCARGO: ");
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo  a ser cadastrado: "); //coletando info do usuário
	scanf("%s",cargo); //armazenando string
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file,cargo); // salvo valor da variável
	fprintf(file,"\n\n");
	fclose(file); //fecha o arquivo
	
	system("pause");
	
}

int consulta () //Função responsável por consultar os usuários no sistema

{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//início consulta de variáveis/string	
	char cpf [40];
	char conteudo [200];
	//Final da consulta de variáveis/string
	
	printf("Digite o CPF a ser consultado: "); //consulta valor da variável
	scanf("%s",cpf); //busca string
	
	FILE *file; // arquivo no banco de dados
	file = fopen(cpf, "r"); //Lê o arquivo (read)
	
	if(file == NULL) //SE a váriavel for diferente do arquivo = NULO
	{
		printf("Não foi possível abrir o arquivo, não localizado! :( "); //Aviso ao nulo
	}
	
		printf("\nEssas são as informações do úsuario: "); //mostra variáveis
	
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
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
		
	}
	
}

int main ()
{
	int opcao = 0; //Definindo as variáveis
	int laco=1;
	
	for (laco=1;laco=1;)
	{
	
		system ("cls"); //responsável por limpar a  tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
	printf("Escolha opção desejada no menu: \n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar os nomes\n");
	printf("\t3 - Deletar nomes\n\n");
	printf("\t4 - Sair do sistema\n\n");
	printf("Opção: ");//fim do menu

	scanf("%d", &opcao);
	
	system("cls");
	
	switch(opcao) //início da seleção do menu
	
		{
			case 1:
			registro(); //chamada de funções
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
			printf ("Essa opção não está disponível!\n");
			system ("pause");
			break;
		//fim da seleção
	}
				
  }	
}

