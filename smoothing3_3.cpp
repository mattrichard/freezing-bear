/*

Assignment 2 for CSC 442

Author: Aubrey Olson // Matt Richard
Date:   Feb 2015

Modifications:
*/

/******************************************************************************
 * Function: Menu_Neighborhood_Smoothing3x3
 * Description: Smooths an image base on a 3x3 filter |1|2|1|
 *                                                    |2|4|2|
 *                                                    |1|2|1|
 * Parameters: image - the image to operate on
 * Returns: true if the image was successfully updated; otherwise, false
 *****************************************************************************/

#include "mainwindow.h"

bool MainWindow::Menu_Neighborhood_Smoothing3x3( Image &image )
{
    if ( image.IsNull() ) return false; // not essential, but good practice

    int threshold = 0;

    //create smoothing filter
    int[3][3] filter = {0};

    filter [0][0] = 1; filter [0][1] = 2; filter [0][2] = 1;
    filter [1][0] = 2; filter [1][1] = 4; filter [1][2] = 2;
    filter [2][0] = 1; filter [2][1] = 2; filter [2][2] = 1;

    // apply binary thresholding
    // loop through each pixel as it is a point process
    int nrows = image.Height();
    int ncols = image.Width();
    for ( int r = 0; r < nrows; r++ )
        for ( int c = 0; c < ncols; c++ )
        {
            // update intensity
            if(image[r][c] > threshold)
                image[r][c] = 255;
            else
                image[r][c] = 0;
        }

    // return true to update the image
    return true;
}
