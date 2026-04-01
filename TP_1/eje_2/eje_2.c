
/*
 * TP 1
 * Ejercicio 1
 * Escriba un programa que solicite 5 número enteros por teclado e imprima su valor
 * medio. Los 5 números deben estar separados por comas, ser signados de hasta 3
 * dígitos y su ingreso realizarse en batch con la tecla enter. El programa debe imprimir
 * en pantalla los errores de ingreso cometidos por el usuario. 
 * 
 * Ejercicio 2                                                                                  
 * Agregue al programa del inciso (1) la muestra en pantalla de los 10 números ordenados        
 * en forma ascendente tras haber realizado un ordenamiento “Bubble Sort”.                      
 * Autor: Mateus Costa
 */

// Librerías
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Macros 
#define buffer_size 50
#define cant_numeros 10
#define cant_digitos 3

// Teclas 
#define NOK 0
#define OK 1

int validate_buffer(char *buffer);

int validate_cant_num(char *buffer);

int validate_num(int num);

void bubble_sort(int *array, int size);

void print_array(int *array, int size);

int main(void){
    
    float prom;
    char buffer[buffer_size], buffer_aux[cant_digitos+2]; 
    int nums[cant_numeros];
    
    int i, j, k;     

    // Se pide al usuario que ingrese 10 números enteros de hasta 3 dígitos, separados por coma.
    // El ingreso se realiza en batch con la tecla enter usando la función fgets para leer la entrada del usuario.
    printf("Escribe 10 numeros enteros de hasta 3 digitos signados o no, separados por coma.\n"); 
    fflush(stdin);
    fgets(buffer, buffer_size, stdin);
    
    // Validar que el buffer solo contenga números, comas, espacios y un salto de línea al final, 
    // y que el número de comas sea correcto para la cantidad de números esperada.
    if (validate_buffer(buffer) == NOK) {
        printf("Error: ingreso de un caracter equivocado.");
        return 0;
    }

    if (validate_cant_num(buffer) == NOK){
        printf("Error: no se ingreso la cantidad de numeros correctos.");
        return 0;
    }

    // i para recorrer el buffer 
    // j para recorrer el buffer_aux  
    // k para recorrer el array de numeros
    j=0; k=0;
    // Paso por el buffer y guardo los numeros en un array de enteros.
    for (i=0; buffer[i] !='\0' && i < buffer_size ; i++){
        if (buffer[i] != ',' && buffer[i] != '\n'){
            buffer_aux[j] = buffer[i];
            j++;
        }
        else if (buffer[i] == ',' || buffer[i] == '\n'){
            buffer_aux[j] = '\0';
            nums[k] = atoi(buffer_aux);
            j=0;
            k++;
        }
        else k++;
    }

    // Valido que cada numero este dentro del rango permitido de hasta 3 dígitos signados o no.
    for (i=0; i<cant_numeros; i++){
        if (validate_num(nums[i]) == NOK){
            printf("Error: ingreso de un numero con mas de 3 digitos.");
            return 0;
        }
    }

    // Se calcula el promedio de los numeros ingresados y se imprime en pantalla. 
    prom = 0;

    for(int i=0; i<cant_numeros;i++){
        prom += nums[i];
    }

    prom = prom / cant_numeros;
    printf("El promedio de los numeros es:%f\n", prom);
    
    // Se ordena los números usando el algoritmo de ordenamiento “Bubble Sort” y se los imprime en pantalla.
    bubble_sort(nums, cant_numeros);
    
    print_array(nums, cant_numeros);

    return 0;
    
}


int validate_buffer(char *buffer){
    int i, botton=OK;

    for(i=0; buffer[i]!='\0'; i++){
        if (((buffer[i] <= '9') && (buffer[i] >= '0')) ||(buffer[i] == '-') || (buffer[i] == ',') || (buffer[i] == '\n') || (buffer[i] == ' ') )  botton=OK;
        else  {
            botton=NOK;
            break;
        }
    }
    return botton;
}

int validate_cant_num(char *buffer){
    int i;
    int k=0; // contador de comas 

    for (i=0; buffer[i]!='\0'; i++){
        if(buffer[i] == ',') k++;
    }
    if (k == cant_numeros - 1) return OK;
    else return NOK;   
}

// valido que numero tenga hasta 3 digitos signados o no
int validate_num(int num){
    if ((num >= -999) && (num <= 999)) return OK;
    else return NOK;
}

void bubble_sort(int *array, int size){
    int i, j, temp;

    for (i=0; i<size-1; i++){
        for (j=0; j<size-i-1; j++){
            if (array[j] > array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    return;
}


void print_array(int *array, int size){
    int i;
    printf("Numeros ordenados:\n");
    for (i=0; i<size; i++){
        printf("%d\t", array[i]);
    }
    printf("\n");
    return;
}

