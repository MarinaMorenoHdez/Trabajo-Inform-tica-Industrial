#include "alfil.h"

vector<Vector2D> Alfil::movimientosPosibles(Pieza* tablero[10][8]) {
    vector<Vector2D> movs;
    int x = posicion.x;
    int y = posicion.y;

    int dx[] = { 1, 1, -1, -1 };
    int dy[] = { 1, -1, 1, -1 };

    // Movimientos de alfil 
    for (int dir = 0; dir < 4; ++dir) {
        int x = posicion.x + dx[dir];
        int y = posicion.y + dy[dir];
        while (x >= 0 && x < 10 && y >= 0 && y < 8) {
            movs.push_back(Vector2D(x, y));
            if (tablero[x][y] != nullptr) break; // Puede comerse a sí mismo, pero no saltar
            x += dx[dir];
            y += dy[dir];
        }
    }
    return movs;
}
