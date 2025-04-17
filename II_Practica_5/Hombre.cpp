#include "hombre.h"
#include "freeglut.h"

hombre::hombre() // constructor
{
	altura = 1.8f;
	aceleracion.y = 0;
}

hombre::~hombre() // destructor
{
}

void hombre::setAltura(float h) 
{
	altura = h;
}

void hombre::setVel(float vx, float vy)
{
	velocidad.x = vx;
	velocidad.y = vy;
}

void hombre::setPosicion(float ix, float iy)
{
	posicion.x = ix;
	posicion.y = iy;
}

void hombre::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidSphere(altura, 20, 20);
	glPopMatrix();
}

void hombre::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
}