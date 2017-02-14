#ifndef DETAILWINDOW_H
#define DETAILWINDOW_H

#include "GUIObj.h"

class DetailWindow : public GUIObj
{
    public:
        DetailWindow(int sizeX, int sizeY);

        void mouseHover(int mouseX, int mouseY);

    protected:

    private:
};

#endif // DETAILWINDOW_H
