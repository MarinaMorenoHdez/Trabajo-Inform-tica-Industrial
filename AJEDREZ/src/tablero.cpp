#include "tablero.h"

Tablero::Tablero() {
	// Inicializar el tablero con nullptr
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 8; ++j) {
			tablero[i][j] = nullptr;
		}
	}
}

void Tablero::inicializar(){
	// Inicializar Peones Blancos y Negros
	for (int i = 0; i < 10; ++i) {
		piezas.push_back(new Peon(i, 1, 'B')); // Peones blancos en la segunda fila
		piezas.push_back (new Peon(i, 6, 'N')); // Peones negros en la septima fila
	}

	// Inicializar Torres Blancas y Negras
	piezas.push_back(new Torre(0, 0, 'B')); 
	piezas.push_back(new Torre(9, 0, 'B')); 
	piezas.push_back(new Torre(0, 7, 'N'));
	piezas.push_back(new Torre(9, 7, 'N'));

	// Inicializar Caballos Blancas y Negras
	piezas.push_back(new Caballo(1, 0, 'B'));
	piezas.push_back(new Caballo(8, 0, 'B'));
	piezas.push_back(new Caballo(1, 7, 'N'));
	piezas.push_back(new Caballo(8, 7, 'N'));

	// Inicializar Alfiles Blancas y Negras
	piezas.push_back(new Alfil(3, 0, 'B'));
	piezas.push_back(new Alfil(6, 0, 'B'));
	piezas.push_back(new Alfil(3, 7, 'N'));
	piezas.push_back(new Alfil(6, 7, 'N'));

	// Inicializar Arzobispo Blancas y Negras
	piezas.push_back(new Arzobispo(2, 0, 'B'));
	piezas.push_back(new Arzobispo(2, 7, 'N'));

	// Inicializar Canciller Blancas y Negras
	piezas.push_back(new Canciller(7, 0, 'B'));
	piezas.push_back(new Canciller(7, 7, 'N'));

	// Inicializar Rey Blancas y Negras
	piezas.push_back(new Rey(5, 0, 'B'));
	piezas.push_back(new Rey(5, 7, 'N'));
	
	// Inicializar Rey Blancas y Negras
	piezas.push_back(new Reina(4, 0, 'B'));
	piezas.push_back(new Reina(4, 7, 'N'));

}




