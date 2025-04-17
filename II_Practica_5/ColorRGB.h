#pragma once
#include "freeglut.h"

typedef unsigned char Byte;

struct ColorRGB
{
	ColorRGB(Byte red = 255, Byte green = 255, Byte blue = 255) 
	{
		set(red, green, blue);
	}; // constructor con valores por defecto

	
	void set(Byte red = 255, Byte green = 255, Byte blue = 255)
	{
		r = red;g = green;b = blue;
	}; // Set valores RGB

	void ponColor() 
	{
		glColor3ub(r, g, b);
	}; // Establece el color en OpenGL

	Byte r, g, b; // componentes RGB
};
