#include "alfil.h"

vector<Vector2D> Alfil::movimientosPosibles(Pieza* tablero[10][8]) {
    vector<Vector2D> movs;
    int x = posicion.x;
    int y = posicion.y;

    // Direcciones diagonales: {dx, dy}
    int dx[] = { 1, 1, -1, -1 };
    int dy[] = { 1, -1, 1, -1 };

    for (int d = 0; d < 4; ++d) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        while (nx >= 0 && nx < 10 && ny >= 0 && ny < 8) {
            if (tablero[nx][ny] == nullptr) {
                movs.push_back(Vector2D(nx, ny));
            }
            else {
                movs.push_back(Vector2D(nx, ny)); // Puede capturar cualquier pieza
                break; // No puede saltar piezas
            }
            nx += dx[d];
            ny += dy[d];
        }
    }

    return movs;
}
