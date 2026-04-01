/*
 * TP 1 
 * Ejercicio 6                                                                           
 * Escriba una librería que permita trabajar con vectores reales en R3, la misma debe permitir  
 * realizar las siguientes operaciones:                                                         
 *      - Norma de 1 vector                                                                     
 *      - Suma entre 2 vectores                                                                 
 *      - Resta entre 2 vectores                                                                
 *      - Producto interno entre 2 vectores                                                     
 *      - Producto externo entre 2 vectores                                                     
 * La implementación debe realizarse mediante el uso de tipos de dato struct y                  
 * punteros a función.
 */

#include "eje_6.h"

int main(void) {
    vector_3D v1, v2, v_buffer;
    float resultado_norma_v1, resultado_norma_v2, resultado_producto_interno;

    // Apuntas el puntero a función dentro del struct 
    // A fcrear_vector 
    v1.crear_vector = fcrear_vector;
    v2.crear_vector = fcrear_vector;
    v_buffer.crear_vector = fcrear_vector;

    // Se crean dos vectores usando la función fcrear_vector a través del puntero a función dentro del struct
    v1 = v1.crear_vector(1.0, 2.0, 3.0);
    v2 = v2.crear_vector(4.0, 5.0, 6.0);
    v_buffer = v_buffer.crear_vector(0.0, 0.0, 0.0);

    // Se calculan las normas de los vectores usando el puntero a función dentro del struct
    resultado_norma_v1 = v1.norma(v1);
    resultado_norma_v2 = v2.norma(v2);

    // Se imprimen los vectores usando el puntero a función dentro del struct 
    // y se realizan las operaciones de suma, resta, producto interno y producto externo, imprimiendo los resultados en pantalla.
    // Esto se realiza usando las funciones correspondientes en la librería y pasando los vectores o punteros a vectores como argumentos.
    printf("Vector 1:\n");
    v1.imprimir_vector(v1);
    printf("Vector 2:\n");
    v2.imprimir_vector(v2);

    // Se pasan punteros a vectores a las funciones de la librería para realizar las operaciones correspondientes 
    // y se imprimen los resultados en pantalla.
    fsuma(&v1, &v2, &v_buffer);
    printf("Suma de v1 y v2 es:\n");
    v_buffer.imprimir_vector(v_buffer);

    // Se pasan punteros a vectores a las funciones de la librería para realizar las operaciones correspondientes 
    // y se imprimen los resultados en pantalla.
    fresta(&v1, &v2, &v_buffer);
    printf("Resta de v1 y v2 es:\n");
    v_buffer.imprimir_vector(v_buffer);

    // Se pasan punteros a vectores a las funciones de la librería para realizar las operaciones correspondientes
    // y se imprimen los resultados en pantalla.
    resultado_producto_interno = fproducto_interno(&v1, &v2);
    printf("Producto Interno: %.2f\n", resultado_producto_interno);

    // Se pasan punteros a vectores a las funciones de la librería para realizar las operaciones correspondientes
    // y se imprimen los resultados en pantalla.
    fproducto_externo(&v1, &v2, &v_buffer);
    printf("Producto Externo de v1 y v2 es:\n");
    v_buffer.imprimir_vector(v_buffer);

    // Se imprimen las normas de los vectores en pantalla.
    printf("Norma de Vector 1: %.2f\n",resultado_norma_v1);
    printf("Norma de Vector 2: %.2f\n", resultado_norma_v2);

    return 0;
}
