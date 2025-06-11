#pragma once
#include <vector>
#include "pieza.h"

class tablero
{
private:

	std::vector<Pieza*> piezas; // lista de piezas del juego

public:
	void Inicializar();
};

