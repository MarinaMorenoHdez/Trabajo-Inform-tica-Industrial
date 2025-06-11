#include <iostream>
#include "tablero.h"
#include "peon.h"
#include "control.h"

//Tablero tablero;
control juego;
void OnDraw(void); 
void OnTimer(int value); 
void OnKeyboardDown(unsigned char key, int x, int y); 
void OnMouseClick(int button, int state, int x, int y); 

int main (int argc, char* argv[])
    Tablero tab;
    tab.inicializar();
    tab.mostrar();

    int x1, y1, x2, y2;
    while (true) {
        std::cout << "\nIntroduce las coordenadas de la pieza a mover (x y) o -1 para salir: ";
        std::cin >> x1;
        if (x1 == -1) break;
        std::cin >> y1;
        std::cout << "Introduce las coordenadas de destino (x y): ";
        std::cin >> x2 >> y2;

        if (tab.moverPieza(Vector2D(x1, y1), Vector2D(x2, y2))) {
            std::cout << "Movimiento realizado.\n";
        }
        else {
            std::cout << "Movimiento no válido.\n";
        }
        tab.mostrar();
    }
       //Inicializar el gestor de ventanas GLUT
    //y crear la ventana
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("The BIT-else");
    
    //habilitar luces y definir perspectiva
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(40.0, 800 / 600.0f, 0.1, 150);
    
    //Registrar los callbacks
    glutDisplayFunc(OnDraw);
    glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
    glutKeyboardFunc(OnKeyboardDown);
    glutMouseFunc(OnMouseClick); //Callback del raton
    
    //pasarle el control a GLUT,que llamara a los callbacks
    glutMainLoop();

return 0;
}


void OnDraw(void)
{
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//funciones de dibujo
	juego.dibuja();

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}

void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el código de teclado
	juego.tecla(key);

	glutPostRedisplay();
}

void OnTimer(int value)
{
	// Música de fondo 
	//ETSIDI::play("sonidos/MusicaFondo.wav");

	glutTimerFunc(210000, OnTimer, 0); //25
	glutPostRedisplay();
}

void OnMouseClick(int b, int state, int x, int y)
{

	bool down = (state == GLUT_DOWN);

	int specialKey = glutGetModifiers();
	bool ctrlKey = (specialKey & GLUT_ACTIVE_CTRL) ? true : false;
	bool sKey = specialKey & GLUT_ACTIVE_SHIFT;

	//juego.MouseButton(juego.Get_mundo().get_oponente(), x, y, b, down, sKey, ctrlKey);

	glutPostRedisplay();
}
