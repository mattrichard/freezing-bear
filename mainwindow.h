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
        bool Menu_Histogram_Equalization(Image &image);
        bool Menu_Noise_Gaussian(Image &image);
        bool Menu_Noise_Impulse(Image &image);
        bool Menu_Neighborhood_Smoothing3x3(Image &image);
        bool Menu_Neighborhood_Sharpening(Image &image);
        bool Menu_Neighborhood_Out_Of_Range(Image &image);
        bool Menu_Neighborhood_Out_Of_RangeNxN(Image &image);
        bool Menu_Neighborhood_MeanNxN(Image &image);
        bool Menu_Neighborhood_PlusShapedMedian(Image &image);
        bool Menu_Neighborhood_Median(Image &image);
        bool Menu_Neighborhood_Max(Image &image);
        bool Menu_Neighborhood_Min(Image &image);
        bool Menu_Neighborhood_Emboss(Image &image);
};

#endif // MAINWINDOW_H
