#ifndef MAPWINDOW_H
#define MAPWINDOW_H

#include "GUIObj.h"
#include "Vec2d.h"

class MapWindow : public GUIObj
{
    public:
        MapWindow(int sizeX, int sizeY);
        void render();

        void mouseHover(int mouseX, int mouseY);
        int mapLeft();
        int mapRight();
        int mapTop();
        int mapBot();

        Vec2d scrToMap(int mouseX, int mouseY);

    protected:

    private:
        Vec2 mapLLH;
        Vec2 mapWorldDim;
        double mapRatio;
        int mapZoom;        // In yards, along the vertical axis

};

#endif // MAPWINDOW_H
