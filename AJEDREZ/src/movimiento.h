#pragma once
#include "vector2D.h"

struct Movimiento {
    Vector2D origen;
    Vector2D destino;

    Movimiento(Vector2D o, Vector2D d) : origen(o), destino(d) {}
};
