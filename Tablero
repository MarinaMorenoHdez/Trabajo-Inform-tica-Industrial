#include "freeglut.h"

float cameraX = 15.0f;
float cameraY = 30.0f;
float cameraZ = 15.0f;
float cameraSpeed = 1.0f;

void OnDraw(void);
void OnTimer(int value);
void OnKeyboardDown(unsigned char key, int x, int y);

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

	//pasarle el control a FREEGLUT,que llamara a los callbacks
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
	gluLookAt(cameraX, cameraY, cameraZ, // posicion del ojo
		0.0, 0, 0, // hacia que punto mira (0,0,0) 
		0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)

	// código de dibujo

	//Dibujar el tablero de ajedrez
	float size = 2.0f; // Tamaño de cada casilla
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if ((i + j) % 2 == 0)
				glColor3f(1.0f, 1.0f, 1.0f); // Casilla blanca
			else
				glColor3f(0.0f, 0.0f, 0.0f); // Casilla negra

			glPushMatrix();
			glTranslatef(i * size - 7 * size / 2, 0, j * size - 7 * size / 2);
			glScalef(size, 0.1f, size); // Escalar para hacer las casillas más delgadas
			glutSolidCube(1.0f);
			glPopMatrix();
		}
	}

	// Dibujar una zanhaoria como si fuese un alfil

	//Al final, cambiar el buffer (redibujar) no borrar esta linea ni poner nada despues
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
