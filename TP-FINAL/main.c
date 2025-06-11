#include "auto.h"
#include "menu.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    if (archivoExiste(ARCHIVO_AUTOS)) {
        cargarAutosDesdeArchivo();
    } else {
        inicializarAutosPorDefecto();
        guardarAutosEnArchivo();
    }
    menuPrincipal();
    return 0;
}

