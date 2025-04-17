#include "vector2D.h"

vector2D::vector2D(float xv, float yv) // Constructor
{
	x = xv; //inicializa el componente x
	y = yv; //inicializa el componente y
}

vector2D::~vector2D() // Destructor
{
}

float vector2D::modulo() // Devuelve el módulo del vector
{
	return (float)sqrt(x * x + y * y); 
}

float vector2D::argumento() // Devuelve el argumento del vector
{
	return (float)atan2(y, x);
}

vector2D vector2D::unitario() // Devuelve el vector unitario del vector
{
	vector2D unitario(x, y);
	float mod = modulo();

	if (mod > 0.00001) // Comprobar que el módulo no es cero
	{
	unitario.x /= mod;
	unitario.y /= mod;
	}

	return unitario;
}

vector2D vector2D::operator-(vector2D v) // Resta de vectores, operador -
{
	vector2D resta;
	resta.x = x - v.x;
	resta.y = y - v.y;
	return resta;
}

vector2D vector2D::operator+(vector2D v) // Suma de vectores, operador +
{
	vector2D suma;
	suma.x = x + v.x;
	suma.y = y + v.y;
	return suma;
}

float vector2D::operator*(vector2D v) // Producto escalar, operador *
{
	float producto_escalar;
	producto_escalar = (x * v.x) + (y * v.y);
	return producto_escalar;
}

vector2D vector2D::operator*(float e) // Producto por un escalar, operador *
{
	vector2D producto_por_escalar;
	producto_por_escalar.x = x * e;
	producto_por_escalar.y = y * e;
	return producto_por_escalar;
}
