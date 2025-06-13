#pragma once

#include "TextureManager.h"

#include <QGridLayout>
#include <QMainWindow>

class MainWindow
{
    public:
        static QMainWindow *build();
        void populateTilePicker(
            TextureManager &manager, const QString &tilePath
        );

        QGridLayout *tilePickerLayout;
};
