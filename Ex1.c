/*1. Escreva um programa que:
a. Crie/abra um arquivo texto de nome “arq.txt”
b. Permita que o usuário grave diversos caracteres nesse arquivo, até que o
usuário entre com o caractere ‘0’
c. Feche o arquivo
d. Agora, abra e leia o arquivo, caractere por caractere, e escreva na tela todos
os caracteres armazenados*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *arquivo;
    char caractere, letra;

    arquivo = fopen("arq.txt", "w");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
    }

    printf("Digite alguns caracteres, digite 0 para parar: \n");
    do{
        scanf("%c", &caractere);
        fputc(caractere, arquivo);
    }while(caractere != '0');

    fclose(arquivo);

    arquivo = fopen("arq.txt", "r");

    printf("Caracteres digitados: \n");
    do{
        letra = fgetc(arquivo);
        printf("%c", letra);

    }while(letra != EOF);

    printf("\n");

    fclose(arquivo);
}