#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include<GL\GL.h>
#include <iostream>
#include <windows.h>
/*

*/
GLfloat T = 0;
void Spin() {
	T += 0.01;
	Sleep(50);
	if (T > 360) {
		T = 0;
	}
	glutPostRedisplay();
}
void Face(GLfloat A[], GLfloat B[], GLfloat C[], GLfloat D[] ) {
	glBegin(GL_POLYGON);
	glVertex3f(A[0],A[1],A[2]);
	glVertex3fv(B);
	glVertex3fv(C);
	glVertex3fv(D);

	glEnd();
}
void Cube(GLfloat v1[], GLfloat v2[], GLfloat v3[], GLfloat v4[], GLfloat v5[], GLfloat v6[], GLfloat v7[],GLfloat v8[] ) {
	glColor3f(1, 1, 0);
	Face(v1, v2, v3, v4);
	glColor3f(0, 1, 0);
	Face(v5, v6, v7, v8);
	glColor3f(0, 1, 1);
	Face(v1, v4, v8, v5);
	glColor3f(0, 0.5, 0.7);
	Face(v2, v3, v7, v6);
	glColor3f(0.6, 0.6, 1);
	Face(v1, v2, v6, v5);
	glColor3f(0, 0.5, 0.3);
	Face(v4, v3, v7, v8);




	
}
void Draw() {
	GLfloat V[8][3] = {
		{-0.5,0.5,0.5}, 
		{0.5,0.5,0.5},
		{0.5,-0.5,0.5},
		{-0.5,-0.5,0.5},

		{-0.5,0.5,-0.5},
		{0.5,0.5,-0.5},
		{0.5,-0.5,-0.5},
		{-0.5,-0.5,-0.5},

	};
	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
	if (T == 0.0) {
		glRotatef(45, 0, 0, 1);
		glRotatef(30, 1, 0, 0);
	}
	
	glRotatef(T, 1,0  , 0 );
	Cube(V[0], V[1], V[2], V[3], V[4], V[5], V[6], V[7]);
	
	glutSwapBuffers();
}
void INit(int argC, char* argV[]) {
	//initialize the opengl library
	glutInit(&argC, argV);
	glutInitWindowPosition(100, 100);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE|GLUT_DEPTH);
	glutInitWindowSize(600, 600);

	glutCreateWindow("Basic OpenGl program to spin a cube");
	glClearColor(1.0, 0.0, 0.0, 1.0);
	glColor3f(1, 1, 0);
	glEnable(GL_DEPTH_TEST);
}

int main(int argC, char* argV[]) {
	INit(argC, argV);
	//glutDisplayFunc takes 0 argument function and returns void
	
	glutDisplayFunc(Draw);
	glutIdleFunc(Spin);
	glutMainLoop();

	return 0;
}