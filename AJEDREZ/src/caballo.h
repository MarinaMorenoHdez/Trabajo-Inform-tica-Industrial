#pragma once
#include "pieza.h"
class Caballo : public Pieza
{
public:
	Caballo(int x, int y, char c) : Pieza(x, y, c, tipo::CABALLO) {} // Constructor 
	void mueve() override {
		// Implementar la lógica de movimiento del Caballo
		// El Caballo se mueve en forma de "L"
	}
};