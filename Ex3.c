/*3. Faça um programa que salvará dados de alunos em arquivos. Um aluno será
composto pelos seguintes campos: numero, nome, curso, nota1, nota2. Cada campo
será informado pelo usuário. O seu programa deverá criar um arquivo chamado
NomeDoAluno.txt (haverá um arquivo por aluno) e salvar as informações do aluno
neste arquivo. Teste seu programa com 3 alunos.*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define TAMANHO 3

typedef struct{
    int numero;
    char nome[50];
    char curso[50];
    float nota1, nota2;
}cadastro;

cadastro alunos[TAMANHO];

void cadastra_aluno(cadastro alunos[TAMANHO]){
    for(int i = 0; i < TAMANHO; i++){
        printf("Digite o número do aluno: ");
        scanf("%d", &alunos[i].numero);
        setbuf(stdin, NULL);
        
        printf("Digite o nome do aluno: ");
        fgets(alunos[i].nome, 50, stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';

        printf("Digite o curso do aluno: ");
        fgets(alunos[i].curso, 50, stdin);
        alunos[i].curso[strcspn(alunos[i].curso, "\n")] = '\0';

        printf("Digite as notas do aluno: ");
        scanf("%f %f", &alunos[i].nota1, &alunos[i].nota2);
        setbuf(stdin, NULL);

        printf("\n");
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    cadastro alunos[TAMANHO];
    FILE *arq;

    cadastra_aluno(alunos);

    for(int i = 0; i < TAMANHO; i++){
        arq = fopen(("%s.txt", alunos[i].nome), "w");

        if(arq == NULL){
            printf("Erro ao abrir o arquivo.\n");
        }

        fprintf(arq, "%d", alunos[i].numero);
        fputc('\n', arq);

        for(int j = 0; j < strlen(alunos[i].nome); j++){
            fputc(alunos[i].nome[j], arq);
        }
        fputc('\n', arq);

        for(int k = 0; k < strlen(alunos[i].curso); k++){
            fputc(alunos[i].curso[k], arq);
        }
        fputc('\n', arq);

        fprintf(arq, "%f", alunos[i].nota1);
        fputc('\n', arq);
        
        fprintf(arq, "%f", alunos[i].nota2);
        fputc('\n', arq);

        fclose(arq);
    }

}