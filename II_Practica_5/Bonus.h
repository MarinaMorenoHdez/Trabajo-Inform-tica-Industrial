#pragma once
#include"vector2D.h"
#include <stdlib.h>
#include "freeglut.h"

class bonus
{
private:
	float lado;
	vector2D posicion;

public:
	bonus();
	virtual ~bonus();
	void setLado(float l);
	void setPos(float ix, float iy);
	vector2D velocidad;
	vector2D aceleracion;
	void dibuja();
	void mueve(float t);
};
