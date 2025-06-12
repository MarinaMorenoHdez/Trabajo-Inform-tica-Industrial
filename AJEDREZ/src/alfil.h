#pragma once
#include "pieza.h"
#include "vector2D.h"
#include <vector>
using std::vector;
class Alfil : public Pieza
{
public:
	Alfil(int x, int y, char c) : Pieza(x, y, c, tipo::ALFIL) {} // Constructor

	std::vector<Vector2D> movimientosPosibles(Pieza* tablero[10][8]) override ;
	void dibuja();
};

