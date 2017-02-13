#include "Helpers.h"

#include "GL/freeglut.h"

double screenToWorld(int mouseLoc, double worldMin, double worldMax,
                    int screenMin, int screenMax, bool invert) {

    double ratioScreen = (double)mouseLoc / (screenMax - screenMin);
    if (invert) ratioScreen = 1 - ratioScreen;
    return ratioScreen * (worldMax - worldMin) + worldMin;
}

// Simple versions of the verbose screenToWorld function
double screenToWorldX(int screenX) {
    return screenToWorld(screenX, 0.0, 1.0, 0, glutGet(GLUT_WINDOW_WIDTH), false);
}

double screenToWorldY(int screenY) {
    return screenToWorld(screenY, 0.0, 1.0, 0, glutGet(GLUT_WINDOW_HEIGHT), true);
}
