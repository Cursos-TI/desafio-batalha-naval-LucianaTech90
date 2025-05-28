#include <stdio.h>
   
int main() {
    printf("Batalha Naval!/n");
  
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int linha, coluna; 

    printf("Inicializando tabuleiro com agua (0)...\n");
    for (linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = AGUA;
        }
    }

    int navio1_linha_inicial = 2;
    int navio1_coluna_inicial = 3;
    int navio1[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};

    int navio2_linha_inicial = 5;
    int navio2_coluna_inicial = 2;
    int navio2[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};

    int navio1_valido = 1;

    if (navio1_coluna_inicial + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio 1 (horizontal) ultrapassa o limite do tabuleiro.\n");
        navio1_valido = 0;
    }

    if (navio1_valido) {
        for (i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[navio1_linha_inicial][navio1_coluna_inicial + i] = NAVIO;
        }
        printf("Navio 1 posicionado com sucesso (horizontal).\n");
    } else {
        printf("Navio 1 não foi posicionado devido a erro.\n");
    }

    int navio2_valido = 1; // Flag para verificar se o navio é válido

    if (navio2_linha_inicial + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio 2 (vertical) ultrapassa o limite do tabuleiro.\n");
        navio2_valido = 0;
    }

    if (navio2_valido) {
        for (i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[navio2_linha_inicial + i][navio2_coluna_inicial] == NAVIO) {
                printf("Erro: Navio 2 (vertical) se sobrepõe ao Navio 1.\n");
                navio2_valido = 0;
                break; 
            }
        }
    }

    if (navio2_valido) {
        for (i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[navio2_linha_inicial + i][navio2_coluna_inicial] = NAVIO;
        }
        printf("Navio 2 posicionado com sucesso (vertical).\n");
    } else {
        printf("Navio 2 não foi posicionado devido a erro ou sobreposição.\n");
    }


    printf("\n--- Tabuleiro Final ---\n");
    
    printf("   "); 
    for (coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
        printf("%2d ", coluna);
    }
    printf("\n");

    for (linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        printf("%2d ", linha); 
        for (coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf("%2d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0; 
}