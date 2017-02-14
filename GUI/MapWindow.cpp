#include "MapWindow.h"

#include <stdio.h>

MapWindow::MapWindow(int sizeX, int sizeY)
{
    this->setSize(sizeX, sizeY);
    this->setPos(0, 200);
    this->setBGColor(1.0, 0.0, 0.0);
}

void MapWindow::mouseHover(int mouseX, int mouseY) {
    printf("Mouse is hovering over MAP window at %d, %d\n", mouseX, mouseY);
}
