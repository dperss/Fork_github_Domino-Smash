#include "Menu_caixa.h"
#include "GlobalVariables.h"

Menu_caixa::Menu_caixa() {}

Menu_caixa::Menu_caixa(GLfloat menux, GLfloat menuy, string s) {
	this->menux = menux;
	this->menuy = menuy;
	this->s = s;
}
void Menu_caixa::draw_Menu_caixa() {
	glColor3f(1, 0, 0);
	glBegin(GL_QUADS);
	glVertex2f(menux, menuy + 2);
	glVertex2f(menux, menuy);
	glVertex2f(menux + 4, menuy);
	glVertex2f(menux + 4, menuy + 2);
	glEnd();
	escreve(10, 10, menux + 0.5, menuy + 1, GLUT_BITMAP_TIMES_ROMAN_24, s, 1, 1, 0);
}