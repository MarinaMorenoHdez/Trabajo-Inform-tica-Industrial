#include "control.h"
#include <iostream>
#include "freeglut.h" 
#include <ETSIDI.h>
#include "mundo.h"      
#include "tablero.h"    


void control::MouseButton(int tipo_oponente, int x, int y, int boton, bool abajo, bool TeclaSp, bool TeclaCtr) {
    if (!abajo) return;

    int anchoVentana = glutGet(GLUT_WINDOW_WIDTH);
    int altoVentana = glutGet(GLUT_WINDOW_HEIGHT);

    float x_mundo = -15.0f + (x / (float)anchoVentana) * 60.0f;
    float y_mundo = 40.0f - (y / (float)altoVentana) * 44.0f;

    std::cout << "Click en coords mundo: x=" << x_mundo << ", y=" << y_mundo << std::endl;

    switch (estado) 
    {
    case INICIO:
        if (x_mundo >= 10 && x_mundo <= 30 && y_mundo >= 3 && y_mundo <= 10) {
            estado = START;
        }
        break;

    case START:
        // Botón 1 vs 1
        if (x_mundo >= 15 && x_mundo <= 45 && y_mundo >= 20 && y_mundo <= 28) {
            estado = V1x1MENU;
            std::cout << "Cambio a V1x1MENU\n";
        }
        // Botón 1 vs MÁQUINA
        else if (x_mundo >= 15 && x_mundo <= 45 && y_mundo >= 10 && y_mundo <= 18) {
            estado = VxMMENU;
            std::cout << "Cambio a VxMMENU\n";
        }
        break;


    case V1x1MENU:
        // Botón EMPEZAR JUEGO
        if (x_mundo >= 15 && x_mundo <= 45 && y_mundo >= 20 && y_mundo <= 28) {
            mundo.inicializa(0, 0);
            estado = RATON;
            std::cout << "Cambio a estado RATON (1vs1)\n";
        }
        // Botón INSTRUCCIONES
        else if (x_mundo >= 15 && x_mundo <= 45 && y_mundo >= 10 && y_mundo <= 18) {
            estado = V1x1_INSTR;
            std::cout << "Cambio a estado V1x1_INSTR\n";
        }
        break;


    case V1x1_INSTR:
        if (x_mundo >= 13 && x_mundo <= 18 && y_mundo >= 0.5 && y_mundo <= 1.2) {
            mundo.inicializa(0, 0);  // Juego 1vs1
            estado = RATON;
            std::cout << "JUGAR desde instrucciones 1vs1\n";
        }
        break;


    case VxMMENU:
        // Botón "EMPEZAR JUEGO"
        if (x_mundo >= 15 && x_mundo <= 45 && y_mundo >= 20 && y_mundo <= 28) {
            mundo.inicializa(0, 1);
            estado = RATON;
            std::cout << "Cambio a estado RATON (vs máquina)\n";
        }
        // Botón "INSTRUCCIONES"
        else if (x_mundo >= 15 && x_mundo <= 45 && y_mundo >= 10 && y_mundo <= 18) {
            estado = VxM_INSTR;
            std::cout << "Cambio a estado VxM_INSTR\n";
        }
        break;


    case VxM_INSTR:
        if (x_mundo >= 13 && x_mundo <= 18 && y_mundo >= 0.5 && y_mundo <= 1.2) {
            mundo.inicializa(0, 1);  // Juego vs máquina
            estado = RATON;
            std::cout << "JUGAR desde instrucciones vs máquina\n";
        }
        break;


    case RATON:
        if (x_mundo >= 13 && x_mundo <= 18 && y_mundo >= 0.3 && y_mundo <= 1.3) {
            estado = JUEGO;
            std::cout << "Cambio a estado JUEGO desde pantalla RATON (instrucciones)\n";
        }
        break;


    case JUEGO:
    case JUEGO_1VS1:
    {
        if (boton == GLUT_LEFT_BUTTON && abajo) {
            Vector2D coord = mouseToBoardCoords(x, y);
            gestionarMovimientoJugador(coord);
        }
        break;
    }
    }
    
}

void control::dibuja() {
    gluLookAt(15, 18, 60, 15, 18, 0, 0.0, 1.0, 0.0);

    int texId = -1;
    switch (estado) {
    case INICIO: texId = ETSIDI::getTexture("imagenes/inicio.png").id; break;
    case START: texId = ETSIDI::getTexture("imagenes/start.png").id; break;
    case V1x1MENU: texId = ETSIDI::getTexture("imagenes/1vs1menu.png").id; break;
    case V1x1_INSTR: texId = ETSIDI::getTexture("imagenes/1vs1instrucciones.png").id; break;
    case VxMMENU: texId = ETSIDI::getTexture("imagenes/1vsmaquinamenu.png").id; break;
    case VxM_INSTR: texId = ETSIDI::getTexture("imagenes/1vamaquinainstruciiones.png").id; break;
    case RATON: texId = ETSIDI::getTexture("imagenes/movimientofichas.png").id; break;
    case JUEGO:
        mundo.dibuja();
        return;
    default:
        return;
    }

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texId);
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
}

void control::tecla(unsigned char key) {
    
}






void control::gestionarMovimientoJugador(Vector2D coord) {
	Pieza* p = mundo.getTablero().getPiezaEn(coord);

	if (!piezaSeleccionada) {
		// Primer clic: seleccionar origen
		if (p && p->getColor() == mundo.getTurno()) {
			seleccion = coord;              // almacenar origen
			piezaSeleccionada = true;       // marcar como seleccionada
		}
	}
	else {
		// Segundo clic: destino
		bool exito = mundo.getTablero().moverPieza(seleccion, coord); // mover con origen y destino
		piezaSeleccionada = false; // reset

		// Si es contra la máquina, actuar después
		if (mundo.get_oponente() == 1 && exito) {
			// ejecutarIA();  // si tienes IA
		}
	}
}

Vector2D control::mouseToBoardCoords(int x, int y) {
    int anchoVentana = glutGet(GLUT_WINDOW_WIDTH);
    int altoVentana = glutGet(GLUT_WINDOW_HEIGHT);

    float x_mundo = -15.0f + (x / (float)anchoVentana) * 60.0f;
    float y_mundo = 40.0f - (y / (float)altoVentana) * 44.0f;

    int col = static_cast<int>(x_mundo / 4.0f);
    int row = static_cast<int>(y_mundo / 4.0f);

    std::cout << "Click en coords mundo: x=" << x_mundo << ", y=" << y_mundo << std::endl;
    std::cout << "Click en casilla tablero: col = " << col << ", fila = " << row << std::endl;

    return Vector2D{ col, row };
}


//CONSTRUCTOR
control::control() {
    mundo.setControl(this);  
}
