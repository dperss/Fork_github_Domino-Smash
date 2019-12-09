#include <GL/glut.h>

class Domino;
class Circulo; 
class Triangulo_obstaculo;

class Hitbox {
public:
	static void boladomino(GLfloat xcentrobola, GLfloat ycentrobola, Domino* domino);
	static void bolacaixa(GLfloat xcentrobola, GLfloat ycentrobola);
	static void bolatriangulo(Triangulo_obstaculo* triangulo);
};