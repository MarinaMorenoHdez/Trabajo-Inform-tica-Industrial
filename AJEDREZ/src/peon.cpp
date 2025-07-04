#include "peon.h"
#include "freeglut.h"
#include <ETSIDI.h>
#include <string>


vector<Vector2D> Peon::movimientosPosibles(Pieza* tablero[10][8], Tablero* /*refTablero*/) {
    vector<Vector2D> movs;
    int dir = (color == 'B') ? 1 : -1;
    int x = posicion.x;
    int y = posicion.y;

    // Movimiento hacia adelante
    if (y + dir >= 0 && y + dir < 8 && tablero[x][y + dir] == nullptr)
        movs.push_back(Vector2D(x, y + dir));

    // Primer movimiento doble hacia adelante 
    int filaInicial = (color == 'B') ? 1 : 6;
    if (y == filaInicial &&
        y + dir >= 0 && y + dir < 8 && tablero[x][y + dir] == nullptr &&
        y + 2 * dir >= 0 && y + 2 * dir < 8 && tablero[x][y + 2 * dir] == nullptr)
    {
        movs.push_back(Vector2D(x, y + 2 * dir));
    }

    // Ataque/captura a la izquierda (siempre añade la diagonal)
    if (x - 1 >= 0 && y + dir >= 0 && y + dir < 8)
        movs.push_back(Vector2D(x - 1, y + dir));

    // Ataque/captura a la derecha (siempre añade la diagonal)
    if (x + 1 < 10 && y + dir >= 0 && y + dir < 8)
        movs.push_back(Vector2D(x + 1, y + dir));

    return movs;
}
void Peon::dibuja() {
    std::string ruta = (color == 'B') ? "imagenes/peonrojo.png" : "imagenes/peonazules.png";
    ETSIDI::Sprite sprite(ruta.c_str());
    sprite.setSize(4, 4);  // Ajusta si lo ves muy grande o pequeño

    float x = posicion.x * 4.0f;  // tamaño casilla
    float y = posicion.y * 4.0f;

    glPushMatrix();
    glTranslatef(x, y, 0.1f);  // Altura Z levemente sobre el tablero
    sprite.draw();
    glPopMatrix();
}


