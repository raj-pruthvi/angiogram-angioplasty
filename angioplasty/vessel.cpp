#include <math.h>
#include <GL/glut.h>
#include <iostream>

float y[] = {11.0,11.0-3,11.0-6,11.0-9};
float WIDTH = 800.0;
float HEIGHT = 600.0;
float vesselLength = 20.0;
float cellLength = 1.0;

void init() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60, (float)WIDTH/HEIGHT, 0.01f, 100.0f);
  glMatrixMode(GL_MODELVIEW);
}

void update(int value) {
  int i = 0;
  if (y[i] != -10.0) {
      y[i] -= 1.0;
      y[i+1] -= 1.0;
      y[i+2] -= 1.0;
      y[i+3] -= 1.0;
  }
  glutPostRedisplay();
  glutTimerFunc(900, update, 0);
}

void drawVessel(){
	glPushMatrix();
  glColor3f(0.0,0,0.5);
  GLUquadricObj *quadratic;
  quadratic = gluNewQuadric();
  glScalef(0.15,0.1,0.0);
  glTranslatef(0.0,7.0,0.0);
  glRotatef(45.0, 1.0, 0.0, 0.0);    
  gluCylinder(quadratic,0.5,0.5,vesselLength,20,20);
	glPopMatrix();
	glutSwapBuffers();
}

void drawCell(int y){
  glPushMatrix();
  glColor3f(0.7,0,0);
  glScalef(0.1,0.1,0.01);
  glTranslatef(0.0,y,0.0);
  glRotatef(45.0, 1.0, 0.0, 0.0);
    GLUquadricObj *quadratic;
    quadratic = gluNewQuadric();
    gluCylinder(quadratic,0.5,0.5,cellLength,10,10);
    glPopMatrix();
    glutSwapBuffers();
}

void display(){
  glClear(GL_COLOR_BUFFER_BIT);
	drawVessel();
  int i = 0;
  while (i < 4){
    drawCell(y[i]);
    i+=1;
  }
	// drawConstrictedVessel(6, 16, 2.0, 0.1);  
	glFlush();
}

int main(int c, char** v){
	glutInit(&c,v);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,600);
	init();
	glutCreateWindow("notW");
	glutDisplayFunc(display);	
  update(0);
	glutMainLoop();
}
