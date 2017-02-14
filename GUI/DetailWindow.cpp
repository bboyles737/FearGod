#include "DetailWindow.h"

#include <stdio.h>

DetailWindow::DetailWindow(int sizeX, int sizeY)
{
    this->setSize(sizeX, sizeY);
    this->setPos(960, 300);
    this->setBGColor(0.3, 0.3, 0.3);
}

void DetailWindow::mouseHover(int mouseX, int mouseY) {
    printf("Mouse is hovering over DETAIL window at %d, %d\n", mouseX, mouseY);
}
