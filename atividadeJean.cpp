#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    genero = "";

    }

    void ler(){
        printf("Insira o nome:\n");
        scanf("%s", nome);

        printf("\nInsira a data de nascimento:\n");
        scanf("%d %d %d", &dataNascimento.ano, &dataNascimento.mes, &dataNascimento.ano);

        printf("\nInsira o gênero(M ou F):\n");
        scanf("%c", &genero);

        system("cls");
    }

    int calcularIdade(){

    }

};

int main(){



    return 0;
}
