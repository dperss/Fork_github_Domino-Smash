#include "Caixadojogo.h"

	void Caixadojogo::DrawCaixa() {
		glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_LINE_LOOP);
		glVertex2f(xx, xx);
		glVertex2f(xx, yy);
		glVertex2f(yy, yy);
		glVertex2f(yy, xx);
		glEnd();
	}
	GLfloat Caixadojogo::getxx() {
		return xx;
	}
	GLfloat Caixadojogo::getyy() {
		return yy;
	}

	GLfloat Caixadojogo::xx = 1;
	GLfloat Caixadojogo::yy = 19;
