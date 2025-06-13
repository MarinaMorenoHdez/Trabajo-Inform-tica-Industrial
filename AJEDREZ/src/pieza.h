#pragma once
#include "vector2D.h"
#include <vector>
using std::vector;

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
	char getColor() const;
	void mueve(Vector2D p) { posicion = p;}
	virtual std::vector<Vector2D> movimientosPosibles(Pieza* tablero[10][8]) = 0; 
	void movimientosHorVer(Pieza* tablero[10][8], const Vector2D& posicion, vector<Vector2D>& movs);
	void movimientosCaballo(Pieza* tablero[10][8], const Vector2D& posicion, vector<Vector2D>& movs);
	void movimientosDiagonal(Pieza* tablero[10][8], const Vector2D& posicion, vector<Vector2D>& movs);
	tipo getTipo() const { return t; }
	Vector2D getPosicion() const { return posicion; }
	void borrar(Pieza*& ptr);
};
