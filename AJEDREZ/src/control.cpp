#include "control.h"
#include <iostream>
#include "freeglut.h" 
#include <ETSIDI.h>
#include "mundo.h"      
#include "tablero.h"  
#include "pieza.h"


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
        if (x_mundo >= 8 && x_mundo <= 23 && y_mundo >= 18 && y_mundo <= 21) {
            estado = V1x1MENU;
            std::cout << "Cambio a V1x1MENU\n";
        }
        else if (x_mundo >= 8 && x_mundo <= 23 && y_mundo >= 10 && y_mundo <= 18) {
            estado = VxMMENU;
            std::cout << "Cambio a VxMMENU\n";
        }
        break;

    case V1x1MENU:
        if (x_mundo >= 8 && x_mundo <= 23 && y_mundo >= 18 && y_mundo <= 21) {
            mundo.inicializa(0, 0);
            estado = RATON;
            std::cout << "Cambio a estado RATON (1vs1)\n";
        }
        else if (x_mundo >= 8 && x_mundo <= 23 && y_mundo >= 10 && y_mundo <= 18) {
            estado = V1x1_INSTR;
            std::cout << "Cambio a estado V1x1_INSTR\n";
        }
        break;

    case V1x1_INSTR:
        if (x_mundo >= 13 && x_mundo <= 18 && y_mundo >= 0.5 && y_mundo <= 1.2) {
            mundo.inicializa(0, 0);
            estado = RATON;
            std::cout << "JUGAR desde instrucciones 1vs1\n";
        }
        break;

    case VxMMENU:
        if (x_mundo >= 15 && x_mundo <= 45 && y_mundo >= 20 && y_mundo <= 28) {
            mundo.inicializa(0, 1);
            estado = RATON;
            std::cout << "Cambio a estado RATON (vs máquina)\n";
        }
        else if (x_mundo >= 15 && x_mundo <= 45 && y_mundo >= 10 && y_mundo <= 18) {
            estado = VxM_INSTR;
            std::cout << "Cambio a estado VxM_INSTR\n";
        }
        break;

    case VxM_INSTR:
        if (x_mundo >= 13 && x_mundo <= 18 && y_mundo >= 0.5 && y_mundo <= 1.2) {
            mundo.inicializa(0, 1);
            estado = RATON;
            std::cout << "JUGAR desde instrucciones vs máquina\n";
        }
        break;

    case RATON:
        if (x_mundo >= 6 && x_mundo <= 27 && y_mundo >= 0.3 && y_mundo <= 2.5) {
            estado = JUEGO;
            std::cout << "Cambio a estado JUEGO desde pantalla RATON (instrucciones)\n";
        }
        break;

    case JUEGO:
    case JUEGO_1VS1:
        if (boton == GLUT_LEFT_BUTTON && abajo) {
            Vector2D coord = mouseToBoardCoords(x, y);
            gestionarMovimientoJugador(coord);
        }
        if (x_mundo >= 36 && x_mundo <= 43 && y_mundo >= -3 && y_mundo <= 1) {
            estado = MENUPAUSA;
        }
        break;

    case MENUPAUSA:
        if (x_mundo >= 7 && x_mundo <= 23 && y_mundo >= 27 && y_mundo <= 30) {
            estado = JUEGO;
            
        }
        if (x_mundo >=7 && x_mundo <= 23 && y_mundo >= 13 && y_mundo <= 17) {
            estado = INSTRUCCIONES;
        }
        if (x_mundo >= 7 && x_mundo <= 23 && y_mundo >= 20 && y_mundo <= 24) {
            mundo.borrar();
            if (mundo.get_oponente() == 0) {
                mundo.inicializa(0, 0);
            }
            else {
                mundo.inicializa(0, 1);
            }
           
            mundo.dibuja();
            estado = JUEGO;
        }
        if (x_mundo >= 7 && x_mundo <= 23 && y_mundo >= 7 && y_mundo <= 11) {
            mundo.borrar();
            if (mundo.get_oponente() == 0) {
                mundo.inicializa(0, 0);
            }
            else {
                mundo.inicializa(0, 1);
            }
            mundo.dibuja();
            estado = START;
        }
        if (x_mundo >= 7 && x_mundo <= 23 && y_mundo >= 0.5 && y_mundo <= 4) {
            exit(0);
        }
        break;
    case PEONFINALAZUL:
    {
        Vector2D pos = mundo.getTablero().getPeonParaPromocion();
        char color = 'B';
        Pieza* nueva = nullptr;

      
        if (x_mundo >= -11 && x_mundo <= -1.5 && y_mundo >= 16 && y_mundo <= 28)
            nueva = new Alfil(pos.x, pos.y, color);
        else if (x_mundo >= 7.5 && x_mundo <= 21.6 && y_mundo >= 16 && y_mundo <= 28)
            nueva = new Arzobispo(pos.x, pos.y, color);
        else if (x_mundo >= 30 && x_mundo <= 40 && y_mundo >= 16 && y_mundo <= 28)
            nueva = new Caballo(pos.x, pos.y, color);
        else if (x_mundo >= -11 && x_mundo <= -1.5 && y_mundo >= -1.6 && y_mundo <= 13)
            nueva = new Canciller(pos.x, pos.y, color);
        else if (x_mundo >= 7.5 && x_mundo <= 21.6 && y_mundo >= -1.6 && y_mundo <= 13)
            nueva = new Reina(pos.x, pos.y, color);
        else if (x_mundo >= 30 && x_mundo <= 40 && y_mundo >= -1.6 && y_mundo <= 13)
            nueva = new Torre(pos.x, pos.y, color);

        if (nueva) {
            mundo.getTablero().reemplazarPeonPromocionado(nueva);
            mundo.getTablero().cancelarPromocion();
            estado = JUEGO;
        }
        break;
    }


    case PEONFINALROJO:
    {

        std::cout << "Click: x = " << x_mundo << ", y = " << y_mundo << std::endl;

        Vector2D pos = mundo.getTablero().getPeonParaPromocion();
        char color = 'N';

        Pieza* nueva = nullptr;

         if (x_mundo >= -11 && x_mundo <= -1.5 && y_mundo >= 16 && y_mundo <= 28)
            nueva = new Alfil(pos.x, pos.y, color);
        else if (x_mundo >= 7.5 && x_mundo <= 21.6 && y_mundo >= 16 && y_mundo <= 28)
            nueva = new Arzobispo(pos.x, pos.y, color);
        else if (x_mundo >= 30 && x_mundo <= 40 && y_mundo >= 16 && y_mundo <= 28)
            nueva = new Caballo(pos.x, pos.y, color);
        else if (x_mundo >= -11 && x_mundo <= -1.5 && y_mundo >= -1.6 && y_mundo <= 13)
            nueva = new Canciller(pos.x, pos.y, color);
        else if (x_mundo >= 7.5 && x_mundo <= 21.6 && y_mundo >= -1.6 && y_mundo <= 13)
            nueva = new Reina(pos.x, pos.y, color);
        else if (x_mundo >= 30 && x_mundo <= 40 && y_mundo >= -1.6 && y_mundo <= 13)
            nueva = new Torre(pos.x, pos.y, color);

        if (nueva) {
            mundo.getTablero().reemplazarPeonPromocionado(nueva);
            mundo.getTablero().cancelarPromocion();
            estado = JUEGO;
        }
        break;
    }


    case GANAROJO:
            if (x_mundo >= -14 && x_mundo <= -4 && y_mundo >= -3 && y_mundo <= 1) {
            mundo.borrar();
            if (mundo.get_oponente() == 0) {
                mundo.inicializa(0, 0);
            }
            else {
                mundo.inicializa(0, 1);
            }
            mundo.dibuja();
            estado = JUEGO;
            std::cout << "Reinicio\n";
        }
        if (x_mundo >= 34 && x_mundo <= 44 && y_mundo >= -2 && y_mundo <= 1) {
            exit(0);
        }
        break;

    case GANAAZUL:
        if (x_mundo >= -14 && x_mundo <= -4 && y_mundo >= -3 && y_mundo <= 1) {
            mundo.borrar();
            if (mundo.get_oponente() == 0) {
                mundo.inicializa(0, 0);
            }
            else {
                mundo.inicializa(0, 1);
            }
            tablero.dibuja();
            estado = JUEGO;
            std::cout << "Reinicio\n";
        }
        if (x_mundo >= 34 && x_mundo <= 44 && y_mundo >= -2 && y_mundo <= 1) {
            exit(0);
        }
        break;

    case TABLAS:
        break;
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
    case MENUPAUSA:texId = ETSIDI::getTexture("imagenes/menupausa.png").id; break;
    case INSTRUCCIONES:texId = ETSIDI::getTexture("imagenes/instrucciones.png").id; break;
    case PEONFINALAZUL:texId = ETSIDI::getTexture("imagenes/peonfinalrojo.png").id; break;
    case PEONFINALROJO:texId = ETSIDI::getTexture("imagenes/peonfinalazul.png").id; break;
    case GANAROJO: texId = ETSIDI::getTexture("imagenes/rojoganador.png").id; break;
    case GANAAZUL: texId = ETSIDI::getTexture("imagenes/azulganador.png").id; break;
    case TABLAS: texId = ETSIDI::getTexture("imagenes/tablas.png").id; break;
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


void control::gestionarMovimientoJugador(Vector2D coord) {
    if (mundo.getTablero().isPartidaFinalizada()) {
        std::cout << "¡Jaque Mate! La partida ha terminado.\n";
        return;
    }

    Pieza* p = mundo.getTablero().getPiezaEn(coord);

    if (!piezaSeleccionada) {
        if (p && p->getColor() == mundo.getTablero().getTurno()) {
            piezaSeleccionada = true;
            casillaSeleccionada = coord;
            casillasPosibles = mundo.getTablero().getMovimientosLegales(coord);
        }
    }
    else {
        if (mundo.getTablero().moverPieza(casillaSeleccionada, coord)) {
            limpiarSeleccion();

          
            if (mundo.getTablero().hayPromocionPendiente()) {
                estado = (mundo.getTurno() == 'N') ? PEONFINALROJO : PEONFINALAZUL;
                return;
            }

            // Si juegas contra la IA, actúa ahora
            if (mundo.get_oponente() == 1) {
                Movimiento mejor = ia.calcularMejorMovimiento(mundo.getTablero(), mundo.getTablero().getTurno());
                if (mejor.origen.x != -1) {
                    mundo.getTablero().moverPieza(mejor.origen, mejor.destino);
                }
            }
        }
        else {
            piezaSeleccionada = false;
            casillasPosibles.clear();
        }
    }
}
