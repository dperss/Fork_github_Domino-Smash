#include <GL/glut.h>

class Shoot {

public:
	GLfloat angulo = 0;
	GLint shoot = 0;
	GLfloat x, y;
	GLfloat directionx = 1;
	GLfloat directiony = 1;


	void Mira();// dispara a bola
	void Hit_box(GLfloat x, GLfloat y);
	void Hit_box_domino(GLfloat x, GLfloat y, GLfloat cx, GLfloat cy);
	void Hit_box_Caixa_obstaculo(GLfloat x, GLfloat y, GLfloat cx, GLfloat cy);

};