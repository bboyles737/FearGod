#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <vector>

#include "GL/freeglut.h"
#include "Vec2.h"
#include "MapWindow.h"
#include "MsgWindow.h"
#include "SummaryWindow.h"
#include "DetailWindow.h"

class GameWindow
{
    public:
        GameWindow(int sizeX, int sizeY);
        ~GameWindow();

        void setView();
        void render();
        void mouseHover(int mouseX, int mouseY);


    protected:

    private:
        Vec2 sz;

        MapWindow *mapW;
        MsgWindow *msgW;
        SummaryWindow *sumW;
        DetailWindow *detW;

        std::vector<GUIObj*> subWindows;

};

#endif // GAMEWINDOW_H
