#pragma once
#include "pieza.h"
class Peon : public Pieza
{
public:
	Peon(int x, int y, char c) : Pieza(x, y, c,tipo::PEON) {} // Constructor 

	void mueve() override {}
};
