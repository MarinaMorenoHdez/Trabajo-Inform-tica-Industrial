#include "caja.h"
#include "pared.h"
#include <stdlib.h>
#include "freeglut.h"
#include "ETSIDI.h"
#include <iostream> // Para mensajes de depuración

caja::caja()
{
    // Configuración inicial de las paredes, suelo y techo
    suelo.setColor(0, 100, 0);
    suelo.setPos(-10.0f, 0, 10.0f, 0);
    techo.setColor(0, 100, 0);
    techo.setPos(-10.0f, 15.0f, 10.0f, 15.0);
    pared_dcha.setColor(0, 150, 0);
    pared_dcha.setPos(-10.0f, 0, -10.0f, 15.0f);
    pared_izq.setColor(0, 150, 0);
    pared_izq.setPos(10.0f, 0, 10.0f, 15.0);
}

void caja::dibuja()
{
    // Dibujar suelo, techo y paredes
    std::cout << "Dibujando suelo..." << std::endl;
    suelo.dibuja();
    std::cout << "Dibujando techo..." << std::endl;
    techo.dibuja();
    std::cout << "Dibujando pared izquierda..." << std::endl;
    pared_izq.dibuja();
    std::cout << "Dibujando pared derecha..." << std::endl;
    pared_dcha.dibuja();

    // Dibujo del fondo con textura
    std::cout << "Cargando textura del fondo..." << std::endl;
    auto texture = ETSIDI::getTexture("imagenes/fondo.png");
    if (texture.id == 0) {
        std::cerr << "Error: No se pudo cargar la textura 'imagenes/fondo.png'" << std::endl;
        return; // Salir si no se puede cargar la textura
    }

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture.id);
    glDisable(GL_LIGHTING);

    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1); // Color blanco para la textura
    glTexCoord2d(0, 1); glVertex2d(-10, 0);
    glTexCoord2d(1, 1); glVertex2d(10, 0);
    glTexCoord2d(1, 0); glVertex2d(10, 15);
    glTexCoord2d(0, 0); glVertex2d(-10, 15);
    glEnd();

    glEnable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);

    std::cout << "Fondo dibujado correctamente." << std::endl;
}

caja::~caja()
{
    // Destructor: liberar recursos si es necesario
    std::cout << "Destruyendo la caja..." << std::endl;
    // Si en el futuro se añaden recursos dinámicos, liberarlos aquí
}
