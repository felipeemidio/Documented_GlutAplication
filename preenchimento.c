#include <GL/glut.h>
#include <stdlib.h>

// Vetor de poligonos em hexadecimal (desenho de um pinguin).
GLubyte tux[] = {
 0x0,  0x0,  0x0,  0x0,
 0x0,  0x0,  0x0,  0x0,
 0x0,  0x0,  0x0,  0x0,
 0x0,  0x0,  0x0,  0x0,
 0x0,  0x0,  0x0,  0x0,
 0x0,  0x0,  0x0,  0x0,
 0x0,  0x7f,  0xfe,  0x0,
 0x0,  0xc4,  0x23,  0x0,
 0x1,  0x83,  0x21,  0x80,
 0x1,  0x7,  0xe0,  0x80,
 0x1,  0x7,  0xf0,  0x80,
 0x1,  0x8f,  0xf9,  0x80,
 0x0,  0xff,  0xff,  0x0,
 0x0,  0x4f,  0xf1,  0x0,
 0x0,  0x6f,  0xf1,  0x0,
 0x0,  0x2f,  0xf3,  0x0,
 0x0,  0x27,  0xe2,  0x0,
 0x0,  0x30,  0x66,  0x0,
 0x0,  0x1b,  0x1c,  0x0,
 0x0,  0xb,  0x88,  0x0,
 0x0,  0xb,  0x98,  0x0,
 0x0,  0x8,  0x18,  0x0,
 0x0,  0xa,  0x90,  0x0,
 0x0,  0x8,  0x10,  0x0,
 0x0,  0xc,  0x30,  0x0,
 0x0,  0x6,  0x60,  0x0,
 0x0,  0x3,  0xc0,  0x0,
 0x0,  0x0,  0x0,  0x0,
 0x0,  0x0,  0x0,  0x0,
 0x0,  0x0,  0x0,  0x0,
 0x0,  0x0,  0x0,  0x0,
 0x0,  0x0,  0x0,  0x0
};

// Variaveis r (red), g (green) e b (blue) para a seleção de cores.
GLfloat r,g,b;

// Cabeçalho dos métodos.
void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);
void mouse(int button, int state, int x, int y);

/*
 * Função principal.
 */
int main(int argc, char** argv){
  glutInit(&argc, argv); // Ativa as ferramentas do GLUT.
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB); //Cria 2 buffers, um principal e outro auxiliar.
  glutInitWindowSize (256, 256); // Tamanho da janela.
  glutInitWindowPosition (100, 100); // Posição inicial da janela.
  glutCreateWindow ("Preenchendo regiões"); // Instanciação da janela com o titulo.
  init();
  glutDisplayFunc(display); // A função de desenho/renderização é a display().
  glutKeyboardFunc(keyboard); // A função caso algum comando do teclado seja executado é keyboard().
  glutMouseFunc(mouse); // A função caso algum comando do mouse seja executado é mouse().
  glutMainLoop(); // Inicia o loop de processamento de eventos do GLUT.
  return 0;
}

void init(void){
  glClearColor(1.0, 1.0, 1.0, 1.0); // Preenche o fundo de branco.
  glOrtho (0, 256, 0, 256, -1 ,1); // Defini  o espaço de desenho.
  r=0; g=1; b=0; // Incializa as variavel CLfloat.
}

/*
 * Função de renderização.
 */
void display(void){
  int i;
  glClear(GL_COLOR_BUFFER_BIT); //limpa o buffer atual.
  glDisable(GL_POLYGON_STIPPLE); // Desabilita o desenho de poligonos padrao.

  /*
   * desenha um quadrado com contorno vermelho.
   */
  glPolygonMode(GL_BACK, GL_LINE); // Defini que a parte de trás (Gl_BACK) dos poligonos
                                   // será desenhada com uma linha de contorno (GL_Line).
  glColor3f(1.0, 0.0, 0.0); // Defini a cor atual de desenho como vermelho.
  // Desenha um poligono.
  glBegin(GL_POLYGON);
  glVertex2i(30,226);  glVertex2i(113,226);
  glVertex2i(113,143); glVertex2i(30,143);
  glEnd();

  /*
   * Desenha um quadrado preenchido com a cor definida pelas
   * variaveis r, g, b.
   */
  glPolygonMode(GL_BACK, GL_FILL); // Significa que o fundo do coligono (GL_BACK) terá
                                   // preenchimento solido (GL_FILL).
  glColor3f(r, g, b); // Defini a cor atual do desenho como as definidas por r, g, e b.
  // Desenha um segundo poligono.
  glBegin(GL_POLYGON);
  glVertex2i(143,226); glVertex2i(226,226);
  glVertex2i(226,143); glVertex2i(143,143);
  glEnd();

  // Desenha um terceiro poligono.
  glBegin(GL_POLYGON);
  // Cada vertice que compoem o poligono recebe uma cor.
  glColor3f(1.0, 0.0, 0.0);  glVertex2i(30,113);
  glColor3f(0.0, 1.0, 0.0);  glVertex2i(113,113);
  glColor3f(0.0, 0.0, 1.0);  glVertex2i(113,30);
  glColor3f(1.0, 1.0, 0.0);  glVertex2i(30,30);
  glEnd();

  glEnable(GL_POLYGON_STIPPLE); // Habilita o desenho de poligonos (foi desativado na linha no começo da func display()).
  glColor3f(1.0, 0.0, 1.0); // A nova cor de desenho é magenta.
  glPolygonStipple(tux); // O poligono de desenho recebe o vetor tux.
  // Desenha um quarto quadrado.
  glBegin(GL_POLYGON);
  glVertex2i(143,113); glVertex2i(226,113);
  glVertex2i(226,30); glVertex2i(143,30);
  glEnd();


  glFlush(); // Executa todos os comandos openGL ainda não executados.
  glutSwapBuffers(); // Troca o buffer principal pelo auxiliar.
}

/*
 * Função de execução de ação do teclado.
 */
void keyboard(unsigned char key, int x, int y){
  switch (key) {
  case 27: // 27 é número de chave da tecla ESC.
	exit(0); // Se a tecla esc for apertada, finalize a aplicação
	break;
  }
}

/*
 * Função de execução de ação do mouse.
 */
void mouse(int button, int state, int x, int y){
  switch (button) {
  case GLUT_LEFT_BUTTON: // Se houver ação do botão esquerdo do mouse...
	if (state == GLUT_DOWN) { // e a ação for um click, faça...
      // Atribui valores randomicos a r, g e b
	  r=(GLfloat)rand()/(RAND_MAX+1.0);
	  g=(GLfloat)rand()/(RAND_MAX+1.0);
	  b=(GLfloat)rand()/(RAND_MAX+1.0);
	  glutPostRedisplay();
	}
	break;
  }
}

