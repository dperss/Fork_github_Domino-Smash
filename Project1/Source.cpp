#include <gl/glut.h>

void initialiaze() {
	glClearColor(0.0,0.0,0.0,1.0);//background color
}

void display(void) {
	glClearColor(0,0,1,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 250, 0, 250);
	glColor3f(1.0f, 0.0f, 0.0f);
	glRectf(100.0f, 150.0f, 150.0f, 100.0f);
	glTranslatef(10, 10, 0);
	glColor3f(1.0f, 1.0f, 0.0f);
	glRectf(100.0f, 150.0f, 150.0f, 100.0f);
	glColor3f(0,1,0);
	glRectf(100.0f, 150.0f, 150.0f, 100.0f);
	glFlush();
}

void reshape(int w, int h) {

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Transformations");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	initialiaze();
	glutMainLoop();
}