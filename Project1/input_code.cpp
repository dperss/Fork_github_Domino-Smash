#include <windows.h>
#include <GL/glut.h>

float xf = 20, yf = 20, win = 250;
int view_w, view_h;
float pointx=0, pointy =0;

void RenderScene(void) {
	//Limpar Janela
	glClear(GL_COLOR_BUFFER_BIT);


	glRectf(pointx, pointy, xf, yf);

	glFlush();
	
}

void SetupRC(void) {

	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

}

void ChangeSize(GLsizei w, GLsizei h) {

	glViewport(0, 0, w, h);
	view_w = w;
	view_h = h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();


	glOrtho(-win, win, -win, win, 1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	
}
void HandleKeyboard(unsigned char key, int x, int y) {

		switch (key)
		{
		case 82:
		case 114:
		glColor3f(1.0f, 0.0f, 0.0f);
		break;
		case 71:
		case 103:
		glColor3f(0.0f, 1.0f, 0.0f);
		break;
		}
		glutPostRedisplay();
}
void HandleMouse(int button, int state, int x, int y) {
	if(button==GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) {
			xf = ((2 * win * x) / view_w) - win;
			yf = (((2 * win) * (y - view_h)) / -view_h) - win;
		}

	glutPostRedisplay();
}

void SpecialKeys(int key, int x, int y) {

	if (key == GLUT_KEY_UP) {
		win -= 20;
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-win, win, -win, win, 1.0, -1.0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}
	if (key == GLUT_KEY_DOWN) {
		win += 20;
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-win, win, -win, win, 1.0, -1.0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}
	if (key == GLUT_KEY_LEFT) {
		pointx -= 0.1;
		xf -= 0.1;
	}
	if (key == GLUT_KEY_RIGHT) {
		glTranslatef(10, 0, 0);
	}
	glutPostRedisplay();
}

