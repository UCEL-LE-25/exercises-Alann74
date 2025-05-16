#include <stdio.h>
#include <string.h>

typedef struct
{
    char nombre[50];
    int cantidad;
    int cantidadMinima;
    float precio;
} producto;

void ingresarProdcuctos(producto deposito[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("-----------------------------------\n");
            printf("Ingrese el nombre del producto: ");
            scanf("%s", deposito[i][j].nombre);
            printf("Ingrese la cantidad del producto: ");
            scanf("%d", &deposito[i][j].cantidad);
            printf("Ingrese el precio del producto: ");
            scanf("%f", &deposito[i][j].precio);
        }
    }
}
void costoTotal(producto deposito[3][3]) {
    float total = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            total += deposito[i][j].precio * deposito[i][j].cantidad;
        }
    }
    printf("El costo total de todos los productos es: %.2f\n", total);
}

void venta(producto deposito[3][3])
{
    int i, j, cantidad, encontrado = 0;
    char nombre[50];

    printf("Ingrese el nombre del producto a vender: ");
    scanf("%s", nombre);
    printf("Ingrese la cantidad a vender: ");
    scanf("%d", &cantidad);

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (strcmp(deposito[i][j].nombre, nombre) == 0)
            {
                encontrado = 1;
                if (deposito[i][j].cantidad >= cantidad)
                {
                    deposito[i][j].cantidad -= cantidad; // disminuyo el stock
                    float costoVenta = deposito[i][j].precio * cantidad;
                    printf("Costo de la venta: %.2f\n", costoVenta);
                    printf("Stock restante: %d\n", deposito[i][j].cantidad);
                }
                else
                {
                    printf("No hay suficiente stock.\n");
                }
                break;
            }
        }
        if (encontrado) break;
    }
    if (!encontrado)
        printf("Producto no encontrado.\n");
}

int main()
{
    producto deposito[3][3];
    ingresarProdcuctos(deposito);
    costoTotal(deposito);
    venta(deposito);

    return 0;
}