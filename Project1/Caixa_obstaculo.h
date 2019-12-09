#include <GL/glut.h>
#include <iostream>

class Caixa_obstaculo {
public:

	GLfloat x;
	GLfloat y;
	GLint R = 0, G = 1, B = 0;
	GLint hit = 1;
	GLfloat directionx = 1, directiony = 1;
	GLfloat velocity = 30;

	Caixa_obstaculo();
	Caixa_obstaculo(GLfloat x, GLfloat y);

	void Drawcaixa_obstaculo();



};