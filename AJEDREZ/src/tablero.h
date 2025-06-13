#pragma once
#include <vector>
#include "pieza.h"
#include "peon.h"
#include "torre.h"
#include "vector2D.h"
#include "canciller.h"
#include "arzobispo.h"
#include "caballo.h"
#include "reina.h"
#include "rey.h"
#include "alfil.h"

class control; 

class Tablero {
private:
	Pieza* tablero[10][8];
	std::vector<Pieza*> piezas;
	char turno;
	int pInd = -1;
	int pI = -1, pJ = -1;
	control* refControl = nullptr;  

public:
	Tablero();
	~Tablero();

	bool moverPieza(Vector2D origen, Vector2D destino);
	void cambiarTurno();
	void inicializar();
	void dibuja();
	bool Jaque(char color);

	Pieza* getPiezaEn(Vector2D pos) const { return tablero[pos.x][pos.y]; }
	char getTurno() const { return turno; }

	void setControl(control* c) { refControl = c; }
};
