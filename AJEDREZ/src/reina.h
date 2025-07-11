#pragma once
#include "pieza.h"
#include "vector2D.h"
#include <vector>
class Reina : public Pieza
{
public:
	Reina(int x, int y, char c) : Pieza(x, y, c, tipo::REINA) {} // Constructor 
	Pieza* clonar() const override { return new Reina(*this); }
	std::vector<Vector2D> movimientosPosibles(Pieza* tablero[10][8], Tablero* /*refTablero*/) override;
	void dibuja();
};
