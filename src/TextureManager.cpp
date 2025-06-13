#include "TextureManager.h"

#include <stdexcept>

#include <QDebug>
#include <QDirIterator>
#include <QFileInfo>
#include <QPixmap>

bool TextureManager::loadTilesFromDirectory(const QString &directory)
{
    QDirIterator it(
        directory,
        QStringList() << "*.png",
        QDir::Files,
        QDirIterator::Subdirectories
    );

    bool success = true;

    while (it.hasNext()) {
        QString filePath = it.next();
        QFileInfo fileInfo(filePath);
        QString relativePath = QDir(directory).relativeFilePath(filePath);

        // Normalize to key format: e.g., "default/default" (no ".png")
        QString tileName =
            relativePath.left(relativePath.length() - 4);  // remove ".png"

        QPixmap pixmap(filePath);
        if (!pixmap.isNull()) {
            insertTile(tileName, pixmap);
        } else {
            qWarning() << "Failed to load texture:" << filePath;
            return false;
        }
    }

    return success;
}

bool TextureManager::insertTile(const QString &name, const QPixmap &pixmap)
{
    uint id;
    if (tileTextureMap.size() == tileNameMap.size()) {
        id = tileTextureMap.size();
    } else {
        throw std::runtime_error("tileTextureMap.size() != tileNameMap.size()");
    }

    tileTextureMap.insert(id, pixmap);
    tileNameMap.insert(id, name);
    return true;
}

QPixmap TextureManager::getTileTexture(uint id) const
{
    return tileTextureMap.value(id, QPixmap());
}

QString TextureManager::getTileName(uint id) const
{
    return tileNameMap.value(id, QString());
}
