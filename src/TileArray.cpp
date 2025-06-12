#include "TileArray.h"
#include <QPainter>

TileArray::TileArray(int width, int height) : nX(width), nY(height) {}

QPixmap TileArray::showTileArray()
{
    // Define dimensions of the output pixmap
    const int tileSize = 32;
    QPixmap canvas(nX * tileSize, nY * tileSize);
    canvas.fill(Qt::white);  // or Qt::transparent if preferred

    QPainter painter(&canvas);
    painter.setPen(Qt::black);

    for (int x = 0; x <= nX; ++x)
        painter.drawLine(x * tileSize, 0, x * tileSize, nY * tileSize);

    for (int y = 0; y <= nY; ++y)
        painter.drawLine(0, y * tileSize, nX * tileSize, y * tileSize);

    return canvas;
}
