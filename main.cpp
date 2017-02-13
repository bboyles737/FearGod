#include <stdio.h>

#include "GL/freeglut.h"

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1440, 900);
    glutInitWindowPosition(100, 50);
    glutCreateWindow("FEAR GOD and DREAD NOUGHT");

    glutDisplayFunc(display);
    glutMainLoop();
}
