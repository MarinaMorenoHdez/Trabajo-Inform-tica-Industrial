#pragma once
#include "tablero.h"

// Declaración adelantada para evitar incluir control.h
class control;

class Mundo {
private:
    Tablero tablero;
    int tipo_oponente = 0;
    control* refControl = nullptr;

public:
    int get_oponente() const { return tipo_oponente; }
    Tablero& getTablero() { return tablero; }  // Acceso al tablero
    char getTurno() const { return tablero.getTurno(); }

    void inicializa(int tipo_juego, const int& tipo_oponente);
    void dibuja();
    void MouseButton(int tipo_oponente, int x, int y, int boton, bool abajo, bool TeclaSp, bool TeclaCtr);

    void setControl(control* c);  // Para pasar el puntero a control
    void borrar() { tablero.borrar(); }
};
