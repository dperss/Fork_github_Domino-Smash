#include <GL/glut.h>
#include <string>

using namespace std;

void escreve(int width, int height, float x, float y, void* font, string texto);



class Menu_caixa {
public:
	GLfloat menux, menuy;
	string s;

	Menu_caixa();

	Menu_caixa(GLfloat menux, GLfloat menuy, string s);
	void draw_Menu_caixa();



};
