#include "Unit.h"
#include "helpers.h"
#include <cmath>

Unit::Unit(){
}

Unit::~Unit(){
}


void Unit::render() {

}

void Unit::moveTo(int posX, int posY) {
    this->pos = Vec2(posX, posY);
}

void Unit::moveBy(int dX, int dY) {
    this->pos.x += dX;
    this->pos.y += dY;
}

void Unit::moveAhead(int dT) {
    // 1 knot = 0.5626 yards per second
    double distTraveled = 0.5626 * this->speed * dT;
    double deltaX = distTraveled * cos(toRadians(this->heading));
    double deltaY = distTraveled * sin(toRadians(this->heading));
    this->incPos.x += deltaX;
    this->incPos.y += deltaY;

    // Now we reduce incPos to within [-1, 1]
    int mapdX = (int)this->incPos.x;
    int mapdY = (int)this->incPos.y;

    this->incPos.x -= mapdX;
    this->incPos.y -= mapdY;
    this->pos.x += mapdX;
    this->pos.y += mapdY;
}

void Unit::changeSpeed(int newSpeed) {
    this->speed = newSpeed;
}

void Unit::changeSpeedBy(int dSpeed) {
    this->speed += dSpeed;
}

void Unit::changeHeading(double newHeading) {
    newHeading = normalizeDeg(newHeading);
    this->heading = newHeading;
}

void Unit::changeHeadingBy(double dHeading) {
    this->changeHeading(dHeading + this->heading);
}

void Unit::changeSide(Side newSide) {
    this->unitSide = newSide;
}

void Unit::changeName(std::string newName) {
    this->name = newName;
}

void Unit::changeHP(int newHP) {
    if (newHP < 0) newHP = 0;
    this->hp = newHP;
}

void Unit::changeHPBy(int dHP) {
    this->changeHP(this->hp + dHP);
}

std::string Unit::getName() {return this->name;}
Side Unit::getSide() {return this->unitSide;}
double Unit::getHeading() {return this->heading;}
int Unit::getSpeed() {return this->speed;}
Vec2 Unit::getPos() {return this->pos;}
Vec2d Unit::getIncPos() {return this->incPos;}
int Unit::getHP() {return this->hp;}
