

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

// Estructura de un vector 3D

typedef struct Vector3D {
    float x;
    float y;
    float z;
    
} Vector3D;

// Estructura de operaciones con vectores

typedef struct OperacionesVector3D {
    float (*calcular_norma)                     (Vector3D v);
    Vector3D (*calcular_suma)                   (Vector3D a, Vector3D b);
    Vector3D (*calcular_resta)                  (Vector3D a, Vector3D b);
    float (*calcular_producto_interno)          (Vector3D a, Vector3D b);
    Vector3D (*calcular_producto_externo)       (Vector3D a, Vector3D b);
    
} OperacionesVector3D;


// Prototipos de Funciones

float fcalcular_norma(Vector3D v);
Vector3D fcalcular_suma(Vector3D a, Vector3D b);
Vector3D fcalcular_resta(Vector3D a, Vector3D b);
float fcalcular_producto_interno(Vector3D a, Vector3D b);
Vector3D fcalcular_producto_externo(Vector3D a, Vector3D b);
