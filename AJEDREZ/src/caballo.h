#pragma once
#include "pieza.h"
class Caballo : public Pieza
{
public:
	Caballo(int x, int y, char c) : Pieza(x, y, c, tipo::CABALLO) {} // Constructor 
};