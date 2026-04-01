/*
 * TP 1
 * Ejercicio 5                                                                           
 * Escriba un programa que permanentemente solicite un número entero e imprima en pantalla      
 * el promedio de los últimos 10 números ingresados hasta que el usuario ingrese la             
 * palabra “EXIT”.
 */

// Librerias
#include <stdio.h> // Para printf, fgets, fflush
#include <stdint.h>
#include <string.h> // Para strcmp
#include <stdlib.h> // Para atoi

// Macros
#define max_size_buff 10
#define max_number_size 10

int main(void){
    int numbers[max_number_size] = {0}, sum = 0;
    char buffer[max_size_buff];
    int i = 0, head = 0, count = 0, valor, start, pos;
    float prom = 0; 

    // El programa solicita un número entero al usuario de forma permanente hasta que se ingrese "EXIT".
    // El programa utiliza un looping infinito para solicitar números y calcular el promedio de los últimos 10 números ingresados.
    while (1){
        
        // Se lee la entrada del usuario usando fgets.
        // Se limpia el buffer antes de cada lectura para evitar problemas con entradas anteriores.
        // En cada loop se pide al usuario que ingrese un número entero o "EXIT" para terminar el programa.
        // Se elimina el salto de línea al final que agrega fgets para facilitar la comparación con "EXIT" y la conversión a entero.
        printf("Enter a integer or 'EXIT' to finish:\n");
        fflush(stdin);
        fgets(buffer, max_number_size, stdin);
        for (i=0; buffer[i] != '\n'; i++);
        buffer[i] = '\0';
        
        // Si el usuario ingresa "EXIT", el programa se termina.
        if (strcmp(buffer,"EXIT") == 0) {
            printf("The program is finished!");
            return 0;
        }
        
        // Valida que la entrada del usuario sea un número entero válido signado o no 
        // Si no lo es, se muestra un mensaje de error y se limpia el buffer para evitar procesar un valor no válido.
        for (i = 0; buffer[i] != '\0';i ++){
            if ((buffer[i] >= '0' && buffer[i] <= '9') || buffer[i] == '-') continue;
            else {
                printf("El valor no es un numero entero \n");
                buffer[0] = '\0'; // Limpiar el buffer para evitar procesar un valor no válido
                break;
            }
        }

        // Si la entrada es un número entero válido, se convierte a entero usando atoi y 
        // si la entrada es un número no válido, se pone el buffer como cadena vacía y con atoi se carga el 0
        // que no afecta el promedio pero permite continuar con el programa sin errores.
        // Y se almacena en un buffer circular para mantener solo los últimos 10 números ingresados.
        valor = atoi(buffer);
        
        // Se almacena siempre el nuevo valor en la posición indicada por head, que se mueve de forma circular 
        // para mantener solo los últimos 10 números ingresados.
        // La operación de resto con max_number_size asegura que head vuelva al inicio del array cuando alcance max_number_size,
        // y así se mantiene un buffer circular de los últimos 10 números ingresados.
        numbers[head] = valor; 
        head = (head + 1) % max_number_size; // Mover el head al siguiente índice

        // El contador de números ingresados se incrementa hasta un máximo de 10 para calcular el promedio correctamente.
        if (count < max_number_size) count++;

        // Calcular la posición de inicio para mostrar los últimos números ingresados en orden correcto, 
        // teniendo en cuenta el head y el count de números ingresados.
        start = (head - count + max_number_size) % max_number_size; 
        
        printf("The 10 most recent values are:\n");
        for (i = 0; i < count; i++) {
            pos = (start + i) % max_number_size; //
            printf("%d\t", numbers[pos]);
        }
        printf("\n");

        // Se calcula el promedio
        sum = 0;
        for (i = 0; i < count; i++) {
            sum += numbers[i];
        }

        prom = (float)sum / count;

        printf("Average: %.2f\n\n", prom);
    }

    return 0;
}
