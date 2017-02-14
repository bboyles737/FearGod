#ifndef MAPWINDOW_H
#define MAPWINDOW_H

#include "GUIObj.h"

class MapWindow : public GUIObj
{
    public:
        MapWindow(int sizeX, int sizeY);
        void render();

        void mouseHover(int mouseX, int mouseY);
        void mouseClick(int button, int state, int mouseX, int mouseY);
        void centerMapOn(int mapX, int mapY);
        void centerMapOn(Vec2 newMapCenter);

        void zoomIn();
        void zoomOut();
        void zoomTo(int newZoom);

        void setGridLabels(bool newValue);
        void enableCentering();
        void enableZooming();

        Vec2 scrToMap(int mouseX, int mouseY);

        int mapLeft();
        int mapRight();
        int mapTop();
        int mapBot();
        int mapCentX();
        int mapCentY();
        int mapXSize();
        int mapYSize();
        int yInv(); // Takes care of inverting mouse coords

    protected:

    private:
        Vec2 mapLLH;
        Vec2 mapWorldDim;
        double mapRatio;
        int mapZoom;        // In yards, along the vertical axis
        int gridSpacing;
        bool showGridLabels;
        bool centerMode;

        void recalcMapSize();   // After we zoom
        void drawGridlines(int spacing);

};

#endif // MAPWINDOW_H
