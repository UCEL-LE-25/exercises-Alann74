#include <stdio.h>
#include <string.h>
//

typedef struct Car
{
    char brand[20];
    char model[20];
    int year;
} Car;

void mostrarMenu()
{
    printf("\n--- Menú ---\n");
    printf("1. Buscar autos\n");
    printf("2. Ingresar como administrador\n");
    printf("3. Salir\n");
}

void mostrarAdminMenu()
{
    printf("\n--- Menú Administrador ---\n");
    printf("1. Cargar auto\n");
    printf("2. Eliminar auto\n");
    printf("3. Volver\n");
}

void findCar(Car autos[3][3])
{
    char brand[20], model[20];
    int year;
    printf("Ingrese marca del auto a buscar: ");
    scanf("%s", brand);
    printf("Ingrese modelo del auto a buscar: ");
    scanf("%s", model);
    printf("Ingrese año del auto a buscar: ");
    scanf("%d", &year);

    int encontrado = 0;
    for (int i = 0; i < 3 && !encontrado; i++) {
        for (int j = 0; j < 3 && !encontrado; j++) {
            if (strcmp(autos[i][j].brand, brand) == 0 &&
                strcmp(autos[i][j].model, model) == 0 &&
                autos[i][j].year == year) {
                printf("Auto encontrado: %s %s %d\n", autos[i][j].brand, autos[i][j].model, autos[i][j].year);
                encontrado = 1;
            }
        }
    }
    if (!encontrado) {
        printf("Auto no encontrado.\n");
    }
}

void cargarAuto(Car autos[3][3])
{
    int i, j, libre = 0;
    for (i = 0; i < 3 && !libre; i++) {
        for (j = 0; j < 3 && !libre; j++) {
            if (strcmp(autos[i][j].brand, "-") == 0) {
                libre = 1;
                printf("Ingrese marca: ");
                scanf("%s", autos[i][j].brand);
                printf("Ingrese modelo: ");
                scanf("%s", autos[i][j].model);
                printf("Ingrese año: ");
                scanf("%d", &autos[i][j].year);
            }
        }
    }
    if (!libre) {
        printf("No hay espacio disponible para cargar un nuevo auto.\n");
    }
}

void eliminarAuto(Car autos[3][3])
{
    char brand[20], model[20];
    int year, encontrado = 0;
    printf("Ingrese marca del auto a eliminar: ");
    scanf("%s", brand);
    printf("Ingrese modelo del auto a eliminar: ");
    scanf("%s", model);
    printf("Ingrese año del auto a eliminar: ");
    scanf("%d", &year);

    for (int i = 0; i < 3 && !encontrado; i++) {
        for (int j = 0; j < 3 && !encontrado; j++) {
            if (strcmp(autos[i][j].brand, brand) == 0 &&
                strcmp(autos[i][j].model, model) == 0 &&
                autos[i][j].year == year) {
                strcpy(autos[i][j].brand, "-");
                strcpy(autos[i][j].model, "-");
                autos[i][j].year = 0;
                printf("Auto eliminado de la posición [%d][%d].\n", i, j);
                encontrado = 1;
            }
        }
    }
    if (!encontrado) {
        printf("Auto no encontrado para eliminar.\n");
    }
}

void validKey(Car autos[3][3])
{
    char key[20];
    printf("Ingrese la clave de administrador: ");
    scanf("%s", key);

    if (strcmp(key, "admin123") == 0)
    {
        printf("Clave correcta. Acceso concedido.\n");
        int op;
        do {
            mostrarAdminMenu();
            printf("Seleccione una opción: ");
            scanf("%d", &op);
            switch (op) {
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
        } while (op != 3);
    }
    else
    {
        printf("Clave incorrecta. Acceso denegado.\n");
    }
}

int main()
{
    Car autos[3][3] = {
        {
            {"Toyota", "Corolla", 2020},
            {"Ford", "Focus", 2018},
            {"Chevrolet", "Onix", 2019}
        },
        {
            {"Honda", "Civic", 2021},
            {"Volkswagen", "Golf", 2017},
            {"Renault", "Clio", 2016}
        },
        {
            {"Peugeot", "208", 2022},
            {"Fiat", "Cronos", 2020},
            {"Nissan", "Versa", 2019}
        }
    };

    // Inicializar espacios vacíos con "-" si quieres permitir eliminar y cargar
    // (En este ejemplo, la matriz está llena, pero si quieres probar cargar, puedes poner algunos autos con "-" y 0)

    int opcion;
    do
    {
        mostrarMenu();
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            findCar(autos);
            break;
        case 2:
            validKey(autos);
            break;
        case 3:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opción inválida. Intente de nuevo.\n");
        }
    } while (opcion != 3);

    return 0;
}