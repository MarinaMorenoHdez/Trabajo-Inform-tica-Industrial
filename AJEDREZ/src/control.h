#include <iostream>
#include "freeglut.h"
#include <ETSIDI.h>
#include "tablero.h"
#include "mundo.h"

enum
{
	JUEGO = 0, INICIO, START,
	V1x1MENU, V1x1_INSTR,
	VxMMENU, VxM_INSTR,
	RATON, JUEGO_1VS1
};

class control {

	int estado = 1;
	Mundo mundo;

public:
	void tecla(unsigned char key);
	void dibuja();
	void MouseButton(int tipo_oponente, int x, int y, int boton, bool abajo, bool TeclaSp, bool TeclaCtr);
	int Get_Estado() { return estado; }
	Vector2D mouseToBoardCoords(int x, int y);
};

