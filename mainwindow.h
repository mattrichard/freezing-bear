#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <qtimagelib.h>

class MainWindow : public QObject
{
    Q_OBJECT

    public slots:
        bool Menu_Palette_Grayscale(Image &image);
        bool Menu_Palette_BinaryThreshold(Image &image);
        bool Menu_Histogram_Display(Image &image);
        bool Menu_Histogram_Stretch(Image &image);
};

#endif // MAINWINDOW_H
