#pragma once
#include "vector2D.h"

enum class tipo { ARZOBISPO, CANCILLER, TORRE, CABALLO, REINA, REY, PEON, ALFIL };

class Pieza
{
protected:
	friend class Tablero;
    char color;            // Tipo B o N
    Vector2D posicion;   // Posición en el tablero
	tipo t;              // Tipo de pieza (Arzobispo, Canciller, etc.)
	
public:
	Pieza(int x, int y, int c, tipo t) : color(c), posicion(x, y), t(t) {} // Constructor
	virtual ~Pieza() = 0;
	virtual void mueve(Vector2D p) = 0;
};
