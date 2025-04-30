#include <stdio.h> //biblioteca de comunicação com o Usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memoria
#include <locale.h> // biblioteca de aloações de texto por regiao 
#include <string.h> // biblioteca responsavel por cuidar das strings 

int registro() //Inicio das criaçoes de variaveis/String
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variaveis 

	printf("Digite o CPF a ser cadastrado:"); //Coletando informação
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); // Responsavel por criar os valores da string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo na pasta que esta salvo o progama o "w" seginifica escrever 
	fprintf(file,cpf); // Salva o valor da viariavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" para atualizar o arquivo
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Nome a ser cadastrado:");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);

	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	fclose(file);
	
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
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // "r" "read" o r vai ler o codigo em busca das informações
	
	if(file == NULL)
	{
		printf("Não foi possivel localizar o CPF digitado.\n");
	}
	
	while(fgets(conteudo, 200, file)!= NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf [40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");	
	}
	

}

int main()
{
		int opcao=0;//Definindno variáveis
		int laco=1;
		char senhadigitada[10]="admin";
		
		int comparacao;
		
		printf("### Cartório da EBAC ###\n\n");
		printf("Login de administrador!\n Digite a senha: ");
		scanf("%s",senhadigitada);
		
		comparacao = strcmp(senhadigitada, "admin");
		
		setlocale(LC_ALL, "portuguese");
		system("cls");
	
		if (comparacao == 0)
		{	
			for(laco=1;laco=1;)
			{
			
				system("cls"); // responsavel por limpar a tela
				
				setlocale(LC_ALL, "portuguese"); //Definindo linguagem
				
				printf("### Cartório da EBAC ###\n\n");	//Inicio do menu 
				
				printf("Escolha a opção desejada do menu: \n\n");
				
				printf("\t1 - Registrar nomes\n");
				printf("\t2 - Consultar nomes\n");
				printf("\t3 - Deletar nomes\n\n");
				printf("\t4 - Sair do sistema \n\n");
				printf("Opção: "); //Fim do menu
				
				scanf("%d", &opcao); //Armazenando a escolha do usuario
				
				system("cls");
				
				switch(opcao) //inicio da seleção de menu
				{
					case 1:
					registro(); //chamada de função
					break;
					
					case 2:
					consulta();
					break;
					
					case 3:
					deletar();
					break;
					
					case 4:
					printf("Obrigado por usar o sistema!\n");
					return 0;
					break;
					
					default:
					printf("Essa opção não esta disponivel!\n");
					system("pause");
					break;	
				} //fim da seleção	
			}	
				
		}	
			else{			
			printf("\nSenha Incorreta!\n\n");
			system("pause");
			system("cls");
			main();
			}
}
				



