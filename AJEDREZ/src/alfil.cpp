#include "alfil.h"
#include "freeglut.h"
#include <ETSIDI.h>
#include <string>

vector<Vector2D> Alfil::movimientosPosibles(Pieza* tablero[10][8], Tablero* /*refTablero*/) {
    vector<Vector2D> movs;

    movimientosDiagonal(tablero, posicion, movs);
    
    return movs;
}
void Alfil::dibuja() {
    std::string ruta = (color == 'B') ? "imagenes/alfilrojo.png" : "imagenes/alfilazules.png";
    ETSIDI::Sprite sprite(ruta.c_str());
    sprite.setSize(4, 4);  // Ajusta si lo ves muy grande o peque�o

    float x = posicion.x * 4.0f;  // tama�o casilla
    float y = posicion.y * 4.0f;

    glPushMatrix();
    glTranslatef(x, y, 0.1f);  // Altura Z levemente sobre el tablero
    sprite.draw();
    glPopMatrix();
}

