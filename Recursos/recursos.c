#include "recursos.h"
#include <stdio.h>

void recursos(int matriz[3][3]) {
    int i, j;

    printf("Ingrese los recursos para cada regioclsn y tipo:\n");
    for (i = 0; i < 3; i++) {
        printf("Region %d:\n", i + 1);
        for (j = 0; j < 3; j++) {
            if (j == 0) {
                printf("  Agua: ");
            } else if (j == 1) {
                printf("  Comida: ");
            } else if (j == 2) {
                printf("  Medicamentos: ");
            }
            scanf("%d", &matriz[i][j]);

        }
    }
}

void mayor(int matriz[3][3]) {
    int acum_agua = 0, acum_comida = 0, acum_medicamentos = 0;

    for (int i = 0; i < 3; i++) {
        acum_agua += matriz[i][0];
        acum_comida += matriz[i][1];
        acum_medicamentos += matriz[i][2];
    }

    if (acum_agua > acum_comida && acum_agua > acum_medicamentos) {
        printf("El recurso con mayor cantidad es Agua: %d\n", acum_agua);
    } else if (acum_comida > acum_agua && acum_comida > acum_medicamentos) {
        printf("El recurso con mayor cantidad es Comida: %d\n", acum_comida);
    } else if (acum_medicamentos > acum_agua && acum_medicamentos > acum_comida) {
        printf("El recurso con mayor cantidad es Medicamentos: %d\n", acum_medicamentos);
    } else {
        printf("Hay un empate en los recursos.\n");
    }
}

void menor(int matriz[3][3]) {
    int acum_agua = 0, acum_comida = 0, acum_medicamentos = 0;

    for (int i = 0; i < 3; i++) {
        acum_agua += matriz[i][0];
        acum_comida += matriz[i][1];
        acum_medicamentos += matriz[i][2];
    }

    if (acum_agua < acum_comida && acum_agua < acum_medicamentos) {
        printf("El recurso con menor cantidad es Agua: %d\n", acum_agua);
    } else if (acum_comida < acum_agua && acum_comida < acum_medicamentos) {
        printf("El recurso con menor cantidad es Comida: %d\n", acum_comida);
    } else if (acum_medicamentos < acum_agua && acum_medicamentos < acum_comida) {
        printf("El recurso con menor cantidad es Medicamentos: %d\n", acum_medicamentos);
    } else {
        printf("Hay un empate en los recursos.\n");
    }
}

void promedio(int matriz[3][3]) {
    int acum_agua = 0, acum_comida = 0, acum_medicamentos = 0;

    for (int i = 0; i < 3; i++) {
        acum_agua += matriz[i][0];
        acum_comida += matriz[i][1];
        acum_medicamentos += matriz[i][2];
    }

    float promedio_agua = (float)acum_agua / 3;
    float promedio_comida = (float)acum_comida / 3;
    float promedio_medicamentos = (float)acum_medicamentos / 3;

    printf("Promedio de recursos por region:\n");
    printf("  Agua: %.2f\n", promedio_agua);
    printf("  Comida: %.2f\n", promedio_comida);
    printf("  Medicamentos: %.2f\n", promedio_medicamentos);
}