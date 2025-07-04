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
#include "movimiento.h"  // Asegúrate de incluir esto si defines Movimiento en otro archivo

class control;

class Tablero {
private:
	Pieza* tablero[10][8];
	std::vector<Pieza*> piezas;
	char turno;
	int pInd = -1;
	int pI = -1, pJ = -1;
	control* refControl = nullptr;
	bool partidaFinalizada = false;
	bool promocionPendiente = false;
	Vector2D peonParaPromocion;

public:
	Tablero();
	~Tablero();
	Tablero(const Tablero& otro);

	bool moverPieza(Vector2D origen, Vector2D destino, bool reproducirSonido = true);
	void cambiarTurno();
	void inicializar();
	void dibuja();
	bool Jaque(char color, bool mostrarDebug = false);
	bool JaqueMate(char color);
	void borrar();

	bool casillaAmenazada(Pieza* tablero[10][8], Vector2D casilla, char color);

	Pieza* getPiezaEn(Vector2D pos) const { return tablero[pos.x][pos.y]; }
	char getTurno() const { return turno; }

	void setControl(control* c) { refControl = c; }

	bool isPartidaFinalizada() const { return partidaFinalizada; }
	std::vector<Movimiento> generarTodosMovimientos(char color,bool soloCapturas = false); //
	std::vector<Vector2D> getMovimientosLegales(Vector2D origen);  
	void setPiezaEn(Vector2D pos, Pieza* p);
	bool hayPromocionPendiente() const { return promocionPendiente; }
	Vector2D getPeonParaPromocion() const { return peonParaPromocion; }
	void cancelarPromocion() { promocionPendiente = false; }
	void reemplazarPeonPromocionado(Pieza* nueva);

	bool empate();
	bool ahogado(char color); 
	void setPartidaFinalizada(bool fin) { partidaFinalizada = fin; }

	//v1
	const std::vector<Pieza*>& getPiezas() const { return piezas; }
};
