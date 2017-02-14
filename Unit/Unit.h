#ifndef UNIT_H
#define UNIT_H

#include "Vec2.h"
#include "Vec2d.h"
#include "SideEnum.h"
#include <string>

class Unit
{
    public:
        Unit();
        virtual ~Unit();
        virtual void render();

        void moveTo(int posX, int posY);
        void moveBy(int dX, int dY);
        void moveAhead(int dT);     // Time in seconds

        void changeSpeed(int newSpeed);
        void changeSpeedBy(int dSpeed);

        void changeHeading(double newHeading);
        void changeHeadingBy(double dHeading);

        void changeSide(Side newSide);
        void changeName(std::string newName);

        void changeHP(int newHP);
        void changeHPBy(int dHP);

        std::string getName();
        Side getSide();
        double getHeading();
        int getSpeed();
        Vec2 getPos();
        Vec2d getIncPos();
        int getHP();

    protected:
        int hp;
        std::string name;
        Side unitSide;
        Vec2 pos;       // discrete (int) position on map
        Vec2d incPos;   // incremental (double) position, amounts > 1 transferred to actual pos every turn
        double heading; // degrees
        int speed;      // knots

    private:

};

#endif // UNIT_H
