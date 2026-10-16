#include <stdio.h>

int main() {
    int sensor;
    float temp;
    int lido, c, lixo;

    while (1) {
        printf("Introduza o valor do sensor (-1 para terminar): ");
        lido = scanf("%d", &sensor);

        if (lido == EOF) {          
            break;
        }

        /* limpar o resto da linha e ver se havia caracteres a mais (ex.: "12abc") */
        lixo = 0;
        while ((c = getchar()) != '\n' && c != EOF) {
            if (c != ' ' && c != '\t' && c != '\r') {
                lixo = 1;
            }
        }

        if (lido != 1 || lixo) {
            printf("Entrada invalida. Introduza um numero inteiro.\n");
            continue;               /* pede de novo, sem terminar */
        }

        if (sensor == -1) {         /* sentinela */
            break;
        }

        if (sensor >= 0 && sensor <= 1023) {
            temp = 260.0f * sensor / 1023 - 20;

            if (temp >= -10 && temp <= 190) {
                printf("A temperatura e %.2f\n", temp);
            } else {
                printf("Valor fora da gama\n");
            }
        } else {
            printf("Valor fora da gama\n");
        }
    }

    return 0;
}