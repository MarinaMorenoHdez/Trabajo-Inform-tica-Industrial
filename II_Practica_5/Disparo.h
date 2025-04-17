#pragma once
#include"vector2D.h"

class disparo
{
private:
	float radio;
	vector2D posicion;

public:
	disparo();
	virtual~disparo();
	void setRadio(float r);
	void setPos(float ix, float iy);
	vector2D velocidad;
	vector2D aceleracion;
	void dibuja();
	void mueve(float t);
};

