#ifndef SUMMARYWINDOW_H
#define SUMMARYWINDOW_H

#include "GUIObj.h"

class SummaryWindow : public GUIObj
{
    public:
        SummaryWindow(int sizeX, int sizeY);

        void mouseHover(int mouseX, int mouseY);

    protected:

    private:
};

#endif // SUMMARYWINDOW_H
