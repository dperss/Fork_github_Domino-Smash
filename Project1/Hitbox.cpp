#include "Hitbox.h"
#include "GlobalVariables.h"
#include "Domino.h"
#include "Triangulo_obstaculo.h"


	void Hitbox::boladomino(GLfloat xcentrobola, GLfloat ycentrobola, Domino* domino) {
		if ((xcentrobola >= domino->x && xcentrobola <= domino->x + 1 && ycentrobola >= domino->y && ycentrobola <= domino->y + 1.4)) {
			pontos++;
			if (bola->directiony == 1)
				domino->y += 2;
			if (bola->directiony == -1)
				domino->y -= 2;
			domino->r = 1;
			domino->g = 0;
			velocity = 0;

		}
	}
	void Hitbox::bolacaixa(GLfloat xcentrobola, GLfloat ycentrobola) {
		if ((xcentrobola - 0.5 <= 1) || (xcentrobola + 0.5 >= 19)) {
			bola->directionx = bola->directionx * -1;
		}
		if ((ycentrobola - 0.5 <= 1) || (ycentrobola + 0.5 >= 19)) {
			bola->directiony = bola->directiony * -1;
		}
	}
	void Hitbox::bolatriangulo(Triangulo_obstaculo* triangulo) {
		if (bola->cx >= triangulo->x && bola->cx <= triangulo->x + 2 && bola->cy >= triangulo->y && bola->cy <= triangulo->y + 1) {
			bola->directionx = -bola->directionx / 2;
			bola->directiony = -bola->directiony / 2;
		}
	}
