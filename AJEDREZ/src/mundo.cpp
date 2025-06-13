#include "mundo.h"
#include "freeglut.h"
#include <ETSIDI.h>
#include <iostream>

// Este método se llama desde control para pasarle el puntero a sí mismo
void Mundo::setControl(control* c) {
    refControl = c;
    tablero.setControl(c);  // También se lo pasamos al tablero
}

void Mundo::inicializa(int tipo_juego, const int& tipo_oponente) {
    this->tipo_oponente = tipo_oponente;
    // Lógica adicional si hace falta
}

void Mundo::dibuja() {
    tablero.dibuja();
}

void Mundo::MouseButton(int tipo_oponente, int x, int y, int boton, bool abajo, bool TeclaSp, bool TeclaCtr) {
    // Este método está vacío si no necesitas usarlo directamente
}

