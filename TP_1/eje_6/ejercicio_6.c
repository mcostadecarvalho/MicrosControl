#include "VECTOR_LIB.h"

int main(void) {

    // Declaro las variables
    struct Vector3D a;
    struct Vector3D b;
    struct Vector3D v; // Variable auxiliar para leer los valores de los vectores
    struct Vector3D suma; // Variable auxiliar para guardar resultados de operaciones
    struct Vector3D resta; // Variable auxiliar para guardar resultados de operaciones
    struct Vector3D producto_externo; // Variable auxiliar para guardar resultados de operaciones
    float producto_interno; // Variable auxiliar para guardar resultados de operaciones

    OperacionesVector3D op;
    // Pido que se ingresen los valores
    printf("Ingrese las componentes del vector a (x y z): ");
    scanf("%f %f %f", &v.x, &v.y, &v.z);   
    a = v;

    printf("Ingrese las componentes del vector b (x y z): ");
    scanf("%f %f %f", &v.x, &v.y, &v.z);
    b = v;

    // Asigno las funciones a la estructura de operaciones 
    op.calcular_norma               = fcalcular_norma;
    op.calcular_suma                = fcalcular_suma;
    op.calcular_resta               = fcalcular_resta;
    op.calcular_producto_interno    = fcalcular_producto_interno;
    op.calcular_producto_externo    = fcalcular_producto_externo;

    printf("a = (%.1f, %.1f, %.1f)\n", a.x, a.y, a.z);
    printf("b = (%.1f, %.1f, %.1f)\n\n", b.x, b.y, b.z);

    printf("Norma de a:        %.4f\n", op.calcular_norma(a));
    printf("Norma de b:        %.4f\n", op.calcular_norma(b));

    suma = op.calcular_suma(a, b);
    printf("Suma:              (%.1f, %.1f, %.1f)\n", suma.x, suma.y, suma.z);

    resta = op.calcular_resta(a, b);
    printf("Resta:             (%.1f, %.1f, %.1f)\n", resta.x, resta.y, resta.z);

    producto_interno = op.calcular_producto_interno(a, b);
    printf("Producto interno:   %.4f\n", producto_interno);
    producto_externo = op.calcular_producto_externo(a, b);
    printf("Producto externo:   (%.1f, %.1f, %.1f)\n", producto_externo.x, producto_externo.y, producto_externo.z);

    return 0;
}
