#include<GL/glut.h>

float x_position = -10;
int state = 1;

void display() {
	glClear(GL_COLOR_BUFFER_BIT);//clean the frame buffer
	glLoadIdentity();//resets all the transformations that were in stack
	//draw
	glBegin(GL_POLYGON);
	glVertex2f(x_position,1.0);
	glVertex2f(x_position, -1.0);
	glVertex2f(x_position + 2, -1.0);
	glVertex2f(x_position+2, 1.0);
	glEnd();

	glutSwapBuffers();//é desenhado o frame no back buffer e o back buffer é trocado
	//para front buffer e é mostrado, o front passa para back daí o swapbuffers
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);//para defenir o referencial e tudo usar este matrixmode
	glLoadIdentity();
	gluOrtho2D(-10,10,-10,10);
	glMatrixMode(GL_MODELVIEW);//para começar a desenhar
}

void init() {
	glClearColor(0.0,0.0,0.0,1.0);
}
void timer(int) {
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timer, 0);
	switch (state) {
	case 1:
		if (x_position < 8)
			x_position += 0.15;
		else 
			state = -1;
		break;
	case -1:
		if (x_position > -10)
			x_position -= 0.15;
		else
			state = 1;
		break;
	}
}

int main(int argc, char** argv) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(200,100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("window 1");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(0, timer, 0);
	glutMainLoop();
}