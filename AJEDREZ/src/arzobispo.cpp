#include "arzobispo.h"

// Alfil y Caballo
std::vector<Vector2D> Arzobispo::movimientosPosibles(Pieza* tablero[10][8])
{
    std::vector<Vector2D> movs;
   
	movimientosDiagonal(tablero, posicion, movs);
	movimientosCaballo(tablero, posicion, movs);

    return movs;
}
