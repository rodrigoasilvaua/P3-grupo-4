#include <stdio.h>

int main()  {
    int sensor; 
    float temp;

    printf ("Introduza o valor do sensor: ");
    scanf ("%d" , &sensor);
    printf ("Sensor: %d\n" , sensor); 

    if (sensor >=0 && sensor <=1023)  { 
        temp = 260 * sensor / 1023 - 20;

        if (temp >=-10 && temp <= 190) {
            printf("A temperatura é %.2f \n", temp);
        } else {
            printf("A temperatura esta fora da gama \n");
        }

    } else {
         printf ("O valor do sensor esta invalido \n");
    }
     
    return 0;

}
