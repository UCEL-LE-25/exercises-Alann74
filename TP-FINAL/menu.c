#include <stdio.h>
#include <string.h>
#include <windows.h> 
#include "auto.h"
#include "utils.h"

#define USERNAME "admin"
#define PASSWORD "admin123"

int login() {
    char usuario[20], contrasena[20];
    int intentos = 3;

    while (intentos > 0) {
        cleanScreen();
        printf("\033[0;35mINICIAR SESION ADMINISTRADOR\n");
        printf("============================\033[0m\n");
        printf("Usuario: ");
        scanf("%s", usuario);
        printf("Contrasena: ");
        scanf("%s", contrasena);
        printf("\nVerificando credenciales...\n");
        Sleep(2000);
        for (volatile long i = 0; i < 200000000; ++i); // Espera simulada
        if (strcmp(usuario, USERNAME) == 0 && strcmp(contrasena, PASSWORD) == 0) {
            printf("\nBienvenido, administrador.\n\n");
            return 1;
        } else {
            intentos--;
            printf("Credenciales incorrectas. Intentos restantes: %d\n", intentos);
        }
    }
    printf("Acceso denegado.\n");
    return 0;
}

void menuAdmin() {
    if (!login()) return;

    int opcion;
    do {
        cleanScreen();
        printf("\033[0;36m======= MENU ADMINISTRADOR =======\n");
        printf("1. Alta de auto\n");
        printf("2. Baja de auto\n");
        printf("3. Modificar auto\n");
        printf("4. Listar autos\n");
        printf("0. Volver al menu principal\033[0m\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: altaAuto(); break;
            case 2: bajaAuto(); break;
            case 3: modificarAuto(); break;
            case 4: listarAutos(); break;
            case 0: printf("\nVolviendo al menu principal...\n"); break;
            default: printf("Opcion invalida.\n");
        }
        if (opcion != 0) {
            printf("\nPresione ENTER para continuar...");
            getchar(); getchar();
        }
    } while (opcion != 0);
}

void menuPrincipal() {
    int opcion;
    do {
        cleanScreen();
        printf("\033[0;32m======= MENU PRINCIPAL =======\n");
        printf("1. Mostrar todos los vehiculos\n");
        printf("2. Busqueda filtrada paso a paso\n");
        printf("3. Login administrador\n");
        printf("0. Salir \033[0m\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: listarAutos(); break;
            case 2: busquedaFiltrada(); break;
            case 3: menuAdmin(); break;
            case 0: printf("Saliendo del sistema...\n"); break;
            default: printf("Opcion invalida.\n");
        }
        if (opcion != 0) {
            printf("\nPresione ENTER para continuar...");
            getchar(); getchar();
        }
    } while (opcion != 0);
}