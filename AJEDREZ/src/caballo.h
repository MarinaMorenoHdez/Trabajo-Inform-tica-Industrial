#pragma once
#include "pieza.h"
#include "vector2D.h"
#include <vector>
using std::vector;
class Caballo : public Pieza
{
public:
	Caballo(int x, int y, char c) : Pieza(x, y, c, tipo::CABALLO) {} // Constructor 
	Pieza* clonar() const override { return new Caballo(*this); }
	std::vector<Vector2D> movimientosPosibles(Pieza* tablero[10][8], Tablero* /*refTablero*/)override;
	void dibuja();
};
