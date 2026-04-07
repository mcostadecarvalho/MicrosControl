#include "VECTOR_LIB.h"

// Funciones 

float fcalcular_norma(Vector3D v) {
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

Vector3D fcalcular_suma(Vector3D a, Vector3D b) {
    return (Vector3D){a.x + b.x, a.y + b.y, a.z + b.z};
}

Vector3D fcalcular_resta(Vector3D a, Vector3D b) {
    return (Vector3D){a.x - b.x, a.y - b.y, a.z - b.z};
}

float fcalcular_producto_interno(Vector3D a, Vector3D b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector3D fcalcular_producto_externo(Vector3D a, Vector3D b) {
    return (Vector3D){a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}
