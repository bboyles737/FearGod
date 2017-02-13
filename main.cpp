#include <stdio.h>

#include "GL/freeglut.h"
#include "Window.h"
#include "Windows.h"

Window mw = Window("Fear God");
Window mx = Window("Fear Blue");
int mode = 1;

void idleA() {
    Sleep(100);
    printf("Window A Idler\n");
}

void idleB() {
    Sleep(33);
    printf("Window B Idler\n");
}

void idleC() {
    Sleep(100);
    printf("Current window active: %d in mode %d\n", glutGetWindow(), mode);
}

void dispBlack() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

void dispRed() {
    glClearColor(1.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

void dispGreen() {
    glClearColor(0.0, 1.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

void dispBlue() {
    glClearColor(0.0, 0.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

void spec(int key, int mouseX, int mouseY) {
    if (key == GLUT_KEY_PAGE_DOWN) mode = mode - 1;
    else if (key == GLUT_KEY_PAGE_UP) mode = mode + 1;
    if (mode <= 0) mode += 3;
    else  if (mode > 3) mode -= 3;


    if (key == GLUT_KEY_UP) mw.setDisplay(dispRed, mode);
    else if (key == GLUT_KEY_DOWN) mw.setDisplay(dispBlue, mode);
    else if (key == GLUT_KEY_LEFT) mw.setDisplay(dispGreen, mode);
    else if (key == GLUT_KEY_RIGHT) mw.setDisplay(dispBlack, mode);

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);


    mw.setDisplay(dispBlue);
    mw.gen();



    /*
    mx.setPos(500, 0);
    mx.setSize(300, 300);
    mx.setDisplay(dispRed);
    mx.gen();
    */
    glutSpecialFunc(spec);

    glutIdleFunc(idleC);

    //mx.setIdle(idleB);
    /*glutInitWindowSize(1440, 900);
    glutInitWindowPosition(100, 50);
    glutCreateWindow("FEAR GOD and DREAD NOUGHT");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 5.0, -2.5, 2.5);
    glutDisplayFunc(dispRed);
    */
    glutMainLoop();
}
