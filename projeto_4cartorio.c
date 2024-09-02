#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string


int registro()  // Função responsável por cadastrar os usúarios no sistema
{
 	//inicio criação de variáveis/string
	char arquivo[40];
    char cpf[40];
 	char nome[40];
 	char sobrenome[40];
 	char cargo[40];
 	//Final criação de variáveis/string
 	
 	
 	printf("Digite o CPF a ser cadastrado:"); //coletando informação do usuário
 	scanf("%s",cpf); //%s refere-se a string
 	
 	strcpy(arquivo,cpf); // responsavel por criar o valor das string
 	
 	FILE *file; // cria o arquivo
 	file = fopen(arquivo,"w");// cria o arquivo e o "w" significa escrever
 	fprintf(file,cpf);// salvo valor da variavel
 	fclose(file);// fecha o arquivo
 	
 	file = fopen(arquivo, "a");
 	fprintf(file,",");
 	fclose(file); // fecha o arquivo
 	
 	printf("Digite o nome a ser cadastrado:"); //coletando informação do usuário
 	scanf("%s",nome);
 	
 	file=fopen(arquivo,"a");
 	fprintf(file,nome);
 	fclose(file); // fecha o arquivo
 	
 	file= fopen(arquivo,"a");
 	fprintf(file,",");
 	fclose(file); // fecha o arquivo
 	
 	printf("Digite o sobrenome a ser cadastrado:"); //coletando informação do usuário
 	scanf("%s",sobrenome);
 	
 	file=fopen(arquivo,"a");
 	fprintf(file,sobrenome);
 	fclose(file);// fecha o arquivo
 	
 	file= fopen(arquivo,"a");
 	fprintf(file,",");
 	fclose(file); // fecha o arquivo
 	
 	printf("Digite o cargo a ser cadastrado:"); //coletando informação do usuário
 	scanf("%s",cargo);
 	
 	file=fopen(arquivo,"a");
 	fprintf(file,cargo);
 	fclose(file);// fecha o arquivo
 	
 	system("pause");
 	
 	
 	
 	
 	
 	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo linguagens
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado:");
	scanf("%s",cpf);
	
	FILE*file;
	file= fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado.\n"); //coletando informação do usuário
		
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas são as informações do usuario:"); //coletando informação do usuário
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
}

int deletar()
{
	char cpf [40];
	
	printf("Digite o CPF do usuário  a  deletado:"); 
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE* file;
	file= fopen(cpf,"r");
	
	if(file==NULL)
	{
		printf("O usuário não se encontra no sistema.\n");
		system ("pause");
	}
	
	
	
	
}

int main()
{
	 int opcao=0; // definindo variaveis
	 int laco=1;
	 
	 for(laco=1;laco=1;)
	 {
	
	 system("cls");  // responsavel por limpar a tela
	 
	 setlocale(LC_ALL, "Portuguese"); //definindo linguagens
	
	 printf("### Cartório da EBAC ###\n\n"); //inicio menu
	 printf("Escolha a opção desejada do menu:\n\n");
	 printf("\t1 - Registrar nomes\n");
	 printf("\t2 - Consultar nomes\n");
	 printf("\t3 - Deletar nomes\n");
	 printf("Opção: "); //fim menu
	
    scanf("%d", &opcao);//armazenando a escolha do usuario
	
	system("cls"); // responsavel por limpar a tela
	
	switch(opcao) // inicio da seleção do menu
	{
		case 1:
		registro(); // chamada de funções
		break;
		
		case 2:
		consulta();
		break;
		
		case 3:
		deletar();
		break;
		
		default:
		printf("Essa opção não esta disponivel\n");
		system("pause");
		break;
		// fim da seleção	
	}
	

	 }
}
