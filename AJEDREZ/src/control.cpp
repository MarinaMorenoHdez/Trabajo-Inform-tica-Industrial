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
        ETSIDI::play("sonidos/pulsartecla.mp3");
        if (x_mundo >= 1.5 && x_mundo <= 32 && y_mundo >= 3 && y_mundo <= 6) {
            estado = START;
        }
        break;

    case START:
        ETSIDI::play("sonidos/pulsartecla.mp3");
        if (x_mundo >= 7.5 && x_mundo <= 24.5 && y_mundo >= 18 && y_mundo <= 22) {
            estado = V1x1MENU;
            std::cout << "Cambio a V1x1MENU\n";
        }
        else if (x_mundo >= 7.5 && x_mundo <= 24.5 && y_mundo >= 12 && y_mundo <= 15.5) {
            estado = VxMMENU;
            std::cout << "Cambio a VxMMENU\n";
        }
        break;

    case V1x1MENU:
        ETSIDI::play("sonidos/pulsartecla.mp3");
        if (x_mundo >= 7.5 && x_mundo <= 24.5 && y_mundo >= 18 && y_mundo <= 22) {
            mundo.inicializa(0, 0);
            estado = RATON;
            std::cout << "Cambio a estado RATON (1vs1)\n";
        }
        else if (x_mundo >= 7.5 && x_mundo <= 24.5 && y_mundo >= 12 && y_mundo <= 15.5) {
            estado = V1x1_INSTR;
            std::cout << "Cambio a estado V1x1_INSTR\n";
        }
        break;

    case V1x1_INSTR:
        ETSIDI::play("sonidos/pulsartecla.mp3");
        if (x_mundo >= 7 && x_mundo <= 19.3 && y_mundo >= -0.4 && y_mundo <= 1.7) {
            mundo.inicializa(0, 0);
            estado = RATON;
            std::cout << "JUGAR desde instrucciones 1vs1\n";
        }
        break;

    case VxMMENU:
        ETSIDI::play("sonidos/pulsartecla.mp3");
        if (x_mundo >= 7.5 && x_mundo <= 24.5 && y_mundo >= 18 && y_mundo <= 22) {
            mundo.inicializa(0, 1);
            estado = RATON;
            std::cout << "Cambio a estado RATON (vs máquina)\n";
        }
        else if (x_mundo >= 7.5 && x_mundo <= 24.5 && y_mundo >= 12 && y_mundo <= 15.5) {
            estado = VxM_INSTR;
            std::cout << "Cambio a estado VxM_INSTR\n";
        }
        break;

    case VxM_INSTR:
        ETSIDI::play("sonidos/pulsartecla.mp3");
        if (x_mundo >= 7 && x_mundo <= 19.3 && y_mundo >= -0.4 && y_mundo <= 1.7) {
            mundo.inicializa(0, 1);
            estado = RATON;
            std::cout << "JUGAR desde instrucciones vs máquina\n";
        }
        break;

    case RATON:

        if (x_mundo >= 6.8 && x_mundo <= 27 && y_mundo >= -0.1 && y_mundo <= 1.7) {
            ETSIDI::play("sonidos/pulsartecla.mp3");
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
        if (x_mundo >= 36 && x_mundo <= 43 && y_mundo >= -3 && y_mundo <= -0.5) {
            ETSIDI::play("sonidos/pulsartecla.mp3");
            estado = MENUPAUSA;
        }
        break;

    case MENUPAUSA:
        ETSIDI::play("sonidos/pulsartecla.mp3");
        if (x_mundo >= 7 && x_mundo <= 23 && y_mundo >= 27 && y_mundo <= 30) {
            ETSIDI::play("sonidos/pulsartecla.mp3");
            estado = JUEGO;

        }
        if (x_mundo >= 7 && x_mundo <= 23 && y_mundo >= 13 && y_mundo <= 17) {
            ETSIDI::play("sonidos/pulsartecla.mp3");
            estado = INSTRUCCIONES;
        }
        if (x_mundo >= 7 && x_mundo <= 23 && y_mundo >= 20 && y_mundo <= 24) {
            ETSIDI::play("sonidos/pulsartecla.mp3");
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
            ETSIDI::play("sonidos/pulsartecla.mp3");
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
            ETSIDI::play("sonidos/pulsartecla.mp3");
            exit(0);
        }
        break;
    case INSTRUCCIONES:
    {
        if (x_mundo >= -14 && x_mundo <= -7 && y_mundo >= -3 && y_mundo <= 0) {
            ETSIDI::play("sonidos/pulsartecla.mp3");
            estado = MENUPAUSA;
        }
    }

    case PEONFINALAZUL:
    {
        Vector2D pos = mundo.getTablero().getPeonParaPromocion();
        Pieza* peon = mundo.getTablero().getPiezaEn(pos);
        char color = peon ? peon->getColor() : 'B'; // Asegúrate de usar el color correcto
        Pieza* nueva = nullptr;
        ETSIDI::play("sonidos/pulsartecla.mp3");
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
            limpiarSeleccion();
            estado = JUEGO;
			mundo.getTablero().cambiarTurno();

        }
        break;
    }

    case PEONFINALROJO:
    {
        Vector2D pos = mundo.getTablero().getPeonParaPromocion();
        Pieza* peon = mundo.getTablero().getPiezaEn(pos);
        char color = peon ? peon->getColor() : 'N'; // Asegúrate de usar el color correcto
        Pieza* nueva = nullptr;
        ETSIDI::play("sonidos/pulsartecla.mp3");
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
            limpiarSeleccion();
            estado = JUEGO;
            mundo.getTablero().cambiarTurno();
        }
        break;
    }

    case GANAROJO:
        if (x_mundo >= -14 && x_mundo <= -4 && y_mundo >= -3 && y_mundo <= 1) {
            ETSIDI::play("sonidos/pulsartecla.mp3");
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
            ETSIDI::play("sonidos/pulsartecla.mp3");
            exit(0);
        }
        break;

    case GANAAZUL:
        if (x_mundo >= -14 && x_mundo <= -4 && y_mundo >= -3 && y_mundo <= 1) {
            ETSIDI::play("sonidos/pulsartecla.mp3");
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
            ETSIDI::play("sonidos/pulsartecla.mp3");
            exit(0);
        }
        break;

    case TABLAS:
        std::cout << "Cargando imagen: imagenes/tablas.png" << std::endl;
        if (x_mundo >= -14 && x_mundo <= -4 && y_mundo >= -3 && y_mundo <= 1) {
            ETSIDI::play("sonidos/pulsartecla.mp3");
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
            ETSIDI::play("sonidos/pulsartecla.mp3");
            exit(0);
        }
        break;

        break;
    }
}




void control::dibuja() {
    // Movimiento de la IA si está pendiente y es su turno
    if (iaPendiente && mundo.get_oponente() == 1 && mundo.getTablero().getTurno() == 'N' && !mundo.getTablero().isPartidaFinalizada()) {
        Movimiento mejor = ia.calcularMejorMovimiento(mundo.getTablero(), 'N');
        if (mejor.origen.x != -1) {
            mundo.getTablero().moverPieza(mejor.origen, mejor.destino);

            // Promoción automática de la IA si corresponde
            if (mundo.getTablero().hayPromocionPendiente()) {
                Vector2D pos = mundo.getTablero().getPeonParaPromocion();
                Pieza* peon = mundo.getTablero().getPiezaEn(pos);
                if (peon && peon->getColor() == 'N') {
                    Pieza* nueva = new Reina(pos.x, pos.y, 'N');
                    mundo.getTablero().reemplazarPeonPromocionado(nueva);
                    mundo.getTablero().cancelarPromocion();
                    limpiarSeleccion();
                    mundo.getTablero().cambiarTurno();
                }
            }
        }
        iaPendiente = false;
    }

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
    case MENUPAUSA: texId = ETSIDI::getTexture("imagenes/menupausa.png").id; break;
    case INSTRUCCIONES: texId = ETSIDI::getTexture("imagenes/instrucciones.png").id; break;
    case PEONFINALAZUL: texId = ETSIDI::getTexture("imagenes/peonfinalrojo.png").id; break;
    case PEONFINALROJO: texId = ETSIDI::getTexture("imagenes/peonfinalazul.png").id; break;
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
        // Permitir cambiar de selección si pulsas otra pieza propia
        if (p && p->getColor() == mundo.getTablero().getTurno()) {
            piezaSeleccionada = true;
            casillaSeleccionada = coord;
            casillasPosibles = mundo.getTablero().getMovimientosLegales(coord);
            return;
        }
        if (mundo.getTablero().moverPieza(casillaSeleccionada, coord)) {
            limpiarSeleccion();

            // Empates y promoción igual que antes...

            if (mundo.getTablero().empate()) {
                std::cout << "¡Empate por falta de piezas!" << std::endl;
                mundo.getTablero().setPartidaFinalizada(true);
                estado = TABLAS;
                ETSIDI::play("sonidos/victoria.mp3");
            }
            char turnoActual = mundo.getTablero().getTurno();
            if (mundo.getTablero().ahogado(turnoActual)) {
                std::cout << "¡Empate por rey ahogado!" << std::endl;
                mundo.getTablero().setPartidaFinalizada(true);
                estado = TABLAS;
                ETSIDI::play("sonidos/victoria.mp3");
                return;
            }

            // Si es el turno de la IA, marca pendiente
            if (mundo.get_oponente() == 1 && mundo.getTablero().getTurno() == 'N') {
                iaPendiente = true;
            }

            // Promoción
            if (mundo.getTablero().hayPromocionPendiente()) {
                Vector2D pos = mundo.getTablero().getPeonParaPromocion();
                Pieza* peon = mundo.getTablero().getPiezaEn(pos);
                if (peon && peon->getColor() == 'N' && mundo.get_oponente() == 1) {
                    Pieza* nueva = new Reina(pos.x, pos.y, 'N');
                    mundo.getTablero().reemplazarPeonPromocionado(nueva);
                    mundo.getTablero().cancelarPromocion();
                    limpiarSeleccion();
                    mundo.getTablero().cambiarTurno();
                    return;
                }
                else if (peon && peon->getColor() == 'B') {
                    estado = PEONFINALAZUL;
                    return;
                }
                else if (peon && peon->getColor() == 'N') {
                    estado = PEONFINALROJO;
                    return;
                }
            }
        }
        else {
            piezaSeleccionada = false;
            casillasPosibles.clear();
        }
        
    }

}

