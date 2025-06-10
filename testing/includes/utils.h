#ifndef UTILS_H
#define UTILS_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h> // Para stat()

#define FILAS 3
#define COLUMNAS 3
#define USERNAME "admin"
#define PASSWORD "admin123"
#define ARCHIVO_AUTOS "autos.txt"

typedef struct {
    int id;
    char marca[20];
    char modelo[20];
    int anio;
    float precio;
    char descripcion[100];
    int disponible;
} Auto;

void cleanScreen();
int archivoExiste(const char *nombreArchivo);

#endif 