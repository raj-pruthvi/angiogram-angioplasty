#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include<iostream>
#include<vector>
GLsizei ww = 1000;
GLsizei wh = 500;

GLfloat bezierCurve(float t, GLfloat P0, GLfloat P1, GLfloat P2, GLfloat P3) {
	// Cubic bezier Curve
	GLfloat point = (pow((1 - t), 3.0) * P0) +
		(3 * pow((1 - t), 2) * t * P1) +
		(3 * (1 - t) * t * t * P2) +
		(pow(t, 3) * P3);
	return point;
}

void display() {
	//vector<int> heart{ 640,850,620,800,600,750,600,650,630,550,680,500,750,460,850,440,1000,500 };
	int start1x = 400, start1y = 200;
	int start2x = 800, start2y = 200;
	int t1x = 400, t1y = 350, t2x = 800, t2y = 350;
	glPointSize(5.0);
	//glColor3b(1.0, 1.0, 0.0);
	glLineWidth(2.5);
	glBegin(GL_LINE_STRIP);
	/*for (std::vector<int>::size_type i = 0; i != heart.size()-1; i+=2) {
		glVertex2d(heart[i], heart[i + 1]);
	}*/
	glColor3f(1.0, 0.5, 0.5);
	//int t = 30;
	glVertex2d(640, 850);
	glVertex2d(620, 800);
	glVertex2d(600, 750);
	glVertex2d(600, 650);
	glVertex2d(600, 650);
	glVertex2d(630, 550);
	glVertex2d(680, 500);
	glVertex2d(750, 460);
	glVertex2d(850, 440);
	glVertex2d(1000, 500);
	//glVertex2d(1020, 550);
	glVertex2d(1020, 600);
	glVertex2d(980, 700);	
	glVertex2d(880, 800);
	glVertex2d(800, 840);
	glVertex2d(640, 850);
	
	/*for (int i = 0; i <= t; i++) {
		float pos = (float)i / (float)t;
		GLfloat x = bezierCurve(pos, start1x, t1x, t2x, start2x);
		GLfloat y = bezierCurve(pos, start2y, t1y, t2y, start2y);
		glVertex2f(x, y);
	}
	*/
	//glVertex2d(100, 200);
	//glVertex2d(400, 200);
	glEnd();
	
	glColor4f(0.9, 0.7, 0.5, 0.7);
	glBegin(GL_POLYGON);
	
	//int t = 30;
	glVertex2d(640, 850);
	glVertex2d(620, 800);
	glVertex2d(600, 750);
	glVertex2d(600, 650);
	glVertex2d(600, 650);
	glVertex2d(630, 550);
	glVertex2d(680, 500);
	glVertex2d(750, 460);
	glVertex2d(850, 440);
	glVertex2d(1000, 500);
	//glVertex2d(1020, 550);
	glVertex2d(1020, 600);
	glVertex2d(980, 700);
	glVertex2d(880, 800);
	glVertex2d(800, 840);
	//glVertex2d(640, 850);

	/*for (int i = 0; i <= t; i++) {
		float pos = (float)i / (float)t;
		GLfloat x = bezierCurve(pos, start1x, t1x, t2x, start2x);
		GLfloat y = bezierCurve(pos, start2y, t1y, t2y, start2y);
		glVertex2f(x, y);
	}
	*/
	//glVertex2d(100, 200);
	//glVertex2d(400, 200);
	glEnd();

	

	glFlush();
}

/*void reshape(GLsizei w, GLsizei h) {
	glViewport(0, 0, (GLdouble)w, (GLdouble)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// glOrtho scales the matrix by multiplying the matrix
	if (w <= h) {
		glOrtho(-5.0, 5.0, -5.0*(GLdouble)h / (GLdouble)w,
			5.0*(GLdouble)h / (GLdouble)w, -5.0, 5.0);
	}
	else {
		glOrtho(-5.0*(GLdouble)w / (GLdouble)h,
			5.0*(GLdouble)w / (GLdouble)h, -5.0, 5.0, -5.0, 5.0);
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	ww = w;
	wh = h;
}*/


void reshape(GLsizei w, GLsizei h) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,(GLdouble)w, 0.0, (GLdouble)h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	ww = w;
	wh = h;
}


void init() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glClearColor(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize((GLdouble)ww, (GLdouble)wh);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);

	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}



