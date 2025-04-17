#include "disparo.h"
#include "freeglut.h"

disparo::disparo() // constructor
{
	radio = 0.25f;
	velocidad.y = 5;
}
disparo::~disparo() // destructor
{
}

void disparo::setRadio(float r)
{
	radio = r;
}

void disparo::setPos(float ix, float iy)
{
	posicion.x = ix;
	posicion.y = iy;
}

void disparo::dibuja()
{
	glColor3f(0.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glPopMatrix();

	glBegin(GL_LINES); // Linea de disparo, estela
	glVertex3f(-5.0, 0, 0); 
	glVertex3f(posicion.x, posicion.y, 0);
	glEnd();
}

void disparo::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * (t * t * 0.5f);
	velocidad = velocidad + aceleracion * t;
}
