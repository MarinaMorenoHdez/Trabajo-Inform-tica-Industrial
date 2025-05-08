// Probando cambios en git clase Andrei
#include "freeglut.h"
#include <iostream>

float cameraX = 15.0f;
float cameraY = 30.0f;
float cameraZ = 15.0f;
float cameraSpeed = 1.0f;

float pawnX = 0.0f;
float pawnZ = 0.0f;
float squareSize = 2.0f;

void OnDraw(void);
void OnTimer(int value);
void OnKeyboardDown(unsigned char key, int x, int y);
void OnSpecialKeyDown(int key, int x, int y);
void drawPawn();

int main(int argc, char* argv[])
{
	//Inicializar el gestor de ventanas FREEGLUT y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//25 ms
	glutKeyboardFunc(OnKeyboardDown);
	glutSpecialFunc(OnSpecialKeyDown);

	//pasarle el control a FREEGLUT,que llamara a los callbacks
	glutMainLoop();

	return 0;
}

void OnDraw(void) {
	// Borrado de la pantalla
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(cameraX, cameraY, cameraZ, // Posición del ojo
		0.0, 0, 0,  // Hacia qué punto mira (0,0,0)
		0.0, 1.0, 0.0); // Definir hacia arriba (eje Y)

	// Dibujar el tablero de ajedrez
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if ((i + j) % 2 == 0)
				glColor3f(1.0f, 1.0f, 1.0f); // Casilla blanca
			else
				glColor3f(0.0f, 0.0f, 0.0f); // Casilla negra

			glPushMatrix();
			glTranslatef(i * squareSize - 7 * squareSize / 2, 0, j * squareSize - 7 * squareSize / 2);
			glScalef(squareSize, 0.1f, squareSize); // Escalar para hacer las casillas más delgadas
			glutSolidCube(1.0f);
			glPopMatrix();
		}
	}

	// Dibujar un peón en la posición (4,4) del tablero
	glPushMatrix();
	glTranslatef(0, 0.1, 0); // Ajustar altura
	glTranslatef(4 * squareSize - 7 * squareSize / 2, 0.15, 4 * squareSize - 7 * squareSize / 2); // Posición en el tablero
	glColor3f(0.8f, 0.6f, 0.4f); // Color marrón claro

	// Base del peón
	glutSolidSphere(0.2, 20, 20);

	// Cuerpo del peón
	glTranslatef(0, 0.3, 0);
	glutSolidSphere(0.25, 20, 20);

	// Cabeza del peón
	glTranslatef(0, 0.25, 0);
	glutSolidSphere(0.15, 20, 20);

	glPopMatrix();

	// Dibujar la Reina (Manzana) en la casilla (3,3)
	glPushMatrix();
	glTranslatef(3 * squareSize - 7 * squareSize / 2, 0.3, 3 * squareSize - 7 * squareSize / 2); // Nueva posición (3,3)

	// Cuerpo de la manzana (Reina)
	glColor3f(1.0f, 0.0f, 0.0f); // Rojo
	glutSolidSphere(0.5, 30, 30); // Manzana

	//  Hoja de la manzana
	glPushMatrix();
	glColor3f(0.0f, 0.8f, 0.0f); // Verde
	glTranslatef(0.2, 0.6, 0.0);
	glRotatef(45, 0, 0, 1);
	glScalef(0.2, 0.05, 0.1);
	glutSolidSphere(1.0, 20, 20); // Hoja
	glPopMatrix();

	//  Tallo de la manzana
	glPushMatrix();
	glColor3f(0.5f, 0.25f, 0.0f); // Marrón
	glTranslatef(0.0, 0.55, 0.0);
	glRotatef(-90, 1, 0, 0);
	GLUquadric* quad = gluNewQuadric();
	gluCylinder(quad, 0.05, 0.05, 0.2, 10, 10); // Tallo
	gluDeleteQuadric(quad);
	glPopMatrix();


	glPopMatrix(); // Fin de la Reina

	// Al final, cambiar el buffer (redibujar) no borrar esta línea ni poner nada después
	glutSwapBuffers();
}



void OnTimer(int value)
{
}

void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	switch (key)
	{
	case 'w':
		cameraY += cameraSpeed;
		break;
	case 's':
		cameraY -= cameraSpeed;
		break;
	case 'a':
		cameraX -= cameraSpeed;
		break;
	case 'd':
		cameraX += cameraSpeed;
		break;
	}

	glutPostRedisplay();
}

void OnSpecialKeyDown(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		pawnZ -= squareSize;
		break;
	case GLUT_KEY_DOWN:
		pawnZ += squareSize;
		break;
	case GLUT_KEY_LEFT:
		pawnX -= squareSize;
		break;
	case GLUT_KEY_RIGHT:
		pawnX += squareSize;
		break;
	}

	// Limitar el movimiento del peón dentro del tablero
	if (pawnX < -7 * squareSize / 2) pawnX = -7 * squareSize / 2;
	if (pawnX > 7 * squareSize / 2) pawnX = 7 * squareSize / 2;
	if (pawnZ < -7 * squareSize / 2) pawnZ = -7 * squareSize / 2;
	if (pawnZ > 7 * squareSize / 2) pawnZ = 7 * squareSize / 2;

	// Calcular la posición del peón en el tablero
	int boardX = (pawnX + 7 * squareSize / 2) / squareSize;
	int boardZ = (pawnZ + 7 * squareSize / 2) / squareSize;

	std::cout << "Peón en la casilla: (" << boardX << ", " << boardZ << ")" << std::endl;

	glutPostRedisplay();
}

void drawPawn()
{
	glColor3f(0.8f, 0.5f, 0.2f); // Color marrón claro
	glutSolidSphere(0.5, 20, 20); // Dibujar una esfera para representar una patata
}
