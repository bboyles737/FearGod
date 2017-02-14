#ifndef MAPWINDOW_H
#define MAPWINDOW_H

#include "GUIObj.h"

class MapWindow : public GUIObj
{
    public:
        MapWindow(int sizeX, int sizeY);

        void mouseHover(int mouseX, int mouseY);


    protected:

    private:
};

#endif // MAPWINDOW_H
