/*2. Faça um programa que receba do usuário um arquivo texto e mostre na tela quantas
letras são vogais.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAMANHO 100

int main(){
    FILE *archive;
    char texto[TAMANHO];
    int qtd_vogais = 0;

    archive = fopen("arquivoBom.txt", "w");

    if(archive == NULL){
        printf("Erro ao abrir o arquivo.\n");
    }

    printf("Digite uma frase: ");
    fgets(texto, TAMANHO, stdin);
    texto[strcspn(texto, "\n")] = '\0';
    for(int i = 0; i < strlen(texto); i++){
        if(tolower(texto[i]) == 'a' || tolower(texto[i]) == 'e' || tolower(texto[i]) == 'i' || tolower(texto[i]) == 'o' || tolower(texto[i]) == 'u'){
            qtd_vogais++;
        }
    }


    for(int i = 0; i < strlen(texto); i++){
        fputc(texto[i], archive);
    }

    printf("No texto tiveram %d vogais.\n", qtd_vogais);

    fclose(archive);
}