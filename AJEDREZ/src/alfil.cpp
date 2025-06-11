#include "alfil.h"

vector<Vector2D> Alfil::movimientosPosibles(Pieza* tablero[10][8]) {
    vector<Vector2D> movs;

    movimientosDiagonal(tablero, posicion, movs);
    
    return movs;
}
