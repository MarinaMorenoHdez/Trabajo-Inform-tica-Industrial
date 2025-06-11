#pragma once
#include "pieza.h"
class Reina : public Pieza
{
public:
	Reina(int x, int y, char c) : Pieza(x, y, c, tipo::REINA) {} // Constructor 
};
