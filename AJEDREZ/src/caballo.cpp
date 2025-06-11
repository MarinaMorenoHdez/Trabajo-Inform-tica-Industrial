#include "caballo.h"


std::vector<Vector2D> Caballo::movimientosPosibles(Pieza* tablero[10][8])
{
    std::vector<Vector2D> movs;
    
	movimientosCaballo(tablero, posicion, movs);

    return movs;
}


