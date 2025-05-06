#include <stdio.h>
#include <string.h>


struct Alumno {
    char nombre[50];
    int edad;
    float nota;
};

struct Alumno estudiantes;
int totalEstudiantes = 0; //contador para ver cuántos alumnos se han agregado

void agregarAlumno() {
    printf("Nombre: ");
    scanf("%s", estudiantes.nombre);
    printf("Edad: ");
    scanf("%d", &estudiantes.edad);
    printf("Nota: ");
    scanf("%f", &estudiantes.nota);
    totalEstudiantes++;
    printf("Alumno agregado.\n");
}

void mostrarEstudiantes() {
    for (int i = 0; i < totalEstudiantes; i++) {
        printf("Nombre: %s\n, Edad: %d\n, Nota: %.2f\n", i + 1, estudiantes[i].nombre, estudiantes[i].edad, estudiantes[i].nota);
    }
}

void calcularPromedioNotas() {
    if (totalEstudiantes == 0) {
        printf("No hay estudiantes registrados.\n");
        return;
    }
    else{
        float suma = 0;
        for (int i = 0; i < totalEstudiantes; i++) {
            suma += estudiantes[i].nota;
        }
        printf("Promedio general: %.2f\n", suma / totalEstudiantes);
    }
   
}

int main() {
    int opcion;
    do {
        printf("\n1. Agregar estudiante\n2. Mostrar estudiantes\n3. Calcular promedio\n4. Salir\nOpción: ");
        scanf("%d", &opcion);
        if (opcion == 1) agregarAlumno();
        else if (opcion == 2) mostrarEstudiantes();
        else if (opcion == 3) calcularPromedioNotas();
        else if (opcion != 4) printf("Opción inválida.\n");
    } while (opcion != 4);
    return 0;
}