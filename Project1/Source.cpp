#include <windows.h>
#include <GL/glut.h>
#include "input_code.cpp"





int main(int argc, char** argv) {
	glutInit(&argc, argv);      // Initialize GLUT
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set modes
	glutInitWindowSize(400, 350);  // Initial window width and height
	glutCreateWindow("fdgfd");     // Create window with the given title            // Pull into full screen
	glutDisplayFunc(RenderScene);    // Register handler for window re-paint
	glutReshapeFunc(ChangeSize);    // Register handler for window re-size
	glutKeyboardFunc(HandleKeyboard);  // Register handler for key event
	glutSpecialFunc(SpecialKeys); // Register handler for special-key event
	glutMouseFunc(HandleMouse);
	SetupRC();          // Our own OpenGL initialization
	glutMainLoop();    // Enter the infinitely event-handling loop
	return 0;
}