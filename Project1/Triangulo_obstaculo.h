#include <GL/glut.h>

class Triangulo_obstaculo {
public:
	GLfloat x, y, angle = 0;


	Triangulo_obstaculo();

	Triangulo_obstaculo(GLfloat x, GLfloat y);
	void draw_Triangulo_obstaculo();


};