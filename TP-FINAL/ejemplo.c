#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILAS 3
#define COLUMNAS 3
#define USERNAME "admin"
#define PASSWORD "admin123"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_BG_BLACK      "\x1b[40m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void cleanScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

typedef struct {
    int id;
    char marca[20];
    char modelo[20];
    int anio;
    int precio; 
    char descripcion[100];
    int disponible; // 1: si, 0: no
} Auto;

Auto autos[FILAS][COLUMNAS] = {
    {
        {1, "Toyota", "Corolla", 2020, 20000, "Nafta, 45.000 km, Motor 1.8L", 1},
        {2, "Ford", "Focus", 2018, 18000, "Nafta, 60.000 km, Motor 2.0L", 1},
        {3, "Chevrolet", "Onix", 2019, 17000, "GNC, 30.000 km, Motor 1.4L", 1}
    },
    {
        {4, "Honda", "Civic", 2021, 22000, "Nafta, 20.000 km, Motor 2.0L", 1},
        {5, "Volkswagen", "Golf", 2017, 16000, "GNC, 70.000 km, Motor 1.6L", 1},
        {6, "Renault", "Clio", 2016, 14000, "Nafta, 80.000 km, Motor 1.2L", 1}
    },
    {
        {7, "Peugeot", "208", 2022, 21000, "GNC, 10.000 km, Motor 1.6L", 1},
        {8, "Fiat", "Cronos", 2020, 15000, "Nafta, 25.000 km, Motor 1.3L", 1},
        {9, "Nissan", "Versa", 2019, 17500, "Diesel, 40.000 km, Motor 1.6L", 1}
    }
};

int proximoID = 10;

void reservarAutoPorID(int id) {
    int reservado = 0;
    if (id == 0) return;
    for (int i = 0; i < FILAS && !reservado; i++) {
        for (int j = 0; j < COLUMNAS && !reservado; j++) {
            if (autos[i][j].disponible && autos[i][j].id == id) {
                autos[i][j].disponible = 0;
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
            if (autos[i][j].disponible && autos[i][j].id == id) {
                printf("\n======= DETALLES DEL VEHICULO =======\n");
                printf("ID: %d\nMarca: %s\nModelo: %s\nAnio: %d\nPrecio: U$D%d\nDescripcion: %s\n",
                    autos[i][j].id, autos[i][j].marca, autos[i][j].modelo,
                    autos[i][j].anio, autos[i][j].precio, autos[i][j].descripcion);
                printf("=====================================\n");
                encontrado = 1;
            }
        }
    }
    if (!encontrado) {
        printf("No se encontro un vehiculo con ese ID.\n");
    } else {
        char reservar;
        printf("\nDesea reservar este vehiculo? (s/n): ");
        scanf(" %c", &reservar);
        if (reservar == 's' || reservar == 'S') {
            reservarAutoPorID(id);
        }
    }
}

void listarAutos() {
    cleanScreen();
    printf("======= MATRIZ DE AUTOS =======\n");
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (autos[i][j].disponible) {
                printf("ID: %d | %s %s | Anio: %d | Precio: U$D%d\n",
                       autos[i][j].id, autos[i][j].marca, autos[i][j].modelo,
                       autos[i][j].anio, autos[i][j].precio);
            } else {
                printf("Reservado\n");
            }
        }
    }
    printf("================================\n");
    char verMas;
    printf("Desea ver detalles de algun vehiculo? (s/n): ");
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
                printf("Precio(en dolares): ");
                scanf("%d", &autos[i][j].precio); 
                printf("Descripcion: ");
                getchar(); // limpiar buffer
                fgets(autos[i][j].descripcion, sizeof(autos[i][j].descripcion), stdin);
                autos[i][j].descripcion[strcspn(autos[i][j].descripcion, "\n")] = 0;
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
    int id, encontrado = 0;
    printf("Ingrese ID del auto a eliminar: ");
    scanf("%d", &id);

    for (int i = 0; i < FILAS && !encontrado; i++) {
        for (int j = 0; j < COLUMNAS && !encontrado; j++) {
            if (autos[i][j].id == id && autos[i][j].disponible) {
                autos[i][j].disponible = 0;
                printf("Auto eliminado correctamente.\n");
                encontrado = 1;
            }
        }
    }
    if (!encontrado) {
        printf("No se encontro un auto con ese ID.\n");
    }
}

void modificarAuto() {
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
                scanf("%d", &autos[i][j].precio); 
                printf("Nueva descripcion: ");
                getchar(); 
                fgets(autos[i][j].descripcion, sizeof(autos[i][j].descripcion), stdin);
                autos[i][j].descripcion[strcspn(autos[i][j].descripcion, "\n")] = 0;
                printf("Auto modificado exitosamente.\n");
                encontrado = 1;
            }
        }
    }
    if (!encontrado) {
        printf("Auto no encontrado o no disponible.\n");
    }
}

void busquedaAvanzada() {
    char marca[20];
    int anioMin;
    int precioMax; 
    int cantidadResultados = 0;
    cleanScreen();
    // Mostrar listado antes de pedir filtros
    listarAutos();
    printf("Busqueda avanzada\n");
    printf("=================\n");
    printf("Marca: ");
    scanf("%s", marca);
    printf("Anio minimo: ");
    scanf("%d", &anioMin);
    printf("Precio maximo(en dolares): ");
    scanf("%d", &precioMax); 

    printf("\n======= RESULTADOS DE BUSQUEDA =======\n");
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (autos[i][j].disponible &&
                strcmp(autos[i][j].marca, marca) == 0 &&
                autos[i][j].anio >= anioMin &&
                autos[i][j].precio <= precioMax) {

                cantidadResultados++;
                printf("ID: %d | %s %s | Anio: %d | Precio: U$D%d\n",
                       autos[i][j].id, autos[i][j].marca, autos[i][j].modelo,
                       autos[i][j].anio, autos[i][j].precio);
            }
        }
    }

    if (cantidadResultados == 0) {
        printf("No se encontraron autos con esos criterios.\n");
    }
    printf("=======================================\n");
    char verMas;
    printf("\n Desea ver detalles de algun vehiculo? (s/n): ");
    scanf(" %c", &verMas);
    if (verMas == 's' || verMas == 'S') {
        mostrarDetallesPorID();
    }
}

void busquedaFiltrada() {
    char marca[20] = "";
    int anioMin = 0;
    int precioMax = 0; 
    int cantidadResultados = 0;

    printf("Busqueda filtrada paso a paso\n");
    printf("================================\n");
    printf("Ingrese marca (deje vacio para no filtrar): ");
    getchar(); // limpiar buffer
    fgets(marca, sizeof(marca), stdin);
    marca[strcspn(marca, "\n")] = 0; // quitar salto de linea
    printf("Ingrese anio minimo (0 para no filtrar): ");
    scanf("%d", &anioMin);
    printf("Ingrese precio maximo (0 para no filtrar): ");
    scanf("%d", &precioMax); 

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
                    printf("ID: %d | %s %s | Anio: %d | Precio: U$D%d\n",
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
    printf("\n Desea ver detalles de algun vehiculo? (s/n): ");
    scanf(" %c", &verMas);
    if (verMas == 's' || verMas == 'S') {
        mostrarDetallesPorID();
    }
}

int login() {
    char usuario[20], contrasena[20];
    int intentos = 3;

    while (intentos > 0) {
        cleanScreen();
        printf("Usuario: ");
        scanf("%s", usuario);
        printf("Contrasena: ");
        scanf("%s", contrasena);

        if (strcmp(usuario, USERNAME) == 0 && strcmp(contrasena, PASSWORD) == 0) {
            printf("\nBienvenido, administrador.\n\n");
            return 1;
        } else {
            intentos--;
            printf("Credenciales incorrectas. Intentos restantes: %d\n", intentos);
        }
    }
    printf("Acceso denegado.\n");
    return 0;
}

void menuAdmin() {
    if (!login()) return;

    int opcion;
    do {
        cleanScreen();
        printf("======= MENU ADMINISTRADOR =======\n");
        printf("1. Alta de auto\n");
        printf("2. Baja de auto\n");
        printf("3. Modificar auto\n");
        printf("4. Listar autos\n");
        printf("0. Volver al menu principal\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: altaAuto(); break;
            case 2: bajaAuto(); break;
            case 3: modificarAuto(); break;
            case 4: listarAutos(); break;
            case 0: printf("Volviendo al menu principal...\n"); break;
            default: printf("Opcion invalida.\n");
        }
        if (opcion != 0) {
            printf("\nPresione ENTER para continuar...");
            getchar(); getchar();
        }
    } while (opcion != 0);
}

void menuPrincipal() {
    int opcion;
    do {
        cleanScreen();
        printf(ANSI_COLOR_GREEN ANSI_BG_BLACK);
        printf("======= MENU PRINCIPAL =======\n");
        printf("1. Mostrar todos los vehiculos\n");
        printf("2. Busqueda filtrada paso a paso\n");
        printf("3. Login administrador\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        printf(ANSI_COLOR_RESET);

        switch (opcion) {
            case 1: listarAutos(); break;
            case 2: busquedaFiltrada(); break;
            case 3: menuAdmin(); break;
            case 0: printf("Saliendo del sistema...\n"); break;
            default: printf("Opcion invalida.\n");
        }
        if (opcion != 0) {
            printf("\nPresione ENTER para continuar...");
            getchar(); getchar();
        }
    } while (opcion != 0);
}

int main() {
    menuPrincipal();
    return 0;
}