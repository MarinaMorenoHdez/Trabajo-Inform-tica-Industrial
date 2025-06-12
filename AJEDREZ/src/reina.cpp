#include "reina.h"
#include "freeglut.h"
#include <ETSIDI.h>
#include <string>

std::vector<Vector2D> Reina::movimientosPosibles(Pieza* tablero[10][8])
{
    std::vector<Vector2D> movs;

	movimientosHorVer(tablero, posicion, movs); 
	movimientosDiagonal(tablero, posicion, movs);

    return movs;
}
void Reina::dibuja() {
    std::string ruta = (color == 'B') ? "imagenes/reinaroja.png" : "imagenes/reinaazules.png";
    ETSIDI::Sprite sprite(ruta.c_str());
    sprite.setSize(4, 4);  

    float x = posicion.x * 4.0f; 
    float y = posicion.y * 4.0f;

    glPushMatrix();
    glTranslatef(x, y, 0.1f); 
    sprite.draw();
    glPopMatrix();
}
