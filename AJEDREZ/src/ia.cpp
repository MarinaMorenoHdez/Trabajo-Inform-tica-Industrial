#include "ia.h"

Movimiento IA::calcularMejorMovimiento(Tablero& tablero, char color) {
    std::vector<Movimiento> movs = tablero.generarTodosMovimientos(false);

    // Filtrar por el color actual
    std::vector<Movimiento> propios;
    for (auto& m : movs) {
        if (tablero.getPiezaEn(m.origen)->getColor() == color) {
            propios.push_back(m);
        }
    }

    // Estrategia muy básica: elegir el primer movimiento que no deje en jaque
    for (auto& m : propios) {
        Pieza* origen = tablero.getPiezaEn(m.origen);
        Pieza* destinoPieza = tablero.getPiezaEn(m.destino);

        tablero.getPiezaEn(m.origen)->mueve(m.destino);
        tablero.setPiezaEn(m.destino, origen);
        tablero.setPiezaEn(m.origen, nullptr);

        bool enJaque = tablero.Jaque(color);

        tablero.setPiezaEn(m.origen, origen);
        tablero.setPiezaEn(m.destino, destinoPieza);
        origen->mueve(m.origen);

        if (!enJaque) return m;
    }

    // Si no hay movimiento seguro, devolver el primero
    if (!propios.empty()) return propios[0];

    return Movimiento({ -1, -1 }, { -1, -1 }); // No hay movimiento legal
}

