#pragma once
#include "pieza.h"
class Alfil : public Pieza
{
public:
	Alfil(int x, int y, char c) : Pieza(x, y, c, tipo::ALFIL) {} // Constructor 

	void mueve() override {}
};


