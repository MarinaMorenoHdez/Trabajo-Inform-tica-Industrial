#include "mundo.h"
#include "freeglut.h"
#include <ETSIDI.h>
#include <iostream>

// Este m�todo se llama desde control para pasarle el puntero a s� mismo
void Mundo::setControl(control* c) {
    refControl = c;
    tablero.setControl(c);  // Tambi�n se lo pasamos al tablero
}

void Mundo::inicializa(int tipo_juego, const int& tipo_oponente) {
    this->tipo_oponente = tipo_oponente;
    // L�gica adicional si hace falta
    tablero.inicializar();
}

void Mundo::dibuja() {
    tablero.dibuja();
}

void Mundo::MouseButton(int tipo_oponente, int x, int y, int boton, bool abajo, bool TeclaSp, bool TeclaCtr) {
    // Este m�todo est� vac�o si no necesitas usarlo directamente
}
