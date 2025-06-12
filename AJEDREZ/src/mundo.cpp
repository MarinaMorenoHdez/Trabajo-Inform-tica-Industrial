#include "mundo.h"
#include <iostream>
#include "freeglut.h"
#include <ETSIDI.h>
#include "tablero.h"

void Mundo::inicializa(int tipo_juego, const int& tipo_oponente) {
    this->tipo_oponente = tipo_oponente;
    // Puedes agregar lógica de inicialización aquí
}

void Mundo::dibuja() {
    tablero.dibuja();
}

void Mundo::MouseButton(int tipo_oponente, int x, int y, int boton, bool abajo, bool TeclaSp, bool TeclaCtr) {
    // Lógica del ratón en el modo JUEGO, si aplica
}

