#include <stdio.h>
#include <math.h>

#define MAX_LEITURAS      20      
#define VALOR_TERMINACAO  -1     
#define SENSOR_MIN        0      
#define SENSOR_MAX        1023
#define TEMP_MIN          -10     
#define TEMP_MAX          190
#define TEMP_AMPLITUDE    260.0f 
#define TEMP_DESLOCAMENTO 20


float converter_sensor_para_temperatura(int valor_sensor) {
    return TEMP_AMPLITUDE * valor_sensor / SENSOR_MAX - TEMP_DESLOCAMENTO;
}

int sensor_esta_na_gama(int valor_sensor) {
    return valor_sensor >= SENSOR_MIN && valor_sensor <= SENSOR_MAX;
}

int temperatura_e_valida(float temperatura) {
    return temperatura >= TEMP_MIN && temperatura <= TEMP_MAX;
}


float calcular_minimo(const float valores[], int quantidade) {
    float minimo = valores[0];
    for (int i = 1; i < quantidade; i++) {
        if (valores[i] < minimo) {
            minimo = valores[i];
        }
    }
    return minimo;
}

float calcular_maximo(const float valores[], int quantidade) {
    float maximo = valores[0];
    for (int i = 1; i < quantidade; i++) {
        if (valores[i] > maximo) {
            maximo = valores[i];
        }
    }
    return maximo;
}

float calcular_media(const float valores[], int quantidade) {
    float soma = 0;
    for (int i = 0; i < quantidade; i++) {
        soma += valores[i];
    }
    return soma / quantidade;
}

float calcular_desvio_padrao(const float valores[], int quantidade, float media) {
    float soma_quadrados = 0;
    for (int i = 0; i < quantidade; i++) {
        soma_quadrados += (valores[i] - media) * (valores[i] - media);
    }
    return sqrtf(soma_quadrados / quantidade);
}


int ler_inteiro(int *valor) {
    int c;
    int lixo = 0;
    int lido = scanf("%d", valor);

    if (lido == EOF) {
        return EOF;
    }

    while ((c = getchar()) != '\n' && c != EOF) {
        if (c != ' ' && c != '\t' && c != '\r') {
            lixo = 1;
        }
    }

    if (lido != 1 || lixo) {
        return 0;
    }
    return 1;
}

int ler_sequencia_valores(float temperaturas[], int max_leituras) {
    int quantidade = 0;
    int valor_sensor;
    int estado;
    float temperatura;

    while (quantidade < max_leituras) {
        printf("Introduza o valor do sensor (-1 para terminar): ");
        estado = ler_inteiro(&valor_sensor);

        if (estado == EOF) {
            break;
        }
        if (estado == 0) {
            printf("Entrada invalida. Introduza um numero inteiro.\n");
            continue;
        }
        if (valor_sensor == VALOR_TERMINACAO) {
            break;
        }

        if (sensor_esta_na_gama(valor_sensor)) {
            temperatura = converter_sensor_para_temperatura(valor_sensor);
            if (temperatura_e_valida(temperatura)) {
                printf("A temperatura e %.2f\n", temperatura);
                temperaturas[quantidade] = temperatura;
                quantidade++;
                continue;
            }
        }
        printf("Valor fora da gama\n");
    }

    if (quantidade == max_leituras) {
        printf("\nLimite maximo de %d leituras atingido.\n", max_leituras);
    }

    return quantidade;
}


void apresentar_lista_valores(const float temperaturas[], int quantidade) {
    printf("\nValores lidos:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("%d: %.2f\n", i + 1, temperaturas[i]);
    }
}

void apresentar_estatisticas(const float temperaturas[], int quantidade) {
    float media = calcular_media(temperaturas, quantidade);

    printf("\nNumero de valores lidos: %d\n", quantidade);
    printf("Maximo: %.2f\n", calcular_maximo(temperaturas, quantidade));
    printf("Minimo: %.2f\n", calcular_minimo(temperaturas, quantidade));
    printf("Media: %.2f\n", media);
    printf("Desvio-padrao: %.2f\n", calcular_desvio_padrao(temperaturas, quantidade, media));
}

void apresentar_resultados(const float temperaturas[], int quantidade) {
    if (quantidade == 0) {
        printf("\nNao foram lidos valores validos.\n");
        return;
    }
    apresentar_lista_valores(temperaturas, quantidade);
    apresentar_estatisticas(temperaturas, quantidade);
}


int main() {
    float temperaturas[MAX_LEITURAS];
    int quantidade;

    quantidade = ler_sequencia_valores(temperaturas, MAX_LEITURAS);
    apresentar_resultados(temperaturas, quantidade);

    return 0;
}