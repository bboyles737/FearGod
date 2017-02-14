#include <stdio.h>

#include "GL/freeglut.h"
#include "GameWindow.h"
#include "Windows.h"

GameWindow gameW = GameWindow(1440, 900);

/** Debugging idle and display functions - to be deleted or ignored.
  */
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

    gameW.setView();
    gameW.render();

    glutSwapBuffers();
}

void specialKeys(int key, int mouseX, int mouseY) {
    if (key == GLUT_KEY_PAGE_UP) gameW.getMap()->enableCentering();
    else if (key == GLUT_KEY_PAGE_DOWN) gameW.getMap()->enableZooming();
}

void passiveMouse(int mouseX, int mouseY) {
    gameW.mouseHover(mouseX, mouseY);
}

void mouseClick(int button, int state, int mouseX, int mouseY) {
    gameW.mouseClick(button, state, mouseX, mouseY);
    glutPostRedisplay();
}

void noReshape(int newWidth, int newHeight) {
    glutReshapeWindow(1440, 900);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(1440, 900);
    glutInitWindowPosition(450, 50);
    glutCreateWindow("Fear God and Dreadnought");

    glutSpecialFunc(specialKeys);
    glutMouseFunc(mouseClick);
    glutPassiveMotionFunc(passiveMouse);
    glutReshapeFunc(noReshape);

    glutDisplayFunc(display);

    glutMainLoop();
}
