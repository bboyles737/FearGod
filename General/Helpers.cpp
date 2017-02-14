#include "Helpers.h"

void drawStringBitmap(double drawX, double drawY, std::string drawStr,
                      void* font) {
    glRasterPos2f(drawX, drawY);// Position to start drawing in world coordinates
    for (unsigned int i = 0; i < drawStr.size(); i++)
        glutBitmapCharacter(font, drawStr[i]);

    // NOTE: Since these are bitmapped fonts, they will always show up as the
    // same size on the screen
}

void drawStringStroke(std::string drawStr, void* font) {
    for (unsigned int i = 0; i < drawStr.size(); i++)
        glutStrokeCharacter(font, drawStr[i]);
}
