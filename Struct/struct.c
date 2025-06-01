#include <stdio.h>
#include <string.h>

#define MAX_ESTUDIANTES 100 // Máximo número de estudiantes

struct Alumno {
    char nombre[50];
    int edad;
    float nota;
};

struct Alumno estudiantes[MAX_ESTUDIANTES]; // Arreglo para almacenar estudiantes
int totalEstudiantes = 0; // Contador para ver cuántos alumnos se han agregado

void agregarAlumno() {
    if (totalEstudiantes >= MAX_ESTUDIANTES) {
        printf("No se pueden agregar más estudiantes. Límite alcanzado.\n");
        return;
    }
    printf("Nombre: ");
    scanf("%s", estudiantes[totalEstudiantes].nombre);
    printf("Edad: ");
    scanf("%d", &estudiantes[totalEstudiantes].edad);
    printf("Nota: ");
    scanf("%f", &estudiantes[totalEstudiantes].nota);
    totalEstudiantes++;
    printf("Alumno agregado.\n");
}

void mostrarEstudiantes() {
    if (totalEstudiantes == 0) {
        printf("No hay estudiantes registrados.\n");
        return;
    }
    for (int i = 0; i < totalEstudiantes; i++) {
        printf("Estudiante %d:\n", i + 1);
        printf("  Nombre: %s\n", estudiantes[i].nombre);
        printf("  Edad: %d\n", estudiantes[i].edad);
        printf("  Nota: %.2f\n", estudiantes[i].nota);
    }
}

void calcularPromedioNotas() {
    if (totalEstudiantes == 0) {
        printf("No hay estudiantes registrados.\n");
        return;
    }
    float suma = 0;
    for (int i = 0; i < totalEstudiantes; i++) {
        suma += estudiantes[i].nota;
    }
    printf("Promedio general: %.2f\n", suma / totalEstudiantes);
}

int main() {
    int opcion;
    do {
        printf("\n1. Agregar estudiante\n2. Mostrar estudiantes\n3. Calcular promedio\n4. Salir\nOpción: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                agregarAlumno();
                break;
            case 2:
                mostrarEstudiantes();
                break;
            case 3:
                calcularPromedioNotas();
                break;
            case 4:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción inválida. Intente de nuevo.\n");
        }
    } while (opcion != 4);
    return 0;
    
}