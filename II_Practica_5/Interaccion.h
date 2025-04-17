#pragma once
#include "hombre.h"
#include "caja.h"
#include "pared.h"
#include "esfera.h"

class Interaccion
{
public:
	// static significa que no es necesario crear un objeto de la clase para usarla
	static void rebote(hombre& h, caja c); // rebote hombre-caja
	static bool rebote(esfera& e, pared p); // rebote esfera-pared
	static void Rebote(esfera& e, caja c); // rebote esfera-caja
	static bool rebote(esfera& e, esfera& e2); // rebote esfera-esfera
};
