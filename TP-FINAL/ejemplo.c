#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILAS 3
#define COLUMNAS 3
#define USERNAME "admin"
#define PASSWORD "admin123"

void cleanScreen() {
#ifdef _WIN32
    system("cls");
#endif
}

typedef struct {
    int id;
    char marca[20];
    char modelo[20];
    int anio;
    float precio;
    int disponible; // 1: si, 0: no
} Auto;

Auto autos[FILAS][COLUMNAS] = {
    {
        {1, "Toyota", "Corolla", 2020, 20000, 1},
        {2, "Ford", "Focus", 2018, 18000, 1},
        {3, "Chevrolet", "Onix", 2019, 17000, 1}
    },
    {
        {4, "Honda", "Civic", 2021, 22000, 1},
        {5, "Volkswagen", "Golf", 2017, 16000, 1},
        {6, "Renault", "Clio", 2016, 14000, 1}
    },
    {
        {7, "Peugeot", "208", 2022, 21000, 1},
        {8, "Fiat", "Cronos", 2020, 15000, 1},
        {9, "Nissan", "Versa", 2019, 17500, 1}
    }
};

int proximoID = 10;

void listarAutos() {
    printf("======= MATRIZ DE AUTOS =======\n");
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("[%d][%d]: ", i, j);
            if (autos[i][j].disponible) {
                printf("ID: %d | %s %s | Anio: %d | Precio: $%.2f\n",
                       autos[i][j].id, autos[i][j].marca, autos[i][j].modelo,
                       autos[i][j].anio, autos[i][j].precio);
            } else {
                printf("VACIO\n");
            }
        }
    }
    printf("================================\n");
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
                scanf("%f", &autos[i][j].precio);
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
    float precioMax;
    int cantidadResultados = 0;

    // Mostrar listado antes de pedir filtros
    listarAutos();

    printf("Busqueda avanzada\n");
    printf("Marca: ");
    scanf("%s", marca);
    printf("Anio minimo: ");
    scanf("%d", &anioMin);
    printf("Precio maximo: ");
    scanf("%f", &precioMax);

    printf("\n======= RESULTADOS DE BUSQUEDA =======\n");
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (autos[i][j].disponible &&
                strcmp(autos[i][j].marca, marca) == 0 &&
                autos[i][j].anio >= anioMin &&
                autos[i][j].precio <= precioMax) {

                cantidadResultados++;
                printf("ID: %d | %s %s | Anio: %d | Precio: $%.2f\n",
                       autos[i][j].id, autos[i][j].marca, autos[i][j].modelo,
                       autos[i][j].anio, autos[i][j].precio);
            }
        }
    }

    if (cantidadResultados == 0) {
        printf("No se encontraron autos con esos criterios.\n");
    }
    printf("=======================================\n");
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
        printf("======= MENU PRINCIPAL =======\n");
        printf("1. Busqueda avanzada\n");
        printf("2. Login administrador\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: busquedaAvanzada(); break;
            case 2: menuAdmin(); break;
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