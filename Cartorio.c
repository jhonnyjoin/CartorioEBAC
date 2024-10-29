#include <stdio.h> //biblioteca de  comunicacaocom o usuario
#include <stdlib.h> //biblioteca de alocacao de  espaco em memoria
#include <locale.h> //biblioteca de alocacoes de  texto por regiao
#include <string.h> //biblioteca responsavel por cuidar das string

int main() 
{
	int opcao=0; // usa 1= para atribuir algo, == eh comparacao, pergunta
	int repeticao=1;
	
	for(repeticao=1;repeticao=1;)
	{
	
        system("cls"); //limpa a tela
	
        setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	    printf("\t Cartório da EBAC\n\n"); //inicio do menu
	    printf("Escolha a opção deseja do menu:\n\n");
	    printf("\t1 - Registrar nomes\n"); 
	    printf("\t2 - Consultar os nomes\n");
	    printf("\t3 - Deletar nomes\n\n"); //fim do menu
	    printf("Opcao:");
	
	    scanf("%d", &opcao); //armazenando a escolha do usuario
	
	    system("cls"); //vai deletar as mensagens anteriores, 'apaga' a pagina
	
	    switch(opcao) //inicio da selacao do menu
	    {
	    
			case 1:
 		    registro(); //chamada de funcoes
		    break;
		    
		    case 2:
		    consulta();  
		    break;
		    
		    case 3:
		    deletar(); 
		    break;
		    
		    default:
		    printf("Essa opção não está disponível!\n");
		    system("pause");
		    break;
		    
		} //fim da selecao
    
	} 
	
}

int registro()  //função responsável por cadastrar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); 
	
	//inicio da criacao de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo [40];
	//final da criacao de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informacao do usuario
	scanf("%s",cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); //string copia, responsavel por copiar o valor das string
	
	FILE *file; // Cria o arquivo / FILE é uma função pronta para procurar um arquivo *file
	file = fopen(arquivo, "w"); //(w)rite, cria um arquivo
	fprintf(file,cpf); //salva o valor da variavel /fprintf colocar o que foi registrado dentro do arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //vai abrir o arquivo chamado arquivo e (a)tualizar a informação
	fprintf(file,", Nome: "); //nesse caso atualizamos o arquivo com uma "," so para melhor a visualizacao
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //Voltamos a falar com o usuario
    scanf("%s",nome); //salvando o que o usuario digitar na variavel Nome
   
    file = fopen(arquivo, "a"); //depois de falar com o usuario abrimos o arquivo novamente
    fprintf(file,nome); //e atualizamos o arquivo Nome criado anteriormente com as informacoes registradas
    fclose(file);
    
    file = fopen(arquivo, "a"); 
	fprintf(file,", Sobrenome: "); 
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome); 
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", Cargo: ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta() //funcao responsavel por consultar os usuarios registrados no sistema
{
    setlocale(LC_ALL, "Portuguese"); //definindo a linguagem

	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //(r)ead
	
	if(file == NULL) //== é para comparação, ent estamos dizendo que se o arquivo for nulo, fazer X coisa
	{
		printf("\nNão foi possível abrir o arquivo, não foi localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: CPF: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
	fclose(file); 
	
}

int deletar() //funcao responsavel por deletar os usuarios registrados no sistema
{
    setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
    
    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf, "r"); //abrindo o arquivo para leitura
    
    if(file == NULL) //se for nulo
    {
    	printf("\nO usuário não se encontra no sistema!.\n");
    	system("pause");
	}
	
	else
	{
		fclose(file); //se nao for nulo, fecha o arquivo
		remove(cpf);
		printf("\nO usuário foi deletado com sucesso!.");
		system("pause");
	}
	
}

