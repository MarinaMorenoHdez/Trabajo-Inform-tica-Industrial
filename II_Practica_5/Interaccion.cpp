#include "Interaccion.h"

void Interaccion::rebote(hombre& h, caja c) // horizontal, no rebota, se para
{
	float xmax = c.suelo.limite2.x; // limite derecho
	float xmin = c.suelo.limite1.x; // limite izquierdo

	if (h.posicion.x > xmax)h.posicion.x = xmax; // rebote derecho (no deja pasar el límite)
	if (h.posicion.x < xmin)h.posicion.x = xmin; // rebote izquierdo (no deja pasar el límite)
}

bool Interaccion::rebote(esfera& e, pared p)
{
	vector2D direccion;
	float diferencia = p.distancia(e.posicion, &direccion) - e.radio;
	
	if (diferencia <= 0.0f) // toca pared
	{
		vector2D v_inicial = e.velocidad; // velocidad antes del rebote
		e.velocidad = v_inicial - direccion * 2.0 * (v_inicial * direccion); // rebote (-velocidad)
		e.posicion = e.posicion - direccion * diferencia; // mueve la esfera fuera de la pared
		return true; 
	}

	return false; // no toca pared
}

void Interaccion::Rebote(esfera& e, caja c) // Para usar rebote con pared
{
	Interaccion::rebote(e, c.suelo); // rebote con el suelo
	Interaccion::rebote(e, c.pared_dcha); // rebote con la pared derecha
	Interaccion::rebote(e, c.pared_izq); // rebote con la pared izquierda
	Interaccion::rebote(e, c.techo); // rebote con el techo
}

bool Interaccion::rebote(esfera& e, esfera& e2) // lo hice con chati
{
	// si la distancia entre los centros de las esferas es menor que la suma de sus radios
	if ((e.posicion.x - e2.posicion.x) * (e.posicion.x - e2.posicion.x) +
		(e.posicion.y - e2.posicion.y) * (e.posicion.y - e2.posicion.y) <=
		(e.radio + e2.radio) * (e.radio + e2.radio)) 
	{
		vector2D v1, v2;
		v1 = e.velocidad;
		v2 = e2.velocidad;

		// Calculamos la velocidad de rebote
		e.velocidad.x = (v1.x * (e.radio * e.radio - e2.radio * e2.radio) +
			2 * v2.x * e2.radio * e2.radio) / (e.radio * e.radio + e2.radio *
				e2.radio);

		e.velocidad.y = (v1.y * (e.radio * e.radio - e2.radio * e2.radio) +
			2 * v2.y * e2.radio * e2.radio) / (e.radio * e.radio + e2.radio *
				e2.radio);

		e2.velocidad.x = (v2.x * (e2.radio * e2.radio - e.radio * e.radio) +
			2 * v1.x * e.radio * e.radio) / (e.radio * e.radio + e2.radio *
				e2.radio);

		e2.velocidad.y = (v2.y * (e2.radio * e2.radio - e.radio * e.radio) +
			2 * v1.y * e.radio * e.radio) / (e.radio * e.radio + e2.radio *
				e2.radio);

		return true; // rebota
	}

	else
		return false; // no rebota
}
