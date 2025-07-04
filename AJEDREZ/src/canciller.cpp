#include "canciller.h"
#include "freeglut.h"
#include <ETSIDI.h>
#include <string>

// Torre y Caballo
std::vector<Vector2D> Canciller::movimientosPosibles(Pieza* tablero[10][8], Tablero* /*refTablero*/)
{
    std::vector<Vector2D> movs;

    movimientosHorVer(tablero, posicion, movs);
	movimientosCaballo(tablero, posicion, movs);

    return movs;
}
void Canciller::dibuja() {
    std::string ruta = (color == 'B') ? "imagenes/cancillerrojo.png" : "imagenes/cancillerazules.png";
    ETSIDI::Sprite sprite(ruta.c_str());
    sprite.setSize(4, 4);  // Ajusta si lo ves muy grande o pequeño

    float x = posicion.x * 4.0f;  // tamaño casilla
    float y = posicion.y * 4.0f;

    glPushMatrix();
    glTranslatef(x, y, 0.1f);  // Altura Z levemente sobre el tablero
    sprite.draw();
    glPopMatrix();
}

