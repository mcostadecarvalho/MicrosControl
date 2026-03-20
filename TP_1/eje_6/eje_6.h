
//Definición de la estructura vector_3D

typedef struct {
    float x;
    float y;
    float z;
} vector_3D;

// Declaración de las funciones

vector_3D suma(vector_3D* v1, vector_3D* v2);
vector_3D resta(vector_3D* v1, vector_3D* v2);
float producto_interno(vector_3D* v1, vector_3D* v2);
vector_3D producto_externo(vector_3D* v1, vector_3D* v2);
float norma(vector_3D* v);  
void imprimir_vector(vector_3D* v);
vector_3D crear_vector(float x, float y, float z);