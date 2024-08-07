#include<stdio.h>
#include<stdlib.h>
#include <time.h>
int main(void){
    int numeroAleatorio;
    int contador=0;
    int numero;
    srand(time(NULL));
    numeroAleatorio=rand()%100;
    printf("%d",numeroAleatorio);
    printf("\n");
    do
    {
        printf("Ingrese un numero entre 1 y 100:");
        scanf("%d",&numero);
        if(numero==numeroAleatorio){
            printf("Encontraste el número secreto");
            contador=10;

        }else if (numero<numeroAleatorio)
        {
           printf("El número es mayor");
           printf("\n");
        }else{
            printf("El numero es menor");
            printf("\n");

        }
        contador++;
    } while (contador<10);
    if (contador==10){
        printf("Perdiste el juego");
    }
    return 0;
}