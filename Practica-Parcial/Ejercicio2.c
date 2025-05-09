#include <stdio.h>

#define MAGO 40
#define MANA 0.15

int calcularDano(int manaEnemigo) {
    if (manaEnemigo < 120 || manaEnemigo > 300) {
        printf("Mana fuera de rango. Intente nuevamente.\n");
        return 1;
    }
    int danoTotal = MAGO + (int)(manaEnemigo * MANA);
    printf("Daño total infligido: %d\n", danoTotal);
    if (danoTotal > 80)
        printf("Critical HIT\n");
    else
        printf("Normal HIT\n");
    return 0;
}

int main() {
    int manaEnemigo;
    printf("Ingrese el mana total del enemigo (entre 120 y 300): ");
    scanf("%d", &manaEnemigo);
    calcularDano(manaEnemigo);
    return 0;
}