#include "TileArray.h"

#include <QDebug>
#include <QPainter>

TileArray::TileArray(int width, int height) : nX(width), nY(height) {}

QPixmap TileArray::showTileArray()
{
    // Define dimensions of the output pixmap
    const int tileSize = 32;
    QPixmap canvas(nX * tileSize, nY * tileSize);
    canvas.fill(Qt::white);

    QPainter painter(&canvas);

    for (int y = 0; y < nY; ++y) {
        for (int x = 0; x < nX; ++x) {
            if (!defaultTile.isNull()) {
                painter.drawPixmap(
                    x * tileSize, y * tileSize, tileSize, tileSize, defaultTile
                );
            }
        }
    }

    painter.setPen(Qt::black);
    for (int x = 0; x <= nX; ++x)
        painter.drawLine(x * tileSize, 0, x * tileSize, nY * tileSize);
    for (int y = 0; y <= nY; ++y)
        painter.drawLine(0, y * tileSize, nX * tileSize, y * tileSize);

    return canvas;
}

bool TileArray::loadDefaultTile(const QString &path)
{
    QPixmap pixmap;
    if (!pixmap.load(path)) {
        qWarning() << "Failed to load default tile from:" << path;
        return false;
    }

    defaultTile = pixmap;
    return true;
}