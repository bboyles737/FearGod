#include "MsgWindow.h"

#include <stdio.h>

MsgWindow::MsgWindow(int sizeX, int sizeY)
{
    this->setSize(sizeX, sizeY);
    this->setPos(0, 0);
    this->setBGColor(0.0, 1.0, 0.0);
}

void MsgWindow::mouseHover(int mouseX, int mouseY) {
    printf("Mouse is hovering over MESSAGE window at %d, %d\n", mouseX, mouseY);
}
