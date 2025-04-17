#pragma once
#include "vector2D.h"

class hombre
{
private:
	float altura;
	vector2D velocidad;
	vector2D posicion;

public:
	vector2D aceleracion; // publico para Interaccion pueda acceder a el
	hombre();
	virtual ~hombre();
	void setAltura(float h);
	void setVel(float vx, float vy);
	void setPosicion(float ix, float iy);
	void dibuja();
	void mueve(float t);
	friend class Interaccion;
};
