#include "includes/car_manager.h" 
#include "includes/data_manager.h" 
#include "includes/utils.h"       

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