#include "auto.h"
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

Auto autos[FILAS][COLUMNAS];
int proximoID = 10;


int archivoExiste(const char *nombreArchivo) {
    struct stat buffer;
    return (stat(nombreArchivo, &buffer) == 0);
}

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

void guardarAutosEnArchivo() {
    FILE *f = fopen(ARCHIVO_AUTOS, "w");
    if (f != NULL) {
        for (int i = 0; i < FILAS; i++) {
            for (int j = 0; j < COLUMNAS; j++) {
                Auto a = autos[i][j];
                fprintf(f, "%d,%s,%s,%d,%.2f,%s,%d\n",
                        a.id, a.marca, a.modelo, a.anio, a.precio, a.descripcion, a.disponible);
            }
        }
        fclose(f);
    }
}

void guardarAutoEnArchivo(Auto *a) {
    FILE *f = fopen(ARCHIVO_AUTOS, "a");
    if (f != NULL) {
        fprintf(f, "%d,%s,%s,%d,%.2f,%s,%d\n",
                a->id, a->marca, a->modelo, a->anio, a->precio, a->descripcion, a->disponible);
        fclose(f);
    }
}

void cargarAutosDesdeArchivo() {
    FILE *f = fopen(ARCHIVO_AUTOS, "r");
    if (f != NULL) {
        for (int i = 0; i < FILAS; i++) {
            for (int j = 0; j < COLUMNAS; j++) {
                Auto *a = &autos[i][j];
                fscanf(f, "%d,%19[^,],%19[^,],%d,%f,%99[^,],%d\n",
                       &a->id, a->marca, a->modelo, &a->anio, &a->precio, a->descripcion, &a->disponible);
            }
        }
        fclose(f);
    }
}

void reservarAutoPorID(int id) {
    int reservado = 0;
    if (id == 0) return;
    for (int i = 0; i < FILAS && !reservado; i++) {
        for (int j = 0; j < COLUMNAS && !reservado; j++) {
            if (autos[i][j].disponible && autos[i][j].id == id) {
                autos[i][j].disponible = 0;
                guardarAutosEnArchivo();
                printf("Vehiculo reservado exitosamente!\n");
                reservado = 1;
            }
        }
    }
    if (!reservado) {
        printf("No se encontro un vehiculo disponible con ese ID.\n");
    }
}

void mostrarDetallesPorID() {
    int id, encontrado = 0;
    printf("\nIngrese el ID del vehiculo para ver detalles (0 para cancelar): ");
    scanf("%d", &id);
    if (id == 0) return;
    for (int i = 0; i < FILAS && !encontrado; i++) {
        for (int j = 0; j < COLUMNAS && !encontrado; j++) {
            if (autos[i][j].id == id) {
                printf("\n======= DETALLES DEL VEHICULO =======\n");
                printf("ID: %d\nMarca: %s\nModelo: %s\nAnio: %d\nPrecio: $%.2f\nDescripcion: %s\nEstado: %s\n",
                       autos[i][j].id, autos[i][j].marca, autos[i][j].modelo,
                       autos[i][j].anio, autos[i][j].precio, autos[i][j].descripcion,
                       autos[i][j].disponible ? "Disponible" : "Reservado");
                printf("=====================================\n");
                encontrado = 1;
            }
        }
    }
    if (!encontrado) {
        printf("No se encontro un vehiculo con ese ID.\n");
    } else {
        char reservar;
        if (autos[id / COLUMNAS][id % COLUMNAS].disponible) {
            printf("\nDesea reservar este vehiculo? (s/n): ");
            scanf(" %c", &reservar);
            if (reservar == 's' || reservar == 'S') {
                reservarAutoPorID(id);
            }
        }
    }
}

void listarAutos() {
    printf("======= LISTADO DE AUTOS =======\n");
    int hayDisponibles = 0;
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            Auto a = autos[i][j];
            if (a.disponible) {
                printf("ID: %d | %s %s | Anio: %d | Precio: $%.2f\n", 
                       a.id, a.marca, a.modelo, a.anio, a.precio);
                hayDisponibles = 1;
            }
        }
    }
    if (!hayDisponibles) {
        printf("No hay autos disponibles.\n");
    }
    printf("================================\n");

    char verMas;
    printf("\nDesea ver detalles de algun vehiculo? (s/n): ");
    scanf(" %c", &verMas);
    if (verMas == 's' || verMas == 'S') {
        mostrarDetallesPorID();
    }
}

void altaAuto() {
    int cargado = 0;
    for (int i = 0; i < FILAS && !cargado; i++) {
        for (int j = 0; j < COLUMNAS && !cargado; j++) {
            if (!autos[i][j].disponible) {
                autos[i][j].id = proximoID++;
                autos[i][j].disponible = 1;
                printf("Marca: ");
                scanf("%s", autos[i][j].marca);
                printf("Modelo: ");
                scanf("%s", autos[i][j].modelo);
                printf("Anio: ");
                scanf("%d", &autos[i][j].anio);
                printf("Precio: ");
                scanf("%f", &autos[i][j].precio);
                printf("Descripcion: ");
                getchar();
                fgets(autos[i][j].descripcion, sizeof(autos[i][j].descripcion), stdin);
                autos[i][j].descripcion[strcspn(autos[i][j].descripcion, "\n")] = 0;
                guardarAutoEnArchivo(&autos[i][j]);
                printf("Auto registrado exitosamente. ID: %d\n", autos[i][j].id);
                cargado = 1;
            }
        }
    }
    if (!cargado) {
        printf("Inventario lleno.\n");
    }
}

void bajaAuto() {
    listarAutos();
    int id, encontrado = 0;
    printf("Ingrese ID del auto a eliminar: ");
    scanf("%d", &id);

    for (int i = 0; i < FILAS && !encontrado; i++) {
        for (int j = 0; j < COLUMNAS && !encontrado; j++) {
            if (autos[i][j].id == id && autos[i][j].disponible) {
                autos[i][j].disponible = 0;
                guardarAutosEnArchivo();
                printf("Auto eliminado correctamente.\n");
                encontrado = 1;
            }
        }
    }
    if (!encontrado) {
        printf("No se encontro un auto con ese ID o ya esta reservado.\n");
    }
}

void modificarAuto() {
    listarAutos();
    int id, encontrado = 0;
    printf("Ingrese ID del auto a modificar: ");
    scanf("%d", &id);

    for (int i = 0; i < FILAS && !encontrado; i++) {
        for (int j = 0; j < COLUMNAS && !encontrado; j++) {
            if (autos[i][j].id == id && autos[i][j].disponible) {
                printf("Nueva marca: ");
                scanf("%s", autos[i][j].marca);
                printf("Nuevo modelo: ");
                scanf("%s", autos[i][j].modelo);
                printf("Nuevo anio: ");
                scanf("%d", &autos[i][j].anio);
                printf("Nuevo precio: ");
                scanf("%f", &autos[i][j].precio);
                printf("Nueva descripcion: ");
                getchar();
                fgets(autos[i][j].descripcion, sizeof(autos[i][j].descripcion), stdin);
                autos[i][j].descripcion[strcspn(autos[i][j].descripcion, "\n")] = 0;
                guardarAutosEnArchivo();
                printf("Auto modificado exitosamente.\n");
                encontrado = 1;
            }
        }
    }
    if (!encontrado) {
        printf("Auto no encontrado o no disponible para modificar.\n");
    }
}

void busquedaFiltrada() {
    char marca[20] = "";
    int anioMin = 0;
    float precioMax = 0;
    int cantidadResultados = 0;

    printf("Busqueda filtrada paso a paso\n");

    printf("Ingrese marca (deje vacio para no filtrar): ");
    getchar();
    fgets(marca, sizeof(marca), stdin);
    marca[strcspn(marca, "\n")] = 0;

    printf("Ingrese anio minimo (0 para no filtrar): ");
    scanf("%d", &anioMin);

    printf("Ingrese precio maximo (0 para no filtrar): ");
    scanf("%f", &precioMax);

    printf("\n======= RESULTADOS DE BUSQUEDA =======\n");
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (autos[i][j].disponible) {
                int cumple = 1;
                if (strlen(marca) > 0 && strcmp(autos[i][j].marca, marca) != 0)
                    cumple = 0;
                if (anioMin > 0 && autos[i][j].anio < anioMin)
                    cumple = 0;
                if (precioMax > 0 && autos[i][j].precio > precioMax)
                    cumple = 0;
                if (cumple) {
                    cantidadResultados++;
                    printf("ID: %d | %s %s | Anio: %d | Precio: $%.2f\n",
                           autos[i][j].id, autos[i][j].marca, autos[i][j].modelo,
                           autos[i][j].anio, autos[i][j].precio);
                }
            }
        }
    }
    if (cantidadResultados == 0) {
        printf("No se encontraron autos con esos criterios.\n");
    }
    printf("=======================================\n");
    char verMas;
    printf("\nDesea ver detalles de algun vehiculo? (s/n): ");
    scanf(" %c", &verMas);
    if (verMas == 's' || verMas == 'S') {
        mostrarDetallesPorID();
    }
}