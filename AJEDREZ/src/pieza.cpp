#include "pieza.h"
char Pieza::getColor() const {
    return color;
}
void Pieza::movimientosHorVer(Pieza* tablero[10][8], const Vector2D& posicion, vector<Vector2D>& movs) {
    // Movimientos de torre (horizontal y vertical)
    int dxTorre[] = { 1, -1, 0, 0 };
    int dyTorre[] = { 0, 0, 1, -1 };
    for (int dir = 0; dir < 4; ++dir) {
        int x = posicion.x + dxTorre[dir];
        int y = posicion.y + dyTorre[dir];
        while (x >= 0 && x < 10 && y >= 0 && y < 8) {
            movs.push_back(Vector2D(x, y));
            if (tablero[x][y] != nullptr) break; // Puede comerse a sí mismo, pero no saltar
            x += dxTorre[dir];
            y += dyTorre[dir];
        }
    }
}

void Pieza::movimientosCaballo(Pieza* tablero[10][8], const Vector2D& posicion, vector<Vector2D>& movs) {
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
}

void Pieza::movimientosDiagonal(Pieza* tablero[10][8], const Vector2D& posicion, vector<Vector2D>& movs) {
    int dxAlfil[] = { 1, 1, -1, -1 };
    int dyAlfil[] = { 1, -1, 1, -1 };
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
}

void Pieza::borrar(Pieza*& ptr) {
    if (ptr != nullptr) {
        delete ptr;
        ptr = nullptr;
    }
}
