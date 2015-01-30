/**
 * Robert Timm
 * Assignment #1 CSCE 441-500
 */

#include <stdio.h>
#include <stdlib.h>

#if defined(__APPLE__)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

int window;

GLdouble width, height;

// the number of points in a hexagon
#define TOTAL_HEX_POINTS 12

// all the points for our hexagon
int hexPoints[TOTAL_HEX_POINTS][2];

// all the colors for the sides of our hexagon
float hexColors[6][3];

/**
 * Init the window and all the shapes for this application
 */
void initWindowAndShapes(void) {

	// define the width and height of the window 2:1 ratio
	width = 800.0;
	height = 400.0;

	// define the points for the hexagon
	// clockwise starting from the top left
	hexPoints[0][0] = (int) 300;
	hexPoints[0][1] = (int) 390;
	hexPoints[1][0] = (int) 500;
	hexPoints[1][1] = (int) 390;

	hexPoints[2][0] = (int) 500;
	hexPoints[2][1] = (int) 390;
	hexPoints[3][0] = (int) 600;
	hexPoints[3][1] = (int) 217;

	hexPoints[4][0] = (int) 600;
	hexPoints[4][1] = (int) 217;
	hexPoints[5][0] = (int) 500;
	hexPoints[5][1] = (int) 44;

	hexPoints[6][0] = (int) 300;
	hexPoints[6][1] = (int) 44;
	hexPoints[7][0] = (int) 500;
	hexPoints[7][1] = (int) 44;

	hexPoints[8][0] = (int) 300;
	hexPoints[8][1] = (int) 44;
	hexPoints[9][0] = (int) 200;
	hexPoints[9][1] = (int) 217;

	hexPoints[10][0] = (int) 200;
	hexPoints[10][1] = (int) 217;
	hexPoints[11][0] = (int) 300;
	hexPoints[11][1] = (int) 390;

	// define all the colors for our hexagon
	hexColors[0][0] = 1.0;
	hexColors[0][1] = 1.0;
	hexColors[0][2] = 1.0;

	hexColors[1][0] = 0.0;
	hexColors[1][1] = 1.0;
	hexColors[1][2] = 0.0;

	hexColors[2][0] = 0.85;
	hexColors[2][1] = 0.48;
	hexColors[2][2] = 0.98;

	hexColors[3][0] = 1.0;
	hexColors[3][1] = 0.47;
	hexColors[3][2] = 0.0;

	hexColors[4][0] = 0.53;
	hexColors[4][1] = 0.33;
	hexColors[4][2] = 0.16;

	hexColors[5][0] = 1.0;
	hexColors[5][1] = 0.96;
	hexColors[5][2] = 0.0;

	return;
}

/**
 * Callback that is registered to GLUT to handle all
 *  keyboard events for this program
 */
void keyboardCallback(unsigned char key, int x, int y) {
	switch ((char) key) {
	case 'q':
	case 27: // esc key
		glutDestroyWindow(window);
		exit(0);
	default:
		break;
	}
	return;
}

/**
 * Draw function for all the onscreen components
 */
void display(void) {

	// set clear color to black and clear
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// draw the hexagon
	glBegin(GL_LINES);
	for (int i = 0; i < TOTAL_HEX_POINTS/2; ++i)
	{
		glColor4f(hexColors[i][0], hexColors[i][1], hexColors[i][2], 1.0f);
		glVertex2iv((GLint *) hexPoints[i*2]);
		glVertex2iv((GLint *) hexPoints[i*2+1]);
	}
	glEnd();
	glFlush();

	return;
}

int main(int argc, char *argv[]) {

	glutInit(&argc, argv);

	initWindowAndShapes();

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	glutInitWindowSize((int) 800, (int) 400);

	window = glutCreateWindow("Robert Timm - Assignment 1");

	glOrtho(0.0, width, 0.0, height, -1.f, 1.f);

	// callback for keyboard events (quit)
	glutKeyboardFunc(keyboardCallback);

	// callback for drawing
	glutDisplayFunc(display);

	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(3.0);

	glutMainLoop();

	exit(0);
}
