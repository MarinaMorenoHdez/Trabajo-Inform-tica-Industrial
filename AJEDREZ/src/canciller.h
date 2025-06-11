#pragma once
#include "pieza.h"
class Canciller : public Pieza
{
public:
	Canciller(int x, int y, char c) : Pieza(x, y, c, tipo::CANCILLER) {} // Constructor 
	void mueve() override {}
};