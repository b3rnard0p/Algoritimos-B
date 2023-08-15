/**
 * Escreva um programa que leia um vetor de produtos, com 50 elementos, sendo cada elemento
uma estrutura que cont�m o nome do produto, seu pre�o de compra e seu pre�o de venda.
Depois de lido o vetor, retorne o nome e o �ndice do produto de menor pre�o de compra.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 50

 typedef struct {
     char nome[100];
     float precoCompra;
     float precoVenda;
     float margemLucro;
 } Produto;

 int main() {
    Produto vetor[TAM];
    int opcao;
    
     setlocale(LC_ALL, "Portuguese");

    int i = 0;
    do {
        system("cls"); 
        printf("Sistema de Produtos\n\n");
        printf("Descri��o do produto: ");
        gets(vetor[i].nome);
        fflush(stdin);

        printf("Pre�o de compra: ");
        scanf("%f", &vetor[i].precoCompra);
        fflush(stdin);

        printf("Pre�o de venda: ");
        scanf("%f", &vetor[i].precoVenda);
        fflush(stdin);
        
        vetor[i].margemLucro = vetor[i].precoVenda - vetor[i].precoCompra;

        i++;

        if (i == TAM) {
            printf("Estrutura lotou... sistema encerrando ...");
            break;
        }
        printf("1 - Continua; 2 - Termina: ");
        scanf("%d", &opcao);
        fflush(stdin);
    } while (opcao == 1);

    printf("Exibindo dados de alunos cadastrados!!\n\n");
    int iAux;
    for (iAux = 0; iAux < i; iAux++) {
        printf("Produto        : %s\n", vetor[iAux].nome);
        printf("Pre�o de Venda : R$%.2f\n", vetor[iAux].precoVenda);
        printf("Pre�o de Compra: R$%.2f\n", vetor[iAux].precoCompra);
        printf("Lucro          : R$%.2f\n", vetor[iAux].margemLucro);
        printf("============================\n");
    }

    
    int indiceMaiorLucro = 0;
    float maiorLucro = vetor[0].margemLucro;
    for (iAux = 1; iAux < i; iAux++) {
        if (vetor[iAux].margemLucro > maiorLucro) {
            indiceMaiorLucro = iAux;
            maiorLucro = vetor[0].margemLucro;
        }
    }

    printf("\n");
    printf("O produto %s possui o maior lucro: R$%.2f\n\n", vetor[indiceMaiorLucro].nome, vetor[indiceMaiorLucro].margemLucro);
    return 1;
 }
 
