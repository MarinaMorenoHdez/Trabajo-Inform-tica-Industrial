#pragma once
#include "tablero.h"

class Mundo {
    Tablero tablero;
    int tipo_oponente = 0;

public:
    int get_oponente() const { return tipo_oponente; }
    Tablero& getTablero() { return tablero; } // Getter para acceder a tablero desde control

    void inicializa(int tipo_juego, const int& tipo_oponente);
    void dibuja();
    void MouseButton(int tipo_oponente, int x, int y, int boton, bool abajo, bool TeclaSp, bool TeclaCtr);
};
