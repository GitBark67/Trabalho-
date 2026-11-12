#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    char entrada[100];
    char *fim;
    long linhas;

    printf("=== TRIANGULO DE PASCAL ===\n");

    while (1) {
        printf("\nQuantidade de linhas (1 a 20) ou 0 para sair: ");
        fflush(stdout);

        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            printf("\nPrograma encerrado.\n");
            break;
        }

        /* Descarta entradas maiores que o tamanho do buffer. */
        if (strchr(entrada, '\n') == NULL && !feof(stdin)) {
            int caractere;
            while ((caractere = getchar()) != '\n' && caractere != EOF) {
            }
            printf("Entrada muito longa. Tente novamente.\n");
            continue;
        }

        linhas = strtol(entrada, &fim, 10);
        if (fim == entrada) {
            printf("Digite um numero inteiro de 0 a 20.\n");
            continue;
        }

        while (isspace((unsigned char)*fim)) {
            fim++;
        }

        if (*fim != '\0' || linhas < 0 || linhas > 20) {
            printf("Digite um numero inteiro de 0 a 20.\n");
            continue;
        }

        if (linhas == 0) {
            printf("Programa encerrado.\n");
            break;
        }

        printf("\n");
        for (int i = 0; i < linhas; i++) {
            unsigned long long valor = 1;

            /* Centraliza as linhas. */
            for (int espaco = 0; espaco < linhas - i - 1; espaco++) {
                printf("   ");
            }

            for (int j = 0; j <= i; j++) {
                printf("%6llu", valor);
                if (j < i) {
                    valor = valor * (i - j) / (j + 1);
                }
            }
            printf("\n");
        }
    }

    return 0;
}
