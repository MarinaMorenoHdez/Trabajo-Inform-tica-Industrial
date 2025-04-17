#pragma once
#include "freeglut.h"
#include "vector2D.h"
#include "ColorRGB.h"
class pared
{
private: 
	unsigned char rojo, verde, azul;
	vector2D limite1;
	vector2D limite2;

public:
	pared(); //constructor
	virtual ~pared(); //destructor (virtual sirve para que se llame al destructor de la clase padre)
	void setColor(Byte r, Byte v, Byte a);
	void setPos(float x1, float y1, float x2, float y2);
	void dibuja();
	float distancia(vector2D punto, vector2D* direccion = 0);
	friend class Interaccion; // friend class Interaccion permite que la clase Interaccion pueda acceder a los atributos privados de pared
};
