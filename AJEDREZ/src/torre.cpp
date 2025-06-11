#include "torre.h"

std::vector<Vector2D> Torre::movimientosPosibles(Pieza* tablero[10][8])
{
    std::vector<Vector2D> movs;

    movimientosHorVer(tablero, posicion, movs);

    return movs;
}
