#pragma once

#include <qpixmap.h>
#include <QPixmap>

class TileArray
{
    public:
        TileArray(int width, int height);
        QPixmap showTileArray();
        bool loadDefaultTile(const QString &path);

    private:
        int nX;
        int nY;
        QPixmap defaultTile;
};
