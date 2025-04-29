#include "recursos.h"
#include <stdio.h>

int main() {
    int matriz[3][3];

    recursos(matriz);
    mayor(matriz);
    menor(matriz);
    promedio(matriz);

    return 0;
}