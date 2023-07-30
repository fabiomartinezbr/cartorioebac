#include <stdio.h> //biblioteca de comunicacao com o usuario
#include <stdlib.h> //biblioteca de alocacao de espaco em memoria
#include <locale.h> //biblioteca de alocacao de texto por regiao
#include <unistd.h>
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro()//funcao responsavel por cadastrar os usuarios no sistema
{
    //inicio criacao de variaveis/strings
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da criacao de variaveis


    printf("Digite o CPF a ser cadastrado: ");//coletando informacoes do usuario
    scanf("%s", cpf);//%s refere-se a string

    strcpy(arquivo, cpf); //responsavel por copiar os valores das strings

    FILE *file; // cria o arquivo no banco de dados
    file = fopen(arquivo,"w"); //cria o arquivo e o w significa escrever
    fprintf(file,cpf); // salva o valor da variavel
    fclose(file); // fecha o arquivo

    file = fopen(arquivo, "a");//atualiza o arquivo
    fprintf(file, ",");// insere , entre os registros
    fclose(file);

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);

     file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);

    pause();

}

int consulta()
{
    setlocale(LC_ALL, "pt_BR.UTF-8"); //definindo linguagem

    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if(file == NULL)
    {
        printf("Nao foi possivel abrir o arquivo, nao localizado!.\n");
    }

    while(fgets(conteudo, 200, file)!=NULL)
    {
        printf("\nEssas sao as informacoes do usuario: ");
        printf("%s", conteudo);
        printf("\n\n");
    }

    pause();
}

int deletar()
{
    char cpf[40];

    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);

    remove(cpf);//remove o registro

    FILE *file;
    file = fopen(cpf, "r");

    if(file == NULL)//validacao de registro
    {
        printf("O usuario nao se encontra no sistema!.\n");
        pause();
    }
}

int main()
{
    int opcao=0; //definindo variaveis
    int x=1;
    char senhadigitada[10]="a";
    int comparacao;

    printf("### Registro de alunos da EBAC ###\n\n");
    printf("login de administrador!\n\nDigite a sua senha: ");
    scanf("%s", senhadigitada);

    comparacao = strcmp(senhadigitada, "admin");

    if(comparacao == 0)
    {
        system("clear");

        for(x=1;x=1;)
        {

            system("clear"); // responsavel por limpar a tela

            setlocale(LC_ALL, "pt_BR.UTF-8"); //definindo linguagem

            printf("### Registro de alunos da EBAC ###\n\n");//inicio do menu
            printf("Qual opção do menu você deseja?\n\n");
            printf("\t1 - Registro de nomes\n");
            printf("\t2 - Consulta de nomes\n");
            printf("\t3 - Exclusão de nomes\n");
            printf("\t4 - sair do sistema\n\n");
            printf("Opção: ");//fim do menu

            scanf("%d", &opcao);//armazenando a escolha do usuario

            system("clear");

            switch(opcao)
            {
                case 1:
                registro();//chamada de funcoes
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
                printf("Você digitou uma opção que não existe!\n");//fim da selecao
                pause();
                break;


            }

        }
    }

    else
        printf("Senha incorreta!");
}
