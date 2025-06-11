#include "peon.h"


vector <Vector2D> Peon::getMovimientos(Peon& p) {
	vector <Vector2D> movimientos;
	if (color == 'B') { // Peón blanco

		movimientos[0] = (posicion.x, posicion.y + 2);
		movimientos[1] = (posicion.x, posicion.y + 1);
		movimientos[2] = (posicion.x + 1, posicion.y + 1);
		movimientos[3] = (posicion.x - 1, posicion.y + 1);
	}
	if (color == 'N') { // Peón negro

		movimientos[0] = (posicion.x, posicion.y - 2);
		movimientos[1] = (posicion.x, posicion.y - 1);
		movimientos[2] = (posicion.x + 1, posicion.y - 1);
		movimientos[3] = (posicion.x - 1, posicion.y - 1);
	}

	return movimientos;
}

void Peon::mueve(Vector2D p) {
	posicion.x = p.x;
	posicion.y = p.y;
}