#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

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

    protected:

    private:
        Vec2 sz;

        MapWindow *mapW;
        MsgWindow *msgW;
        SummaryWindow *sumW;
        DetailWindow *detW;

};

#endif // GAMEWINDOW_H
