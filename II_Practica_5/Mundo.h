#include "caja.h"
#include "hombre.h"
#include "esfera.h"
#include "bonus.h"
#include "disparo.h"
#include "Interaccion.h"
#include "vector2D.h"
#include "pared.h"

class Mundo
{
	disparo Disparo;
	esfera Esfera;
	hombre Hombre;
	caja Caja;
	bonus Bonus;
	pared Plataforma;
	esfera Esfera2;

public:
	void tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void inicializa();
	void rotarOjo();
	void mueve();
	void dibuja();
	float x_ojo;
	float y_ojo;
	float z_ojo;
};
