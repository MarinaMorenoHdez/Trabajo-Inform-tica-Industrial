#pragma once
#include "vector2D.h"
#include "ColorRGB.h"

class esfera
{
private:
	float radio;
	unsigned char rojo, ver, azul;
	vector2D posicion;
	vector2D velocidad;

public:
	esfera();
	virtual~esfera();
	void setColor(Byte r, Byte v, Byte a);
	void setRadio(float r);
	void setPosicion(float ix, float iy);
	void setVel(float vx, float vy);
	vector2D aceleracion;
	void dibuja();
	void mueve(float t);
	friend class Interaccion;
};
