#include <GL/glut.h>
#include <string>
#include <Windows.h>
#include "Domino.h"
#include "GlobalVariables.h"
#include "Caixadojogo.h"
#include "Triangulo_obstaculo.h"
#include "Hitbox.h"
#include "Menu_caixa.h"
#include "Shoot.h"
#include "Caixa_obstaculo.h"




using namespace std;




//declarações

void menu();


Shoot* mira = new Shoot;


Caixa_obstaculo box(10, 3);
Caixa_obstaculo box_c(10, 3);




Triangulo_obstaculo tri_c[5] =
{
Triangulo_obstaculo(6,5),
Triangulo_obstaculo(11,6),
Triangulo_obstaculo(8,8),
Triangulo_obstaculo(13,4),
Triangulo_obstaculo(15,6),
};
Triangulo_obstaculo tri_d[6] =
{
Triangulo_obstaculo(7,5),
Triangulo_obstaculo(9,8),
Triangulo_obstaculo(11,5),
Triangulo_obstaculo(3,5),
Triangulo_obstaculo(1.1,8),
Triangulo_obstaculo(5,8),
};




Domino a[15] =
{
Domino(6.1,8.5),
Domino(7.2, 7),
Domino(8.3, 7),
Domino(5, 8.5),
Domino(5, 10),
Domino(6.1,8.5),
Domino(7.2,8.5),
Domino(8.3, 8.5),
Domino(9.4, 8.5),
Domino(6.1,10),
Domino(7.2,10),
Domino(8.3, 10),
Domino(9.4,10),
Domino(10.5,10),
Domino(10.5,8.5),
};

Domino b[11] =
{
Domino(16,5),
Domino(14.9,5),
Domino(13.8, 5),
Domino(12.7, 5),
Domino(11.6, 5),
Domino(10.5,5),
Domino(9.4, 5),
Domino(9.4, 6.5),
Domino(9.4, 8),
Domino(9.4,9.5),
Domino(8.3,11),
};

Domino c[8] =
{
Domino(5,4),
Domino(5, 5.5),
Domino(5, 7),
Domino(5, 8.5),
Domino(5, 10),
Domino(6.1,10),
Domino(7.2,10),
Domino(8.3, 10),
};

Domino d[7] =
{
Domino(5,4),
Domino(5, 5.5),
Domino(5, 7),
Domino(5, 8.5),
Domino(5, 10),
Domino(6.1,10),
Domino(7.2,10),
};


Menu_caixa caixas[7] =
{
Menu_caixa(8,2,"Exit"),
Menu_caixa(8, 5,"Nivel 4"),
Menu_caixa(8, 8,"Nivel 3"),
Menu_caixa(8, 11,"Nivel 2"),
Menu_caixa(8, 14,"Nivel 1"),
};


//fim das declarações



//event handler

void HandleMouse(int button, int state, int x, int y) {
	if (handlemouse == 0)
		return;
	GLfloat xx, yy;

	xx = (x * 10) / windowWidth;
	yy = (y * 10) / windowHeight;

	if (button == GLUT_LEFT_BUTTON)

		if (state == GLUT_UP) {


			if (xx >= 8 && xx <= 14 && yy >= 16 && yy <= 18) {
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

void HandleKeyboard(unsigned char key, int x, int y) {
	if (key == 32) {
		mira->shoot = 1;
	}
	if (key == 27 && pontos!=maxpontos) {
		nivel = 0;
		
	}
	if (key == 82 || key == 114) {
		bola = new Circulo;
		mira = new Shoot;
		
			a[1] = Domino(6.1, 8.5);
			a[2] = Domino(7.2, 7);
			a[3] = Domino(8.3, 7);
			a[4] = Domino(5, 8.5);
			a[5] = Domino(5, 10);
			a[6] = Domino(6.1, 8.5);
			a[7] = Domino(7.2, 8.5);
			a[8] = Domino(8.3, 8.5);
			a[9] = Domino(9.4, 8.5);
			a[10] = Domino(6.1, 10);
			a[11] = Domino(7.2, 10);
			a[12] = Domino(8.3, 10);
			a[13] = Domino(9.4, 10);
			a[14] = Domino(10.5, 10);
			a[15] = Domino(10.5, 8.5);
			
		
			b[1] = Domino(16, 5);
			b[2] = Domino(14.9, 5);
			b[3] = Domino(13.8, 5);
			b[4] = Domino(12.7, 5);
			b[5] = Domino(11.6, 5);
			b[6] = Domino(10.5, 5);
			b[7] = Domino(9.4, 5);
			b[8] = Domino(9.4, 6.5);
			b[9] = Domino(9.4, 8);
			b[10] = Domino(9.4, 9.5);
			b[11] = Domino(8.3, 11);
			
		
			c[1] = Domino(5, 4);
			c[2] = Domino(5, 5.5);
			c[3] = Domino(5, 7);
			c[4] = Domino(5, 8.5);
			c[5] = Domino(5, 10);
			c[6] = Domino(6.1, 10);
			c[7] = Domino(7.2, 10);
			c[8] = Domino(8.3, 10);
		
			d[1] = Domino(5, 4);
			d[2] = Domino(5, 5.5);
			d[3] = Domino(5, 7);
			d[4] = Domino(5, 8.5);
			d[5] = Domino(5, 10);
			d[6] = Domino(6.1, 10);
			d[7] = Domino(7.2, 10);
		
		nivel = 0;
		pontos = 0;
	}
	glutPostRedisplay();
}

void SpecialKeys(int key, int x, int y) {


	if (key == GLUT_KEY_UP) {
		if (mira->shoot == 0) {
			velocity = velocity + 1;
		}
	}
	if (key == GLUT_KEY_DOWN) {
		if (mira->shoot == 0) {
			velocity = velocity - 1;
		}
	}
	if (key == GLUT_KEY_LEFT) {
		//bola.cx -= 0.1;
		if (mira->shoot == 0) {
			mira->angulo += 0.1;
		}
	}
	if (key == GLUT_KEY_RIGHT) {
		//bola.cx += 0.1;
		if (mira->shoot == 0) {
			mira->angulo -= 0.1;
		}
	}
	glutPostRedisplay();
}


//fim de event handler




void menu() {
	handlemouse = 1;
	if (velocity > 100)
		velocity = 100;
	std::string s = std::to_string(velocity/2);
	std::string ni = std::to_string(nivel);
	std::string po = std::to_string(pontos);
	switch (nivel) {
	case 0://menu
		Caixadojogo::DrawCaixa();
		escreve(10, 10, 7, 18, GLUT_BITMAP_TIMES_ROMAN_24, "Domino Smash",1,1,0);
		for (int i = 0; i < 5; i++) {
			caixas[i].draw_Menu_caixa();
		}
		break;
	case 1://nivel 1
		maxpontos = 3;
		handlemouse = 0;
		Caixadojogo::DrawCaixa();
		mira->Hit_box_Caixa_obstaculo(box.x, box.y, bola->cx, bola->cy);	//AS hitboxes têm que aparecer sempre depois do draw senão da erros
		Hitbox::bolacaixa(bola->cx, bola->cy);
		mira->Mira();
		for (int j = 0; j < 15; j++) {
			Hitbox::boladomino(bola->cx, bola->cy, &a[j]);
			for(int i=0; i<15; i++){
				a[j].Domino_Compare(&(a[i]));
			}
			a[j].DrawDomino();
		}

		box.Drawcaixa_obstaculo();

		escreve(10, 10, 7, 18, GLUT_BITMAP_TIMES_ROMAN_24, "Domino Smash", 1, 1, 0);
		escreve(10, 10, 1, 18, GLUT_BITMAP_TIMES_ROMAN_24, "Nivel:" + ni, 1, 1, 0);
		escreve(10, 10, 1, 17, GLUT_BITMAP_TIMES_ROMAN_24, "Potencia:" + s, 1, 1, 0);
		escreve(10, 10, 1, 16, GLUT_BITMAP_TIMES_ROMAN_24, "Pontos:" + po, 1, 1, 0);

		bola->DrawCircle();

		
		if (pontos == maxpontos) {

			escreve(15, 15, 5, 6, GLUT_BITMAP_TIMES_ROMAN_24, "Maximo de pontos atingido", 1, 1, 1);
			escreve(15, 15, 5, 5, GLUT_BITMAP_TIMES_ROMAN_24, "R para fazer reset ao nivel", 1, 1, 1);
		}
		break;
			
		case 2://Nivel 2
			maxpontos = 4;
			handlemouse = 0;
			Caixadojogo::DrawCaixa();
			mira->Hit_box_Caixa_obstaculo(box.x, box.y, bola->cx, bola->cy);	//AS hitboxes têm que aparecer sempre depois do draw senão da erros
			Hitbox::bolacaixa(bola->cx, bola->cy);
			mira->Mira();
			for (int j = 0; j < 11; j++) {
				Hitbox::boladomino(bola->cx, bola->cy, &b[j]);
				for (int i = 0; i < 11; i++) {
					b[j].Domino_Compare(&(b[i]));
				}
				b[j].DrawDomino();
			}

			box.Drawcaixa_obstaculo();

			escreve(10, 10, 7, 18, GLUT_BITMAP_TIMES_ROMAN_24, "Domino Smash", 1, 1, 0);
			escreve(10, 10, 1, 18, GLUT_BITMAP_TIMES_ROMAN_24, "Nivel:" + ni, 1, 1, 0);
			escreve(10, 10, 1, 17, GLUT_BITMAP_TIMES_ROMAN_24, "Potencia:" + s, 1, 1, 0);
			escreve(10, 10, 1, 16, GLUT_BITMAP_TIMES_ROMAN_24, "Pontos:" + po, 1, 1, 0);

			bola->DrawCircle();

			if (pontos == maxpontos) {

				escreve(15, 15, 5, 6, GLUT_BITMAP_TIMES_ROMAN_24, "Maximo de pontos atingido", 1, 1, 1);
				escreve(15, 15, 5, 5, GLUT_BITMAP_TIMES_ROMAN_24, "R para fazer reset ao nivel", 1, 1, 1);
			}

			break;
		case 3: // Nivel 3
			maxpontos = 5;
			handlemouse = 0;
			Caixadojogo::DrawCaixa();
			mira->Hit_box_Caixa_obstaculo(box.x, box.y, bola->cx, bola->cy);	//AS hitboxes tenhem que aparecer sempre depois do draw senão da erros
			Hitbox::bolacaixa(bola->cx, bola->cy);
			mira->Mira();

			for (int j = 0; j < 8; j++) {
				Hitbox::boladomino(bola->cx, bola->cy, &c[j]);
				for (int i = 0; i < 8; i++) {
					c[j].Domino_Compare(&(c[i]));
				}
				c[j].DrawDomino();
			}

			for (int i = 0; i < 5; i++) {
				tri_c[i].draw_Triangulo_obstaculo();
				Hitbox::bolatriangulo(&(tri_c[i]));
			}
			
			box_c.Drawcaixa_obstaculo();

			escreve(10, 10, 7, 18, GLUT_BITMAP_TIMES_ROMAN_24, "Domino Smash", 1, 1, 0);
			escreve(10, 10, 1, 18, GLUT_BITMAP_TIMES_ROMAN_24, "Nivel:" + ni, 1, 1, 0);
			escreve(10, 10, 1, 17, GLUT_BITMAP_TIMES_ROMAN_24, "Potencia:" + s, 1, 1, 0);
			escreve(10, 10, 1, 16, GLUT_BITMAP_TIMES_ROMAN_24, "Pontos:" + po, 1, 1, 0);

			bola->DrawCircle();

			if (pontos == maxpontos) {

				escreve(15, 15, 5, 6, GLUT_BITMAP_TIMES_ROMAN_24, "Maximo de pontos atingido", 1, 1, 1);
				escreve(15, 15, 5, 5, GLUT_BITMAP_TIMES_ROMAN_24, "R para fazer reset ao nivel", 1, 1, 1);
			}

			break;
		case 4: //Nivel 4
			maxpontos = 5;
			handlemouse = 0;
			Caixadojogo::DrawCaixa();
			Hitbox::bolacaixa(bola->cx, bola->cy);
			mira->Mira();

			for (int j = 0; j < 7; j++) {
				Hitbox::boladomino(bola->cx, bola->cy, &d[j]);
				for (int i = 0; i < 7; i++) {
					d[j].Domino_Compare(&(d[i]));
				}
				d[j].DrawDomino();
			}

			for (int i = 0; i < 6; i++) {
				tri_d[i].draw_Triangulo_obstaculo();
				Hitbox::bolatriangulo(&(tri_d[i]));
			}

			escreve(10, 10, 7, 18, GLUT_BITMAP_TIMES_ROMAN_24, "Domino Smash", 1, 1, 0);
			escreve(10, 10, 1, 18, GLUT_BITMAP_TIMES_ROMAN_24, "Nivel:" + ni, 1, 1, 0);
			escreve(10, 10, 1, 17, GLUT_BITMAP_TIMES_ROMAN_24, "Potencia:" + s, 1, 1, 0);
			escreve(10, 10, 1, 16, GLUT_BITMAP_TIMES_ROMAN_24, "Pontos:" + po, 1, 1, 0);

			bola->DrawCircle();

			if (pontos == maxpontos) {

				escreve(15, 15, 5, 6, GLUT_BITMAP_TIMES_ROMAN_24, "Maximo de pontos atingido", 1, 1, 1);
				escreve(15, 15, 5, 5, GLUT_BITMAP_TIMES_ROMAN_24, "R para fazer reset ao nivel", 1, 1, 1);
			}

			break;
	}

}


void display(void)
{


	glClearColor(0.0, 0.0, 0.0, 1.0); // define a cor do fundo da janela (RGBA)
	glClear(GL_COLOR_BUFFER_BIT); // Aplica a cor atual no fundo
	
	glLoadIdentity();

	glColor3f(0, 100, 0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 20, 0, 20);

	menu();


	glutPostRedisplay();
	glutSwapBuffers(); //despeja imgs da memoria para o ecran
}

void reshape(int w, int h) {
	if (w == 500 && h == 500) {
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
		gluOrtho2D(-10, windowWidth, -10, windowHeight);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		return;
	}
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
			windowHeight = 500.0f * h / w;
			windowWidth = 500.0f;
		}
		else {
			windowWidth = 500.0f * w / h;
			windowHeight = 500.0f;
		}

		// Set the clipping volume
		//glOrtho(0.0f, windowWidth, 0.0f, windowHeight, 1.0f, -1.0f);
		gluOrtho2D(-10, windowWidth, -10, windowHeight);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(windowHeight, windowWidth);
	glutCreateWindow("Domino Smash");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(HandleMouse);
	glutKeyboardFunc(HandleKeyboard);
	glutSpecialFunc(SpecialKeys);
	//glutFullScreen();
	glutMainLoop();
}