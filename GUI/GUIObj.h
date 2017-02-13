#ifndef GUIOBJ_H
#define GUIOBJ_H

#include "Vec2.h"
#include "Vec3f.h"

class GUIObj
{
    public:
        GUIObj();
        void render();
        void setSize(int x, int y);
        void setPos(int x, int y);
        void setBGColor(double r, double g, double b);
        void setBGColorub(int r, int g, int b);
        bool collide(int mouseX, int mouseY);

    protected:
        Vec2 pos;
        Vec2 size;
        Vec3f bgColor;

    private:

};

#endif // GUIOBJ_H
