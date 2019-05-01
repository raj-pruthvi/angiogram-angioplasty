#include <math.h>
#include <GL/glut.h>

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
  glutTimerFunc(400, update, 0);
}

void drawVessel(){
	glPushMatrix();
  glColor3f(0.0,0,0.5);
  GLUquadricObj *quadratic;
  quadratic = gluNewQuadric();
  glScalef(0.15,0.1,0.0);
  glTranslatef(0.0,7.0,0.0);
  glRotatef(45.0, 1.0, 0.0, 0.0);    
  gluCylinder(quadratic,0.5,0.5,vesselLength,32,32);
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

void DrawCircle(float cx, float cy, float r, int num_segments, float tx, float ty, float sx, float sy, float theta){
  glPushMatrix();
  glScalef(sx,sy,0.0);
  glTranslatef(tx,ty,0.0);
  glRotatef(theta, 0.0, 0.0, 10.0);
  glBegin(GL_TRIANGLE_FAN);
  if (r >= 0){
	  for(int ii = 0; ii < num_segments; ii++){
	      float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);
	      float x = r * cosf(theta/2);
	      float y = r * sinf(theta/2);
	      glVertex2f(x + cx, y + cy);
	  }
	}
  glEnd();
  glPopMatrix();
}

void drawFat(float tx, float ty, float sx, float sy, float theta) {  
  glColor3f(1.0, 0.5, 0.0);
	DrawCircle(0.5, 0.5, 0.05, 35, tx, ty, sx, sy, theta);
}

void drawMesh(){
	glPushMatrix();
  glColor3f(0.7,0.7,0.7);
  GLUquadricObj *quadratic;
  quadratic = gluNewQuadric();
	gluQuadricDrawStyle(quadratic, GLU_LINE); /* flat shaded */
 	gluQuadricNormals(quadratic, GLU_SMOOTH);
  glScalef(0.15,0.1,0.0);
  glTranslatef(0.0,1.0,0.0);
  glRotatef(45.0, 1.0, 0.0, 0.0);    
  gluCylinder(quadratic,0.5,0.5,vesselLength/6,32,32);
	glPopMatrix();
	glutSwapBuffers();	
}

void display(){
  glClear(GL_COLOR_BUFFER_BIT);
	drawVessel();
  drawFat(-.81, 0.49, 0.25, 1.0, -90.0);
  drawFat(.81, -0.49, 0.25, 1.0, 90.0);
  drawMesh();
  int i = 0;
  while (i < 4){
    drawCell(y[i]);
    i+=1;
  }
	glFlush();
}

int main(int c, char** v){
	glutInit(&c,v);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(WIDTH,HEIGHT);
	init();
	glutCreateWindow("Block");
	glutDisplayFunc(display);	
  glutTimerFunc(300, update, 0);
	glutMainLoop();
}
