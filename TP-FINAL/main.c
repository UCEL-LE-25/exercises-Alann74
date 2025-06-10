#include "auto.h"
#include "menu.h"

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