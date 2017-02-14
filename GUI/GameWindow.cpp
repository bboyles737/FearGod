#include "GameWindow.h"

/**** For now, the sub-window sizes are hard-coded.
    * Ultimately, want to be able to modify this based on overall screen resolution
    */
GameWindow::GameWindow(int sizeX, int sizeY) {
    this->sz = Vec2(sizeX, sizeY);
    this->mapW = new MapWindow(1060, 700);
    this->msgW = new MsgWindow(1060, 200);
    this->sumW = new SummaryWindow(380, 300);
    this->detW = new DetailWindow(380, 600);

    this->subWindows.push_back(this->mapW);
    this->subWindows.push_back(this->msgW);
    this->subWindows.push_back(this->sumW);
    this->subWindows.push_back(this->detW);
}

GameWindow::~GameWindow() {
    delete this->mapW;
    delete this->msgW;
    delete this->sumW;
    delete this->detW;
    this->subWindows.clear();
}



/**** Since most of the objects in the game window will be the GUI and we'll be using
    * screen coordinates a lot, we're keeping this projection as 1:1 screen-to-world
    * and just have a separate setView method for the map which will show the actual world. */
void GameWindow::setView() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1440.0, 900.0, 0.0);    // Note Y-axis inversion
    glViewport(0, 0, 1440, 900);
}

/**** Checks to see which sub-window the mouse cursor is over, and then calls the associated
    * mouse hover method for that sub-window. */
void GameWindow::mouseHover(int mouseX, int mouseY) {
    for (unsigned int i = 0; i < this->subWindows.size(); i++) {
        GUIObj *curWindow = this->subWindows.at(i);
        if (curWindow->collide(mouseX, mouseY)) curWindow->mouseHover(mouseX, mouseY);
    }
}

/**** Checks to see which sub-window the mouse cursor is over when clicked, and then calls the associated
    * mouse hover method for that sub-window. */
void GameWindow::mouseClick(int button, int state, int mouseX, int mouseY) {
    for (unsigned int i = 0; i < this->subWindows.size(); i++) {
        GUIObj *curWindow = this->subWindows.at(i);
        if (curWindow->collide(mouseX, mouseY)) curWindow->mouseClick(button, state, mouseX, mouseY);
    }
}

/**** Draws the sub-windows using their specific render methods. */
void GameWindow::render() {
    // Need to treat the map window rendering separately because
    // it uses a different gluOrtho2D and viewport from the rest
    this->mapW->render();
    this->setView();
    for (unsigned int i = 1; i < this->subWindows.size(); i++) {
        GUIObj *curWindow = this->subWindows.at(i);
        curWindow->render();
    }
}
