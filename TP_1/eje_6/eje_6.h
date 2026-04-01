
//Librerías necesarias para el funcionamiento del programa
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

//Definición de la estructura vector_3D

typedef struct v_3D {
    float x;
    float y;
    float z;

    float (*norma)(struct v_3D v);
    struct v_3D (*crear_vector)(float x, float y, float z);
    void (*imprimir_vector)(struct v_3D v);

} vector_3D;

// Declaración de las funciones

void fsuma(vector_3D *v1, vector_3D *v2, vector_3D *resultado);
void fresta(vector_3D *v1, vector_3D *v2, vector_3D *resultado);
float fproducto_interno(vector_3D *v1, vector_3D *v2);
void fproducto_externo(vector_3D *v1, vector_3D *v2, vector_3D *resultado);
float fnorma(vector_3D v);  
void fimprimir_vector(vector_3D v);
vector_3D fcrear_vector(float x, float y, float z);