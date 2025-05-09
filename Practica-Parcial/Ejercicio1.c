#include <stdio.h>
#include <stdbool.h> //agregue esta libreria para usar bool

int main() {
    int vida;
    printf("Ingrese la vida del jugador: ");
    scanf("%d", &vida); 
    float escudo;
    printf("Ingrese el escudo del jugador: ");
    scanf("%f", &escudo);
    bool tienePocion = true;

    if (vida == 100 && escudo > 0)
        printf("Jugador con vida y escudo\n");
    else if (vida == 0)
        printf("Jugador muerto\n");
    else if (vida > 0 || tienePocion)
        printf("Jugador herido pero con posibilidad de curarse\n");
    else
        printf("Estado desconocido\n");

    return 0;
}