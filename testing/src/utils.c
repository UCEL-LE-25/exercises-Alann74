#include "../includes/utils.h"

// Implementación de cleanScreen
void cleanScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Implementación de archivoExiste
int archivoExiste(const char *nombreArchivo) {
    struct stat buffer;
    return (stat(nombreArchivo, &buffer) == 0);
}