#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

#define VERMELHO "\x1B[31m"
#define RESET "\x1B[0m"
#define VERDE "\x1B[32m"
#define AMARELO "\x1B[33m"
#define AZUL "\x1B[34m"
#define MAG "\x1B[35m"
#define CIANETO "\x1B[36m"
#define BRANCO "\x1B[37m"

typedef struct Produto
{
    char nomeProduto[20];
    float valorProduto, quantidadeProduto;
} Produto; // registro do cadatro do produtos.

typedef struct Funcionario
{
    char nomeFuncionario[20],
        matricula[10];

} Funcionario; // registro do cadatro do funcionario

// varialvel global
Funcionario funcionario[100];
Produto produto[100];
Produto produtoRelatorio[100];

int indProdutos = 0,
    indiceFuncionario = 0, indiceVendidos = 0;
float totalProdutos;

//assinaturas procedimentos
void CadastrarProdutos();
void CadastrarFuncionario();
void Menu();
void MenuAdm();
void MenuFuncionario();
void LoginFuncionario();
void ListarFuncionarios();
void VerificaPreco();
void ListarProdutos();
void VenderProdutos();
void ListarRelatorio();

int main()
{
    setlocale(LC_ALL, "portuguese");
    // struct DataTime *data;

    Menu();
    //CadastrarProdutos();
    //ListarProdutos();
    return 0;
}

void MenuAdm()
{
    int op, leftMenu, i=0;
    char c, compPass, user[10], pass[10];
    do
    {
        printf("\n -- Usuário: --");
        fflush(stdin);
        gets(user);
        printf("\n -- Informe a Senha: -- ");

        while ((c = getch()) != 13)
        { //13 é o valor de ENTER na tabela ASCII
            pass[i] = c;
            i++;
            printf ("*"); //imprime o * Anterisco
        }
        pass[i] = '\0';
        i = 0;
      
        system("cls");

         c = strcmp(pass, "123"); 
        compPass = strcmp(user, "adm");
       

    } while (c != 0 || compPass != 0); // login para adm entrar no menu
       

    if (c == 0 && compPass == 0)
    {
        do
        {
            system("cls");
            printf("\n ----- MENU ADM -----");
            printf("\n [1]- CADASTRAR FUNCIONÁRIO ");
            printf("\n [2]- CADASTRAR PRODUTOS ");
            printf("\n [3]- RELATÓRIO ");
            printf("\n [0]- MENU PRINCIPAL ");
            printf("\n ESCOLHA UMA OPÇÃO: ");
            scanf("%d", &op);

            switch (op)
            {
            case 1:
                CadastrarFuncionario();
                break;
            case 2:
                CadastrarProdutos();
                break;
            case 0:
                Menu();
                break;
            case 3:
                ListarRelatorio();
                break;

            default:
                printf("\n *** Option Invalidates! *** ");
                break;
            }
            printf("\n [1]-Main Menu ADM || [0]- Menu Anterior: ");
            scanf("%d", &leftMenu);
        } while (leftMenu != 0);
    }
}
void MenuFuncionario()
{
    int op, leftMenu;

    do
    {
        system("cls");
        printf("\n\n ----- MENU FUNCIONÁRIO -----\n ");
        printf("\n[1]- REALIZAR VENDA:");
        printf("\n [2]- MENU PRINCIPAL ");
        printf("\n [0]- SAIR DO SISTEMA");
        //printf("\n [2]- CADASTRAR PRODUTOS:");
        printf("\n ESCOLHA UMA OPÇÃO ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            VenderProdutos();
            break;
        case 2:
            Menu();
            break;
        case 0:
            printf("\n *** LOGOUT ***");
            Sleep(1000);
            system("cls");
            exit(0);
        default:
            printf("\n *** Option Invalidates! *** ");
            break;
        }
        printf("\n [1]-Main Menu FUNCIONÁRIO || [0]- Main Menu: ");
        scanf("%d", &leftMenu);
    } while (leftMenu != 0);
}

void Menu()
{
    int leftMenu, opcao;

    do
    {

        printf(VERMELHO "\n  ------------------------------------------- \n");
        printf(BRANCO "       MERCADINHO ALICE VIU ALICE VE              " RESET);
        printf(VERMELHO "\n ------------------------------------------- \n ");
        printf("\n ---- MENU OPÇÕES -----");
        printf("\n [1]- ÁREA ADM: ");
        printf("\n [2]- ÁREA FUNCIÓNARIO: ");
        //printf("\n [3]- RELATORIO: ");
        printf("\n [0]- EXIT SYSTEM: \n" RESET);
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            printf("\n *** LOGOUT ***");
            Sleep(1000);
            system("cls");
            exit(0);
            break;
        case 1:
            MenuAdm();
            break;
        case 2:
            LoginFuncionario();
            break;
            /*
        case 3:
            ListarRelatorio();
            break;
            */
        default:
            printf("\n *** Option Invalidates! *** ");
            break;
        }
        printf("\n [1]-Main Menu  || [0]- get out of the system: ");
        scanf("%d", &leftMenu);
    } while (leftMenu != 0);
}
void LoginFuncionario()
{
    int leftMenu, achou = 0;
    char nomeFuncionario[25], matricula[25];

    do
    {
        system("cls");
        printf("\n ----- LOGIN FUNCIONÁRIO -----");

        printf("\n Informe o nome do funcionário: ");
        fflush(stdin);
        gets(nomeFuncionario);
        printf("\n Informe a  matrícula: ");
        fflush(stdin);
        gets(matricula);

        for (int i = 0; i < indiceFuncionario; i++)
        {
            if (strcmp(funcionario[i].nomeFuncionario, nomeFuncionario) == 0 && strcmp(funcionario[i].matricula, matricula) == 0)
            {
                achou = 1;
                if (achou = 1)
                {
                    for (int j = 0; j < 100; j++)
                    {
                        printf("\n --- LOADING %d %% ---", (j + 1));
                        system("cls");
                    }
                }

                printf("\n *****  WELLCOME: %s ***** ", strupr(funcionario[i].nomeFuncionario)); //upperCase
                Sleep(1000);
                system("cls");
                MenuFuncionario();
            }
        }
        if (achou == 0)
        {
            for (int j = 0; j < 100; j++)
            {
                printf("\n --- LOADING %d %% ---", (j + 1));
                //Sleep(10);
                system("cls");
            }
            printf("{--error not found!--}");
        }

        printf("\n [1]-Main Menu FUNCIONÁRIO || [0]- MENU ANTERIOR: ");
        scanf("%d", &leftMenu);
    } while (leftMenu != 0);
}

void CadastrarProdutos()
{
    int leftMenu;

    do
    {
        system("cls");
        printf("\n \n ----- CADASTRAR PRODUTOS -----");
        printf("\n Informe o nome do produto: ");
        fflush(stdin);
        gets(produto[indProdutos].nomeProduto);
        VerificaPreco(); // tratamento de verificação
        do
        {
            printf("\n Informe a quantidade do produto %s: ", produto[indProdutos].nomeProduto);
            scanf("%f", &produto[indProdutos].quantidadeProduto);

            if (produto[indProdutos].quantidadeProduto <= 0)
            {
                printf("\n {ERRO! VERIFIQUE A QUANTIDADE DOS PRODUTOS} \n");
            }
        } while (produto[indProdutos].quantidadeProduto <= 0);
        indProdutos++;
        //totalProdutos += produto[indProdutos].quantidadeProduto;
        printf("\n *****  successfully registered! ***** ");
        Sleep(1000);
        system("cls");
        printf("\n ----- [1]- Cadastrar Novamente || [0]- Menu Anterior -----\n ");
        scanf("%d", &leftMenu);

    } while (leftMenu != 0);
} // cadastro dos produtos
void CadastrarFuncionario()
{

    int leftMenu;

    do
    {
        system("cls");
        printf("\n ----- CADASTRAR FUNCIONÁRIO -----");

        printf("\n Informe o Nome do Funcionário: ");
        fflush(stdin);
        gets(funcionario[indiceFuncionario].nomeFuncionario);
        printf("\n Informe o Número da Matrícula do Funcionário: ");
        fflush(stdin);
        gets(funcionario[indiceFuncionario].matricula);
        indiceFuncionario++;
        printf("\n ***** successfully registered! ***** ");
        Sleep(1000);
        system("cls");
        printf("\n ----- [1]- Cadastrar Novamente || [0]- Menu Anterior -----\n ");
        scanf("%d", &leftMenu);

    } while (leftMenu != 0);

} // cadastrar funcionario.

void ListarFuncionarios()
{

    int i = 0;

    printf("\n ----- LISTA DE FUNCIONÁRIOS -----");

    for (i = 0; i < indiceFuncionario; i++)
    {
        printf("\n ______-----------_________-----------___________");
        printf("\n NOME DO FUNCIONÁRIO: %s", funcionario[i].nomeFuncionario);
        printf("\n NÚMERO DA MATRÍCULA: %s", funcionario[i].matricula);
        printf("\n ______-----------_________-----------___________");
    }
}

void VerificaPreco()
{
    do
    {
        printf("\n Infome o preço do(a) %s R$ : ", produto[indProdutos].nomeProduto);
        scanf("%f", &produto[indProdutos].valorProduto);

        if (produto[indProdutos].valorProduto <= 0)
        {
            printf("\n {ERRO! VERIFIQUE OS PREÇOS DOS PRODUTOS} \n");
        }
    } while (produto[indProdutos].valorProduto <= 0);

} // verificar se o preço é <= 0

void ListarProdutos()
{
    int i = 0;

    printf(VERDE "\n ----- LISTA DE PRODUTOS -----" RESET);

    for (i = 0; i < indProdutos; i++)
    {
        printf(AZUL "\n ______-----------_________-----------___________");
        printf("\n NOME DO PRODUTO: %s", produto[i].nomeProduto);
        printf("\n QUANTIDADE: %.0f", produto[i].quantidadeProduto);
        printf("\n PREÇO R$: %.2f", produto[i].valorProduto);
        printf("\n ______-----------_________-----------___________" RESET);
    }
}

void ListarRelatorio()
{
    int i = 0;

    printf(VERDE "\n ----- RELATORIO -----" RESET);

    for (i = 0; i < indiceVendidos; i++)
    {
        printf(AZUL "\n --------------------------------------------------");
        printf("\n NOME DO PRODUTO: %s", produtoRelatorio[i].nomeProduto);
        printf("\n QUANTIDADE: %.0f", produtoRelatorio[i].quantidadeProduto);
        printf("\n PREÇO R$: %.2f", produtoRelatorio[i].valorProduto);
        //   printf("\n DATA R$: %d", data -> dataTime);

        printf("\n --------------------------------------------------" RESET);
    }
}

void VenderProdutos()
{
    char nomeProdu[20], op, achou = 0;
    float quantProd, valorTotalProduto, valorPago, valorTroco;
    do
    {
        printf("\n ----- SETOR DE VENDAS ----- \n");

        printf("\n Informe o produto: ");
        fflush(stdin);
        gets(nomeProdu);
        for (int i = 0; i < indProdutos; i++)
        {
            if (strcmp(produto[i].nomeProduto, nomeProdu) == 0)
            {
                achou = 1;
                do
                {
                    printf("\n Informe a quantidade: ");
                    scanf("%f", &quantProd);
                } while (quantProd <=0 || quantProd > produto[i].quantidadeProduto);
                
                if (quantProd <= produto[i].quantidadeProduto)
                {
                    produto[i].quantidadeProduto = produto[i].quantidadeProduto - quantProd; //icrementar de forma correta não quer.

                    valorTotalProduto = quantProd * produto[i].valorProduto;
                    printf("\n Total em Estoque: %.0f", produto[i].quantidadeProduto);
                    printf("\n Total do produto R$: %.2f", valorTotalProduto);

                    do
                    {
                        printf("\n Informe o pagamento: ");
                        scanf("%f", &valorPago);

                        if (valorPago < valorTotalProduto)
                        {
                            printf("\n {ERRO! VERIFIQUE O VALOR PAGO} \n");
                        }

                    } while (valorPago < valorTotalProduto);

                    if (valorPago >= valorTotalProduto)
                    {

                        valorTroco = valorPago - valorTotalProduto; //icrementar de forma correta não quer.

                        printf("\n\n TROCO R$: %f", valorTroco);

                        strcpy(produtoRelatorio[indiceVendidos].nomeProduto, nomeProdu);

                        produtoRelatorio[indiceVendidos].quantidadeProduto = quantProd;
                        produtoRelatorio[indiceVendidos].valorProduto = valorTotalProduto;
                        // invalid array assignment
                        indiceVendidos++;
                    }
                }
            }
        }

        if (achou == 0)
        {
            printf(VERMELHO "{\n **** PRODUTO NÃO ENCONTRADO! *****}" RESET);
        }
        printf("\n ----- [1]- Realizar nova venda || [0]- Menu Anterior -----\n ");
        scanf("%d", &op);

    } while (op != 0);
}
