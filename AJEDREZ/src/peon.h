#pragma once
#include "pieza.h"
#include "vector2D.h"
#include <vector>

using namespace std;
class Peon : public Pieza
{
public:
	Peon(int x, int y, char c) : Pieza(x, y, c, tipo::PEON) {} // Constructor 
	std::vector<Vector2D> movimientosPosibles(Pieza* tablero[10][8]);
	void mueve(Vector2D p) override;
};
