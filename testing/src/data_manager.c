#include "../includes/data_manager.h"

// Inicialización de las variables globales (se definen una vez aquí)
Auto autos[FILAS][COLUMNAS];
int proximoID = 10;

// Implementación de inicializarAutosPorDefecto
void inicializarAutosPorDefecto() {
    Auto autosPorDefecto[FILAS][COLUMNAS] = {
        {
            {1, "Toyota", "Corolla", 2020, 20000, "Nafta, 45000 km, Motor 1.8L", 1},
            {2, "Ford", "Focus", 2018, 18000, "Diesel, 60000 km, Motor 2.0L", 1},
            {3, "Chevrolet", "Onix", 2019, 17000, "GNC, 30000 km, Motor 1.4L", 1}
        },
        {
            {4, "Honda", "Civic", 2021, 22000, "Diesel, 20000 km, Motor 2.0L", 1},
            {5, "Volkswagen", "Golf", 2017, 16000, "GNC, 70000 km, Motor 1.6L", 1},
            {6, "Renault", "Clio", 2016, 14000, "Nafta, 80000 km, Motor 1.2L", 1}
        },
        {
            {7, "Peugeot", "208", 2022, 21000, "GNC, 10000 km, Motor 1.6L", 1},
            {8, "Fiat", "Cronos", 2020, 15000, "Nafta, 25000 km, Motor 1.3L", 1},
            {9, "Nissan", "Versa", 2019, 17500, "Diesel, 40000 km, Motor 1.6L", 1}
        }
    };
    memcpy(autos, autosPorDefecto, sizeof(autos));
    proximoID = 10;
}

// Implementación de guardarAutosEnArchivo
void guardarAutosEnArchivo() {
    FILE *f = fopen(ARCHIVO_AUTOS, "w");
    if (f != NULL) {
        for (int i = 0; i < FILAS; i++) {
            for (int j = 0; j < COLUMNAS; j++) {
                Auto a = autos[i][j];
                if (a.id != 0) { // Guardar solo autos que existen (no eliminados)
                    fprintf(f, "%d,%s,%s,%d,%.2f,%s,%d\n",
                            a.id, a.marca, a.modelo, a.anio, a.precio, a.descripcion, a.disponible);
                }
            }
        }
        fclose(f);
    }
}

// Implementación de guardarAutoEnArchivo
void guardarAutoEnArchivo(Auto *a) {
    FILE *f = fopen(ARCHIVO_AUTOS, "a");
    if (f != NULL) {
        fprintf(f, "%d,%s,%s,%d,%.2f,%s,%d\n",
                a->id, a->marca, a->modelo, a->anio, a->precio, a->descripcion, a->disponible);
        fclose(f);
    }
}

// Implementación de cargarAutosDesdeArchivo
void cargarAutosDesdeArchivo() {
    FILE *f = fopen(ARCHIVO_AUTOS, "r");
    int i = 0, j = 0;
    int maxID = 0;
    if (f != NULL) {
        char linea[256];
        while (fgets(linea, sizeof(linea), f) && i < FILAS) {
            if (strlen(linea) < 5) continue; // Ignorar líneas vacías o muy cortas
            Auto *a = &autos[i][j];
            int r = sscanf(linea, "%d,%19[^,],%19[^,],%d,%f,%99[^,],%d",
                &a->id, a->marca, a->modelo, &a->anio, &a->precio, a->descripcion, &a->disponible);
            if (r == 7) {
                if (a->id > maxID) maxID = a->id;
                j++;
                if (j == COLUMNAS) { j = 0; i++; }
            }
        }
        // Rellenar el resto de la matriz con autos vacíos
        for (; i < FILAS; i++) {
            for (; j < COLUMNAS; j++) {
                autos[i][j].disponible = 0;
                autos[i][j].id = 0;
                autos[i][j].marca[0] = '\0';
                autos[i][j].modelo[0] = '\0';
                autos[i][j].anio = 0;
                autos[i][j].precio = 0;
                autos[i][j].descripcion[0] = '\0';
            }
            j = 0;
        }
        fclose(f);
        proximoID = maxID + 1;
    }
}