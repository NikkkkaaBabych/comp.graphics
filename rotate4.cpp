
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
    static int time = 0;// ��� ���

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix(); // �������� ������ ����������, ���� �� ��� �����

                  // � ������� ��� ������� ����������� �� ���������� �����������

    glRotated(time / 20, 0.0, 1.0, 0.0); // ��������� ����������

    glLineWidth(5); // ������������ ������� �� - �'���

    glColor3f(1, 0, 0); // ������������ �������� ���� - ��������

    glBegin(GL_LINES); // ������� ������� ���, ���� �� �� ��������� ����������,

    glVertex3d(-0.3, 0, 0); // ��� ���� ��������� � ���������� �����������,

    glVertex3d(1.5, 0, 0); // � ���� ������� display ����������� � ����, � �����

    glEnd(); // time ���������� �� ������� ��� ������� ������� display, ��

                           // �������� ������� - �������� ���

    glPushMatrix(); // ����� ���� ���������� ���������

                    // �� ���������� �� ����� ���������             

    glRotated(2 * time, 1, 0, 0); // ��������� �� �� ��� 2 * time ������� ������� ��

    glTranslated(-0.3, 0, 0); // � ������� �� ���� ��

    glColor3f(0, 0, 1); // ������������ ���� ����

    glPushMatrix(); // ����� �� ��� ���������� �� ����� ���������,

    glRotated(90, 0, 1, 0); // ��� ���������� ��� �� 90 �������

    glLineWidth(1);

    auxWireTorus(0.2, 0.7);

    glPopMatrix(); // ����������� ���, �� ����������� �� ��������� ���������

                             // ������� ��� ��������� ������ �� ���� ������� ��

    glLineWidth(7);

    glColor3f(0, 1, 0);

    glBegin(GL_LINES); // ����� ������� ��� ������� ��

    glVertex3d(0, 0, 0);

    glVertex3d(0, 1, 0);

    glVertex3d(0, 0, 0);

    glVertex3d(0, -0.5, 1);

    glVertex3d(0, 0, 0);

    glVertex3d(0, -0.5, -1);

    glEnd();

    glPopMatrix(); // ����� ����������� �� ���������, ���������� �� ��� time / 2

    glPopMatrix(); // � ���������� �� ���������� ���������

    time++; // �������� �������� ����� ��� ��� �� �������

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

    //glEnable(GL_LIGHTING);
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
