#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>


// funcoes pra obter o retorno da data automaticamente
int obterAno(){

    SYSTEMTIME ano;

    GetSystemTime(&ano);

    return ano.wYear;
}

int obterDia(){

    SYSTEMTIME dia;

    GetSystemTime(&dia);

    return dia.wDay;
}

int obterMes(){

    SYSTEMTIME mes;

    GetSystemTime(&mes);

    return mes.wMonth;
}

int anoAtual = obterAno();
int mesAtual = obterMes();
int diaAtual = obterDia();

void mostrarMenu(){

    printf("****************************************************************************\n");
    printf("****************************************************************************\n");
    printf("***                              Menu                                    ***\n");
    printf("***                                                                      ***\n");
    printf("***   Escolha uma opcao:                                                 ***\n");
    printf("***                                                                      ***\n");
    printf("***   1- Cadastrar um cliente.                                           ***\n");
    printf("***   2- Listar todos clientes.                                          ***\n");
    printf("***                                                                      ***\n");
    printf("***   Caso deseje sair do programa, preencha qualquer outro caractere.   ***\n");
    printf("***                                                                      ***\n");
    printf("****************************************************************************\n");
    printf("****************************************************************************\n");

}

void limparTela(){

    system("cls");

}// funcao pra limpar a tela

void pausarTela(){

    system("pause");

}// funcao pra pausar a tela

struct DataDeNascimento{

    int dia;
    int mes;
    int ano;

}; // declarando struct de data

typedef struct DataDeNascimento data; // mudando a maneira de declarar a struct


struct Cliente {

    char nome[50];
    data dataNascimento;
    int idade;
    char genero;

    Cliente(){

    strcpy(nome, "");
    dataNascimento.dia = 0;
    dataNascimento.mes = 0;
    dataNascimento.ano = 0;
    idade = 0;
    genero = '0';

    }//construtora que zera todos os valores sempre que um cliente eh declarado



    void ler(){

        limparTela();

        printf("Insira o nome:\n");
        fflush(stdin);
        scanf("%[^\n]s", nome);


        printf("\nInsira a data de nascimento:\n");
        scanf("%d %d %d", &dataNascimento.dia, &dataNascimento.mes, &dataNascimento.ano);

        printf("\nInsira o genero(M ou F):\n");
        scanf(" %c", &genero);

        idade = calcularIdade();

        limparTela();
    }
    //metodo pra ler os dados de um cliente



    int calcularIdade(){

        int anoTemp = anoAtual - dataNascimento.ano;

        mesAtual < dataNascimento.mes ? anoTemp-- : diaAtual < dataNascimento.dia ? anoTemp-- : printf("");
                                                                                                // o que colocar quando nao quiser que aconteca nada?

        return anoTemp;
    }
    // funcao pra calcular a idade ------ subtrai o ano atual pelo ano informado e, caso o mes informado seja maior que o mes atual, subtrai o ano em 1



    void imprimir(){

        printf("\n");
        printf("****************************************\n");
        printf("     Cliente: %s\n", nome);
        printf("     Data de Nascimento: %02d/%02d/%04d\n", dataNascimento.dia, dataNascimento.mes, dataNascimento.ano);
        printf("     Idade: %d\n", idade);
        printf("     Genero: %c\n", genero);
        printf("****************************************\n");

    } // metodo que imprime os dados na tela

};

int main(){

    Cliente clientes[50];

    int totalClientes = 0; // variavel pra armazenar a quantidade de clientes cadastrados, para futuramente impedir que passe de 50
    int opcao; // variavel pra guardar a opcao escolhida pelo usuario no menu
    int mostrouAlerta = 0; // variavel que define se mostra o alerta apos o switch ou nao

    do{

        mostrarMenu();

        scanf("%d", &opcao);
        mostrouAlerta = 0;

        switch(opcao){

            case 1:

                if(totalClientes == 49){
                    printf("Nao e possivel registrar novos clientes.\n");
                    mostrouAlerta = 1;
                    break;
                }
                // if que impede o usuario de cadastrar mais de 50 clientes e emite um alerta


                clientes[totalClientes].ler(); // chamando o metodo que le os dados

                totalClientes++; // incrementando o total de clientes

                break;

            case 2:

                limparTela();

                for(int i = 0; i < totalClientes; i++){
                    clientes[i].imprimir(); // metodo dentro de um for pra imprimir TODOS os clientes cadastrados
                }

                pausarTela();

                limparTela();
        }


        if(totalClientes == 49 && !mostrouAlerta){

            printf("Alerta!\nO programa chegou ao limite de clientes registrados.\n\n");
            pausarTela();
            limparTela();

        }
        // emite um alerta(apenas no exato momento que o usuario cadastrar o cliente numero 50)


    }while(opcao == 1 || opcao == 2);
    // do while enquanto nao for digitado as opcoes oferecidas no menu, qualquer outro input sai do programa


    return 0;
}
