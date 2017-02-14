#include "MsgWindow.h"

MsgWindow::MsgWindow(int sizeX, int sizeY)
{
    this->setSize(sizeX, sizeY);
    this->setPos(0, 0);
    this->setBGColor(0.0, 1.0, 0.0);
}
