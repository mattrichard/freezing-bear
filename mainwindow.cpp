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


bool MainWindow::Menu_Histogram_Equalization(Image &image)
{
    histogramEqualize(image);
    return true;
}

bool MainWindow::Menu_Noise_Gaussian(Image &image)
{
    double sigma = 0;
    if(!Dialog("Gaussian Noise").Add(sigma, "Sigma", 0, 10).Show())
        return false;

    gaussianNoise(image, sigma);
    return true;
}

bool MainWindow::Menu_Noise_Impulse(Image &image)
{
    int probability = 0;
    if(!Dialog("Impulse Noise").Add(probability, "Probability", 0, 100).Show())
        return false;

    gaussianNoise(image, probability);
    return true;
}
