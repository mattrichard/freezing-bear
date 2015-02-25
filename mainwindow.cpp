/*

mainwindow.cpp

Assignment 2 for CSC 442

Author: Aubrey Olson // Matt Richard
Date:   Feb 2015

Modifications:
*/

#include "mainwindow.h"

/******************************************************************************
 * Function: Menu_Palette_Grayscale
 * Description: Uses the built in qtimagelib grayscale function to convert
 *              the image to grayscale.
 * Parameters: image - the image to operate on
 * Returns: true if the image was successfully updated; otherwise, false
 *****************************************************************************/
bool MainWindow::Menu_Palette_Grayscale(Image &image)
{
    grayscale(image);
    return true;
}

/******************************************************************************
 * Function: Menu_Palette_BinaryThreshold
 * Description: Uses the built in qtimagelib function to perform binary
 *              thresholding on the given image.
 * Parameters: image - the image to operate on
 * Returns: true if the image was successfully updated; otherwise, false
 *****************************************************************************/
bool MainWindow::Menu_Palette_BinaryThreshold(Image &image)
{
    int threshold = 128;
    if(!Dialog("BinaryThreshold").Add(threshold, "threshold", 0, 255).Show())
        return false;

    binaryThreshold(image, threshold);
    return true;
}

/******************************************************************************
 * Function: Menu_Histogram_Display
 * Description: Uses the built in qtimagelib fuction to display a histogram
 *              of the image.
 * Parameters: image - the image to operate on
 * Returns: true if the image was successfully updated; otherwise, false
 *****************************************************************************/
bool MainWindow::Menu_Histogram_Display(Image &image)
{
    displayHistogram(image);
    return true;
}

/******************************************************************************
 * Function: Menu_Histogram_Stretch
 * Description: Uses the built in qtimagelib function to perform histogram
 *              stretching on the image
 * Parameters: image - the image to operate on
 * Returns: true if the image was successfully updated; otherwise, false
 *****************************************************************************/
bool MainWindow::Menu_Histogram_Stretch(Image &image)
{
    histogramStretch(image);
    return true;
}


/******************************************************************************
 * Function: Menu_Histogram_Equalization
 * Description: Uses the built in qtimagelib function to perform histogram
 *              equalization on the given image.
 * Parameters: image - the image to operate on
 * Returns: true if the image was successfully updated; otherwise, false
 *****************************************************************************/
bool MainWindow::Menu_Histogram_Equalization(Image &image)
{
    histogramEqualize(image);
    return true;
}

/******************************************************************************
 * Function: Menu_Noise_Gaussian
 * Description: Uses the built in qtimagelib function to add gaussin noise
 *              to the given image.
 * Parameters: image - the image to operate on
 * Returns: true if the image was successfully updated; otherwise, false
 *****************************************************************************/
bool MainWindow::Menu_Noise_Gaussian(Image &image)
{
    double sigma = 0;
    if(!Dialog("Gaussian Noise").Add(sigma, "Sigma", 0, 10).Show())
        return false;

    gaussianNoise(image, sigma);
    return true;
}

/******************************************************************************
 * Function: Menu_Noise_Impluse
 * Description: Uses the built in qtimagelib function to add impulse noise
 *              to the given image.
 * Parameters: image - the image to operate on
 * Returns: true if the image was successfully updated; otherwise, false
 *****************************************************************************/
bool MainWindow::Menu_Noise_Impulse(Image &image)
{
    int probability = 0;
    if(!Dialog("Impulse Noise").Add(probability, "Probability", 0, 100).Show())
        return false;

    gaussianNoise(image, probability);
    return true;
}
