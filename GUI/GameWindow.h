#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <vector>

#include "GL/freeglut.h"
#include "Vec2.h"
#include "MapWindow.h"
#include "MsgWindow.h"
#include "SummaryWindow.h"
#include "DetailWindow.h"

/**** GameWindow class: This class is the main window being displayed during gameplay.  Consists of four sections:
    *   - Map Window: Largest area of the four, used for seeing the map and units on it
    *   - Message Window: Used to show console output in the game, also used for displaying messages during gameplay
    *   - Summary Window: Small window to display basic scenario info (i.e. date/time) and perhaps buttons for common commands
    *   - Detail Window: Shows detailed information about ships, objects, etc. */
class GameWindow
{
    public:
        GameWindow(int sizeX, int sizeY);
        ~GameWindow();

        void setView();     // Projection matrix is 2D Orthographic with Y-axis inverted, 1:1 ratio between screen and world coordinates
        void render();      // Calls the render methods on the four sub sections

        void mouseHover(int mouseX, int mouseY);    // Calls the mouseHover method for whichever sub section the cursor is hovering over
        void mouseClick(int button, int state, int mouseX, int mouseY);

    protected:

    private:
        Vec2 sz;            // Size

        // Keeping direct pointers to the four sub-windows
        MapWindow *mapW;
        MsgWindow *msgW;
        SummaryWindow *sumW;
        DetailWindow *detW;

        // Uses a vector of the sub-windows for when we need to do something to all of our sub-windows.
        std::vector<GUIObj*> subWindows;

};

#endif // GAMEWINDOW_H
