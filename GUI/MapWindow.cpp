#include "MapWindow.h"
#include "GL/freeglut.h"
#include <stdio.h>

MapWindow::MapWindow(int sizeX, int sizeY)
{
    this->setSize(sizeX, sizeY);
    this->setPos(0, 0);
    this->setBGColor(1.0, 0.0, 1.0);

    this->mapRatio = (double)sizeX / sizeY;
    this->mapZoom = 100;
    this->mapLLH = Vec2(0, 0);
    this->mapWorldDim = Vec2(this->mapZoom * this->mapRatio, this->mapZoom);
}

void MapWindow::render() {
    // Need to change the projection window and viewport
    // based on the map's location
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(this->mapLeft(), this->mapRight(), this->mapBot(), this->mapTop());

    // Need to account for y-axis inversion
    // Note the game window size is hard-coded.
    glViewport(this->pos.x, 900 - this->sz.y + this->pos.y, this->sz.x, this->sz.y);

    glColor3f(0.0, 1.0, 1.0);
    glRecti(this->mapLeft(), this->mapBot(), this->mapRight(), this->mapTop());
}

int MapWindow::mapLeft() {return this->mapLLH.x;}
int MapWindow::mapRight() {return this->mapLLH.x + this->mapWorldDim.x;}
int MapWindow::mapTop() {return this->mapLLH.y + this->mapWorldDim.y;}
int MapWindow::mapBot() {return this->mapLLH.y;}

void MapWindow::mouseHover(int mouseX, int mouseY) {
    printf("Mouse is hovering over MAP window at %d, %d\n", mouseX, mouseY);
}
