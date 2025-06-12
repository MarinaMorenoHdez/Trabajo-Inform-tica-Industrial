#include "rey.h"
#include "freeglut.h"
#include <ETSIDI.h>
#include <string>


std::vector<Vector2D> Rey::movimientosPosibles(Pieza* tablero[10][8])
{
    std::vector<Vector2D> movs;
    int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    for (int i = 0; i < 8; ++i) {
        int x = posicion.x + dx[i];
        int y = posicion.y + dy[i];
        if (x >= 0 && x < 10 && y >= 0 && y < 8) {
            movs.push_back(Vector2D(x, y));
        }
    }
    return movs;
}
void Rey::dibuja() {
    std::string ruta = (color == 'B') ? "imagenes/reyrojo.png" : "imagenes/reyazules.png";
    ETSIDI::Sprite sprite(ruta.c_str());
    sprite.setSize(4, 4);  

    float x = posicion.x * 4.0f;  
    float y = posicion.y * 4.0f;

    glPushMatrix();
    glTranslatef(x, y, 0.1f);  
    sprite.draw();
    glPopMatrix();
}
