//============================================================================
// Name        : OpenGl-Transformacao2.cpp
// Author      : Marcelo Oliveira
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include<GL/gl.h>
#include<GL/glut.h>
#include <stdlib.h>

static int year = 0, day = 0;

void init(void){
	glClearColor (0.0, 0.0, 0.0, 0.0);
}

void display(void){
	glClear (GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 0.0); // Cor amarela
	glPushMatrix();
		glRotatef ((GLfloat) year, 1.0, 0.0, 0.0);
		glRotatef ((GLfloat) day, 0.0, 0.0, 1.0);
		glutWireSphere(1.0, 20, 16);   /* desenha o sol */
	glPopMatrix();

    glColor3f(0.0, 0.0, 1.0); // Cor azul
	glPushMatrix();
		glRotatef ((GLfloat) year, 0.0, 1.0, 0.0);
		glTranslatef (1.5, 0.0, 0.0); //Translada a partir do novo sistema de coordenadas resultante da Rotacao
		glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
		glutWireSphere(0.2, 10, 8);    /* desenha a Terra */
	glPopMatrix();

    glColor3f(1.0, 0.0, 0.0); // Cor vermelha
	glPushMatrix();
		glRotatef ((GLfloat) -year, 0.0, 1.0, 0.0);
		glTranslatef (-2.0, 0.0, 0.0); //Translada a partir do novo sistema de coordenadas resultante da Rotacao
		glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
		glutWireSphere(0.2, 10, 8);    /* desenha Marte */

        glColor3f(0.5, 0.5, 0.5); // Cor cinza
		glRotatef ((GLfloat)-year, 0.0, 1.0, 0.0);
		glTranslatef (-0.5, 0.0, 0.0); //Translada a partir do novo sistema de coordenadas resultante da Rotacao
		glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
		glutWireSphere(0.05, 5, 5);    /* desenha uma lua de marte */

        glTranslatef (0.5, 0.0, 0.0);
        glColor3f(1.0, 1.0, 1.0); // Cor branca

		glRotatef ((GLfloat)year, 1.0, 0.0, 1.0);
		glTranslatef (-0.3, 0.0, 0.0);
		glutWireSphere(0.05, 5, 5); /* desenha a segunda lua de marte */
	glPopMatrix();

	glutSwapBuffers(); //pois estamos adotando o GLUT_DOUBLE

}

void reshape (int w, int h){
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
	gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); //posicao da camera

}

void keyboard (unsigned char key, int x, int y){
	switch (key) {
	case 'd':
		day = (day + 10) % 360;  //% valor do resto
		glutPostRedisplay(); //Redesenha a cena com novas coordenadas, é executado no glutMainLoop;
		break;
	case 'D':
		day = (day - 10) % 360;
		glutPostRedisplay();
		break;
	case 'y':
		year = (year + 5) % 360;
		glutPostRedisplay();
		break;
	case 'Y':
		year = (year - 5) % 360;
		glutPostRedisplay();
		break;
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("Rotacao de Planetas");
	init ();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
