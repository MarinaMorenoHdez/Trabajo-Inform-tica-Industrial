#include "peon.h"


vector<Vector2D> Peon::movimientosPosibles(Pieza* tablero[10][8]) {
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

    // Captura a la izquierda 
    if (x - 1 >= 0 && y + dir >= 0 && y + dir < 8 && tablero[x - 1][y + dir] != nullptr)
        movs.push_back(Vector2D(x - 1, y + dir));

    // Captura a la derecha 
    if (x + 1 < 10 && y + dir >= 0 && y + dir < 8 && tablero[x + 1][y + dir] != nullptr)
        movs.push_back(Vector2D(x + 1, y + dir));

    return movs;
}

void Peon::mueve(Vector2D p)
{
	posicion = p;
}
