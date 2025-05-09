#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FLECHAS 10
#define PROBABILIDAD_IMPACTO 0.6

int main()
{
    int resultados[FLECHAS]; // Array para almacenar los resultados de las flechas
    int aciertos = 0, fallos = 0;

    srand(time(NULL));

    for (int i = 0; i < FLECHAS; i++)
    {
        if (rand() / (double)RAND_MAX < PROBABILIDAD_IMPACTO)
        {
            resultados[i] = 1; // Flecha impacta, guardo 1 en el array
            aciertos++;
        }
        else
        {
            resultados[i] = 0; // Flecha no impacta, guardo 0 en el array
            fallos++;
        }
    }

    printf("Array de resultados: ");
    for (int i = 0; i < FLECHAS; i++)
    {
        printf("%d", resultados[i]);
        if (i < FLECHAS - 1)
        {
            printf(", ");
        }
    }
    printf("\n");

    printf("Flechas acertadas: %d\n", aciertos);
    printf("Flechas falladas: %d\n", fallos);

    return 0;
}