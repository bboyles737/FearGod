#include <stdio.h>

#include "GL/freeglut.h"
#include "GameWindow.h"
#include "Windows.h"

GameWindow x = GameWindow(1440, 900);

void idleA() {
    Sleep(100);
    printf("Window A Idler\n");
}

void idleB() {
    Sleep(33);
    printf("Window B Idler\n");
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

void display() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    x.setView();
    x.render();

    glutSwapBuffers();
}

void spec(int key, int mouseX, int mouseY) {

}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);



    glutInitWindowSize(1440, 900);
    glutInitWindowPosition(100, 50);
    glutCreateWindow("FEAR GOD and DREAD NOUGHT");
    glutSpecialFunc(spec);


    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    //gluOrtho2D(0.0, 5.0, -2.5, 2.5);
    glutDisplayFunc(display);

    glutMainLoop();
}
