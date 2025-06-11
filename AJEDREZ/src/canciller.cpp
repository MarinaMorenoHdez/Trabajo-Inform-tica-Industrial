#include "canciller.h"

// Torre y Caballo
std::vector<Vector2D> Canciller::movimientosPosibles(Pieza* tablero[10][8])
{
    std::vector<Vector2D> movs;

    movimientosHorVer(tablero, posicion, movs);
	movimientosCaballo(tablero, posicion, movs);

    return movs;
}
