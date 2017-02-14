#include "MapWindow.h"
#include "Helpers.h"
#include "GL/freeglut.h"
#include <stdio.h>
#include <sstream>

MapWindow::MapWindow(int sizeX, int sizeY)
{
    this->setSize(sizeX, sizeY);
    this->setPos(0, 0);
    this->setBGColor(1.0, 0.0, 1.0);

    this->mapRatio = (double)sizeX / sizeY;
    this->mapZoom = 100;
    this->gridSpacing = 25;
    this->showGridLabels = true;
    this->mapLLH = Vec2(0, 0);
    this->mapWorldDim = Vec2(this->mapZoom * this->mapRatio, this->mapZoom);
    this->centerMode = true;
}

void MapWindow::enableCentering() {
    this->centerMode = true;
    printf ("Map center mode enabled\n");
}
void MapWindow::enableZooming() {
    this->centerMode = false;
    printf ("Map zoom mode enabled\n");
}

void MapWindow::zoomIn() {
    int newZoom = this->mapZoom / 2;
    if (newZoom < 100) newZoom = 100;
    this->zoomTo(newZoom);
    printf ("Map zoomed in to level: %d\n", this->mapZoom);
}

void MapWindow::zoomOut() {
    int newZoom = this->mapZoom * 2;
    if (newZoom > 6400) newZoom = 6400;
    this->zoomTo(newZoom);
    printf ("Map zoomed out to level: %d\n", this->mapZoom);
    this->recalcMapSize();
}

void MapWindow::zoomTo(int newZoom) {
    if (newZoom < 100) this->mapZoom = 100;
    else this->mapZoom = newZoom;
    this->recalcMapSize();
}

void MapWindow::recalcMapSize() {
    this->mapWorldDim.x = this->mapZoom * this->mapRatio;
    this->mapWorldDim.y = this->mapZoom;
    printf("New world dimensions: %d, %d\n", this->mapWorldDim.x, this->mapWorldDim.y);
    this->mapLLH.x = this->mapCentX() - (this->mapWorldDim.x / 2);
    this->mapLLH.y = this->mapCentY() - (this->mapWorldDim.y / 2);

    this->gridSpacing = this->mapZoom / 4;
}

void MapWindow::drawGridlines(int spacing) {
    glColor3f(1.0, 1.0, 0.0);
    std::ostringstream txt;

    for (int x = this->mapLeft() / spacing; x <= this->mapRight() / spacing; x++) {
        glBegin(GL_LINES);
            glVertex2i(x*spacing, this->mapTop());
            glVertex2i(x*spacing, this->mapBot());
        glEnd();
        txt << (x*spacing);
        drawStringBitmap(x*spacing + 0.02*this->mapZoom, this->mapBot() + 0.02*this->mapZoom, txt.str());
        txt.str("");
    }
    for (int y = this->mapBot() / spacing; y <= this->mapTop() / spacing; y++) {
        glBegin(GL_LINES);
            glVertex2i(this->mapLeft(), y*spacing);
            glVertex2i(this->mapRight(), y*spacing);
        glEnd();
        txt << (y*spacing);
        drawStringBitmap(this->mapLeft() + 0.02*this->mapZoom, y*spacing + 0.02*this->mapZoom, txt.str());
        txt.str("");
    }
    glEnd();
}

void MapWindow::centerMapOn(int mapX, int mapY) {
    this->mapLLH.x = mapX - this->mapXSize() / 2;
    this->mapLLH.y = mapY - this->mapYSize() / 2;
}

void MapWindow::centerMapOn(Vec2 newMapCenter) {this->centerMapOn(newMapCenter.x, newMapCenter.y);}

void MapWindow::render() {
    // Need to change the projection window and viewport
    // based on the map's location
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(this->mapLeft(), this->mapRight(), this->mapBot(), this->mapTop());

    // Need to account for y-axis inversion
    // Note the game window size is hard-coded.
    glViewport(this->pos.x, this->yInv(), this->sz.x, this->sz.y);

    glColor3f(0.0, 0.0, 0.0);
    glRecti(this->mapLeft(), this->mapBot(), this->mapRight(), this->mapTop());
    drawGridlines(this->gridSpacing);
}

Vec2 MapWindow::scrToMap(int mouseX, int mouseY) {
    double ratioX = (double)(mouseX - this->pos.x) / this->sz.x;
    double ratioY = 1-(double)(mouseY) / this->sz.y;

    Vec2 mapCoord;
    mapCoord.x = (int)(ratioX * this->mapXSize() + this->mapLeft());
    mapCoord.y = (int)(ratioY * this->mapYSize() + this->mapBot());
    return mapCoord;
}

int MapWindow::mapLeft() {return this->mapLLH.x;}
int MapWindow::mapRight() {return this->mapLLH.x + this->mapWorldDim.x;}
int MapWindow::mapTop() {return this->mapLLH.y + this->mapWorldDim.y;}
int MapWindow::mapBot() {return this->mapLLH.y;}
int MapWindow::mapCentX() {return (this->mapRight() + this->mapLeft())/2;}
int MapWindow::mapCentY() {return (this->mapTop() + this->mapBot())/2;}
int MapWindow::mapXSize() {return this->mapWorldDim.x;}
int MapWindow::mapYSize() {return this->mapWorldDim.y;}
int MapWindow::yInv() {return 900 - this->sz.y + this->pos.y;}

void MapWindow::mouseHover(int mouseX, int mouseY) {
    Vec2 x = scrToMap(mouseX, mouseY);
    printf("MAP window at %d, %d == %d, %d\n", mouseX, mouseY, x.x, x.y);
}

void MapWindow::mouseClick(int button, int state, int mouseX, int mouseY) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        if (!this->centerMode) {
            Vec2 mouseAt = this->scrToMap(mouseX, mouseY);
            this->zoomIn();
            this->centerMapOn(mouseAt);
        }
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
        Vec2 mouseAt = this->scrToMap(mouseX, mouseY);
        if (!this->centerMode) this->zoomOut();
        this->centerMapOn(mouseAt);

    }

}
