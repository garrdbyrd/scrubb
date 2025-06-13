#pragma once

#include <qcontainerfwd.h>
#include <qpixmap.h>
#include <QMap>
#include <QPixmap>
#include <QVector>

class TextureManager
{
    public:
        TextureManager(int width, int height);

        bool loadDefaultTile(const QString &path);
        bool loadTilesFromDirectory(const QString &directory);

        bool insertTile(const QString &name, const QPixmap &pixmap);
        QString getTileName(const uint id) const;
        QPixmap getTileTexture(const uint id) const;

        QPixmap showTileArray();
        void reloadTileTextures();

    private:
        // Metadata
        uint gridWidth;
        uint gridHeight;

        // Graphics
        uint tileSize;
        QPixmap defaultTile;

        // Grid
        QVector<QVector<uint>> activeGrid;
        QVector<QVector<QPixmap>> activeTextures;

        QMap<uint, QPixmap> tileTextureMap;
        QMap<uint, QString> tileNameMap;

        void applyTextures(const QVector<QPoint> &positions);
};
