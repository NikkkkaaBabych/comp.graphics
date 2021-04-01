#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GLAux.h>

void CALLBACK resize(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5, 5, -5, 5, 2, 12);
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
    glMatrixMode(GL_MODELVIEW);
}

void CALLBACK display(void)
{
    GLUquadricObj* quadObj;
    quadObj = gluNewQuadric();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glTranslated(-4, 4, 0); 
    glColor3d(1, 0, 0);
    gluQuadricDrawStyle(quadObj, GLU_FILL);
    gluSphere(quadObj, 0.5, 10, 10);
    glTranslated(2, 0, 0);
    gluCylinder(quadObj, 0.5, 0.75, 1, 15, 15);
    glTranslated(2, 0, 0);
    gluDisk(quadObj, 0.1, 1, 7, 7);
    glTranslated(2, 0, 0);
    gluPartialDisk(quadObj, 0.5, 0.8, 12, 12, 15, 330);

    glTranslated(-6, -2, 0);
    glColor3d(0, 1, 0);
    gluQuadricDrawStyle(quadObj, GLU_LINE);
    gluSphere(quadObj, 0.5, 10, 10);
    glTranslated(2, 0, 0);
    gluCylinder(quadObj, 0.5, 0.75, 1, 15, 15);
    glTranslated(2, 0, 0);
    gluDisk(quadObj, 0.1, 1, 7, 7);
    glTranslated(2, 0, 0);
    gluPartialDisk(quadObj, 0.5, 0.8, 12, 12, 15, 330);

    glTranslated(-6, -2, 0);
    glColor3d(0, 0, 1);
    gluQuadricDrawStyle(quadObj, GLU_SILHOUETTE);
    gluSphere(quadObj, 0.5, 10, 10);
    glTranslated(2, 0, 0);
    gluCylinder(quadObj, 0.5, 0.75, 1, 15, 15);
    glTranslated(2, 0, 0);
    gluDisk(quadObj, 0.1, 1, 7, 7);
    glTranslated(2, 0, 0);
    gluPartialDisk(quadObj, 0.5, 0.8, 12, 12, 15, 330);

    glTranslated(-6, -2, 0);
    glColor3d(1, 1, 1);
    gluQuadricDrawStyle(quadObj, GLU_POINT);
    gluSphere(quadObj, 0.5, 10, 10);
    glTranslated(2, 0, 0);
    gluCylinder(quadObj, 0.5, 0.75, 1, 15, 15);
    glTranslated(2, 0, 0);
    gluDisk(quadObj, 0.1, 1, 7, 7);
    glTranslated(2, 0, 0);
    gluPartialDisk(quadObj, 0.5, 0.8, 12, 12, 15, 330);

    glPopMatrix();
    
    gluDeleteQuadric(quadObj);
    auxSwapBuffers();
}



int main()
{
    float pos[4] = { 3,3,3,1 };
    float dir[3] = { -1,-1,-1 };

    GLfloat mat_specular[] = { 1,1,1,1 };

    auxInitPosition(50, 10, 400, 400);
    auxInitDisplayMode(AUX_RGB | AUX_DEPTH | AUX_DOUBLE);
    auxInitWindowA("Kotelevska IN82");
    auxIdleFunc(display);
    auxReshapeFunc(resize);


    glEnable(GL_DEPTH_TEST);

    glEnable(GL_COLOR_MATERIAL);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glLightfv(GL_LIGHT0, GL_POSITION, pos);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, dir);

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, 128.0);

    auxMainLoop(display);
}
