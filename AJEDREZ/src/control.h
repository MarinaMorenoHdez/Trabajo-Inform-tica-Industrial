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

private:
private:
	Vector2D casillaSeleccionada = { -1, -1 };  // Inicialmente inválida
	bool piezaSeleccionada = false;
	Vector2D seleccion;
	void gestionarMovimientoJugador(Vector2D coord);


public:
	void tecla(unsigned char key);
	void dibuja();
	void MouseButton(int tipo_oponente, int x, int y, int boton, bool abajo, bool TeclaSp, bool TeclaCtr);
	int Get_Estado() { return estado; }
	Vector2D mouseToBoardCoords(int x, int y);
	
	Vector2D getCasillaSeleccionada() const { return casillaSeleccionada; }
	bool haySeleccion() const { return piezaSeleccionada; }


	control();



};
