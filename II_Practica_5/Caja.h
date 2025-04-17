#pragma once
#include "pared.h"

class caja
{
private:
	pared suelo;
	pared techo;
	pared pared_izq;
	pared pared_dcha;
public:
	caja();
	virtual~caja();
	void dibuja();
	friend class Interaccion;
};
