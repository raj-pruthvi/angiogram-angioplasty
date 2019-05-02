#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include<iostream>
#include<vector>
GLsizei ww = 1536;
GLsizei wh = 801;
float inc = 0.0;

GLfloat bezierCurve(float t, GLfloat P0, GLfloat P1, GLfloat P2, GLfloat P3) {
	// Cubic bezier Curve
	GLfloat point = (pow((1 - t), 3.0) * P0) +
		(3 * pow((1 - t), 2) * t * P1) +
		(3 * (1 - t) * t * t * P2) +
		(pow(t, 3) * P3);
	return point;
}

void update(int v) {
	if (inc < 1.0)
		inc += 0.8;

	glutPostRedisplay();
	glutTimerFunc(900, update, 0);
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
	/*
	glVertex2d(440, 650);
	glVertex2d(420, 600);
	glVertex2d(400, 550);
	glVertex2d(400, 450);
	glVertex2d(400, 450);
	glVertex2d(430, 350);
	glVertex2d(480, 300);
	glVertex2d(550, 260);
	glVertex2d(650, 240);
	glVertex2d(800, 300);
	//glVertex2d(1020, 550);
	glVertex2d(820, 400);
	glVertex2d(780, 500);	
	glVertex2d(680, 600);
	glVertex2d(600, 640);
	glVertex2d(440, 650);
	*/
	
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
	
	glColor4f(0.9, 0.7, 0.5, 1.0);
	glBegin(GL_POLYGON);
	
	int t = 10;
	//glVertex2d(440, 650);
	//
	//glVertex2f(440, 650);
	//glVertex2f(650, 550);
	for (int i = 0; i <= t; i++) {
		float pos = (float)i / (float)t;
		GLfloat x = bezierCurve(pos, 440, 400, 410, 400);
		GLfloat y = bezierCurve(pos, 650, 630, 620, 550);
		glVertex2f(x, y);
	}
	//glVertex2d(420, 600);
	////glVertex2d(400, 550);
	//glVertex2d(400, 450);
	for (int i = 0; i <= t; i++) {
		float pos = (float)i / (float)t;
		GLfloat x = bezierCurve(pos, 400, 390, 390, 430);
		GLfloat y = bezierCurve(pos, 550, 430, 350, 350);
		glVertex2f(x, y);
	}
	//glVertex2d(430, 350);
	for (int i = 0; i <= t; i++) {
		float pos = (float)i / (float)t;
		GLfloat x = bezierCurve(pos, 430, 420, 470, 480);
		GLfloat y = bezierCurve(pos, 350, 330, 290, 300);
		glVertex2f(x, y);
	}
	//glVertex2d(480, 300);
	for (int i = 0; i <= t; i++) {
		float pos = (float)i / (float)t;
		GLfloat x = bezierCurve(pos, 480, 470, 550, 580);
		GLfloat y = bezierCurve(pos, 300, 290, 230, 230);
		glVertex2f(x, y);
	}
	//glVertex2d(550, 260);
	t = 50;
	for (int i = 0; i <= t; i++) {
		float pos = (float)i / (float)t;
		GLfloat x = bezierCurve(pos, 580, 690, 900, 820);
		GLfloat y = bezierCurve(pos, 230, 190, 250, 400);
		glVertex2f(x, y);
	}
	//glVertex2d(650, 240);
	////glVertex2d(800, 300);
	////glVertex2d(1020, 550);
	//glVertex2d(820, 400);
	for (int i = 0; i <= t; i++) {
		float pos = (float)i / (float)t;
		GLfloat x = bezierCurve(pos, 820, 820, 770, 750);
		GLfloat y = bezierCurve(pos, 400, 410, 500, 500);
		glVertex2f(x, y);
	}
	//glVertex2d(770, 500);
	for (int i = 0; i <= t; i++) {
		float pos = (float)i / (float)t;
		GLfloat x = bezierCurve(pos, 750, 780, 680, 700);
		GLfloat y = bezierCurve(pos, 500, 540, 630, 600);
		glVertex2f(x, y);
	}
	//glVertex2d(700, 600);
	for (int i = 0; i <= t; i++) {
		float pos = (float)i / (float)t;
		GLfloat x = bezierCurve(pos, 700, 700, 640, 620);
		GLfloat y = bezierCurve(pos, 600, 630, 630, 630);
		glVertex2f(x, y);
	}
	//glVertex2d(620, 630);
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
	//tubes right side


	glBegin(GL_POLYGON);
	//glVertex2f(620, 630);
	t = 30;
	for (int i = 0; i <= t; i++) {
		float pos = (float)i / (float)t;
		GLfloat x = bezierCurve(pos, 620, 630, 770, 750);
		GLfloat y = bezierCurve(pos, 630, 650, 670, 650);
		glVertex2f(x, y);
	}
	//glVertex2f(750, 650);
	for (int i = 0; i <= t; i++) {
		float pos = (float)i / (float)t;
		GLfloat x = bezierCurve(pos, 750, 760, 780, 770);
		GLfloat y = bezierCurve(pos, 650, 670, 640, 620);
		glVertex2f(x, y);
	}
	//glVertex2f(770, 620);
	t = 10;
	for (int i = 0; i <= t; i++) {
		float pos = (float)i / (float)t;
		GLfloat x = bezierCurve(pos, 770, 750, 640, 640);
		GLfloat y = bezierCurve(pos, 620, 630, 610, 580);
		glVertex2f(x, y);
	}
	//glVertex2f(640, 590);
	glEnd();
	//right 2,3rd tube
	glBegin(GL_POLYGON);
	glVertex2f(710,580);
	//glVertex2f(760,600);
	for (int i = 0; i <= t; i++) {
		float pos = (float)i / (float)t;
		GLfloat x = bezierCurve(pos, 760, 780, 780, 780);
		GLfloat y = bezierCurve(pos, 600, 600, 590, 570);
		glVertex2f(x, y);
	}
	//glVertex2f(780,570);
	for (int i = 0; i <= t; i++) {
		float pos = (float)i / (float)t;
		GLfloat x = bezierCurve(pos, 780, 750, 750, 750);
		GLfloat y = bezierCurve(pos, 570, 560, 540, 560);
		glVertex2f(x, y);
	}
	//glVertex2f(750,560);
	//glVertex2f(780, 540);
	for (int i = 0; i <= t; i++) {
		float pos = (float)i / (float)t;
		GLfloat x = bezierCurve(pos, 780, 800, 780, 780);
		GLfloat y = bezierCurve(pos, 540, 540, 515, 520);
		glVertex2f(x, y);
	}
	//glVertex2f(780, 520);
	glVertex2f(720, 530);

	glEnd();

	glBegin(GL_POLYGON);
	//glVertex2f(360, 520);
	for (int i = 0; i <= t; i++) {
		float pos = (float)i / (float)t;
		GLfloat x = bezierCurve(pos, 360, 340, 350, 360);
		GLfloat y = bezierCurve(pos, 520, 520, 550, 560);
		glVertex2f(x, y);
	}
	//glVertex2f(360, 580);
	glVertex2f(410, 550);
	glVertex2f(410, 510);

	glEnd();
	/*
	glBegin(GL_POLYGON);
	//glVertex2f(360, 470);
	for (int i = 0; i <= t; i++) {
		float pos = (float)i / (float)t;
		GLfloat x = bezierCurve(pos, 360, 340, 350, 360);
		GLfloat y = bezierCurve(pos, 470, 470, 500, 510);
		glVertex2f(x, y);
	}
	//glVertex2f(360, 510);
	glVertex2f(410, 500);
	glVertex2f(410, 460);
	glEnd();
	*/
	glBegin(GL_POLYGON);
	//glVertex2f(360, 470);
	for (int i = 0; i <= t; i++) {
		float pos = (float)i / (float)t;
		GLfloat x = bezierCurve(pos, 360, 340, 350, 360);
		GLfloat y = bezierCurve(pos, 470, 470, 500, 510);
		glVertex2f(x, y);
	}
	//glVertex2f(360, 510);
	glVertex2f(410, 500);
	glVertex2f(410, 460);
	glEnd();

	glBegin(GL_POLYGON);
	//glVertex2f(360, 470);
	for (int i = 0; i <= t; i++) {
		float pos = (float)i / (float)t;
		GLfloat x = bezierCurve(pos, 360, 340, 350, 360);
		GLfloat y = bezierCurve(pos, 570, 570, 600, 610);
		glVertex2f(x, y);
	}
	//glVertex2f(360, 510);
	glVertex2f(410, 600);
	glVertex2f(410, 560);
	glEnd(); 

	glBegin(GL_POLYGON);
	glVertex2f(460, 320);
	glVertex2f(500, 320);
	//glVertex2f(500, 250);
	for (int i = 0; i <= t; i++) {
		float pos = (float)i / (float)t;
		GLfloat x = bezierCurve(pos, 500, 510, 460, 460);
		GLfloat y = bezierCurve(pos, 270, 260, 240, 270);
		glVertex2f(x, y);
	}
	//glVertex2f(460, 250);

	glEnd();


	//AORTA BIG TUBE
	glColor4f(1.0, 0.0, 0.0,1.0);
	glBegin(GL_POLYGON);
	//glVertex2f(610, 650);
	//glVertex2f(510,660);
	glVertex2f(607, 638);
	//glColor3f(1.0, 0.478, 0.537);

	for (int i = 0; i <= t; i++) {
		float pos = (float)i / (float)t;
		GLfloat x = bezierCurve(pos, 610, 610, 510, 510);
		GLfloat y = bezierCurve(pos, 650, 660, 700, 660);
		glVertex2f(x, y);
	}
	glColor3f(1.0, 0.078, 0.180);

	for (int i = 0; i <= t; i++) {
		float pos = (float)i / (float)t;
		GLfloat x = bezierCurve(pos, 510, 510, 410, 483);
		GLfloat y = bezierCurve(pos, 660, 690, 530, 483);
		glVertex2f(x, y);
	}
	//glColor3f(0.690, 0.152, 0.211);
	//glVertex2f(480, 500);
	//glVertex2f(490, 500);
	for (int i = 0; i <= t; i++) {
		float pos = (float)i / (float)t;
		GLfloat x = bezierCurve(pos, 483, 483, 490, 560);
		GLfloat y = bezierCurve(pos, 483, 483, 460, 460);
		glVertex2f(x, y);
	}
	//glVertex2f(560,460);
	for (int i = 0; i <= t; i++) {
		float pos = (float)i / (float)t;
		GLfloat x = bezierCurve(pos, 560, 590, 630, 590);
		GLfloat y = bezierCurve(pos, 460, 460, 530, 530);
		glVertex2f(x, y);
	}
	//glVertex2f(590,530);
	//glVertex2f(590,510);
	glEnd();
	

	//AORTA COVER(SKIN)
	glColor3f(0.9, 0.7, 0.5);
	glBegin(GL_POLYGON);
	//glVertex2f(650,530);
	for (int i = 0; i <= t; i++) {
		float pos = (float)i / (float)t;
		GLfloat x = bezierCurve(pos, 670, 670, 540, 540);
		GLfloat y = bezierCurve(pos, 520, 520, 510, 540);
		glVertex2f(x, y);
	}
	//glVertex2f(520,550);
	for (int i = 0; i <= t; i++) {
		float pos = (float)i / (float)t;
		GLfloat x = bezierCurve(pos, 540, 520, 540, 570);
		GLfloat y = bezierCurve(pos, 540, 540, 630, 630);
		glVertex2f(x, y);
	}
	//glVertex2f(550, 610);
	for (int i = 0; i <= t; i++) {
		float pos = (float)i / (float)t;
		GLfloat x = bezierCurve(pos, 570, 570, 670, 670);
		GLfloat y = bezierCurve(pos, 630, 640, 640, 630);
		glVertex2f(x, y);
	}
	//glVertex2f(650, 610);
	glEnd();
	glFlush();


	//AORTA TUBE 1
	glColor3f(1.0, 0.078, 0.180); //CHANGED COLOR TO LRED
	glBegin(GL_POLYGON);
	glVertex2f(510, 630);
	glVertex2f(555, 630);
	//glVertex2f(520, 730);
	for (int i = 0; i <= t; i++) {
		float pos = (float)i / (float)t;
		GLfloat x = bezierCurve(pos, 515, 505, 480, 490);
		GLfloat y = bezierCurve(pos, 710, 720, 690, 680);
		glVertex2f(x, y);
	}
	//glVertex2f(500, 700);
	glEnd();

	//AORTA TUBE 2
	glBegin(GL_POLYGON);
	glVertex2f(540, 630);
	glVertex2f(585, 630);
	//glVertex2f(590, 740);
	for (int i = 0; i <= t; i++) {
		float pos = (float)i / (float)t;
		GLfloat x = bezierCurve(pos, 585, 585, 540, 540);
		GLfloat y = bezierCurve(pos, 720, 740, 740, 720);
		glVertex2f(x, y);
	}
	//glVertex2f(550, 740);
	glEnd();

	//AORTA TUBE 3
	glBegin(GL_POLYGON);
	//glVertex2f(620, 730);
	for (int i = 0; i <= t; i++) {
		float pos = (float)i / (float)t;
		GLfloat x = bezierCurve(pos, 615, 625, 650, 640);
		GLfloat y = bezierCurve(pos, 710, 720, 690, 680);
		glVertex2f(x, y);
	}
	//glVertex2f(640, 700);
	glVertex2f(610, 650);
	glVertex2f(565, 650);
	glEnd();

	//AORTA TUBES COVER
	glColor3f(1.0, 0.078, 0.180);
	glBegin(GL_POLYGON);
	//glVertex2f(520, 700);
	for (int i = 0; i <= t; i++) {
		float pos = (float)i / (float)t;
		GLfloat x = bezierCurve(pos, 520, 520, 630, 620);
		GLfloat y = bezierCurve(pos, 680, 695, 695, 680);
		glVertex2f(x, y);
	}
	//glVertex2f(630, 700);
	glVertex2f(600, 640);
	glVertex2f(550, 640);
	glEnd();

	//AORTA INNER VEINS 1
	/////////////////////////////////////////////////////////////////////////////////////
	
	glColor3f(1.0, 0.078, 0.180);
	glLineWidth(8);
	glBegin(GL_LINE_STRIP);
	//glVertex2f(500, 390);
	t = 10;
	for (int i = 0; i <= t; i++) {
		float pos = (float)i / (float)t;
		GLfloat x = bezierCurve(pos, 500, 500, 450, 450);
		GLfloat y = bezierCurve(pos, 490, 420, 420, 350);
		//glColor3f(1.0 - inc, 0.078 - inc, 0.180 - inc);
		glVertex2f(x, y);

	}
	glEnd();
	
	////////////////////////////////
	//AORTA INNER VEINS 2
	glBegin(GL_LINE_STRIP);
	t = 20;
	//glVertex2f(490, 450);
	for (int i = 0; i <= t; i++) {

		float pos = (float)i / (float)t;
		GLfloat x = bezierCurve(pos, 490, 470, 500, 550);
		GLfloat y = bezierCurve(pos, 450, 450, 300, 260);
		//glColor3f(1.0 - inc, 0.078 - inc, 0.180 - inc);
		glVertex2f(x, y);
	}
	//glVertex2f(500, 350);
	//glVertex2f();
	glEnd();

	glLineWidth(8);
	////////////////
	//AORTA INNER VEINS 3
	glBegin(GL_LINE_STRIP);
	//glVertex2f(600, 510);
	t = 30;
	for (int i = 0; i <= t; i++) {
		float pos = (float)i / (float)t;
		GLfloat x = bezierCurve(pos, 595, 650, 800, 780);
		GLfloat y = bezierCurve(pos, 515, 540, 480, 450);
		//glColor3f(1.0 - inc, 0.078 - inc, 0.180 - inc);
		glVertex2f(x, y);
	}
	//glVertex2f(630, 250);
	glEnd();

	/////////////////////
	//AORTA INNER VEINS 4
	glLineWidth(5);

	glBegin(GL_LINE_STRIP);
	//glVertex2f(700, 510);
	for (int i = 0; i <= t; i++) {
		float pos = (float)i / (float)t;
		GLfloat x = bezierCurve(pos, 700, 670, 770, 750);
		GLfloat y = bezierCurve(pos, 510, 470, 430, 300);
		//glColor3f(1.0 - inc, 0.078 - inc, 0.180 - inc);
		glVertex2f(x, y);
	}
	//glVertex2f(620, 250);
	glEnd();

	////////////////////
	//AORTA INNER VEINS 5

	glBegin(GL_LINE_STRIP);
	//glVertex2f(780, 450);		
	for (int i = 0; i <= t; i++) {
		float pos = (float)i / (float)t;
		GLfloat x = bezierCurve(pos, 780, 780, 650, 650);
		GLfloat y = bezierCurve(pos, 450, 400, 420, 350);
		//glColor3f(1.0 - inc, 0.078 - inc, 0.180 - inc);
		glVertex2f(x, y);
	}
	//glVertex2f(650, 350);
	glEnd();

	////////////////////////////////
	//AORTA INNER VEINS 6-1
	glBegin(GL_LINE_STRIP);
	//glVertex2f(450, 350);
	for (int i = 0; i <= t; i++) {
		float pos = (float)i / (float)t;
		GLfloat x = bezierCurve(pos, 450, 450, 600, 650);
		GLfloat y = bezierCurve(pos, 350, 300, 400, 250);
		//glColor3f(1.0 - inc, 0.078 - inc, 0.180 - inc);
		glVertex2f(x, y);
	}
	//glVertex2f(650, 250);
	glEnd();

	/////////////////////
	//AORTA INNER VEINS 2-6
	glBegin(GL_LINE_STRIP);
	//glVertex2f(550, 340);
	for (int i = 0; i <= t; i++) {
		float pos = (float)i / (float)t;
		GLfloat x = bezierCurve(pos, 550, 550, 600, 600);
		GLfloat y = bezierCurve(pos, 340, 250, 250, 250);
		//glColor3f(1.0 - inc, 0.078 - inc, 0.180 - inc);
		glVertex2f(x, y);
	}
	//glVertex2f(600, 250); 
	glEnd();

	glBegin(GL_LINE_STRIP);
	//glVertex2f(700, 400);
	for (int i = 0; i <= t; i++) {
		float pos = (float)i / (float)t;
		GLfloat x = bezierCurve(pos, 700, 650, 770, 740);
		GLfloat y = bezierCurve(pos, 405, 340, 310, 270);
		//glColor3f(1.0 - inc, 0.078 - inc, 0.180 - inc);
		glVertex2f(x, y);
	}
	//glVertex2f(740, 270);
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
	glViewport(150, -50, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,(GLdouble)w, 0.0, (GLdouble)h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// printf_s("%d\n", w);
	// printf_s("%d\n", h);
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
	glViewport(0, 0, ww, wh);

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
	//glutTimerFunc(1500, update, 0);
	glutMainLoop();
	return 0;
}



