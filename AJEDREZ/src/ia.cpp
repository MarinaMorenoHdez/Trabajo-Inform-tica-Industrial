#include "ia.h"
#include "tablero.h"
#include "pieza.h"
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

// Evaluación simple: suma el valor de tus piezas y resta el de las rivales
int IA::evaluarTablero(const Tablero& tablero, char color) {
    int valor = 0;
    for (Pieza* pieza : tablero.getPiezas()) {
        int v = valorPieza(pieza->getTipo());
        if (pieza->getColor() == color)
            valor += v;
        else
            valor -= v;
    }
    return valor;
}

// Minimax con poda alfa-beta
int IA::minimax(Tablero& tablero, int profundidad, int alpha, int beta, bool maximizando, char color) {
    if (profundidad == 0 || tablero.isPartidaFinalizada()) {
        return evaluarTablero(tablero, color);
    }

    char turno = maximizando ? color : (color == 'B' ? 'N' : 'B');
    std::vector<Movimiento> movimientos = tablero.generarTodosMovimientos(turno);

    if (movimientos.empty()) {
        // Si no hay movimientos, es mate o ahogado
        if (tablero.JaqueMate(turno))
            return (turno == color) ? -100000 : 100000;
        else
            return 0; // Tablas
    }
   
    if (maximizando) {
        int maxEval = -100000;
        for (const auto& mov : movimientos) {
            Tablero copia = tablero; 
			copia.moverPieza(mov.origen, mov.destino, false); // No reproducir sonido en la IA
            int eval = minimax(copia, profundidad - 1, alpha, beta, false, color);
            maxEval = std::max(maxEval, eval);
            alpha = std::max(alpha, eval);
            if (beta <= alpha)
                break;
        }
        return maxEval;
    }
    else {
        int minEval = 100000;
        for (const auto& mov : movimientos) {
            Tablero copia = tablero;
			copia.moverPieza(mov.origen, mov.destino, false); // No reproducir sonido en la IA
            int eval = minimax(copia, profundidad - 1, alpha, beta, true, color);
            minEval = std::min(minEval, eval);
            beta = std::min(beta, eval);
            if (beta <= alpha)
                break;
        }
        return minEval;
    }
    

}

// Elige el mejor movimiento para el color dado

Movimiento IA::calcularMejorMovimiento(Tablero& tablero, char color) {
    std::vector<Movimiento> movimientos = tablero.generarTodosMovimientos(color);
    Movimiento mejor({ -1, -1 }, { -1, -1 });
    int mejorValor = -100000;

    for (const auto& mov : movimientos) {
        Tablero copia = tablero;
        copia.moverPieza(mov.origen, mov.destino, false);
        int valor = minimax(copia, 2, -100000, 100000, false, color); // Profundidad 2
        if (valor > mejorValor) {
            mejorValor = valor;
            mejor = mov;
        }
    }
    std::cout << "[DEBUG] Destino " << mejor.destino.x <<", "<< mejor.destino.y << ")\n";
    std::cout << "[DEBUG] Origen " << mejor.origen.x << ", " << mejor.origen.y << ")\n";
    return mejor;
}
