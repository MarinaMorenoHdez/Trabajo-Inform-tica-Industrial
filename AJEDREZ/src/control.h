#include <iostream>
#include "freeglut.h"
#include <ETSIDI.h>
#include "tablero.h"
#include "mundo.h"
#include "ia.h"



enum
{
	JUEGO = 0, INICIO, START,
	V1x1MENU, V1x1_INSTR,
	VxMMENU, VxM_INSTR,
	RATON, JUEGO_1VS1,MENUPAUSA,INSTRUCCIONES,PEONFINALROJO, PEONFINALAZUL, GANAROJO,GANAAZUL,TABLAS
};

class control {

	int estado = 1;
	Mundo mundo;
	Tablero tablero;
	IA ia;


private:
	Vector2D casillaSeleccionada = { -1, -1 };  // Inicialmente inválida
	bool piezaSeleccionada = false;
	Vector2D seleccion;
	void gestionarMovimientoJugador(Vector2D coord);
	std::vector<Vector2D> casillasPosibles;


public:
	void tecla(unsigned char key);
	void dibuja();
	void MouseButton(int tipo_oponente, int x, int y, int boton, bool abajo, bool TeclaSp, bool TeclaCtr);
	int Get_Estado() { return estado; }
	void Set_Estado(int e) { estado = e; }
	Vector2D mouseToBoardCoords(int x, int y);
	
	Vector2D getCasillaSeleccionada() const { return casillaSeleccionada; }
	bool haySeleccion() const { return piezaSeleccionada; }
	const std::vector<Vector2D>& getCasillasPosibles() const { return casillasPosibles; }
	void limpiarSeleccion() { piezaSeleccionada = false; casillasPosibles.clear(); }

	control();



};
