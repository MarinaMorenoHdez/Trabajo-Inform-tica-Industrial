#include "pared.h"
#include "freeglut.h"

void pared::dibuja()
{
	glBegin(GL_POLYGON);
	glColor3ub(rojo, verde, azul);
	glVertex3d(limite1.x, limite1.y, 10); // Esquina superior izquierda
	glVertex3d(limite2.x, limite2.y, 10); // Esquina superior derecha
	glVertex3d(limite2.x, limite2.y, -10); // Esquina inferior derecha
	glVertex3d(limite1.x, limite1.y, -10); // Esquina inferior izquierda
	glEnd();
	glEnable(GL_LIGHTING);
}

// Devuelve la distancia entre un punto y la pared
float pared::distancia(vector2D punto, vector2D* direccion)
{
	vector2D u = (punto - limite1); //vector desde el limite1 hasta el punto
	vector2D v = (limite2 - limite1).unitario(); //vector de la pared
	vector2D dir; //vector que contendrá la distancia
	
	float longitud = (limite1 - limite2).modulo(); //longitud de la pared
	float valor = u * v; //proyeccion del vector u sobre el vector v
	float distancia = 0; //distancia entre el punto y la pared
	
	if (valor < 0) //si el punto está por detrás del limite1
		dir = u; //la distancia es el vector u
	
	else if (valor > longitud) //si el punto está por delante del limite2
		dir = (punto - limite2); //la distancia es el vector desde el limite2 hasta el punto
	
	else //si el punto está entre los limites
		dir = u - v * valor; //la distancia es el vector u menos la proyeccion
	distancia = dir.modulo(); //modulo del vector dir
	
	if (direccion != 0) //si nos dan un vector...
		*direccion = dir.unitario(); //...lo normalizamos
	
	return distancia;
}

pared::pared() //constructor
{
	rojo = verde = azul = 255; //blanco
}

pared::~pared() //destructor 
{
}

void pared::setColor(Byte r, Byte v, Byte a)
{
	rojo = r;
	verde = v;
	azul = a;
}

void pared::setPos(float x1, float y1, float x2, float y2)
{
	limite1.x = x1;
	limite1.y = y1;
	limite2.x = x2;
	limite2.y = y2;
}