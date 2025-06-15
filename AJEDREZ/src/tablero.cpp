#include "tablero.h"
#include "iostream"
#include "freeglut.h"
#include <ETSIDI.h>
#include "control.h"


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
	//simulación del movimiento para ver si se deja al propio rey en jaque 
	Pieza* destinoPieza = tablero[destino.x][destino.y]; //ver si hay una pieza en la casilla destino
	Vector2D origenOriginal = pieza->getPosicion();
	tablero[origen.x][origen.y] = nullptr;
	tablero[destino.x][destino.y] = pieza;
	pieza->mueve(destino);

	bool enJaque = Jaque(turno);
	
	// Revertir simulación
	pieza->mueve(origenOriginal);
	tablero[origen.x][origen.y] = pieza;
	tablero[destino.x][destino.y] = destinoPieza;

	if (enJaque) {
		std::cout <<"Movimiento no permitido, el Rey sigue en Jaque.\n";
		return false;
	}
	
	//movimiento real
	if (destinoPieza != nullptr) { //comprobar si hay pieza para comer
	// Eliminar del vector de piezas
	auto it = std::find(piezas.begin(), piezas.end(), destinoPieza);
	if (it != piezas.end()) piezas.erase(it);
	delete destinoPieza;
	}

	tablero[destino.x][destino.y] = pieza;
	tablero[origen.x][origen.y] = nullptr;
	pieza->mueve(destino);
	
	// Aviso de jaque
	char enemigo = (turno == 'B') ? 'N' : 'B';
	if (Jaque(enemigo)) {
	std::cout << "¡Jaque al Rey " << enemigo << "!\n";
	if (JaqueMate(enemigo)) {
		std::cout << "¡Jaque mate! Gana el jugador " << turno << std::endl;
		partidaFinalizada = true; // Partida finalizada
		if (refControl != nullptr) {
				if (turno == 'B')  
					refControl->Set_Estado(GANAROJO);
				else               
					refControl->Set_Estado(GANAAZUL);
			}
		
	}
	}
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
void Tablero::dibuja() {
	// DIBUJAR FONDO PRIMERO
	glDisable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/tablero.png").id);

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3d(-15, -4, -1); 
	glTexCoord2d(1, 1); glVertex3d(45, -4, -1);
	glTexCoord2d(1, 0); glVertex3d(45, 40, -1);
	glTexCoord2d(0, 0); glVertex3d(-15, 40, -1);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);

	// DIBUJAR TABLERO CON CASILLAS
	float casillaSize = 4.0f;
	float offsetX = 0.0f;
	float offsetY = 0.0f;

	for (int fila = 0; fila < 8; ++fila) {
		for (int col = 0; col < 10; ++col) {
			if ((fila + col) % 2 == 0)
				glColor3f(0.9f, 0.9f, 0.9f); // claro
			else
				glColor3f(0.2f, 0.2f, 0.2f); // oscuro

			float x1 = offsetX + col * casillaSize;
			float y1 = offsetY + fila * casillaSize;
			float x2 = x1 + casillaSize;
			float y2 = y1 + casillaSize;

			glBegin(GL_QUADS);
			glVertex3f(x1, y1, 0);  
			glVertex3f(x2, y1, 0);
			glVertex3f(x2, y2, 0);
			glVertex3f(x1, y2, 0);
			glEnd();
		}
	}

	if (refControl && refControl->haySeleccion()) {
		const std::vector<Vector2D>& posibles = refControl->getCasillasPosibles();
		float casillaSize = 4.0f;
		float offsetX = 0.0f;
		float offsetY = 0.0f;

		glDisable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glColor4f(0.0f, 1.0f, 0.0f, 0.3f);  // verde semitransparente

		for (const Vector2D& pos : posibles) {
			float x = offsetX + pos.x * casillaSize;
			float y = offsetY + pos.y * casillaSize;

			glBegin(GL_QUADS);
			glVertex3f(x, y, 0.01f);
			glVertex3f(x + casillaSize, y, 0.01f);
			glVertex3f(x + casillaSize, y + casillaSize, 0.01f);
			glVertex3f(x, y + casillaSize, 0.01f);
			glEnd();
		}

		glDisable(GL_BLEND);
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_LIGHTING);
	}

	// DIBUJAR CASILLA SELECCIONADA resaltar
	//HAY Q CAMBIARLO NO FUNCIONA TIENE Q SER COMO CONTROL.CPP
	//Vector2D control::mouseToBoardCoords(int x, int y)
	//PASAR LAS COORDENADAS DE SELECCION AQUI 
if (refControl && refControl->haySeleccion()) {
    Vector2D celda = refControl->getCasillaSeleccionada();
    float casillaSize = 4.0f;
    float offsetX = 0.0f;
    float offsetY = 0.0f;

    float x = offsetX + celda.x * casillaSize;
    float y = offsetY + celda.y * casillaSize;

    glDisable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glColor4f(1.0f, 1.0f, 0.0f, 0.5f);  // amarillo semitransparente

    glBegin(GL_QUADS);
    glVertex3f(x, y, 0.01f);  // z bajo para estar debajo de la pieza
    glVertex3f(x + casillaSize, y, 0.01f);
    glVertex3f(x + casillaSize, y + casillaSize, 0.01f);
    glVertex3f(x, y + casillaSize, 0.01f);
    glEnd();

    glDisable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
}


	//dibujar pieza
	for (int x = 0; x < 10; ++x) {
		for (int y = 0; y < 8; ++y) {
			Pieza* p = tablero[x][y];
			if (p != nullptr) {
				p->dibuja();  // Dibujar cada pieza
			}
		}

	}

	
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

bool Tablero::Jaque(char color)
{
	Vector2D posicionRey;
	bool reyEncontrado = false;

	// Buscar al rey del color dado
	for (Pieza* p : piezas) {
		if (p->getColor() == color && p->getTipo() == tipo::REY) {
			posicionRey = p->getPosicion();
			reyEncontrado = true;
			break;
		}
	}

	if (!reyEncontrado) return false; // No hay rey 

	// Comprobar si alguna pieza enemiga puede atacarlo
	for (Pieza* p : piezas) {
		if (p->getColor() != color) {
			std::vector<Vector2D> movs = p->movimientosPosibles(tablero);
			for (const Vector2D& m : movs) {
				if (m.x == posicionRey.x && m.y == posicionRey.y) {
					return true; // Jaque detectado
				}
			}
		}
	}

	return false; // No hay jaque
}



bool Tablero::JaqueMate(char color) {
		if (!Jaque(color)) return false; // Si no está en jaque, no es jaque mate

		// Para cada pieza del color del turno
		for (Pieza* p : piezas) {
			if (p->getColor() == color) {
				std::vector<Vector2D> movs = p->movimientosPosibles(tablero);
				Vector2D origen = p->getPosicion();

				for (const Vector2D& destino : movs) {
					// Simular el movimiento
					Pieza* destinoPieza = tablero[destino.x][destino.y];
					tablero[origen.x][origen.y] = nullptr;
					tablero[destino.x][destino.y] = p;
					p->mueve(destino);

					bool sigueEnJaque = Jaque(color);

					// Revertir simulación
					p->mueve(origen);
					tablero[origen.x][origen.y] = p;
					tablero[destino.x][destino.y] = destinoPieza;

					if (!sigueEnJaque)
						return false; // Hay al menos un movimiento que evita el jaque mate
				}
			}
		}
		// Si ningún movimiento evita el jaque, es jaque mate
		return true;
}


std::vector<Vector2D> Tablero::getMovimientosLegales(Vector2D origen) {
	Pieza* p = getPiezaEn(origen);  
	if (!p) return {};

	return p->movimientosPosibles(tablero);  
}


std::vector<Movimiento> Tablero::generarTodosMovimientos(bool soloCapturas) {
	std::vector<Movimiento> lista;

	for (int x = 0; x < 10; ++x) {
		for (int y = 0; y < 8; ++y) {
			Pieza* p = tablero[x][y];
			if (p && p->getColor() == turno) {
				Vector2D origen = { x, y };
				std::vector<Vector2D> posibles = p->movimientosPosibles(tablero);

				for (const Vector2D& destino : posibles) {
					Pieza* piezaDestino = tablero[destino.x][destino.y];

					// Si se piden solo capturas y no hay pieza enemiga, se ignora
					if (soloCapturas && (!piezaDestino || piezaDestino->getColor() == turno))
						continue;

					// Simular movimiento
					Pieza* tmp = tablero[destino.x][destino.y];
					tablero[x][y] = nullptr;
					tablero[destino.x][destino.y] = p;
					Vector2D posOriginal = p->getPosicion();
					p->mueve(destino);

					bool enJaque = Jaque(turno);

					// Revertir simulación
					p->mueve(posOriginal);
					tablero[x][y] = p;
					tablero[destino.x][destino.y] = tmp;

					if (!enJaque) {
						lista.emplace_back(origen, destino);
					}
				}
			}
		}
	}

	return lista;
}
void Tablero::borrar() {
	for (Pieza* pieza : piezas) {
		delete pieza; 
	}

	piezas.clear(); 
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 8; ++j) {
			tablero[i][j] = nullptr;
		}
	}
}



