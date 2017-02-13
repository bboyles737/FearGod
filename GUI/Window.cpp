#include <stdio.h>
#include "Window.h"

Window::Window(std::string winName)
{
    this->dispFunc = NULL;
    this->active = false;
    this->name = winName;
    this->windowID = -1;
    this->pos = Vec2(0, 0);
    this->sz = Vec2(1440, 900);
}

void Window::setDisplay(void (*f)(), int subwindow) {
    if (this->windowID == -1) {
        this->dispFunc = f;
        return;
    }

    if (subwindow == 1) glutSetWindow(this->windowID);
    else if (subwindow == 2) glutSetWindow(this->winA);
    else if (subwindow == 3) glutSetWindow(this->winB);

    glutDisplayFunc(f);

}

void Window::setSize(int x, int y) {
    if (x < 1 || y < 1) {
        printf("ERROR: Can't set size of window %s to %d, %d: dimensions must be > 0\n",
               this->name.c_str(), x, y);
        return;
    }
    this->sz = Vec2(x, y);
}

void Window::setPos(int x, int y) {
    if (x < 0 || y < 0) {
        printf("ERROR: Can't set pos of window %s to %d, %d: dimensions must be >= 0\n",
               this->name.c_str(), x, y);
        return;
    }
    this->pos = Vec2(x, y);
}

void dG() {
    glClearColor(0.0, 1.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

void dB() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

// Creates the window
void Window::gen() {
    if (this->dispFunc == NULL) {
        printf("ERROR: Can't spawn window >%s<: display function not defined\n", this->name.c_str());
        return;
    }
    if (this->active) {
        printf("ERROR: Can't spawn window >%s<: already active\n", this->name.c_str());
        return;
    }
    this->active = true;

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(this->pos.x, this->pos.y);
    glutInitWindowSize(this->sz.x, this->sz.y);
    this->windowID = glutCreateWindow(name.c_str());
    glutDisplayFunc(this->dispFunc);

    this->winA = glutCreateSubWindow(this->windowID, 0, 0, 400, 400);
    glutDisplayFunc(dG);
    this->winB = glutCreateSubWindow(this->windowID, 500, 0, 300, 300);
    glutDisplayFunc(dB);
    glutSetWindow(this->windowID);
}
