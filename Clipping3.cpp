
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
    GLdouble equation0[4] = {-1, -0.25, 0, 1 };
    GLdouble equation1[4] = { 1, -0.25, 0, 1 };
    GLdouble equation2[4] = { 0,  1,    0, 2 };
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_CLIP_PLANE0);
    glClipPlane(GL_CLIP_PLANE0, equation0);
    glEnable(GL_CLIP_PLANE1);
    glClipPlane(GL_CLIP_PLANE1, equation1);
    glEnable(GL_CLIP_PLANE2);
    glClipPlane(GL_CLIP_PLANE2, equation2);
    glColor3d(1, 0, 1);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_TRIANGLES);
    glColor3d(1, 0, 1);
    glVertex3d(-1.2, 0, 0);
    glVertex3d(0, 3, 0);
    glVertex3d(1.2, 0, 0);
    glColor3d(0, 0, 1);
    glVertex3d(0.2, 0.2, 1);
    glVertex3d(0.2, 2, 1);
    glVertex3d(2, 0.5, 1);
    glEnd();
    glTranslated(0, -3, 0);
    auxSolidSphere(2);
    glTranslated(0,  3, 0);
    glDisable(GL_CLIP_PLANE0);
    glDisable(GL_CLIP_PLANE1);
    glDisable(GL_CLIP_PLANE2);
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


    /*
    * Enter your cod here
    */
    auxMainLoop(display);
}
