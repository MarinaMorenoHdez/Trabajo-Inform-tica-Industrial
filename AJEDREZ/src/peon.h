#pragma once
#include "pieza.h"
#include "vector2D.h"
#include <vector>

using namespace std;
class Peon : public Pieza
{
public:
	Peon(int x, int y, char c) : Pieza(x, y, c,tipo::PEON) {} // Constructor 
	vector <Vector2D> getMovimientos(Peon& p);
	void mover(int x, int y);
};
