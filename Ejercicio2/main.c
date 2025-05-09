#include <stdio.h>
#include "ejercicio2.h"

int main() {
    int opcion, sector, nro, estado, paginas;

    inicializarImpresoras();

    do {
        mostrarMenu();
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                sectorMasPaginas();
                break;
            case 2:
                printf("Ingrese el sector (0-%d): ", SECTORES - 1);
                scanf("%d", &sector);
                printf("Impresoras activas en el sector %d: %d\n", sector, impresorasActivasPorSector(sector));
                break;
            case 3:
                printf("Ingrese el sector (0-%d): ", SECTORES - 1);
                scanf("%d", &sector);
                printf("Páginas impresas en el sector %d: %d\n", sector, paginasPorSector(sector));
                break;
            case 4:
                printf("Ingrese el sector (0-%d): ", SECTORES - 1);
                scanf("%d", &sector);
                printf("Ingrese el número de impresora (0-%d): ", IMPRESORAS - 1);
                scanf("%d", &nro);
                printf("Ingrese el estado (1 = activa, 0 = inactiva): ");
                scanf("%d", &estado);
                printf("Ingrese la cantidad de páginas impresas: ");
                scanf("%d", &paginas);
                modificarImpresora(sector, nro, estado, paginas);
                break;
            case 5:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción inválida. Intente de nuevo.\n");
        }
    } while (opcion != 5);

    return 0;
}