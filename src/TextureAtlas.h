#pragma once

#include <QPixmap>
#include <QString>
#include <QVector>
#include <QMap>

class TextureAtlas {
public:
    bool loadFromDirectory(const QString& rootPath);

    const QPixmap& getPixmap(int id) const;
    const QString& getName(int id) const;
    int getId(const QString& name) const;
    int count() const;

private:
    QVector<QPixmap> pixmaps;
    QVector<QString> names;
    QMap<QString, int> nameToId; // For quick lookup
};
