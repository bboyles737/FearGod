#include "SummaryWindow.h"

#include <stdio.h>

SummaryWindow::SummaryWindow(int sizeX, int sizeY)
{
    this->setSize(sizeX, sizeY);
    this->setPos(960, 600);
    this->setBGColor(0.0, 0.0, 1.0);
}

void SummaryWindow::mouseHover(int mouseX, int mouseY) {
    printf("Mouse is hovering over SUMMARY window at %d, %d\n", mouseX, mouseY);
}
