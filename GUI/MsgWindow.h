#ifndef MSGWINDOW_H
#define MSGWINDOW_H

#include "GUIObj.h"

class MsgWindow : public GUIObj
{
    public:
        MsgWindow(int sizeX, int sizeY);

        void mouseHover(int mouseX, int mouseY);

    protected:

    private:
};

#endif // MSGWINDOW_H
