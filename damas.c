#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define ALTURA 8
#define COMPRIMENTO 8

void printartabuleiroatual();
void inicializartabuleiro();
void inicializarpretas();
void inicializarbrancas();
void contarpecas();
void jogarbrancas();
void verificacao();
void moverpeca();
void jogarPretas();
void verificarvencedor();

char tabuleiro[COMPRIMENTO][ALTURA];
char vezdejogar;

int origemlinha;
int origemcoluna;
int destinolinha;
int destinocoluna;
int sorteio;
int qtdbrancas = 0;
int qtdpretas = 0;

    // ETAPA DE CONTRUÇÃO DO TABULEIRO

void inicializartabuleiro() {
    for (int i = 0; i < COMPRIMENTO; i++) {
        for(int j = 0; j < ALTURA; j++) { 
            tabuleiro[i][j] = '.';
        }
    }
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

    // CONTAGEM DE PEÇAS

void contarpecas() {

    qtdbrancas = 0;
    qtdpretas = 0;

    for (int i = 0; i < COMPRIMENTO; i++) {
        for(int j = 0; j < ALTURA; j++) { 
            if (tabuleiro[i][j] == 'B'){
                qtdbrancas++;
            } else if (tabuleiro[i][j] == 'P'){
                qtdpretas++;
            }     
        }
    }
}

void verificarvencedor() {
    if (qtdbrancas == 0) {
        printf("As pretas ganharam!!!");
    } else if (qtdpretas == 0) {
        printf("As brancas ganharam!!!");
    }

    qtdbrancas = 0;
    qtdpretas = 0;
    
}

void jogarbrancas() {

    printf("Escreva as coordenadas da peca que deseja mover: [COLUNA] [LINHA] ");
    scanf("%d %d", &origemcoluna, &origemlinha);

    if (origemlinha < 1 || origemlinha > 8 || origemcoluna < 1 || origemcoluna > 8) {
        printf("Corrdenadas incorretas!!\n");
        jogarbrancas();
    } else {
        if (tabuleiro[origemlinha-1][origemcoluna-1] == 'B') {
            printf("Escreva as coordenadas para onde a peca sera movida: [COLUNA] [LINHA] ");
            scanf("%d %d", &destinocoluna, &destinolinha);
            verificacao();   
        } else {
            printf("Coordenadas incorretas!!\n");
            jogarbrancas();
        }
    }
}

void jogarpretas() {

    printf("Escreva as coordenadas da peca que deseja mover: [COLUNA] [LINHA] ");
    scanf("%d %d", &origemcoluna, &origemlinha);

    if (origemlinha < 1 || origemlinha > 8 || origemcoluna < 1 || origemcoluna > 8) {
        printf("Corrdenadas incorretas!!\n");
        jogarpretas();
    } else {
        if (tabuleiro[origemlinha-1][origemcoluna-1] == 'P') {
            printf("Escreva as coordenadas para onde a peca sera movida: [COLUNA] [LINHA] ");
            scanf("%d %d", &destinocoluna, &destinolinha);
            verificacao();   
        } else {
            printf("Coordenadas incorretas!!\n");
            jogarpretas();
        }
    }
}

void verificacao() {
    int dLinha = destinolinha - origemlinha;
    int dColuna = destinocoluna - origemcoluna;

    if ((destinolinha < 1) || (destinolinha > 8) || (destinocoluna < 1) || (destinocoluna > 8)) {
        printf("Destino fora do tabuleiro!\n");
        if (vezdejogar == 'B'){
            jogarbrancas();
        } else {
            jogarpretas();
        }
    }

    if (tabuleiro[origemlinha-1][origemcoluna-1] != vezdejogar){
        printf("Coordenadas incorretas!!! Voce escolheu uma peça que não eh sua... \n");
    } else {
        if ((vezdejogar == 'B' && dLinha == -1 && (dColuna == 1 || dColuna == -1)) || (vezdejogar == 'P' && dLinha == 1 && (dColuna == 1 || dColuna == -1))) {

            if (tabuleiro[destinolinha-1][destinocoluna-1] == '.') {
                moverpeca();
            } else {
                printf("Casa ocupada!");
                if (vezdejogar == 'B') {
                jogarbrancas();
                } else {
                jogarpretas();
                }
            } 
        } else {
            printf("Movimento invalido!!! Voce so pode mover as pecas na diagonal!!!\n");
            if (vezdejogar == 'B') {
                jogarbrancas();
            } else {
                jogarpretas();
            }
        }
    }
}

void moverpeca() {

    tabuleiro[destinolinha-1][destinocoluna-1] = tabuleiro[origemlinha-1][origemcoluna-1];
    tabuleiro[origemlinha-1][origemcoluna-1]  = '.';  
    
    if (vezdejogar == 'P'){
        vezdejogar = 'B';
    } else if (vezdejogar == 'B'){
        vezdejogar = 'P';
    }

    printartabuleiroatual();
}

int main() {

    vezdejogar = 'B';

    // ETAPA DE CONTRUÇÃO DO TABULEIRO

    inicializartabuleiro();
    inicializarpretas();
    inicializarbrancas();
    printartabuleiroatual();

    while (1) {

        contarpecas();

        if (qtdbrancas == 0 || qtdpretas == 0) {
            verificarvencedor();
            break;
        }

        if (vezdejogar == 'B'){
            jogarbrancas();
        } else if (vezdejogar == 'P') {
            jogarpretas();
        }

        verificarvencedor();
    }
    return 0;
}