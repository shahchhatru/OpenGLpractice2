#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include<GL\GL.h>
#include <iostream>
/*

*/
void Draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(2);
	glBegin(GL_POLYGON);
	glVertex2f(-0.5, -0.5);
	glVertex2f(0.5, -0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(-0.5, 0.5);
	glVertex2f(-0.7, -0.7);
	glEnd();
	glFlush();
}

int main(int argC, char* argV[]) {
	//initialize the opengl library
	glutInit(&argC,argV);
	glutInitWindowPosition(100, 100);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(600, 600);
	
	glutCreateWindow("Basic OpenGl program");
	glClearColor(1.0, 0.0, 0.0, 1.0);
	//glutDisplayFunc takes 0 argument function and returns void
	glColor3f(1, 1, 0);
	glutDisplayFunc(Draw);
	glutMainLoop();

	return 0;
}