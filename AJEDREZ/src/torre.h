#pragma once
#include "pieza.h"
#include "vector2D.h"
#include <vector>
class Torre : public Pieza
{
public:
	Torre(int x, int y, char c) : Pieza(x, y, c, tipo::TORRE) {} // Constructor 
	std::vector<Vector2D> movimientosPosibles(Pieza* tablero[10][8]) override;
	void dibuja();
};
