#include "eje_6.h"

float fnorma(vector_3D v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

void fsuma(vector_3D *v1, vector_3D *v2, vector_3D *resultado) {
    resultado->x = v1->x + v2->x;
    resultado->y = v1->y + v2->y;
    resultado->z = v1->z + v2->z;
}

void fresta(vector_3D *v1, vector_3D *v2, vector_3D *resultado) {
    resultado->x = (v1->x - v2->x);
    resultado->y = (v1->y - v2->y);
    resultado->z = (v1->z - v2->z);
}

float fproducto_interno(vector_3D *v1, vector_3D *v2) {
    return (v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z);
}

void fproducto_externo(vector_3D *v1, vector_3D *v2, vector_3D *resultado) {
    resultado->x = (v1->y * v2->z - v1->z * v2->y);
    resultado->y = (v1->z * v2->x - v1->x * v2->z);
    resultado->z = (v1->x * v2->y - v1->y * v2->x);
}

void fimprimir_vector(vector_3D v) {
    printf("%.2f\t%.2f\t%.2f\n", v.x, v.y, v.z);
}

vector_3D fcrear_vector(float x, float y, float z) {
    vector_3D v;
    v.x = x;
    v.y = y;
    v.z = z;

    // Se apuntan los punteros a función dentro del struct a las funciones correspondientes
    v.norma = fnorma;
    v.imprimir_vector = fimprimir_vector;

    return v;
}



