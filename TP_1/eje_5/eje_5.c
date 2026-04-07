#include <stdio.h>
#include <string.h>

#define n 10

void promedioDinamicoUltimos10();

int main() {
    //PromedioConOrdenamientoBurbuja();
    promedioDinamicoUltimos10();
    
    return 0;
}


//PEDIR NUMEROS CADA UN SEGUNDO AL USUARIO Y CALCULAR EL PROMEDIO DE LOS ULTIMOS 10 NUMEROS INGRESADOS
//LA CONDICION SE DEBE CUMPLIR HASTA QUE SE INGRESE "EXIT"

void promedioDinamicoUltimos10() {
    float arr[n], num, sum = 0.0;
    int count = 0;

    while (1) {
        printf("Ingrese un numero (o 'EXIT' para salir): ");
        if (scanf("%f", &num) != 1) { //Verfico que la entrada no es un numero
            char exitStr[5];
            scanf("%s", exitStr);
            if (strcmp(exitStr, "EXIT") == 0) {
                break; // si efectivamente no es un numero se compara con EXIT, si es igual, se corta el programa
            } else {
                printf("Entrada no valida. Intente de nuevo.\n"); 
                continue;
            }
        }
        if (count + 1 < n ) {
            arr[count+1] = num;
            sum += num;
            count++;
            printf("Ingrese %d numeros para completar los ultimos 10 y hacer el promedio.\n", n - count);
        } else {
            sum -= arr[0]; // Restar el primer numero del arreglo, YA TIENE SUMADOS LOS ANTERIORES
            for (int i = 0; i < n; i++) {
                arr[i] = arr[i + 1]; // Desplazar los numeros a la izquierda
            }
            arr[n - 1] = num; // Agregar el nuevo numero al final
            sum += num; // Sumar el nuevo numero
            printf("El promedio de los ultimos %d numeros es: %.2f\n", 10 , sum / 10);
        }  
    }
}