#include "Caixa_obstaculo.h"


	Caixa_obstaculo::Caixa_obstaculo() {}
	Caixa_obstaculo::Caixa_obstaculo(GLfloat x, GLfloat y) {
		this->x = x;
		this->y = y;
	}

	void Caixa_obstaculo::Drawcaixa_obstaculo() {

		glColor3f(R, G, B);
		glBegin(GL_QUADS);
		glVertex2f(x, y);
		glVertex2f(x + 1.4, y);
		glVertex2f(x + 1.4, y + 0.8);
		glVertex2f(x, y + 0.8);
		glEnd();
		x += cos(90) / 750 * directionx * velocity;
		//y += sin(0) / 750 * directiony;
		if (x >= 19 || x <= 1) {
			directionx = -directionx;//inverte a direçao no eixo do x
		}
		/*if (y >= 1.99 || y <= -1.99) {
			directiony = -directiony;//inverte a direçao no eixo do y
		}*/
	}

