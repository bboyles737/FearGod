#include "GameWindow.h"

GameWindow::GameWindow(int sizeX, int sizeY) {
    this->sz = Vec2(sizeX, sizeY);
    this->mapW = new MapWindow(960, 700);
    this->msgW = new MsgWindow(960, 200);
    this->sumW = new SummaryWindow(480, 300);
    this->detW = new DetailWindow(480, 600);

    this->subWindows.push_back(this->mapW);
    this->subWindows.push_back(this->msgW);
    this->subWindows.push_back(this->sumW);
    this->subWindows.push_back(this->detW);
}

void GameWindow::setView() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1440.0, 0.0, 900.0);
}

void GameWindow::mouseHover(int mouseX, int mouseY) {
    for (unsigned int i = 0; i < this->subWindows.size(); i++) {
        GUIObj *curWindow = this->subWindows.at(i);
        if (curWindow->collide(mouseX, mouseY)) curWindow->mouseHover(mouseX, mouseY);
    }
}

void GameWindow::render() {
    for (unsigned int i = 0; i < this->subWindows.size(); i++) {
        GUIObj *curWindow = this->subWindows.at(i);
        curWindow->render();
    }
}

GameWindow::~GameWindow() {
    delete this->mapW;
    delete this->msgW;
    delete this->sumW;
    delete this->detW;
    this->subWindows.clear();
}
