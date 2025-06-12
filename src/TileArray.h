#pragma once

#include <QPixmap>

class TileArray
{
    public:
        TileArray(int width, int height);
        QPixmap showTileArray();

    private:
        int nX;
        int nY;
};
