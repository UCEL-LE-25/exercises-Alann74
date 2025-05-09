#include <stdio.h>
#include "ejercicio2.h"

#define SECTORES 5
#define IMPRESORAS 10

struct Impresora {
    int estado;   // 1 = activa, 0 = inactiva
    int paginas;  // Páginas impresas
};

struct Impresora impresoras[SECTORES][IMPRESORAS];

void inicializarImpresoras() {
    for (int i = 0; i < SECTORES; i++) {
        for (int j = 0; j < IMPRESORAS; j++) {
            impresoras[i][j].estado = 0; 
            impresoras[i][j].paginas = 0;
        }
    }
}

void sectorMasPaginas() {
    int maxPaginas = 0, sectorMax = -1;

    for (int i = 0; i < SECTORES; i++) {
        int totalPaginas = 0;
        for (int j = 0; j < IMPRESORAS; j++) {
            totalPaginas += impresoras[i][j].paginas;
        }
        if (totalPaginas > maxPaginas) {
            maxPaginas = totalPaginas;
            sectorMax = i;
        }
    }

    if (sectorMax != -1) {
        printf("El sector con más páginas impresas es el sector %d con %d páginas.\n", sectorMax, maxPaginas);
    } else {
        printf("No hay impresoras activas.\n");
    }
}

int impresorasActivasPorSector(int sector) {
    if (sector < 0 || sector >= SECTORES) {
        printf("Sector inválido.\n");
        return 0;
    }

    int activas = 0;
    for (int i = 0; i < IMPRESORAS; i++) {
        if (impresoras[sector][i].estado == 1) {
            activas++;
        }
    }
    return activas;
}

int paginasPorSector(int sector) {
    if (sector < 0 || sector >= SECTORES) {
        printf("Sector inválido.\n");
        return 0;
    }

    int totalPaginas = 0;
    for (int i = 0; i < IMPRESORAS; i++) {
        totalPaginas += impresoras[sector][i].paginas;
    }
    return totalPaginas;
}

void modificarImpresora(int sector, int nro, int estado, int paginas) {
    if (sector < 0 || sector >= SECTORES || nro < 0 || nro >= IMPRESORAS) {
        printf("Datos inválidos.\n");
        return;
    }

    impresoras[sector][nro].estado = estado;
    impresoras[sector][nro].paginas = paginas;
    printf("Impresora modificada correctamente.\n");
}

void mostrarMenu() {
    printf("\n--- Menú ---\n");
    printf("1. Mostrar sector con más páginas impresas\n");
    printf("2. Mostrar impresoras activas por sector\n");
    printf("3. Mostrar páginas impresas por sector\n");
    printf("4. Modificar impresora\n");
    printf("5. Salir\n");
}