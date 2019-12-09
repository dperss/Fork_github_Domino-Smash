#include <GL/glut.h>
#include <iostream>
#include "GlobalVariables.h"
#include "Shoot.h"



void Shoot::Mira()// dispara a bola
{
		x = 10 + 2 * cos(angulo);
		y = 2 + 2 * sin(angulo);

		glLineWidth(3);
		glColor3f(0.0, 0.4, 0.2);
		glPointSize(3.0);
		glBegin(GL_LINES);
		glVertex2f(10, 2);
		glVertex2f(x, y);
		glEnd();
		if (shoot == 1) {

			bola->cx += cos(angulo) / 750 * bola->directionx * velocity;
			bola->cy += sin(angulo) / 750 * bola->directiony * velocity;
	}
}
void Shoot::Hit_box(GLfloat x, GLfloat y) {//deteta o limite do campo de jogo e muda a direçao da bola 
	if (x >= 19 || x <= 1) {
			bola->directionx = -bola->directionx;//inverte a direçao no eixo do x
	}
	if (y >= 19 || y <= 1) {
			bola->directiony = -bola->directiony;//inverte a direçao no eixo do y
	}
}
void Shoot::Hit_box_domino(GLfloat x, GLfloat y, GLfloat cx, GLfloat cy) {//deteta quando a bola bate numa domino 

	if (cx >= x && cx <= x + 1 && cy >= y && cy <= y + 1.4) {
			bola->directionx = -bola->directionx / 2;
			bola->directiony = -bola->directiony / 2;
			velocity *= 0;

	}
}

void Shoot::Hit_box_Caixa_obstaculo(GLfloat x, GLfloat y, GLfloat cx, GLfloat cy) {//deteta quando a bola bate numa Caixa_obstaculo 

	if (cx >= x && cx <= x + 1.4 && cy >= y && cy <= y + 0.8) {//Umas vezes funciona outras não investigar ???
			bola->directionx = -bola->directionx;
			bola->directiony = -bola->directiony;
			velocity *= 2;
	}

}



