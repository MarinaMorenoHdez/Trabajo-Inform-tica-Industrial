#include "esfera.h"
#include "freeglut.h"

esfera::esfera() // constructor
{
	rojo = ver = azul = 255; //blanco
	radio = 1.0f;
	aceleracion.y = -9.8f;
}

esfera::~esfera() // destructor
{
}

void esfera::setColor(Byte r, Byte v, Byte a)
{
	rojo = r;
	ver = v;
	azul = a;
}

void esfera::setRadio(float r)
{
	if (r > 0)
		radio = r;
}

void esfera::setPosicion(float ix, float iy)
{
	posicion.x = ix;
	posicion.y = iy;
}

void esfera::setVel(float vx, float vy)
{
	velocidad.x = vx;
	velocidad.y = vy;
}

void esfera::dibuja()
{
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3ub(rojo, ver, azul);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 0);
}

void esfera::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
}
