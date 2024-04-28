#include <iostream>

#include "Interfaz.h"

int main() {
    // SETAMOS ALGUNAS CONFIGURACIONES
    std::srand(time(NULL));
    System::Console::CursorVisible = false;
    // DECLARAMOS E INICIALIZAMOS NUESTRO OBJETO INTERFAZ
    Interfaz* queerQuest = new Interfaz();
    // LLAMAMOS A LA FUNCION INTERFAZ
    queerQuest->interfaz();
    // BORRAMOS EL OBJETO
    delete queerQuest;
    // TERMINAMOS :)
    return 0;
}
