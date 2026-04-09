/*
 * TP 1
 * Ejercicio 5                                                                           
 * Escriba un programa que permanentemente solicite un número entero e imprima en pantalla      
 * el promedio de los últimos 10 números ingresados hasta que el usuario ingrese la             
 * palabra “EXIT”.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _N 10

int main(void){

    char buffer[50];
    int i=0;
    int h=0;
    int numeros[_N]={0};
    float promedio;
    long num;
    char *fin;

    while(1){
        printf("Ingrese un numero entero o EXIT para finalizar:\n");
        if(fgets(buffer, 50, stdin)==NULL){
            printf("Error de lectura.\n");
            return 1;
        }
        buffer[strcspn(buffer, "\n")]='\0';
        
        if(strcmp(buffer,"EXIT")==0){
            printf("Programa terminado\n"); 
            return(0);
        }

        num = strtol(buffer, &fin, 10); // (string to long) convierte buffer a numero; fin apunta al primer caracter no convertido; 10 indica base decimal

         if(*buffer == '\0' || *fin != '\0'){  //primer condición: usuario no ingresó nada, segunda: usuario ingresó caracteres inválidos
            printf("Error: debe ingresar un numero entero valido o la palabra EXIT.\n");
            continue;
        }

        numeros[i] = (int)num;

        promedio=0;
        for(int j=0; j<_N;j++){
            promedio=promedio+numeros[j];

        }
    
        i=i+1;
        h=h+1;

        if(h<=10){
            printf("El promedio de los ultimos %d numeros ingresados es: %.2f \n",h , promedio/((float) h));
        }else{
            printf("El promedio de los ultimos 10 numeros ingresados es: %.2f \n", promedio/((float) _N));
        }
        
        if(i==_N){
            i=0;
        }
        
    }

    return 0;
}
