#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

void cleanScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int archivoExiste(const char *nombreArchivo) {
    struct stat buffer;
    return (stat(nombreArchivo, &buffer) == 0);
}