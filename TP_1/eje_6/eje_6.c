#include <stdio.h>
#include <math.h>
#include "eje_6.h"

float norma(vector_3D* v) {
    return sqrt((*v).x * (*v).x + (*v).y * (*v).y + (*v).z * (*v).z);
}

vector_3D suma(vector_3D* v1, vector_3D* v2) {
    vector_3D result;
    result.x = (*v1).x + (*v2).x;
    result.y = (*v1).y + (*v2).y;
    result.z = (*v1).z + (*v2).z;
    return result;
}

vector_3D resta(vector_3D* v1, vector_3D* v2) {
    vector_3D result;
    result.x = (*v1).x - (*v2).x;
    result.y = (*v1).y - (*v2).y;
    result.z = (*v1).z - (*v2).z;
    return result;
}
float producto_interno(vector_3D* v1, vector_3D* v2) {
    return (*v1).x * (*v2).x + (*v1).y * (*v2).y + (*v1).z * (*v2).z;
}

vector_3D producto_externo(vector_3D* v1, vector_3D* v2) {
    vector_3D result;
    result.x = (*v1).y * (*v2).z - (*v1).z * (*v2).y;
    result.y = (*v1).z * (*v2).x - (*v1).x * (*v2).z;
    result.z = (*v1).x * (*v2).y - (*v1).y * (*v2).x;
    return result;
}

void imprimir_vector(vector_3D* v) {
    printf("%.2f\t%.2f\t%.2f\n", (*v).x, (*v).y, (*v).z);
}

vector_3D crear_vector(float x, float y, float z) {
    vector_3D v;
    v.x = x;
    v.y = y;
    v.z = z;
    
    return v;
}



