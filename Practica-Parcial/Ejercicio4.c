#include <stdio.h>

#define TABLA 50
#define CLAVO 10
#define SOGA 75
#define MIN_MONEDA 100
#define MAX_MONEDA 300

typedef struct  {
    char nombre[50];
    int precio;
} Material;

Material clavo = {"Clavo", CLAVO};
Material soga = {"Soga", SOGA};
Material tabla = {"Tabla", TABLA};

void mostrarMenu() {
    printf("Bienvenido al juego de supervivencia!\n");
    printf("Materiales disponibles:\n");
    printf("1. %s - $%d\n", tabla.nombre, tabla.precio);
    printf("2. %s - $%d\n", clavo.nombre, clavo.precio);
    printf("3. %s - $%d\n", soga.nombre, soga.precio);
}

int main() {
    int oro;
    printf("Ingrese la cantidad de oro que tiene el jugador (entre %d y %d): ", MIN_MONEDA, MAX_MONEDA);
    scanf("%d", &oro);

    if (oro < MIN_MONEDA || oro > MAX_MONEDA) {
        printf("Cantidad de oro inválida. Debe estar entre %d y %d.\n", MIN_MONEDA, MAX_MONEDA);
        return 1;
    }

    mostrarMenu();

    int costoTotal = (2 * tabla.precio) + (4 * clavo.precio) + (1 * soga.precio);

    if (oro >= costoTotal) {
        oro -= costoTotal;
        printf("Compra realizada con éxito. Compraste 2 tablas, 4 clavos y 1 soga.\n");
        printf("Oro restante: %d\n", oro);
    } else if (oro >= soga.precio) {
        oro -= soga.precio;
        printf("No tienes suficiente oro para comprar todo. Solo compraste 1 soga.\n");
        printf("Oro restante: %d\n", oro);
    } else {
        printf("No tienes suficiente oro para comprar nada.\n");
        printf("Oro restante: %d\n", oro);
    }

    return 0;
}