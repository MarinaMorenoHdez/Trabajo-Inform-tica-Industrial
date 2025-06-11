#include <iostream>
#include "tablero.h"
#include "peon.h"

int main() {
    Tablero tab;
    tab.inicializar();
    tab.mostrar();

    int x1, y1, x2, y2;
    while (true) {
        std::cout << "\nIntroduce las coordenadas de la pieza a mover (x y) o -1 para salir: ";
        std::cin >> x1;
        if (x1 == -1) break;
        std::cin >> y1;
        std::cout << "Introduce las coordenadas de destino (x y): ";
        std::cin >> x2 >> y2;

        if (tab.moverPieza(Vector2D(x1, y1), Vector2D(x2, y2))) {
            std::cout << "Movimiento realizado.\n";
        }
        else {
            std::cout << "Movimiento no válido.\n";
        }
        tab.mostrar();
    }
    return 0;
}
