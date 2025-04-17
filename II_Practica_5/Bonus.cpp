#include "bonus.h"

bonus::bonus() // constructor
{
	lado = 0.5;
	aceleracion.y = -9.8;
	posicion.x = 5;
	posicion.y = 0;
}

bonus::~bonus() // destructor
{
}

void bonus::setLado(float l) 
{
	lado = l;
}

void bonus::setPos(float ix, float iy)
{
	posicion.x = ix;
	posicion.y = iy;
}

void bonus::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glRotatef(30, 1, 1, 1);
	glColor3f(rand() / (float)RAND_MAX, rand() / (float)RAND_MAX,
		rand() / (float)RAND_MAX);//color aleatorio
	glutSolidCube(lado);
	glPopMatrix();
}

void bonus::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion.x * (t * t * 0.5f);
	velocidad = velocidad + aceleracion * t;
}
