#include<stdio.h>
#include <GL/glut.h>
#include<math.h> 
#include <string>

#define pi 3.14159265f


using namespace std;

GLfloat windowHeight = 500, windowWidth = 500 ;
GLint nivel=0,pontos=0;

GLint Veloctity = 0;

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
	GLint hit = 0, direcao;//1-para cima 2-para baixo 3- para a direita 4- para a esquerda

	Domino() {

	}

	Domino(GLfloat x, GLfloat y, GLint direcao) {
		this->x = x;
		this->y = y;
		this->direcao = direcao;
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

		if ((cx >= x && cx <= x + 1) && (cy >= y && cy <= y+ 1.4)) {//Compara se a bola bate no domino, ou se o domino bate no domino
			pontos++;
			if (direcao == 1) {
				y += 2;
				R = 1;
				G = 0;
			}
			else {
				if (direcao == 4) {
					x -= 2;
					R = 1;
					G = 0;
				}
				else {
					if (direcao == 3) {
						x += 2;
						R = 1;
						G = 0;
					}
					else {
						if (direcao == 2) {
							y -= 2;
							R = 1;
							G = 0;
						}
					}
				}
			}
		}
	}
};

Domino a[11] =
{
Domino(5,4,1),
Domino(5, 5.5,1),
Domino(5, 7,1),
Domino(5, 8.5,1),
Domino(5, 10,3),
Domino(6.1,10,3),
Domino(7.2,10,3),
Domino(8.3, 10,3),
Domino(9.4,10,3	),
Domino(10.5,10,2),
Domino(10.5,8.5,2),
};

Domino b[12] =
{
Domino(16,7,4),
Domino(14.9,7,4),
Domino(13.8, 7,4),
Domino(12.7, 7,4),
Domino(11.6, 7,4),
Domino(10.5,7,4),
Domino(9.4,7,1),
Domino(9.4,9,1),
Domino(9.4,11,1),
Domino(9.4,13,4),
Domino(8.3,13,4),
Domino(7.2,13,4),
};

Domino c[12] =
{
Domino(4,5,1),
Domino(4.5, 7,1),
Domino(5, 9,1),
Domino(5.5, 11,1),
Domino(6.7, 11,3),
Domino(7.9,11,3),
Domino(9,11,3),
Domino(10.2, 11,3),
Domino(11.4, 11,3),
Domino(12.5, 11,3),
Domino(13,9,1),
Domino(13.5, 7,1),
};

Domino d[6] =
{
Domino(13,7,1),
Domino(12.5,8.5,1),
Domino(12,10,1),
Domino(11.5,11.5,1),
Domino(10.3, 11.7,3),
Domino(9, 12,3),
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
			Veloctity = 0;
	
		}
	}

	void Hit_box_Caixa_obstaculo(GLfloat x, GLfloat y, GLfloat cx, GLfloat cy) {//deteta quando a bola bate numa Caixa_obstaculo 

		if (cx >= x && cx <= x + 1.4 && cy >= y && cy <= y + 0.8) {//Umas vezes funciona outras não investigar ???
			directionx = -directionx ;
			directiony = -directiony ;
			Veloctity *= 2;
		}
		
	}

	void Hitbox_triangulo(GLfloat x, GLfloat y, GLfloat cx, GLfloat cy) {
		if (cx >= x && cx <= x + 2 && cy >= y && cy <= y + 1) {
			directionx = -directionx / 2;
			directiony = -directiony / 2;
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
Caixa_obstaculo box_c(10, 3);

class reta_obsaculo {
public:
	GLfloat x, y,x2;

	reta_obsaculo() {

	}
	reta_obsaculo(GLfloat x, GLfloat y,GLfloat x2) {
		this->x = x;
		this->y = y;
		this->x2 = x2;
	}
	void draw_reta_obsaculo() {
		glColor3f(1, 0, 0);
		glBegin(GL_QUADS);
		glVertex2f(x, y);
		glVertex2f(x + x2, y);
		glVertex2f(x + x2, y + 0.5);
		glVertex2f(x, y + 0.5);
		glEnd();
	}
	void draw_reta_obsaculo_angulo() {
		GLfloat xx = x + 10 * cos(90);
		GLfloat yy = y + 10 * sin(90);

		glColor3f(1, 0, 0);
		glBegin(GL_QUADS);
		glVertex2f(x, y);
		glVertex2f(x+1, y);
		glVertex2f(xx+1 , yy+0.5);
		glVertex2f(xx, yy+0.5);
		glEnd();
	}

};

reta_obsaculo reta_b[2] =
{
reta_obsaculo(8,5,8),
reta_obsaculo(6.5,5.5,8),
};



class triangulo_obsaculo {
public:
	GLfloat x, y,angle=0;
	

	triangulo_obsaculo() {

	}
	triangulo_obsaculo(GLfloat x, GLfloat y) {
		this->x = x;
		this->y = y;
	}
	void draw_triangulo_obsaculo() {

		
		glColor3f(1, 0, 0);
		glBegin(GL_POLYGON);
		glVertex2f(x, y);
		glVertex2f(x + 2, y);
		glVertex2f(x + 1, y + 2);
		glEnd();
	}
};//acabar//acabar

triangulo_obsaculo tri_c[5] =
{
triangulo_obsaculo(6,5),
triangulo_obsaculo(11,6),
triangulo_obsaculo(8,8),
triangulo_obsaculo(13,4),
triangulo_obsaculo(15,6),
};
triangulo_obsaculo tri_d[6] =
{
triangulo_obsaculo(7,5),
triangulo_obsaculo(9,8),
triangulo_obsaculo(11,5),
triangulo_obsaculo(3,5),
triangulo_obsaculo(1.1,8),
triangulo_obsaculo(5,8),
};

void escreve(int width, int height, float x, float y, void* font, string texto) {//largura, altura e posição da caixa de texto
	float xxx = (float)x;
	float yyy = (float)y;
	glColor3f(1, 1, 0);
	glRasterPos2f(xxx, yyy);
	for (int i = 0; i < texto.length(); i++) {
		glutBitmapCharacter(font, texto.at(i));
	}
}


class menu_caixa{
public:
	GLfloat menux = 8, menuy = 2;
	string s;

	menu_caixa() {

	}

	menu_caixa(GLfloat menux, GLfloat menuy,string s) {
		this->menux = menux;
		this->menuy = menuy;
		this-> s = s;
	}
	void draw_menu_caixa() {
		glColor3f(1, 0, 0);
		glBegin(GL_QUADS);
		glVertex2f(menux, menuy + 2);
		glVertex2f(menux, menuy);
		glVertex2f(menux + 4, menuy);
		glVertex2f(menux + 4, menuy + 2);
		glEnd();
		escreve(10, 10, menux+0.5, menuy+1, GLUT_BITMAP_TIMES_ROMAN_24, s);
	}



};

menu_caixa caixas[7] =
{
menu_caixa(8,2,"Exit"),
menu_caixa(8, 5,"Nivel 4"),
menu_caixa(8, 8,"Nivel 3"),
menu_caixa(8, 11,"Nivel 2"),
menu_caixa(8, 14,"Nivel 1"),
};




void menu() {
	std::string s = std::to_string(Veloctity);
	std::string ni = std::to_string(nivel);
	std::string po = std::to_string(pontos);

	// o swicth tava todo bugado
	if (nivel == 0) {//menu
		caixa.DrawCaixa();
		escreve(10, 10, 7, 18, GLUT_BITMAP_TIMES_ROMAN_24, "Domino Smash");
		for (int i = 0; i < 5; i++) {
			caixas[i].draw_menu_caixa();
		}
	}else{
		if (nivel == 1) {



			caixa.DrawCaixa();
			mira.Hit_box_Caixa_obstaculo(box.x, box.y, bola.cx, bola.cy);	//AS hitboxes tenhem que aparecer sempre depois do draw senão da erros
			mira.Hit_box(bola.cx, bola.cy);
			mira.Mira();

			for (int i = 0; i < 11; i++) {
				mira.Hit_box_domino(a[i].x, a[i].y, bola.cx, bola.cy);
				a[i].DrawDomino();
				a[i].Domino_Compare(a[i - 1].x, a[i - 1].y);
				a[i].Domino_Compare(bola.cx, bola.cy);
			}

			box.Drawcaixa_obstaculo();

			escreve(10, 10, 7, 18, GLUT_BITMAP_TIMES_ROMAN_24, "Domino Smash");
			escreve(10, 10, 1, 18, GLUT_BITMAP_TIMES_ROMAN_24, "Nivel:" + ni);
			escreve(10, 10, 1, 17, GLUT_BITMAP_TIMES_ROMAN_24, "Potencia:" + s);
			escreve(10, 10, 1, 16, GLUT_BITMAP_TIMES_ROMAN_24, "Pontos:" + po);

			bola.DrawCircle();

			if (pontos == 11) {
				pontos = 0;
				nivel = 0;
			}
		}
		else {
			if (nivel == 2) {



				caixa.DrawCaixa();
				mira.Hit_box(bola.cx, bola.cy);
				mira.Mira();

				for (int ii = 0; ii < 12; ii++) {
					mira.Hit_box_domino(b[ii].x, b[ii].y, bola.cx, bola.cy);
					b[ii].DrawDomino();
					b[ii].Domino_Compare(b[ii - 1].x, b[ii - 1].y);
					b[ii].Domino_Compare(bola.cx, bola.cy);
				}

				//for (int ii = 0; ii < 2; ii++) {
					reta_b[0].draw_reta_obsaculo();
					reta_b[1].draw_reta_obsaculo_angulo();
				



				escreve(10, 10, 7, 18, GLUT_BITMAP_TIMES_ROMAN_24, "Domino Smash");
				escreve(10, 10, 1, 18, GLUT_BITMAP_TIMES_ROMAN_24, "Nivel:" + ni);
				escreve(10, 10, 1, 17, GLUT_BITMAP_TIMES_ROMAN_24, "Potencia:" + s);
				escreve(10, 10, 1, 16, GLUT_BITMAP_TIMES_ROMAN_24, "Pontos:" + po);

				bola.DrawCircle();

				if (pontos == 11) {
					pontos = 0;
					nivel = 0;
				}

			}
			else {
				if (nivel == 3) {


					caixa.DrawCaixa();
					mira.Hit_box_Caixa_obstaculo(box.x, box.y, bola.cx, bola.cy);	//AS hitboxes tenhem que aparecer sempre depois do draw senão da erros
					mira.Hit_box(bola.cx, bola.cy);
					mira.Mira();

					for (int iii = 0; iii < 12; iii++) {
						mira.Hit_box_domino(c[iii].x, c[iii].y, bola.cx, bola.cy);
						c[iii].DrawDomino();
						c[iii].Domino_Compare(c[iii - 1].x, c[iii - 1].y);
						c[iii].Domino_Compare(bola.cx, bola.cy);
					}

					for (int iii = 0; iii < 5; iii++) {
						tri_c[iii].draw_triangulo_obsaculo();
						mira.Hitbox_triangulo(tri_c[iii].x, tri_c[iii].y, bola.cx, bola.cy);
					}

					box_c.Drawcaixa_obstaculo();

					escreve(10, 10, 7, 18, GLUT_BITMAP_TIMES_ROMAN_24, "Domino Smash");
					escreve(10, 10, 1, 18, GLUT_BITMAP_TIMES_ROMAN_24, "Nivel:" + ni);
					escreve(10, 10, 1, 17, GLUT_BITMAP_TIMES_ROMAN_24, "Potencia:" + s);
					escreve(10, 10, 1, 16, GLUT_BITMAP_TIMES_ROMAN_24, "Pontos:" + po);

					bola.DrawCircle();

					if (pontos == 12) {
						pontos = 0;
						nivel = 0;
					}
				}
				else {
					if (nivel == 4) {


						caixa.DrawCaixa();
						mira.Hit_box(bola.cx, bola.cy);
						mira.Mira();

						for (int iiii = 0; iiii < 6; iiii++) {
							mira.Hit_box_domino(d[iiii].x, d[iiii].y, bola.cx, bola.cy);
							d[iiii].DrawDomino();
							d[iiii].Domino_Compare(d[iiii - 1].x, d[iiii - 1].y);
							d[iiii].Domino_Compare(bola.cx, bola.cy);
						}

						for (int iiii = 0; iiii < 6; iiii++) {
							tri_d[iiii].draw_triangulo_obsaculo();
							mira.Hitbox_triangulo(tri_c[iiii].x, tri_c[iiii].y, bola.cx, bola.cy);
						}

						

						escreve(10, 10, 7, 18, GLUT_BITMAP_TIMES_ROMAN_24, "Domino Smash");
						escreve(10, 10, 1, 18, GLUT_BITMAP_TIMES_ROMAN_24, "Nivel:" + ni);
						escreve(10, 10, 1, 17, GLUT_BITMAP_TIMES_ROMAN_24, "Potencia:" + s);
						escreve(10, 10, 1, 16, GLUT_BITMAP_TIMES_ROMAN_24, "Pontos:" + po);

						bola.DrawCircle();

						if (pontos == 11) {
							pontos = 0;
							nivel = 0;
						}
					}
				}
			}
		}
	}

}

void display(void)
{	
	
	
	glClearColor(0.0, 0.0, 0.0, 0.0); // define a cor do fundo da janela (RGBA)
	glClear(GL_COLOR_BUFFER_BIT); // Aplica a cor atual no fundo
	
	glLoadIdentity();

	glColor3f(0, 100, 0);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 20, 0, 20);
	
	menu();
	
	
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
	//glOrtho(0.0f, windowWidth, 0.0f, windowHeight, 1.0f, -1.0f);
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
		nivel=0;
		break;
	}
	glutPostRedisplay();
}

void SpecialKeys(int key, int x, int y) {


	if (key == GLUT_KEY_UP) {
		if (mira.shoot == 0) {
			Veloctity = Veloctity + 1;
		}
	}
	if (key == GLUT_KEY_DOWN) {
		if (mira.shoot == 0) {
			Veloctity = Veloctity - 1;
		}
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

void HandleMouse(int button, int state, int x, int y) {
	
	GLfloat xx, yy;

	xx = (x * 10) / windowWidth;
	yy = (y * 10) / windowHeight;
	
	if (button == GLUT_LEFT_BUTTON)

		if (state == GLUT_UP) {
			

			if (xx>=8 && xx<= 14 && yy>=16 && yy<=18) {
				exit(1);
			}
			if (xx >= 8 && xx <= 14 && yy >= 13 && yy <= 15) {
				nivel = 4;
			}
			if (xx >= 8 && xx <= 14 && yy >= 10 && yy <= 12) {
				nivel = 3;
			}
			if (xx >= 8 && xx <= 14 && yy >= 7 && yy <= 9) {
				nivel = 2;
			}
			if (xx >= 8 && xx <= 14 && yy >= 4 && yy <= 6) {
				nivel = 1;
			}
		
		}
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
	glutMouseFunc(HandleMouse);
	SetupRC();	
	glutMainLoop();
}

