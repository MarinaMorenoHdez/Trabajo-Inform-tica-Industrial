#include "torre.h"
#include "freeglut.h"
#include <ETSIDI.h>
#include <string>

std::vector<Vector2D> Torre::movimientosPosibles(Pieza* tablero[10][8],Tablero* /*refTablero*/)
{
    std::vector<Vector2D> movs;

    movimientosHorVer(tablero, posicion, movs);

    return movs;
}
void Torre::dibuja() {
    std::string ruta = (color == 'B') ? "imagenes/torrerojo.png" : "imagenes/torreazules.png";
    ETSIDI::Sprite sprite(ruta.c_str());
    sprite.setSize(4, 4);  // Ajusta si lo ves muy grande o pequeño

    float x = posicion.x * 4.0f;  // tamaño casilla
    float y = posicion.y * 4.0f;

    glPushMatrix();
    glTranslatef(x, y, 0.1f);  // Altura Z levemente sobre el tablero
    sprite.draw();
    glPopMatrix();
}
