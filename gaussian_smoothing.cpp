/*

gaussian_smoothing.cpp

Assignment 2 for CSC 442

Author: Aubrey Olson // Matt Richard
Date:   Feb 2015
*/

#include "mainwindow.h"

#include <cmath>

/******************************************************************************
 * Function: Menu_Neighborhood_Gaussian_Smoothing
 * Description: Computes a gaussian smoothing kernel using a sigma value given
 *              by the user, then uses the kernel to smooth the given image.
 * Parameters: image - the image to operate on
 * Returns: true if the image was successfully updated; otherwise, false
 *****************************************************************************/
bool MainWindow::Menu_Neighborhood_Gaussian_Smoothing(Image &image)
{
    Image imageCopy = image;
    double mask[5][5];

    if(image.IsNull())
        return false;

    double sigma = 1;
    // Get sigma from the user
    if(!Dialog("Gaussian Smoothing").Add(sigma, "sigma").Show())
        return false;

    // Validate sigma
    if(sigma <= 0)
        return false;

    double sum = 0;
    // Initialize the gaussian smoothing mask
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            mask[i][j] = 1 / sqrt(2.0 * M_PI * sigma * sigma) *
                exp( - ((i - 2) * (i - 2) + (j - 2) * (j - 2)) / (2.0 * sigma * sigma));
            sum += mask[i][j];
        }
    }

    int nrows = image.Height();
    int ncols = image.Width();
    // Loop through every pixel in the image
    for(int r = 0; r < nrows; r++)
    {
        for(int c = 0; c < ncols; c++)
        {
            double intensity = 0;
            // Convolve
            for(int i = -2; i <= 2; i++)
                for(int j = -2; j <= 2; j++)
                    intensity += imageCopy[(r + i + nrows) % nrows][(c + j + ncols) % ncols] * mask[i + 2][j + 2];

            intensity /= sum;

            // Make sure the intensity is in the valid range
            if(intensity > 255)
                intensity = 255;
            else if(intensity < 0)
                intensity = 0;

            image[r][c] = intensity;
        }
    }

    return true;
}
