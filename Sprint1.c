#include <stdio.h>

int main()  {
    int sensor; 

    printf ("Introduza o valor do sensor: ");
    scanf ("%d" , &sensor);
    printf ("Sensor: %d\n" , sensor); 

    if (sensor >=0 && sensor <=1023)  { 

        float temp = 260 * sensor / 1023 - 20;
        printf("O valor da temperatura e: %.2f \n" , temp); 
    }
    else {
        printf ("O valor do sensor esta invalido");
    }
        return 0;

}