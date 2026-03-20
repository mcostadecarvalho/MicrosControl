/*
 Ejercicio 6 - 2025                                                                           
 Escriba una librería que permita trabajar con vectores reales en R3, la misma debe permitir  
 realizar las siguientes operaciones:                                                         
      - Norma de 1 vector                                                                     
      - Suma entre 2 vectores                                                                 
      - Resta entre 2 vectores                                                                
      - Producto interno entre 2 vectores                                                     
      - Producto externo entre 2 vectores                                                     
 La implementación debe realizarse mediante el uso de tipos de dato struct y                  
 punteros a función.
*/

#include <stdio.h>
#include <stdint.h>
#include "eje_6.c"
#include <stdlib.h>

int main(void) {
    vector_3D v1 = crear_vector(1.0, 2.0, 3.0);
    vector_3D v2 = crear_vector(4.0, 5.0, 6.0);
    vector_3D v_buffer;

    printf("Vector 1:\n");
    imprimir_vector(&v1);
    printf("Vector 2:\n");
    imprimir_vector(&v2);

    v_buffer = suma(&v1, &v2);
    printf("Suma de v1 y v2 es:\n");
    imprimir_vector(&v_buffer);

    v_buffer = resta(&v1, &v2);
    printf("Resta de v1 y v2 es:\n");
    imprimir_vector(&v_buffer);

    float producto_interno_result = producto_interno(&v1, &v2);
    printf("Producto Interno: %.2f\n", producto_interno_result);

    v_buffer = producto_externo(&v1, &v2);
    printf("Producto Externo de v1 y v2 es:\n");
    imprimir_vector(&v_buffer);

    float norma_v1 = norma(&v1);
    printf("Norma de Vector 1: %.2f\n", norma_v1);
    printf("Norma de Vector 2: %.2f\n", norma(&v2));

    return 0;
}
