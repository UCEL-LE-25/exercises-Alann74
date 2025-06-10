#include <stdio.h>

struct Alumno {
    char nombre[20];
    float notas[3];
    float promedio;
};

void calcularPromedios(struct Alumno alumnos[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        float suma = 0;
        for (int j = 0; j < 3; j++) {
            suma += alumnos[i].notas[j];
        }
        alumnos[i].promedio = suma / 3;
    }
}

int main() {
    struct Alumno alumnos[5];
    for (int i = 0; i < 5; i++) {
        printf("\nAlumno %d\n", i + 1);
        printf("Nombre: ");
        scanf("%s", alumnos[i].nombre);

        for (int j = 0; j < 3; j++) {
            printf("Nota %d: ", j + 1);
            scanf("%f", &alumnos[i].notas[j]);
        }
    }
    calcularPromedios(alumnos, 5);
    printf("\n--- Promedios de los alumnos ---\n");
    for (int i = 0; i < 5; i++) {
        printf("Alumno: %s - Promedio: %.2f\n", alumnos[i].nombre, alumnos[i].promedio);
    }

    return 0;
}

/*
struct Alumno {
    char nombre[20];
    float notas[3];
    float promedio;
};

void calcularPromedios(struct Alumno alumnos[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        float suma = 0;
        for (int j = 0; j < 3; j++) {
            suma += alumnos[i].notas[j];
        }
        alumnos[i].promedio = suma / 3;
    }
}

int main(){
    struct Alumno alumnos[5];
    calcularPromedios(alumnos, 5);
}

DATOS YA CARGADOS
*/
