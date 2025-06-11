#include "arzobispo.h"

// Alfil y Caballo
std::vector<Vector2D> Arzobispo::movimientosPosibles(Pieza* tablero[10][8])
{
    std::vector<Vector2D> movs;
    int dxAlfil[] = { 1, 1, -1, -1 };
    int dyAlfil[] = { 1, -1, 1, -1 };

    // Movimientos de alfil (diagonales)
    for (int dir = 0; dir < 4; ++dir) {
        int x = posicion.x + dxAlfil[dir];
        int y = posicion.y + dyAlfil[dir];
        while (x >= 0 && x < 10 && y >= 0 && y < 8) {
            movs.push_back(Vector2D(x, y));
            if (tablero[x][y] != nullptr) break; // Puede comerse a sí mismo, pero no saltar
            x += dxAlfil[dir];
            y += dyAlfil[dir];
        }
    }

    // Movimientos de caballo
    int dxCaballo[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int dyCaballo[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    for (int i = 0; i < 8; ++i) {
        int x = posicion.x + dxCaballo[i];
        int y = posicion.y + dyCaballo[i];
        if (x >= 0 && x < 10 && y >= 0 && y < 8) {
            movs.push_back(Vector2D(x, y));
        }
    }

    return movs;
}

