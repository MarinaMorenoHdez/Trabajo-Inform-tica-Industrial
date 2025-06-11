#include "pieza.h"

Pieza::Pieza(int x, int y, int tipo): tipo(tipo)
{
    posicion.x = x;
    posicion.y = y;
}

void Pieza::Set_Posicion(int x, int y) {
    posicion.x = x;
    posicion.y = y;
}

Vector2D Pieza::Get_Posicion() const {
    return posicion;
}

int Pieza::GetTipo() const {
    return tipo;
}

void Pieza::CambiarTipo(int nuevoTipo) {
    tipo = nuevoTipo;
}
}