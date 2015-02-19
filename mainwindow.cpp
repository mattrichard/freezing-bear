#include "mainwindow.h"

bool MainWindow::Menu_Palette_Grayscale(Image &image)
{
    grayscale(image);
    return true;
}

bool MainWindow::Menu_Palette_BinaryThreshold(Image &image)
{
    int threshold = 128;
    if(!Dialog("BinaryThreshold").Add(threshold, "threshold", 0, 255).Show())
        return false;

    binaryThreshold(image, threshold);
    return true;
}

bool MainWindow::Menu_Histogram_Display(Image &image)
{
    displayHistogram(image);
    return true;
}

bool MainWindow::Menu_Histogram_Stretch(Image &image)
{
    histogramStretch(image);
    return true;
}
