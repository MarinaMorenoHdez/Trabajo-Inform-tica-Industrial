#pragma once
#include "pieza.h"
class Torre : public Pieza
{
public:
	Torre(int x, int y, char c) : Pieza(x, y, c, tipo::TORRE) {} // Constructor 
	void mueve(Vector2D p)override {};
};