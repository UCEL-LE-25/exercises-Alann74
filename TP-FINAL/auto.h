#ifndef AUTO_H
#define AUTO_H

#define FILAS 3
#define COLUMNAS 3
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

extern Auto autos[FILAS][COLUMNAS];
extern int proximoID;

void inicializarAutosPorDefecto();
void guardarAutosEnArchivo();
void guardarAutoEnArchivo(Auto *a);
void cargarAutosDesdeArchivo();
void reservarAutoPorID(int id);
void mostrarDetallesPorID();
void listarAutos();
void altaAuto();
void bajaAuto();
void modificarAuto();
void busquedaFiltrada();


#endif