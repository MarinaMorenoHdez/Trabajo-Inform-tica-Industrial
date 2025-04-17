#pragma once
#include <math.h>
class vector2D
{
public:
	//atributos
	float x;
	float y;

	//metodos
	vector2D(float xv = 0.0f, float yv = 0.0f);
	virtual ~vector2D();
	float modulo(); 
	float argumento(); 
	vector2D unitario(); 
	vector2D operator - (vector2D v); 
	vector2D operator + (vector2D v); 
	float operator *(vector2D v); 
	vector2D operator *(float); 
};