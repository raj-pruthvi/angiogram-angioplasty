#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <GL/glut.h>

#ifndef M_PI
#define M_PI 3.14159265
#endif


int needsLightUpdate = GL_TRUE;
int useLighting = GL_TRUE;
int useSpecularTexture = GL_FALSE;
int useTexture = GL_FALSE;
int useHighRes = GL_FALSE;
int usePattern = GL_FALSE;

int moveLight = GL_FALSE;
int moveObject = GL_FALSE;

int drawObj = 0, maxObj = 2;
GLfloat lightRotX, lightRotY;
GLfloat objectRotX, objectRotY;
int curx, cury, width, height;

void drawCylinder(int numMajor, int numMinor, float height, float radius) {
    double majorStep = height / numMajor;
    double minorStep = 2.0 * M_PI / numMinor;
    int i, j;

    for (i = 0; i < numMajor; ++i) {
        GLfloat z0 = 0.5 * height - i * majorStep;
        GLfloat z1 = z0 - majorStep;
        glBegin(GL_TRIANGLE_STRIP);
        for (j = 0; j <= numMinor; ++j) {
            double a = j * minorStep;
            GLfloat x, y;
            if (i <= numMajor / 2){
                x = radius * cos(a/2);
                y = radius * sin(a/2);
            }
            else{
                x = radius * cos(a);
                y = radius * sin(a);
            }
            //glNormal3f(x / radius, y / radius, 0.0);
            //glTexCoord2f(j / (GLfloat) numMinor, i / (GLfloat) numMajor);
            glVertex3f(x, y, z0);

            //glNormal3f(x / radius, y / radius, 0.0);
            //glTexCoord2f(j / (GLfloat) numMinor, (i + 1) / (GLfloat) numMajor);
            glVertex3f(x, y, z1);
        }
        glEnd();
    }
}

void initialize(void) {
    glMatrixMode(GL_PROJECTION);
    glFrustum(-0.50, 0.50, -0.50, 0.50, 1.0, 3.0);
    glMatrixMode(GL_MODELVIEW);
    glTranslatef(0.0, 0.0, -2.0);

    glDepthFunc(GL_LEQUAL);

    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
}

void redraw(void) {
    glClearColor(1.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.5);
    glVertex3f(-2.0, -2.0, -1.0);
    glColor3f(0.0, 0.0, 0.5);
    glVertex3f(2.0, -2.0, -1.0);
    glColor3f(0.0, 0.0, 0.3);
    glVertex3f(2.0, 2.0, -1.0);
    glColor3f(0.0, 0.0, 0.3);
    glVertex3f(-2.0, 2.0, -1.0);
    glEnd();
    glEnable(GL_DEPTH_TEST);
    if (useLighting) {
        glEnable(GL_LIGHTING);
        glPushMatrix();
        glRotatef(lightRotY, 0, 1, 0);
        glRotatef(lightRotX, 1, 0, 0);
        glPopMatrix();
    } else {
        glColor3f(1.0, 0.0, 0.0);
    }
    if (useTexture || useSpecularTexture) {
        glEnable(GL_TEXTURE_2D);
    }

    if (useSpecularTexture) {
        /* pass one */
        glEnable(GL_BLEND);
        glBlendFunc(GL_ONE, GL_ZERO);
    }

    glPushMatrix();
    glRotatef(objectRotY, 0, 1, 0);
    glRotatef(objectRotX, 1, 0, 0);
    drawCylinder(6, 16, 2.0, 0.1);
        // glBegin(GL_POLYGON);
        //     GLUquadricObj *obj = gluNewQuadric();
        //         gluCylinder(obj, 0.0, 1.0, 6, 15, 15);
        // glEnd();
    glPopMatrix();

    if (useSpecularTexture) {
        /* pass two */
        if (!useLighting) {
            glColor3f(1.0, 0.0, 0.0);
        }
        glBlendFunc(GL_ONE, GL_ONE);
        glEnable(GL_TEXTURE_GEN_S);
        glEnable(GL_TEXTURE_GEN_T);
        glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
        glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
        glPushMatrix();
        glRotatef(objectRotY, 0, 1, 0);
        glRotatef(objectRotX, 1, 0, 0);        
        drawCylinder(6, 16, 1.0, 0.1);
        // glBegin(GL_POLYGON);
        //     GLUquadricObj *obj = gluNewQuadric();
        //         gluCylinder(obj, 0.0, 1, 6, 15, 15);
        // glEnd();

        glPopMatrix();
    }
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_BLEND);
    glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
}

void motion(int x, int y) {
    if (moveLight || moveObject) {
        GLfloat dx = (y - cury) * 360.0 / height;
        GLfloat dy = (x - curx) * 360.0 / width;
        if (moveLight) {
            lightRotX += dx;
            if (lightRotX > 360)
            lightRotX -= 360;
            if (lightRotX < 0)
            lightRotX += 360;
            lightRotY += dy;
            if (lightRotY > 360)
            lightRotY -= 360;
            if (lightRotY < 0)
            lightRotY += 360;
            needsLightUpdate = GL_TRUE;
        }
       else if (moveObject) {
            GLfloat dx = (y - cury) * 360.0 / height;
            GLfloat dy = (x - curx) * 360.0 / width;

            objectRotX += dx;
            if (objectRotX > 360)
            objectRotX -= 360;
            if (objectRotX < 0)
            objectRotX += 360;
            objectRotY += dy;
            if (objectRotY > 360)
            objectRotY -= 360;
            if (objectRotY < 0)
            objectRotY += 360;
        }
        curx = x;
        cury = y;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
    if (state == GLUT_DOWN) {
        switch (button) {
            case GLUT_LEFT_BUTTON:
            moveObject = GL_TRUE;
            motion(curx = x, cury = y);
            break;
            case GLUT_MIDDLE_BUTTON:
            moveLight = GL_TRUE;
            motion(curx = x, cury = y);
            break;
        }
    } 
    else if (state == GLUT_UP) {
        switch (button) {
            case GLUT_LEFT_BUTTON:
            moveObject = GL_FALSE;
            break;
            case GLUT_MIDDLE_BUTTON:
            moveLight = GL_FALSE;
            break;
        }
    }
}

void display(void) {
    redraw();
    glFlush();
    glutSwapBuffers();
}

int main (int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(width = 500, height = 500);                                  
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    for (int i = 1; i < argc; ++i) {
        exit(1);
    }
    glutCreateWindow("vessel");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    initialize();
    glutMainLoop();
    return 0;
}
