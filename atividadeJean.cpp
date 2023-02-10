#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int anoAtual = 2023;
int mesAtual = 2;
// sempre que mudasse o mês teria que vir mudar manualmente

struct Data{

    int dia;
    int mes;
    int ano;

};

typedef struct Data data;


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

    }

    void ler(){
        system("cls");

        printf("Insira o nome:\n");
        scanf("%s", nome);

        printf("\nInsira a data de nascimento:\n");
        scanf("%d %d %d", &dataNascimento.dia, &dataNascimento.mes, &dataNascimento.ano);

        printf("\nInsira o genero(M ou F):\n");
        scanf(" %c", &genero);

        system("cls");
    }

    int calcularIdade(){

        int anoTemp = anoAtual - dataNascimento.ano;

        if(mesAtual < dataNascimento.mes){
            anoTemp--;
        }

        return anoTemp;
    }

    void imprimir(){

        system("cls");

        printf("Cliente: %s\n", nome);
        printf("Data de Nascimento: %d-%d-%d\n", dataNascimento.dia, dataNascimento.mes, dataNascimento.ano);
        printf("Idade: %d\n", calcularIdade());
        printf("Genero: %c\n\n", genero);

    }

};

int main(){

    Cliente clientes[50];

    int totalClientes = 0;
    int opcao;

    do{

        printf("***Menu***\n\n");
        printf("***Escolha uma opcao:\n");
        printf("***1- Cadastrar um cliente.***\n");
        printf("***2- Listar todos clientes.***\n");
        printf("***Caso deseje sair do programa, preencha qualquer outro caractere.***\n\n");

        scanf("%d", &opcao);

        switch(opcao){

            case 1:
                if(totalClientes == 49){
                    printf("Nao e possivel registrar novos clientes.\n");
                    break;
                }
                clientes[totalClientes].ler();
                totalClientes++;
                break;

            case 2:
                for(int i = 0; i < totalClientes; i++){
                    clientes[i].imprimir();
                }
                system("pause");
                system("cls");
        }

        if(totalClientes == 49){
            char opcaoTemp;
            printf("Alerta!\nO programa chegou ao limite de clientes registrados.\n");
        }



    }while(opcao == 1 || opcao == 2);


    return 0;
}
