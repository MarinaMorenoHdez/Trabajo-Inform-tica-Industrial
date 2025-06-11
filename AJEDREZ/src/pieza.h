#pragma once
#include "vector2D.h"

class Pieza
{
private:
    char tipo;            // Pieza B o N
    Vector2D posicion;   // Posición en el tablero

public:
    Pieza(int x, int y, int tipo); 

	void Set_Posicion(int x, int y); //cambia la posicion de la pieza
    Vector2D Get_Posicion() const; //posicion de la pieza actual

    int GetTipo() const; //tipo de pieza
    void CambiarTipo(int nuevoTipo); // cambia el tipo de pieza 
};
