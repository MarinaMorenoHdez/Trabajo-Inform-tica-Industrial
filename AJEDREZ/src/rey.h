#pragma once
#include "pieza.h"
class Rey : public Pieza
{
public:
	Rey(int x, int y, char c) : Pieza(x, y, c, tipo::REY) {} // Constructor 
	void mueve() override {}
};