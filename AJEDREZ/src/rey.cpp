#include "rey.h"
#include "freeglut.h"
#include "tablero.h"
#include <ETSIDI.h>
#include <string>
using namespace std;

std::vector<Vector2D> Rey::movimientosPosibles(Pieza* tablero[10][8], Tablero* refTablero)
{
    std::vector<Vector2D> movs;
    int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    // Movimientos normales del rey
    for (int i = 0; i < 8; ++i) {
        int x = posicion.x + dx[i];
        int y = posicion.y + dy[i];
        if (x >= 0 && x < 10 && y >= 0 && y < 8) {
            movs.push_back(Vector2D(x, y));
        }
    }

    // Enroque
    if (!this->getMovida()) {
        int fila = posicion.y;

        // Enroque corto
        Pieza* torreCorta = tablero[9][fila];
        if (torreCorta && torreCorta->getTipo() == tipo::TORRE && torreCorta->getColor() == this->color && !torreCorta->getMovida()) {
            if (tablero[8][fila] == nullptr && tablero[7][fila] == nullptr) {
                if (!refTablero->casillaAmenazada(tablero, Vector2D(posicion.x, fila), color) &&
                    !refTablero->casillaAmenazada(tablero, Vector2D(posicion.x + 1, fila), color) &&
                    !refTablero->casillaAmenazada(tablero, Vector2D(posicion.x + 2, fila), color)) {
                    movs.push_back(Vector2D(posicion.x + 3, fila));
                }
            }
        }

        // Enroque largo
        Pieza* torreLarga = tablero[0][fila];
        if (torreLarga && torreLarga->getTipo() == tipo::TORRE && torreLarga->getColor() == this->color && !torreLarga->getMovida()) {
            if (tablero[1][fila] == nullptr && tablero[2][fila] == nullptr && tablero[3][fila] == nullptr) {
                if (!refTablero->casillaAmenazada(tablero, Vector2D(posicion.x, fila), color) &&
                    !refTablero->casillaAmenazada(tablero, Vector2D(posicion.x - 1, fila), color) &&
                    !refTablero->casillaAmenazada(tablero, Vector2D(posicion.x - 2, fila), color)) {
                    movs.push_back(Vector2D(posicion.x - 3, fila));
                }
            }
        }
    }

    return movs;
}
void Rey::dibuja() {
    std::string ruta = (color == 'B') ? "imagenes/reyrojo.png" : "imagenes/reyazules.png";
    ETSIDI::Sprite sprite(ruta.c_str());
    sprite.setSize(4, 4);  // Ajusta si lo ves muy grande o pequeño

    float x = posicion.x * 4.0f;  // tamaño casilla
    float y = posicion.y * 4.0f;

    glPushMatrix();
    glTranslatef(x, y, 0.1f);  // Altura Z levemente sobre el tablero
    sprite.draw();
    glPopMatrix();
}
