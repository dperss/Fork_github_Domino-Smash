#include <GL/glut.h>

class Domino {
public:
	GLfloat x, y;
	GLint r = 0, g = 1, b = 0;//color
	bool ja_deitou_abaixo = 0;

	Domino();
	Domino(GLfloat x, GLfloat y);


	void DrawDomino();

	void Domino_Compare(Domino *outro);
};