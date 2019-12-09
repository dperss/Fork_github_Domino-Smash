#include "Triangulo_obstaculo.h"

	GLfloat x, y, angle = 0;


	Triangulo_obstaculo::Triangulo_obstaculo() {

	}
	Triangulo_obstaculo::Triangulo_obstaculo(GLfloat x, GLfloat y) {
		this->x = x;
		this->y = y;
	}
	void Triangulo_obstaculo::draw_Triangulo_obstaculo() {


		glColor3f(1, 0, 0);
		glBegin(GL_POLYGON);
		glVertex2f(x, y);
		glVertex2f(x + 2, y);
		glVertex2f(x + 1, y + 2);
		glEnd();
	}


