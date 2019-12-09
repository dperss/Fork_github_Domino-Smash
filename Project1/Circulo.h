#include <GL/glut.h>

class Circulo {
public:

	GLfloat cx = 10, cy = 2, r = 0.5;
	GLint num_segments = 124;
	GLfloat directionx = 1;
	GLfloat directiony = 1;

	void DrawCircle();

};