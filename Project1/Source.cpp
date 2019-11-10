#include<stdio.h>
#include <GL/glut.h>
#include<math.h> 
#define pi 3.142857 

GLfloat windowHeight = 500, windowWidth = 500 ;

class Caixadojogo {
public:
	GLfloat xx, xy, yy, yx;

	Caixadojogo() {
		xx = 0;
		yy = 1.99;
	}
	void DrawCaixa() {
		glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_LINE_LOOP);
		glVertex2f(xx, xx);
		glVertex2f(xx, yy);
		glVertex2f(yy, yy);
		glVertex2f(yy, xx);
		glEnd();
	}

};
Caixadojogo caixa;

class Domino
{
	public:

	GLfloat x;
	GLfloat y;
	GLint R = 0, G = 1, B = 0;
	GLint hit = 0;
	

	Domino(GLfloat x, GLfloat y) {
		this->x = x;
		this->y = y;
	}

	void DrawDomino() {

			glColor3f(R, G, B);
			glBegin(GL_QUADS);
			glVertex2f(x, y);
			glVertex2f(x + 0.2, y);
			glVertex2f(x + 0.2, y + 0.3);
			glVertex2f(x, y + 0.3);
			glEnd();
				
	}

	void Domino_Compare(GLfloat cx, GLfloat cy) {
		
		if ( (cx>=x && cx<=x+0.2) && (cy>=y && cy<=y+0.3)) {//Compara se a bola bate no domino, ou se o domino bate no domino
			
			y += 0.4;
			R = 1;
			G = 0;			
		}
	}



};

Domino domino(0.1,0.1);
Domino a(0.1, 0.5);

class Circulo {

public:
	GLfloat cx = 0, cy = 0, r = 0.08;
	GLint num_segments=124;

	/*
	http://slabode.exofire.net/circle_draw.shtml
	*/
	void DrawCircle()
	{
		float theta = 2 * pi / float(num_segments);
		float tangetial_factor = tanf(theta);//calculate the tangential factor 

		float radial_factor = cosf(theta);//calculate the radial factor 

		float x = r;//we start at angle = 0 

		float y = 0;

		glBegin(GL_POLYGON);
		for (int ii = 0; ii < num_segments; ii++)
		{
			glColor3f(0, 1, 0);
			glVertex2f(x + cx, y + cy);//output vertex 

			//calculate the tangential vector 
			//remember, the radial vector is (x, y) 
			//to get the tangential vector we flip those coordinates and negate one of them 

			float tx = -y;
			float ty = x;

			//add the tangential vector 

			x += tx * tangetial_factor;
			y += ty * tangetial_factor;

			//correct using the radial factor 

			x *= radial_factor;
			y *= radial_factor;
		}
		glEnd();
	}

};

Circulo bola;

class Shoot {

	public:
	GLfloat angulo=0;
	GLint shoot = 0;
	GLfloat x, y;
	GLfloat directionx = 1;
	GLfloat directiony = 1;

	void Mira()// dispara a bola
	{
		x = 0 + 0.5 * cos(angulo);
		y = 0 + 0.5 * sin(angulo);

		glLineWidth(1.5);
		glColor3f(0.0, 0.4, 0.2);
		glPointSize(3.0);
		glBegin(GL_LINES);
		glVertex2f(0, 0);
		glVertex2f(x, y);
		glEnd();
		if (shoot == 1) {

			bola.cx += cos(angulo) / 750 * directionx;
			bola.cy += sin(angulo) / 750 * directiony;
		}
	}
	void Hit_box(GLfloat x, GLfloat y) {//deteta o limite do campo de jogo e muda a direçao da bola 
		if (x >= 1.99 || x <= -1.99) {
			directionx = -directionx;
		}
		if (y >= 1.99 || y <= -1.99) {
			directiony = -directiony;
		}

	}


};

Shoot mira;




void display(void)
{	
	
	
	glClearColor(0.0, 0.0, 0.0, 0.0); // define a cor do fundo da janela (RGBA)
	glClear(GL_COLOR_BUFFER_BIT); // Aplica a cor atual no fundo
	glLoadIdentity();

	glColor3f(0, 100, 0);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-2, 2, -2, 2);
	
	caixa.DrawCaixa();
	
	mira.Mira();
	mira.Hit_box(bola.cx, bola.cy);

	/*domino.DrawDomino();
	domino.Domino_Compare(bola.cx, bola.cy);
	a.DrawDomino();
	a.Domino_Compare(bola.cx, bola.cy);
	a.Domino_Compare(domino.x, domino.y);
	*/

	bola.DrawCircle();
	


	glutPostRedisplay();
	glFlush(); //despeja imgs da memoria para o ecran
}



void SetupRC(void)
{
	// Set clear color to blue
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

void ChangeSize(GLsizei w, GLsizei h)
{
	// Prevent a divide by zero
	if (h == 0)
		h = 1;

	// Set Viewport to window dimensions
	glViewport(0, 0, w, h);

	// Reset coordinate system
	glMatrixMode(GL_PROJECTION);
	

	// Keep the square square, this time, save calculated
	// width and height for later use
	if (w <= h) {
		windowHeight = 250.0f * h / w;
		windowWidth = 250.0f;
	}
	else {
		windowWidth = 250.0f * w / h;
		windowHeight = 250.0f;
	}

	// Set the clipping volume
	glOrtho(0.0f, windowWidth, 0.0f, windowHeight, 1.0f, -1.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}




 void HandleKeyboard(unsigned char key, int x, int y) {

	switch (key)
	{
	
	case 45://space bar
		mira.shoot = 1;
		break;
	
	}
	glutPostRedisplay();
}
 /*
void HandleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) {
			xf = ((2 * win * x) / view_w) - win;
			yf = (((2 * win) * (y - view_h)) / -view_h) - win;
		}

	glutPostRedisplay();
}
*/
void SpecialKeys(int key, int x, int y) {


	if (key == GLUT_KEY_UP) {
		//bola.cy += 0.1;
		mira.shoot = 1;
	}
	if (key == GLUT_KEY_DOWN) {
		//bola.cy -= 0.1;
		mira.shoot = 0;
	}
	if (key == GLUT_KEY_LEFT) {
		//bola.cx -= 0.1;
		
		mira.angulo += 0.1;
	}
	if (key == GLUT_KEY_RIGHT) {
		//bola.cx += 0.1;
		mira.angulo -= 0.1;
		
	}
	glutPostRedisplay();
}


void main(int argc, char** argv)
{
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(windowHeight, windowWidth); 
	glutCreateWindow("Domino Smash");
	glutDisplayFunc(display);
	glutReshapeFunc(ChangeSize);	
	glutKeyboardFunc(HandleKeyboard);  
	glutSpecialFunc(SpecialKeys); 
	//glutMouseFunc(HandleMouse);
	SetupRC();
	glutMainLoop();
}


















