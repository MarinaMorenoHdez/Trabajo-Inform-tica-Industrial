#pragma once
#include "vector2D.h"
#include <vector>
using std::vector;

enum class tipo { ARZOBISPO, CANCILLER, TORRE, CABALLO, REINA, REY, PEON, ALFIL };

inline int valorPieza(tipo t) {
    switch (t) {
    case tipo::REY: return 10000;
    case tipo::REINA: return 900;
    case tipo::TORRE: return 500;
    case tipo::ALFIL: return 330;
    case tipo::CABALLO: return 320;
    case tipo::CANCILLER: return 700;
    case tipo::ARZOBISPO: return 700;
    case tipo::PEON: return 100;
    default: return 0;
    }
}
class Pieza {
protected:
    bool movida = false;
    friend class Tablero;
    char color;
    Vector2D posicion;
    tipo t;

public:
    virtual Pieza* clonar() const = 0;
    Pieza(int x, int y, int c, tipo t) : color(c), posicion(x, y), t(t) {}
    virtual ~Pieza() = 0;

    bool getMovida() const { return movida; }
    char getColor() const;
    void mueve(Vector2D p) { posicion = p; movida = true; }
    virtual std::vector<Vector2D> movimientosPosibles(Pieza* tablero[10][8], Tablero* refTablero) = 0;

    void movimientosHorVer(Pieza* tablero[10][8], const Vector2D& posicion, vector<Vector2D>& movs);
    void movimientosCaballo(Pieza* tablero[10][8], const Vector2D& posicion, vector<Vector2D>& movs);
    void movimientosDiagonal(Pieza* tablero[10][8], const Vector2D& posicion, vector<Vector2D>& movs);

    tipo getTipo() const { return t; }
    Vector2D getPosicion() const { return posicion; }
    void setPosicion(int x, int y);

    virtual void dibuja() = 0;
};
