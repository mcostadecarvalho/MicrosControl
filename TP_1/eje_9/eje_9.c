 /*
  * TP 1 
  * Ejercicio 9                                                                           
  * Escriba un programa el cual pida por pantalla el nombre del usuario y lo imprima en          
  * mayúsculas en forma permanente solo pudiendo salir mediante la señal SIGINT, tras la cual    
  * debe despedirse al usuario. El programa debe imprimir en pantalla los errores de             
  * ingreso cometidos por el usuario, ya que no serán válidos los nombres que contengan números  
  * o carácteres especiales.
  */  

// Librerías
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <signal.h> // Para manejar SIGINT
#include <unistd.h> // Para sleep

// Macros
#define MAX_NAME_LENGTH 20
#define OK 1
#define NOK 0

// Tipos de datos
typedef enum estados {
    INICIO,
    ESPERANDO,
    VALIDANDO,
    INVALIDO

} t_estados;

// Prototipos de funciones
void sigint_handler(int signal);

void convertir_caracter_mayuscula(char *c);

int verificar_caracter_valido(char c);

int verificar_caracter_minuscula(char c);

int main(void) {
    char buffer[MAX_NAME_LENGTH];
    t_estados estado = INICIO;
    int i;

    // Se configura el control de la señal SIGINT para que llame a la función sigint_handler cuando se reciba la señal
    // Esto permite que el programa pueda manejar la interrupción con Ctrl+c y ejecutar una función de despedida antes de terminar
    signal(SIGINT, sigint_handler);
    printf("Inicializando...\n");

    // El programa entra en un loop infinito donde se maneja el estado del programa 
    // para solicitar el nombre del usuario, validar la entrada y convertirla a mayúsculas.
    while(1){

        switch (estado) {
            case INICIO:
                printf("Ingrese su nombre:\n");
                estado = ESPERANDO;
                break;

            case ESPERANDO:
                fflush(stdin); // Se limpia el buffer de entrada para evitar problemas con entradas anteriores
                if (fgets(buffer, MAX_NAME_LENGTH, stdin) != NULL) {
                    estado = VALIDANDO;
                } else {
                    fprintf(stderr, "\nError al leer el nombre. Intente nuevamente.\n");
                    estado = INICIO;
                }
                break;

            case VALIDANDO:
                
                for (i = 0; buffer[i] != '\n'; i++) {
                    if (verificar_caracter_valido(buffer[i]) != OK) {
                        estado = INVALIDO;
                        break;
                    }
                }
                if (estado != INVALIDO) {
                    for (i = 0; buffer[i] != '\n'; i++) {
                        
                        if (verificar_caracter_minuscula(buffer[i]) == OK) convertir_caracter_mayuscula(&buffer[i]);
                        
                        else buffer[i] = buffer[i]; // Si el caracter es mayúscula, lo dejamos igual          
                        }

                    buffer[i] = '\0'; // Se reemplaza el salto de línea por el carácter nulo
                    printf("Nombre en mayusculas:\n%s\n", buffer);
                    estado = INICIO;

                    }
                
                break;

            case INVALIDO:
                fprintf(stderr, "Nombre invalido. Intente nuevamente.\n");
                estado = INICIO;
                break;

            default:
                fprintf(stderr, "Estado desconocido. Reiniciando.\n");
                estado = INICIO;
                break;
        }
        
        sleep(1); // Agregar un pequeño retraso para evitar que el programa consuma demasiados recursos
        
    }

    return 0;
}

void sigint_handler(int signal) {

    printf("\nEl programa ha sido interrumpido.\n");
    
    exit(0);
}

void convertir_caracter_mayuscula(char *c) {
    if (*c >= 'a' && *c <= 'z') {
        *c = *c - ('a' - 'A');
    }
}

// Verificar si el caracter es una letra mayúscula o minúscula
int verificar_caracter_valido(char c) {
    if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) return NOK;
    else return OK;
}

int verificar_caracter_minuscula(char c) {
    if (c >= 'a' && c <= 'z') return OK;
    else return NOK;
}
