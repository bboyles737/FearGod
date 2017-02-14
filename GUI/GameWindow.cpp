#include "GameWindow.h"

GameWindow::GameWindow(int sizeX, int sizeY) {
    this->sz = Vec2(sizeX, sizeY);
    this->mapW = new MapWindow(960, 700);
    this->msgW = new MsgWindow(960, 200);
    this->sumW = new SummaryWindow(480, 300);
    this->detW = new DetailWindow(480, 600);
}

void GameWindow::setView() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1440.0, 0.0, 900);
}

void GameWindow::render() {

    this->mapW->render();


    this->msgW->render();


    this->sumW->render();


    this->detW->render();
}

GameWindow::~GameWindow() {
    delete this->mapW;
    delete this->msgW;
    delete this->sumW;
    delete this->detW;
}
