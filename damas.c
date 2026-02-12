#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define ALTURA 8
#define COMPRIMENTO 8

void printartabuleiroatual();
void inicializarpretas();
void inicializarbrancas();
void suavez();
void verificacao();
void moverpeca();

char tabuleiro[COMPRIMENTO][ALTURA];

int origemlinha;
int origemcoluna;
int destinolinha;
int destinocoluna;

int main() {
    setlocale(LC_ALL, "");
    for (int i = 0; i < COMPRIMENTO; i++) {
        for(int j = 0; j < ALTURA; j++) { 
            tabuleiro[i][j] = '.';
        }
    }
    printf("Voce eh as BRANCAS 'B'!\n\n");

    inicializarpretas();
    inicializarbrancas();
    printartabuleiroatual();

    suavez();
    verificacao();
    return 0;
}

void inicializarpretas () {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < ALTURA; j++) {
            if((i + j) % 2 == 1) {
                tabuleiro[i][j] = 'P';
            }
        }
    }
}

void inicializarbrancas () {
    for (int i = 5; i < COMPRIMENTO; i++) {
        for (int j = 0; j < ALTURA; j++) {
            if((i + j) % 2 == 1) {
                tabuleiro[i][j] = 'B';
            }
        }
    }
}

void printartabuleiroatual () {

    printf("  ");
    for (int j = 0; j < ALTURA; j++) {
        printf("%d ", j+1);
    }
    printf("\n");

    for (int i = 0; i < COMPRIMENTO; i++) {
        printf("%d ", i+1);
        for(int j = 0; j < ALTURA; j++) { 
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void suavez(){

    printf("Sua vez de jogar!!!\n");
    printf("Escreva as coordenadas da peca que deseja mover: [COLUNA] [LINHA] ");
    scanf("%d %d", &origemcoluna, &origemlinha);

    if (origemlinha < 1 || origemlinha > 8 || origemcoluna < 1 || origemcoluna > 8) {
        printf("Corrdenadas incorretas!!\n");
        suavez();
    } else {
        if (tabuleiro[origemlinha-1][origemcoluna-1] != '.') {
            printf("Escreva as coordenadas para onde a peca sera movida: [COLUNA] [LINHA] ");
            scanf("%d %d", &destinocoluna, &destinolinha);    
        } else {
            printf("Corrdenadas incorretas!!\n");
            suavez();
        }
    }

}

void verificacao(){
    int dLinha = destinolinha - origemlinha;
    int dColuna = destinocoluna - origemcoluna;

    if (tabuleiro[origemlinha-1][origemcoluna-1] != 'B') {
        printf("Coordenadas incorretas!!! Voce escolheu uma peça que não eh sua... \n");
    } else {
        if (dLinha == -1 && (dColuna == 1 || dColuna == -1)) {
            if (tabuleiro[destinolinha-1][destinocoluna-1] == '.') {
                moverpeca();
            } else {
                printf("Casa ocupada!");
            }
            
        } else {
            printf("Movimento invalido!!! Voce so pode mover as pecas na diagonal!!!\n");
            suavez();
        }
    }
}

void moverpeca(){

    tabuleiro[destinolinha-1][destinocoluna-1] = tabuleiro[origemlinha-1][origemcoluna-1];
    tabuleiro[origemlinha-1][origemcoluna-1]  = '.';    
    printartabuleiroatual();
}