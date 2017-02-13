#include <stdio.h>

#include "GUIObj.h"
#include "GL/freeglut.h"

GUIObj::GUIObj(){
    this->pos = Vec2(0, 0);
    this->size = Vec2(100, 100);
    this->setBGColor(1.0, 1.0, 1.0);
}

void GUIObj::render() {
    glColor3f(this->bgColor.x, this->bgColor.y, this->bgColor.z);

}

void GUIObj::setSize(int x, int y) {
    if (x < 0 || y < 0) {
        printf("GUI Object size %d, %d can't be negative.\n", x, y);
        return;
    }
    this->size = Vec2(x, y);
}

void GUIObj::setPos(int x, int y) {
    if (x < 0 || y < 0) {
        printf("GUI Object pos %d, %d can't be negative.\n", x, y);
        return;
    }
    this->pos = Vec2(x, y);
}

void GUIObj::setBGColor(double r, double g, double b) {
    if (r < 0 || r > 1 || g < 0 || g > 1 || b < 0 || b > 1) {
        printf("GUI Object background color (float) %f, %f, %f must be between 0.0-1.0\n",
               r, g, b);
       return;
    }
    this->bgColor = Vec3f(r, g, b);
}

void GUIObj::setBGColorub(int r, int g, int b) {
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
        printf("GUI Object background color (int) %d, %d, %d must be between 0-255\n",
               r, g, b);
        return;
    }
    this->bgColor = Vec3f(r / 255.0, g / 255.0, b / 255.0);
}

bool GUIObj::collide(int mouseX, int mouseY) {
    int screenxMin = this->pos.x;
    int screenxMax = this->pos.x + this->size.x;
    if (screenxMin < mouseX && screenxMax > mouseX) return true;

    int screenyMin = this->pos.y;
    int screenyMax = this->pos.y + this->size.y;
    if (screenyMin < mouseY && screenyMax > mouseY) return true;
    return false;
}