#include "MapWindow.h"

MapWindow::MapWindow(int sizeX, int sizeY)
{
    this->setSize(sizeX, sizeY);
    this->setPos(0, 200);
    this->setBGColor(1.0, 0.0, 0.0);
}
