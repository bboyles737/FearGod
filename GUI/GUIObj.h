#ifndef GUIOBJ_H
#define GUIOBJ_H

#include "Vec2.h"
#include "Vec3d.h"

class GUIObj
{
    public:
        GUIObj();
        virtual ~GUIObj();
        virtual void render();
        void setSize(int x, int y);
        void setPos(int x, int y);
        void setBGColor(double r, double g, double b);
        void setBGColorub(int r, int g, int b);
        bool collide(int mouseX, int mouseY);

        virtual void mouseHover(int mouseX, int mouseY);
        virtual void mouseClick(int button, int state, int mouseX, int mouseY);

    protected:
        Vec2 pos;
        Vec2 sz;
        Vec3d bgColor;

    private:

};

#endif // GUIOBJ_H
