#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include "GL/freeglut.h"
#include "Vec2.h"

class Window
{
    public:
        Window(std::string winName);
        void setDisplay(void (*dispFunc)(), int subwindow=1);
        void setSize(int x, int y);
        void setPos(int x, int y);
        void gen();

    protected:

    private:
        bool active;
        std::string name;
        int windowID;

        Vec2 pos;
        Vec2 sz;
        void (*dispFunc)();

        int winA;
        int winB;
};

#endif // WINDOW_H
