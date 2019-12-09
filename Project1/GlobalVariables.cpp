#include "GlobalVariables.h"

GLfloat windowHeight = 500, windowWidth = 500;
GLint pontos = 0, velocity = 0;
bool handlemouse = 0;
GLint nivel = 0;
Circulo *bola = new Circulo;
GLint maxpontos;

void escreve(int width, int height, float x, float y, void* font, string texto, int r, int g, int b) {//largura, altura e posição da caixa de texto
	GLfloat xxx = (GLfloat)x;
	GLfloat yyy = (GLfloat)y;
	glColor3f(r, g, b);
	glRasterPos2f(xxx, yyy);
	for (int i = 0; i < texto.length(); i++) {
		glutBitmapCharacter(font, texto.at(i));
	}
}
