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


class Tablero
{
private:
	Pieza* tablero[10][8];
	std::vector<Pieza*> piezas; // lista de piezas del juego
	void cambiarTurno();

public:
	Tablero(); // Constructor
	~Tablero(); // Destructor

	bool moverPieza(Vector2D origen, Vector2D destino);

	void inicializar();

};

