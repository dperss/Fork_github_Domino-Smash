#include <GL/glut.h>
#include "Circulo.h"
#include <string>

using namespace std;

#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H




extern GLfloat windowHeight, windowWidth;
extern GLint pontos, velocity;
extern bool handlemouse;
extern GLint nivel;
extern Circulo *bola;
extern GLint maxpontos;

void escreve(int width, int height, float x, float y, void* font, string texto, int r, int g, int b);

#endif
