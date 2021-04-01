
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

float density;
void CALLBACK Key_UP(void)
{
    density += (float)0.1;
    glFogf(GL_FOG_DENSITY, density);
}
void CALLBACK Key_DOWN(void)
{
    density -= (float)0.1;
    glFogf(GL_FOG_DENSITY, density);
}


void CALLBACK display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1, 1, 1);
    auxSolidSphere(1);
    glPushMatrix();
    glTranslated(0, -2, 0);
    auxSolidSphere(1.5);
    glPopMatrix();
    glPushMatrix();
    glTranslated(0, 1.3, 0);
    auxSolidSphere(0.7);
    glColor3d(1, 0, 0);
    auxSolidCone(0.5, 1);
    glColor3d(0, 0, 1);
    glRotated(-90, 1, 0, 0);
    glTranslated(0, 0, 0.6);
    auxSolidCone(0.5, 1);
    glColor3d(0, 0, 0);
    glTranslated(0.3, -1, -0.4);
    auxSolidSphere(0.1);
    glTranslated(-0.6, 0, 0);
    auxSolidSphere(0.1);
    glPopMatrix();
    glPushMatrix();
    glTranslated(0, 1, 1);
    auxSolidBox(0.3, 0.1, 0.1);
    glPopMatrix();
    auxSwapBuffers();
}



int main()
{
    float pos[4] = { 3,3,3,1 };
    float dir[3] = { -1,-1,-1 };
    float fogcolor[4] = { 0.25,0.25,0.25,1 }; // колір туману
    auxInitPosition(50, 10, 400, 400);
    auxInitDisplayMode(AUX_RGB | AUX_DEPTH | AUX_DOUBLE);
    auxInitWindowA("Snowman");
    auxIdleFunc(display);
    auxReshapeFunc(resize);
    auxKeyFunc(AUX_UP, Key_UP); // встановлюємо обробник
    auxKeyFunc(AUX_DOWN, Key_DOWN); // стрілок вгору / вниз
    glEnable(GL_FOG); // дозволяємо туман
    glGetFloatv(GL_FOG_DENSITY, &density); // отримуємо значення щільності
    glFogfv(GL_FOG_COLOR, fogcolor); // встановлюємо колір туману
    glEnable(GL_ALPHA_TEST);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glLightfv(GL_LIGHT0, GL_POSITION, pos);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, dir);
    auxMainLoop(display);
    return 0;
}
