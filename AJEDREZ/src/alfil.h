#pragma once
#include "pieza.h"
#include "vector2D.h"
#include <vector>
using std::vector;
class Alfil : public Pieza
{
public:
	Alfil(int x, int y, char c) : Pieza(x, y, c, tipo::ALFIL) {} // Constructor
	Pieza* clonar() const override { return new Alfil(*this); }//clonar piezas para la IA

	std::vector<Vector2D> movimientosPosibles(Pieza* tablero[10][8], Tablero* /*refTablero*/) override ;
	void dibuja();
};

