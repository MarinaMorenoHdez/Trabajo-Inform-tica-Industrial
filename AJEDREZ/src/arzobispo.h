#pragma once
#include "pieza.h"
class Arzobispo : public Pieza
{
public:
	Arzobispo(int x, int y, char c) : Pieza(x, y, c, tipo::ARZOBISPO) {} // Constructor 
	void mueve(Vector2D p)override {};

};
