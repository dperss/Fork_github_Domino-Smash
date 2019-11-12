#include<stdio.h>
#include <GL/glut.h>
#include<math.h> 
#define pi 3.142857 

GLfloat windowHeight = 500, windowWidth = 500 ;

class Caixadojogo {
public:
	GLfloat xx, xy, yy, yx;

	Caixadojogo() {
		xx = 1;
		yy = 19;
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
	
	Domino() {

	}

	Domino(GLfloat x, GLfloat y) {
		this->x = x;
		this->y = y;
	}

	void DrawDomino() {

			glColor3f(R, G, B);
			glBegin(GL_QUADS);
			glVertex2f(x, y);
			glVertex2f(x + 1, y);
			glVertex2f(x + 1, y + 1.4);
			glVertex2f(x, y + 1.4);
			glEnd();
				
	}

	void Domino_Compare(GLfloat cx, GLfloat cy) {
		
		if ( (cx>=x && cx<=x+1) && (cy>=y && cy<=y+1.4)) {//Compara se a bola bate no domino, ou se o domino bate no domino
			
			y += 2;
			R = 1;
			G = 0;			
		}
	}



};

Domino a[5] =
{
Domino(5,4),
Domino(5, 5.5),
Domino(8, 7),
Domino(10, 8.5 )
};


class Circulo {

public:
	GLfloat cx = 10, cy = 2, r = 0.5;
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
	GLfloat Veloctity = 3;

	void Mira()// dispara a bola
	{
		x = 10 + 2 * cos(angulo);
		y = 2  + 2 * sin(angulo);

		glLineWidth(3);
		glColor3f(0.0, 0.4, 0.2);
		glPointSize(3.0);
		glBegin(GL_LINES);
		glVertex2f(10, 2);
		glVertex2f(x, y);
		glEnd();
		if (shoot == 1) {

			bola.cx += cos(angulo) / 750 * directionx* Veloctity;
			bola.cy += sin(angulo) / 750 * directiony* Veloctity;
		}
	}
	void Hit_box(GLfloat x, GLfloat y) {//deteta o limite do campo de jogo e muda a direçao da bola 
		if (x >= 19 || x <= 1) {
			directionx = -directionx;//inverte a direçao no eixo do x
		}
		if (y >= 19 || y <= 1) {
			directiony = -directiony;//inverte a direçao no eixo do y
		}
	}
	void Hit_box_domino(GLfloat x, GLfloat y,GLfloat cx, GLfloat cy) {//deteta quando a bola bate numa domino 

		if ( cx>=x && cx<=x+1 && cy>=y && cy<=y+1.4) {
			directionx = -directionx/2;
			directiony = -directiony/2;
	
		}
	}
	void Hit_box_Caixa_obstaculo(GLfloat x, GLfloat y, GLfloat cx, GLfloat cy) {//deteta quando a bola bate numa Caixa_obstaculo 

		if (cx >= x && cx <= x + 1.4 && cy >= y && cy <= y + 0.8) {//Umas vezes funciona outras não investigar ???
			directionx = -directionx ;
			directiony = -directiony ;
			Veloctity *= 2;
		}
		
	}


};

Shoot mira;

class Caixa_obstaculo {
public:
	GLfloat x;
	GLfloat y;
	GLint R = 0, G = 1, B = 0;
	GLint hit = 1;
	GLfloat directionx = 1, directiony = 1;
	GLfloat Velocity = 4;

	Caixa_obstaculo() {

	}
	Caixa_obstaculo(GLfloat x, GLfloat y) {
		this->x = x;
		this->y = y;
	}

	void Drawcaixa_obstaculo() {

		glColor3f(R, G, B);
		glBegin(GL_QUADS);
		glVertex2f(x, y);
		glVertex2f(x + 1.4, y);
		glVertex2f(x + 1.4, y + 0.8);
		glVertex2f(x, y + 0.8);
		glEnd();
		x += cos(90) / 750 * directionx* Velocity;
		//y += sin(0) / 750 * directiony;
		if (x >= 19 || x <= 1) {
			directionx = -directionx;//inverte a direçao no eixo do x
		}
		/*if (y >= 1.99 || y <= -1.99) {
			directiony = -directiony;//inverte a direçao no eixo do y
		}*/
	}
	
		

};

Caixa_obstaculo box(10,3);




void display(void)
{	
	
	
	glClearColor(0.0, 0.0, 0.0, 0.0); // define a cor do fundo da janela (RGBA)
	glClear(GL_COLOR_BUFFER_BIT); // Aplica a cor atual no fundo
	
	glLoadIdentity();

	glColor3f(0, 100, 0);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 20, 0, 20);
	
	caixa.DrawCaixa();
	mira.Hit_box_Caixa_obstaculo(box.x, box.y, bola.cx, bola.cy);	//AS hitboxes tenhem que aparecer sempre depois do draw senão da erros
	mira.Hit_box(bola.cx, bola.cy);
	mira.Mira();

	for (int i = 0; i < 4; i++) {
		mira.Hit_box_domino(a[i].x, a[i].y, bola.cx, bola.cy);
		a[i].DrawDomino();
		a[i].Domino_Compare(a[i-1].x, a[i - 1].y);
		a[i].Domino_Compare(bola.cx, bola.cy);		
	}
	
	box.Drawcaixa_obstaculo();
	

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
	//gluOrtho2D(-10, 10, -10, 10);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

 void HandleKeyboard(unsigned char key, int x, int y) {

	switch (key)
	{
	
	case 32://space bar
		mira.shoot = 1;
		break;
	case 27://fechar o jogo
		exit(1);
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
		if (mira.shoot == 0) {
			mira.angulo += 0.1;
		}
	}
	if (key == GLUT_KEY_RIGHT) {
		//bola.cx += 0.1;
		if (mira.shoot == 0) {
			mira.angulo -= 0.1;
		}
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