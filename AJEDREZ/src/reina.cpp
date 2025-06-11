#include "reina.h"

std::vector<Vector2D> Reina::movimientosPosibles(Pieza* tablero[10][8])
{
    std::vector<Vector2D> movs;

	movimientosHorVer(tablero, posicion, movs); 
	movimientosDiagonal(tablero, posicion, movs);

    return movs;
}
