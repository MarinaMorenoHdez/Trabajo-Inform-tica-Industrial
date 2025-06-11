#pragma once
#include "vector2D.h"

enum class tipo { ARZOBISPO, CANCILLER, TORRE, CABALLO, REINA, REY, PEON };

class Pieza
{
private:
    char color;            // Tipo B o N
    Vector2D posicion;   // Posición en el tablero
	tipo t;              // Tipo de pieza (Arzobispo, Canciller, etc.)
	

public:
	Pieza(int x, int y, int c, tipo t) : color(c), posicion(x, y), t(t) {} // Constructor

	void Set_Posicion(int x, int y); //cambia la posicion de la pieza
    Vector2D Get_Posicion() const; //posicion de la pieza actual

    int GetTipo() const; //tipo de pieza
    void CambiarTipo(int nuevoTipo); // cambia el tipo de pieza 

	virtual mueve() = 0; 
};
