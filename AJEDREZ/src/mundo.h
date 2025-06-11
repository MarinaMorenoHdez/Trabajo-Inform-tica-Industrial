#pragma once
#include "tablero.h"

using namespace std;

enum { BOTON_RATON_IZQ, BOTON_RATON_DRCH };

class Mundo
{
	Tablero tablero;

public:

	void inicializa(int tipo_juego, const int& tipo_oponente);
	void dibuja();


	void MouseButton(int tipo_oponente, int x, int y, int boton, bool abajo, bool TeclaSp, bool TeclaCtr);
	
	
	
};

