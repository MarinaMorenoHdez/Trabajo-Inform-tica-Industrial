#pragma once
#include "pieza.h"
#include "vector2D.h"
#include <vector>
using std::vector;

class Arzobispo : public Pieza
{
public:
	Arzobispo(int x, int y, char c) : Pieza(x, y, c, tipo::ARZOBISPO) {} // Constructor 
	Pieza* clonar() const override { return new Arzobispo(*this); }

	std::vector<Vector2D> movimientosPosibles(Pieza* tablero[10][8], Tablero* /*refTablero*/) override ;
	void dibuja();
};
