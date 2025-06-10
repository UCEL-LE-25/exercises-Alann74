#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include "utils.h" // Necesita la estructura Auto y las definiciones de constantes

// Variable global para almacenar los autos (se maneja aquí)
extern Auto autos[FILAS][COLUMNAS];
extern int proximoID;

// Declaraciones de funciones para la gestión de datos
void inicializarAutosPorDefecto();
void guardarAutosEnArchivo();
void guardarAutoEnArchivo(Auto *a);
void cargarAutosDesdeArchivo();

#endif // DATA_MANAGER_H