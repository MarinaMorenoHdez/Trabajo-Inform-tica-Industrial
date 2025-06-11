#include "control.h"

void control::MouseButton(int tipo_oponente, int x, int y, int boton, bool abajo, bool TeclaSp, bool TeclaCtr) {
	if (estado == 0)
		mundo.MouseButton(tipo_oponente, x, y, boton, abajo, TeclaSp, TeclaCtr);
}

void control::dibuja() {
	gluLookAt(15, 18, 60,  // posicion del ojo
		15, 18, 0,         // hacia que punto mira (0,0,0)
		0.0, 1.0, 0.0);    // definimos hacia arriba (eje Y)

	switch (estado) {
	case INICIO: //imagen inicio completa

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,
			ETSIDI::getTexture("imagenes/inicio.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex2d(-15, -4); //inferior izquierda
		glTexCoord2d(1, 1); glVertex2d(45, -4); //Inferior derecha
		glTexCoord2d(1, 0); glVertex2d(45, 40); //Superior derecha
		glTexCoord2d(0, 0); glVertex2d(-15, 40); //Superior izquierda
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;

	case START:
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/start.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex2d(-15, -4);
		glTexCoord2d(1, 1); glVertex2d(45, -4);
		glTexCoord2d(1, 0); glVertex2d(45, 40);
		glTexCoord2d(0, 0); glVertex2d(-15, 40);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;

	case V1x1MENU:
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/1vs1menu.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex2d(-15, -4);
		glTexCoord2d(1, 1); glVertex2d(45, -4);
		glTexCoord2d(1, 0); glVertex2d(45, 40);
		glTexCoord2d(0, 0); glVertex2d(-15, 40);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;

	case V1x1_INSTR:
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/1vs1instrucciones.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex2d(-15, -4);
		glTexCoord2d(1, 1); glVertex2d(45, -4);
		glTexCoord2d(1, 0); glVertex2d(45, 40);
		glTexCoord2d(0, 0); glVertex2d(-15, 40);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;

	case VxMMENU:
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/1vsmaquinamenu.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex2d(-15, -4);
		glTexCoord2d(1, 1); glVertex2d(45, -4);
		glTexCoord2d(1, 0); glVertex2d(45, 40);
		glTexCoord2d(0, 0); glVertex2d(-15, 40);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;

	case VxM_INSTR:
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/1vamaquinainstruciiones.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex2d(-15, -4);
		glTexCoord2d(1, 1); glVertex2d(45, -4);
		glTexCoord2d(1, 0); glVertex2d(45, 40);
		glTexCoord2d(0, 0); glVertex2d(-15, 40);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;

	case RATON:
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/movimientofichas.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex2d(-15, -4);
		glTexCoord2d(1, 1); glVertex2d(45, -4);
		glTexCoord2d(1, 0); glVertex2d(45, 40);
		glTexCoord2d(0, 0); glVertex2d(-15, 40);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;

	case JUEGO:
		mundo.dibuja();
		break;

	default:
		break;
	}
}

void control::tecla(unsigned char key) {
	switch (estado) {
	case INICIO:
		if (key == 's' || key == 'S') {
			estado = START;
			
		}
		break;

	case START:
		if (key == 'v' || key == 'V') {
			estado = V1x1MENU;
			
		}
		else if (key == 'm' || key == 'M') {
			estado = VxMMENU;
			
		}
		break;

	case V1x1MENU:
		if (key == 'i' || key == 'I') {
			estado = V1x1_INSTR;
		
		}
		else if (key == 'p' || key == 'P') {
			mundo.inicializa(0, 0);
			estado = RATON;
			
		}
		break;

	case V1x1_INSTR:
		if (key == 'y' || key == 'Y') {
			
			estado = V1x1MENU;
		}
		break;



	case VxMMENU:
		if (key == 'i' || key == 'I') {
			estado = VxM_INSTR;
			
		}
		else if (key == 'p' || key == 'P') {
			mundo.inicializa(0, 1);
			estado = RATON;
		
		}
		break;

	case VxM_INSTR:
		if (key == 'y' || key == 'Y') {
			estado = VxMMENU;
		}
		break;

	case RATON:
		if (key == 'o' || key == 'O') {
			estado = JUEGO;
		}
		break;

	case JUEGO:
		break;
	}
}
