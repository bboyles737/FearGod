#ifndef HELPERS_H
#define HELPERS_H


double screenToWorld(int mouseLoc, double worldMin, double worldMax, int screenMin, int screenMax, bool invert=false);
double screenToWorldX(int screenX);
double screenToWorldY(int screenY);

#endif // HELPERS_H
