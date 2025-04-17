#include "Mundo.h"
#include "freeglut.h"
#include <math.h>

void Mundo::rotarOjo() // rotar cámara para encontrar punto
{
	float dist = sqrt(x_ojo * x_ojo + z_ojo * z_ojo);
	float ang = atan2(z_ojo, x_ojo);
	ang += 0.05f;
	x_ojo = dist * cos(ang);
	z_ojo = dist * sin(ang);
}

void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo, // posicion del ojo
		0.0, y_ojo, 0.0, // hacia que punto mira (0,0,0)
		0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)

	//codigo de dibujo

	Esfera.dibuja();
	Esfera2.dibuja();
	Caja.dibuja();
	Hombre.dibuja();
	Disparo.dibuja();
	Plataforma.dibuja();
	Bonus.dibuja();
}

void Mundo::mueve() // mueve los objetos
{
	Hombre.mueve(0.025f);
	Esfera.mueve(0.025f);
	Esfera2.mueve(0.025f);
	Bonus.mueve(0.025f);
	Disparo.mueve(0.025f);

	Interaccion::rebote(Hombre, Caja);

	Interaccion::Rebote(Esfera, Caja);
	Interaccion::rebote(Esfera, Plataforma);

	Interaccion::Rebote(Esfera2, Caja);
	Interaccion::rebote(Esfera2, Plataforma);

	Interaccion::rebote(Esfera2, Esfera);
}

void Mundo::inicializa() // crear mundo inicial
{
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 30;
	Esfera.setColor(0, 0, 255);
	Esfera.setRadio(1.5f);
	Esfera.setPosicion(2, 4);
	Esfera.setVel(5, 15);
	Esfera2.setRadio(2);
	Esfera2.setPosicion(-2, 4);
	Esfera2.setVel(-5, 15);
	Bonus.setPos(5.0f, 5.0f);
	Disparo.setPos(-5.0f, 0.0f);
	Plataforma.setPos(-5.0f, 9.0f, 5.0f, 9.0f);
	Hombre.setPosicion(0, 0);
	Hombre.setVel(5, 0);
	Hombre.setAltura(1.8f);
}

void Mundo::teclaEspecial(unsigned char key) // gestion de los cursores
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		Hombre.setVel(-5.0f, 0.0f);
		break;

	case GLUT_KEY_RIGHT:
		Hombre.setVel(5.0f, 0.0f);
		break;
	
	}
}
void Mundo::tecla(unsigned char key) // Otras teclas 
{
}
