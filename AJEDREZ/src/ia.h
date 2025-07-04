#pragma once
#include "tablero.h"
#include "movimiento.h"

class IA {
public:
    Movimiento calcularMejorMovimiento(Tablero& tablero, char color);
private:
    int evaluarTablero(const Tablero& tablero, char color);
    int minimax(Tablero& tablero, int profundidad, int alpha, int beta, bool maximizando, char color);

};
