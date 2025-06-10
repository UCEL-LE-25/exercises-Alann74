#include <stdio.h>

// Definición de la estructura
struct Estudiante {
    char nombre[30];
    int edad;
    float promedio;
};

int main() {
    struct Estudiante alumno; // Declaración de una variable de tipo Estudiante
    
    printf("Ingrese el nombre del estudiante (sin espacios): ");
    scanf("%s", alumno.nombre);  

    printf("Ingrese la edad del estudiante: ");
    scanf("%d", &alumno.edad);

    printf("Ingrese el promedio del estudiante: ");
    scanf("%f", &alumno.promedio);

    printf("\n--- Datos del estudiante ---\n");
    printf("Nombre: %s\n", alumno.nombre);
    printf("Edad: %d\n", alumno.edad);
    printf("Promedio: %.2f\n", alumno.promedio);

    return 0;
}
