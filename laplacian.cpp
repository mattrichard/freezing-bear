/*

laplacian.cpp

Assignment 2 for CSC 442

Author: Aubrey Olson // Matt Richard
Date:   Feb 2015

Modifications:
*/

#include "mainwindow.h"

/******************************************************************************
 * Function: Menu_Neighborhood_Laplacian
 * Description:
 * Parameters: image - the image to operate on
 * Returns: true if the image was successfully updated; otherwise, false
 *****************************************************************************/
bool MainWindow::Menu_Neighborhood_Laplacian(Image &image)
{
    Image imageCopy = image;
    int mask[3][3] = {{0, -1, 0}, {-1, 4, -1}, {0, -1, 0}};

    if(image.IsNull())
        return false;

    int nrows = image.Height();
    int ncols = image.Width();
    // Loop through every pixel in the image
    for(int r = 0; r < nrows; r++)
    {
        for(int c = 0; c < ncols; c++)
        {
            int intensity = 0;
            // Convolve
            for(int i = -1; i <=1; i++)
                for(int j = -1; j <= 1; j++)
                    intensity += imageCopy[(r + i + nrows) % nrows][(c + j + ncols) % ncols] * mask[i + 1][j + 1];

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
