#include <stdio.h>
#include <math.h>

#define MAX_LEITURAS 20   

int main() {
    int sensor;
    float temp;
    int lido, c, lixo;

    float temps[MAX_LEITURAS];  
    int n = 0;                  

    while (n < MAX_LEITURAS) {  
        printf("Introduza o valor do sensor (-1 para terminar): ");
        lido = scanf("%d", &sensor);

        if (lido == EOF) {
            break;
        }

        lixo = 0;
        while ((c = getchar()) != '\n' && c != EOF) {
            if (c != ' ' && c != '\t' && c != '\r') {
                lixo = 1;
            }
        }

        if (lido != 1 || lixo) {
            printf("Entrada invalida. Introduza um numero inteiro.\n");
            continue;
        }

        if (sensor == -1) {      
            break;
        }

        if (sensor >= 0 && sensor <= 1023) {
            temp = 260.0f * sensor / 1023 - 20;

            if (temp >= -10 && temp <= 190) {
                printf("A temperatura e %.2f\n", temp);
                temps[n] = temp;     
                n++;
            } else {
                printf("Valor fora da gama\n");
            }
        } else {
            printf("Valor fora da gama\n");
        }
    }

    if (n == MAX_LEITURAS) {
        printf("\nLimite maximo de %d leituras atingido.\n", MAX_LEITURAS);
    }

    if (n == 0) {
        printf("\nNao foram lidos valores validos.\n");
        return 0;
    }

    float max = temps[0];
    float min = temps[0];
    float soma = 0;
    int i;

    printf("\nValores lidos:\n");
    for (i = 0; i < n; i++) {
        printf("%d: %.2f\n", i + 1, temps[i]);

        if (temps[i] > max) max = temps[i];
        if (temps[i] < min) min = temps[i];
        soma += temps[i];
    }

    float media = soma / n;

    float somaQuad = 0;
    for (i = 0; i < n; i++) {
        somaQuad += (temps[i] - media) * (temps[i] - media);
    }
    float desvio = sqrtf(somaQuad / n);

    printf("\nNumero de valores lidos: %d\n", n);
    printf("Maximo: %.2f\n", max);
    printf("Minimo: %.2f\n", min);
    printf("Media: %.2f\n", media);
    printf("Desvio-padrao: %.2f\n", desvio);

    return 0;
}