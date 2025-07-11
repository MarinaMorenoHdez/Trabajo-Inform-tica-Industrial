#pragma once
#include "pieza.h"
#include "vector2D.h"
#include <vector>
class Canciller : public Pieza
{
public:
	Canciller(int x, int y, char c) : Pieza(x, y, c, tipo::CANCILLER) {} // Constructor 
	Pieza* clonar() const override { return new Canciller(*this); }
	std::vector<Vector2D> movimientosPosibles(Pieza* tablero[10][8], Tablero* /*refTablero*/)override;
	void dibuja();
};
