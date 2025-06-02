#include <stdio.h>
#include <string.h>

typedef struct {
    char brand[20];
    char model[20];
    int year;
} Car;

void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void mostrarMenu() {
    printf("\n--- MENÚ PRINCIPAL ---\n");
    printf("1. Ver y buscar autos\n");
    printf("2. Ingresar como administrador\n");
    printf("3. Salir\n");
}

void mostrarMenuAdmin() {
    printf("\n--- MENÚ ADMINISTRADOR ---\n");
    printf("1. Cargar auto\n");
    printf("2. Eliminar auto\n");
    printf("3. Volver al menú principal\n");
}

void mostrarAutos(Car autos[3][3]) {
    printf("\n%-15s %-15s %-6s\n", "Marca", "Modelo", "Año");
    printf("========================================\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%-15s %-15s %-6d\n", autos[i][j].brand, autos[i][j].model, autos[i][j].year);
        }
    }
}

void buscarAuto(Car autos[3][3]) {
    char marca[20], modelo[20];
    int anio, encontrado = 0;

    printf("\nIngrese marca: ");
    scanf("%s", marca);
    printf("Ingrese modelo: ");
    scanf("%s", modelo);
    printf("Ingrese año: ");
    scanf("%d", &anio);

    for (int i = 0; i < 3 && !encontrado; i++) {
        for (int j = 0; j < 3 && !encontrado; j++) {
            if (strcmp(autos[i][j].brand, marca) == 0 &&
                strcmp(autos[i][j].model, modelo) == 0 &&
                autos[i][j].year == anio) {
                printf("\nAuto encontrado: %s %s %d\n", marca, modelo, anio);
                encontrado = 1;
            }
        }
    }

    if (!encontrado) {
        printf("\nAuto no encontrado.\n");
    }
}

void cargarAuto(Car autos[3][3]) {
    int cargado = 0;
    for (int i = 0; i < 3 && !cargado; i++) {
        for (int j = 0; j < 3 && !cargado; j++) {
            if (strcmp(autos[i][j].brand, "ELIMINADO") == 0) {
                printf("\nIngrese marca: ");
                scanf("%s", autos[i][j].brand);
                printf("Ingrese modelo: ");
                scanf("%s", autos[i][j].model);
                printf("Ingrese año: ");
                scanf("%d", &autos[i][j].year);
                cargado = 1;
                printf("Auto cargado correctamente.\n");
            }
        }
    }
    if (!cargado) {
        printf("No hay espacio disponible para cargar un auto nuevo.\n");
    }
}

void eliminarAuto(Car autos[3][3]) {
    char marca[20], modelo[20];
    int anio, eliminado = 0;

    printf("\nIngrese marca del auto a eliminar: ");
    scanf("%s", marca);
    printf("Ingrese modelo: ");
    scanf("%s", modelo);
    printf("Ingrese año: ");
    scanf("%d", &anio);

    for (int i = 0; i < 3 && !eliminado; i++) {
        for (int j = 0; j < 3 && !eliminado; j++) {
            if (strcmp(autos[i][j].brand, marca) == 0 &&
                strcmp(autos[i][j].model, modelo) == 0 &&
                autos[i][j].year == anio) {
                strcpy(autos[i][j].brand, "ELIMINADO");
                strcpy(autos[i][j].model, "ELIMINADO");
                autos[i][j].year = 0;
                eliminado = 1;
                printf("Auto eliminado correctamente.\n");
            }
        }
    }

    if (!eliminado) {
        printf("Auto no encontrado para eliminar.\n");
    }
}

// Control de acceso del administrador
void administrador(Car autos[3][3]) {
    char clave[20];
    printf("Ingrese clave de administrador: ");
    scanf("%s", clave);

    if (strcmp(clave, "admin123") == 0) {
        int opAdmin;
        do {
            limpiarPantalla();
            mostrarMenuAdmin();
            printf("Seleccione una opción: ");
            scanf("%d", &opAdmin);

            switch (opAdmin) {
                case 1:
                    cargarAuto(autos);
                    break;
                case 2:
                    eliminarAuto(autos);
                    break;
                case 3:
                    printf("Volviendo al menú principal...\n");
                    break;
                default:
                    printf("Opción inválida.\n");
            }
        } while (opAdmin != 3);
    } else {
        printf("Clave incorrecta.\n");
    }
}

// Función principal
int main() {
    Car autos[3][3] = {
        {{"Toyota", "Corolla", 2020}, {"Ford", "Focus", 2018}, {"Chevrolet", "Onix", 2019}},
        {{"Honda", "Civic", 2021}, {"Volkswagen", "Golf", 2017}, {"Renault", "Clio", 2016}},
        {{"Peugeot", "208", 2022}, {"Fiat", "Cronos", 2020}, {"Nissan", "Versa", 2019}}
    };

    int opcion;
    do {
        limpiarPantalla();
        mostrarMenu();
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        limpiarPantalla();

        switch (opcion) {
            case 1:
                mostrarAutos(autos);
                buscarAuto(autos);
                break;
            case 2:
                administrador(autos);
                break;
            case 3:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción inválida. Intente de nuevo.\n");
        }

        printf("\nPresione Enter para continuar...\n");
        getchar(); // limpia el enter anterior
        getchar(); // espera un enter del usuario

    } while (opcion != 3);

    return 0;
}
