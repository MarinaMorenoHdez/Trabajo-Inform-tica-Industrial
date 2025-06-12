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
	char turno; // 'B' = blancas, 'N' = negras
	

public:
	Tablero(); // Constructor
	~Tablero(); // Destructor

	bool moverPieza(Vector2D origen, Vector2D destino);
	void cambiarTurno();
	void inicializar();
	void dibuja();
	bool Jaque(char color);
	void Tomar_Pieza_1VS1(Vector2D origen); 
	void Soltar_Pieza_1VS1(Vector2D destino);

};
