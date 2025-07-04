#pragma once
#include "pieza.h"
#include "vector2D.h"
#include <vector>
class Rey : public Pieza
{
public:
	Rey(int x, int y, char c) : Pieza(x, y, c, tipo::REY) {} // Constructor 
	Pieza* clonar() const override { return new Rey(*this); }
	std::vector<Vector2D> movimientosPosibles(Pieza* tablero[10][8], Tablero* refTablero) override;
	void dibuja();

}; 
