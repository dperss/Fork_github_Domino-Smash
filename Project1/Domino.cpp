#include "Domino.h"
#include "GlobalVariables.h"


	Domino::Domino() {}
	Domino::Domino(GLfloat x, GLfloat y) {
		this->x = x;
		this->y = y;
	}


	void Domino::DrawDomino() {

		glColor3f(r, g, b);
		glBegin(GL_QUADS);
		glVertex2f(x, y);
		glVertex2f(x + 1, y);
		glVertex2f(x + 1, y + 1.4);
		glVertex2f(x, y + 1.4);
		glEnd();

	}

	void Domino::Domino_Compare(Domino *outro) {
		if (r != 1 || ja_deitou_abaixo == 1 || (x==outro->x && y==outro->y))
			return;
		if ((x+0.5 >= outro->x && x+0.5 <= outro->x + 1) && (y+0.7 >= outro->y && y+0.7 <= outro->y + 1.4)) {
			pontos++;
			if (bola->directiony==1) {
				outro->y += 2;
			}
			if (bola->directiony==-1) {
				outro->y -= 2;
			}
			outro->r = 1;
			outro->g = 0;
			
			ja_deitou_abaixo = 1;
		}


		
		}
