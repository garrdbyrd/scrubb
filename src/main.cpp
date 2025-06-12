// main.cpp
#include <QApplication>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QMainWindow>
#include <QPixmap>
#include <QScrollArea>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QWidget>

#include "TileArray.h"

int main(int argc, char *argv[])
{
    // Main program
    QApplication app(argc, argv);

    // Window
    QMainWindow *window = new QMainWindow;
    window->setWindowTitle("scrubb");
    window->resize(1280, 720);

    // Central widget and top-level layout
    QWidget *central = new QWidget;
    QVBoxLayout *mainLayout = new QVBoxLayout(central);

    // Inner horizontal layout split into 3 sections: left - center - right
    QHBoxLayout *middleLayout = new QHBoxLayout;

    // === Left Column ===
    QVBoxLayout *leftColumn = new QVBoxLayout;

    QLabel *pickerLabel = new QLabel("Tile Picker");
    pickerLabel->setFrameShape(QFrame::StyledPanel);
    pickerLabel->setAlignment(Qt::AlignCenter);

    QScrollArea *scrollArea = new QScrollArea;
    scrollArea->setWidgetResizable(true);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setFrameShadow(QFrame::Raised);

    QWidget *tilePickerWidget = new QWidget;
    tilePickerWidget->setMinimumSize(153, 631);
    scrollArea->setWidget(tilePickerWidget);

    leftColumn->addWidget(pickerLabel);
    leftColumn->addWidget(scrollArea);

    // === Center Column (Tile Grid) ===
    QVBoxLayout *centerColumn = new QVBoxLayout;

    QLabel *mainLabel = new QLabel("Level/Chunk: Title");
    mainLabel->setFrameShape(QFrame::StyledPanel);
    mainLabel->setAlignment(Qt::AlignCenter);

    QLabel *tileGridLabel = new QLabel;
    TileArray tileArray(10, 10);
    tileGridLabel->setPixmap(tileArray.showTileArray());
    tileGridLabel->setAlignment(Qt::AlignCenter);

    centerColumn->addWidget(mainLabel);
    centerColumn->addWidget(tileGridLabel, /*stretch=*/1);

    // === Right Column ===
    QVBoxLayout *rightColumn = new QVBoxLayout;

    QLabel *propertiesLabel = new QLabel("Tile Properties");
    propertiesLabel->setFrameShape(QFrame::StyledPanel);
    propertiesLabel->setAlignment(Qt::AlignCenter);

    QGraphicsView *selectedGraphicsView = new QGraphicsView;
    selectedGraphicsView->setFrameShadow(QFrame::Raised);

    QLabel *selectedTileLabel = new QLabel;
    selectedTileLabel->setFrameShape(QFrame::StyledPanel);
    selectedTileLabel->setFrameShadow(QFrame::Raised);
    selectedTileLabel->setAlignment(Qt::AlignCenter);
    selectedTileLabel->setWordWrap(true);

    QTableWidget *selectedProperties = new QTableWidget(18, 2);
    selectedProperties->setAlternatingRowColors(true);
    selectedProperties->setFrameShadow(QFrame::Raised);
    selectedProperties->horizontalHeader()->setStretchLastSection(true);
    selectedProperties->verticalHeader()->setVisible(false);

    rightColumn->addWidget(propertiesLabel);
    rightColumn->addWidget(selectedGraphicsView);
    rightColumn->addWidget(selectedTileLabel);
    rightColumn->addWidget(selectedProperties);

    // === Assemble 3 columns ===
    middleLayout->addLayout(leftColumn, 2);
    middleLayout->addLayout(centerColumn, 12);
    middleLayout->addLayout(rightColumn, 2);

    mainLayout->addLayout(middleLayout);
    window->setCentralWidget(central);

    window->show();
    return app.exec();
}
