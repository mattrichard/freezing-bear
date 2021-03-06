/*

mainwindow.h

Assignment 2 for CSC 442

Author: Aubrey Olson // Matt Richard
Date:   Feb 2015
*/

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
        bool Menu_Neighborhood_Smoothing(Image &image);
        bool Menu_Neighborhood_Sharpening(Image &image);
        bool Menu_Neighborhood_MedianPlus(Image &image);
        bool Menu_Neighborhood_Out_Of_Range(Image &image);
        bool Menu_Neighborhood_MeanNxN(Image &image);
        bool Menu_Neighborhood_Median_NxN(Image &image);
        bool Menu_Neighborhood_Minimum_NxN(Image &image);
        bool Menu_Neighborhood_Maximum_NxN(Image &image);
        bool Menu_Neighborhood_RangeNxN(Image &image);
        bool Menu_Neighborhood_Standard_Deviation_NxN(Image &image);
        bool Menu_Neighborhood_Emboss(Image &image);
        bool Menu_Neighborhood_Sobel_Edge_Mag(Image &image);
        bool Menu_Neighborhood_Sobel_Edge_Dir(Image &image);
        bool Menu_Neighborhood_KirshMagnitude(Image &image);
        bool Menu_Neighborhood_KirshDirection(Image &image);
        bool Menu_Neighborhood_Laplacian(Image &image);
        bool Menu_Neighborhood_Gaussian_Smoothing(Image &image);

};

#endif // MAINWINDOW_H
