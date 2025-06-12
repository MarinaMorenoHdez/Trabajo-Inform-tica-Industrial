#include "tablero.h"
using namespace std;

Tablero::Tablero() {
	// Inicializar el tablero con nullptr
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 8; ++j) {
			tablero[i][j] = nullptr;
		}
	}
	turno = 'B';
	inicializar(); // Llamar a la función para inicializar las piezas
}

bool Tablero::moverPieza(Vector2D origen, Vector2D destino) {

	Pieza* pieza = tablero[origen.x][origen.y];
	// No hay pieza en la posición de origen
	if (!pieza) return false; 
	//comprobar turno 
	if (pieza->getColor() != turno) return false;
	// Limites tablero
	if (destino.x < 0 || destino.x >= 10 || destino.y < 0 || destino.y >= 8)
		return false;

	// Movimientos posibles de cada pieza
	bool valido = false;
	std::vector<Vector2D> movs = pieza->movimientosPosibles(tablero);

	for (const auto& ref : movs) {
		if (ref.x == destino.x && ref.y == destino.y) {
			valido = true;
			break;
		}
	}

	if (!valido) return false;
	//captura de la pieza contraria, eliminarla de lista de piezas
	Pieza* destinoPieza = tablero[destino.x][destino.y]; //ver si hay una pieza en la casilla destino
	if (destinoPieza != nullptr && destinoPieza->getColor() != turno) { //comprobar si hay pieza y es de color contrario
	// Eliminar del vector de piezas
	auto it = std::find(piezas.begin(), piezas.end(), destinoPieza);
	if (it != piezas.end()) piezas.erase(it);
	delete destinoPieza;
	}

	tablero[destino.x][destino.y] = pieza;
	tablero[origen.x][origen.y] = nullptr;
	pieza->mueve(Vector2D(destino.x, destino.y));
	cambiarTurno();
	return true;
}
Tablero::~Tablero() {
	for (auto pieza : piezas) {
		delete pieza;
	}
	piezas.clear();
}

void Tablero::cambiarTurno() {
	turno = (turno == 'B') ? 'N' : 'B';
}

void Tablero::inicializar(){
	// Peones blancos
	Pieza* peonBlanco1 = new Peon(0, 1, 'B');
	piezas.push_back(peonBlanco1); tablero[0][1] = peonBlanco1;

	Pieza* peonBlanco2 = new Peon(1, 1, 'B');
	piezas.push_back(peonBlanco2); tablero[1][1] = peonBlanco2;

	Pieza* peonBlanco3 = new Peon(2, 1, 'B');
	piezas.push_back(peonBlanco3); tablero[2][1] = peonBlanco3;

	Pieza* peonBlanco4 = new Peon(3, 1, 'B');
	piezas.push_back(peonBlanco4); tablero[3][1] = peonBlanco4;

	Pieza* peonBlanco5 = new Peon(4, 1, 'B');
	piezas.push_back(peonBlanco5); tablero[4][1] = peonBlanco5;

	Pieza* peonBlanco6 = new Peon(5, 1, 'B');
	piezas.push_back(peonBlanco6); tablero[5][1] = peonBlanco6;

	Pieza* peonBlanco7 = new Peon(6, 1, 'B');
	piezas.push_back(peonBlanco7); tablero[6][1] = peonBlanco7;

	Pieza* peonBlanco8 = new Peon(7, 1, 'B');
	piezas.push_back(peonBlanco8); tablero[7][1] = peonBlanco8;

	Pieza* peonBlanco9 = new Peon(8, 1, 'B');
	piezas.push_back(peonBlanco9); tablero[8][1] = peonBlanco9;

	Pieza* peonBlanco10 = new Peon(9, 1, 'B');
	piezas.push_back(peonBlanco10); tablero[9][1] = peonBlanco10;

	// Peones negros
	Pieza* peonNegro1 = new Peon(0, 6, 'N');
	piezas.push_back(peonNegro1); tablero[0][6] = peonNegro1;

	Pieza* peonNegro2 = new Peon(1, 6, 'N');
	piezas.push_back(peonNegro2); tablero[1][6] = peonNegro2;

	Pieza* peonNegro3 = new Peon(2, 6, 'N');
	piezas.push_back(peonNegro3); tablero[2][6] = peonNegro3;

	Pieza* peonNegro4 = new Peon(3, 6, 'N');
	piezas.push_back(peonNegro4); tablero[3][6] = peonNegro4;

	Pieza* peonNegro5 = new Peon(4, 6, 'N');
	piezas.push_back(peonNegro5); tablero[4][6] = peonNegro5;

	Pieza* peonNegro6 = new Peon(5, 6, 'N');
	piezas.push_back(peonNegro6); tablero[5][6] = peonNegro6;

	Pieza* peonNegro7 = new Peon(6, 6, 'N');
	piezas.push_back(peonNegro7); tablero[6][6] = peonNegro7;

	Pieza* peonNegro8 = new Peon(7, 6, 'N');
	piezas.push_back(peonNegro8); tablero[7][6] = peonNegro8;

	Pieza* peonNegro9 = new Peon(8, 6, 'N');
	piezas.push_back(peonNegro9); tablero[8][6] = peonNegro9;

	Pieza* peonNegro10 = new Peon(9, 6, 'N');
	piezas.push_back(peonNegro10); tablero[9][6] = peonNegro10;

	// Inicializar Torres Blancas y Negras
	Pieza* torreBlanca1 = new Torre(0, 0, 'B');
	piezas.push_back(torreBlanca1);
	tablero[0][0] = torreBlanca1;

	Pieza* torreBlanca2 = new Torre(9, 0, 'B');
	piezas.push_back(torreBlanca2);
	tablero[9][0] = torreBlanca2;

	Pieza* torreNegra1 = new Torre(0, 7, 'N');
	piezas.push_back(torreNegra1);
	tablero[0][7] = torreNegra1;

	Pieza* torreNegra2 = new Torre(9, 7, 'N');
	piezas.push_back(torreNegra2);
	tablero[9][7] = torreNegra2;

	// Inicializar Caballos Blancos y Negros
	Pieza* caballoBlanco1 = new Caballo(1, 0, 'B');
	piezas.push_back(caballoBlanco1);
	tablero[1][0] = caballoBlanco1;

	Pieza* caballoBlanco2 = new Caballo(8, 0, 'B');
	piezas.push_back(caballoBlanco2);
	tablero[8][0] = caballoBlanco2;

	Pieza* caballoNegro1 = new Caballo(1, 7, 'N');
	piezas.push_back(caballoNegro1);
	tablero[1][7] = caballoNegro1;

	Pieza* caballoNegro2 = new Caballo(8, 7, 'N');
	piezas.push_back(caballoNegro2);
	tablero[8][7] = caballoNegro2;

	// Inicializar Alfiles Blancos y Negros
	Pieza* alfilBlanco1 = new Alfil(3, 0, 'B');
	piezas.push_back(alfilBlanco1);
	tablero[3][0] = alfilBlanco1;

	Pieza* alfilBlanco2 = new Alfil(6, 0, 'B');
	piezas.push_back(alfilBlanco2);
	tablero[6][0] = alfilBlanco2;

	Pieza* alfilNegro1 = new Alfil(3, 7, 'N');
	piezas.push_back(alfilNegro1);
	tablero[3][7] = alfilNegro1;

	Pieza* alfilNegro2 = new Alfil(6, 7, 'N');
	piezas.push_back(alfilNegro2);
	tablero[6][7] = alfilNegro2;

	// Inicializar Arzobispo Blanco y Negro
	Pieza* arzobispoBlanco = new Arzobispo(2, 0, 'B');
	piezas.push_back(arzobispoBlanco);
	tablero[2][0] = arzobispoBlanco;

	Pieza* arzobispoNegro = new Arzobispo(2, 7, 'N');
	piezas.push_back(arzobispoNegro);
	tablero[2][7] = arzobispoNegro;

	// Inicializar Canciller Blanco y Negro
	Pieza* cancillerBlanco = new Canciller(7, 0, 'B');
	piezas.push_back(cancillerBlanco);
	tablero[7][0] = cancillerBlanco;

	Pieza* cancillerNegro = new Canciller(7, 7, 'N');
	piezas.push_back(cancillerNegro);
	tablero[7][7] = cancillerNegro;

	// Inicializar Rey Blanco y Negro
	Pieza* reyBlanco = new Rey(5, 0, 'B');
	piezas.push_back(reyBlanco);
	tablero[5][0] = reyBlanco;

	Pieza* reyNegro = new Rey(5, 7, 'N');
	piezas.push_back(reyNegro);
	tablero[5][7] = reyNegro;

	// Inicializar Reina Blanca y Negra
	Pieza* reinaBlanca = new Reina(4, 0, 'B');
	piezas.push_back(reinaBlanca);
	tablero[4][0] = reinaBlanca;

	Pieza* reinaNegra = new Reina(4, 7, 'N');
	piezas.push_back(reinaNegra);
	tablero[4][7] = reinaNegra;

}




