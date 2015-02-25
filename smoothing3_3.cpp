/*
Assignment 2 for CSC 442
Author: Aubrey Olson // Matt Richard
Date: Feb 2015
Modifications:
*/
/******************************************************************************
* Function: Menu_Neighborhood_Smoothing3x3
* Description: Smooths an image base on a 3x3 filter |1|2|1|
* |2|4|2|
* |1|2|1|
* Parameters: image - the image to operate on
* Returns: true if the image was successfully updated; otherwise, false
*****************************************************************************/
#include "mainwindow.h"
bool MainWindow::Menu_Neighborhood_Smoothing3x3( Image &image )
{
    if ( image.IsNull() ) return false; // not essential, but good practice

    //create smoothing filter
    int filter[3][3] = {{1,2,1},{2,4,2},{1,2,1}};

    //temp image
    Image imageCopy = image;

    //variables
    int nrows = image.Height();
    int ncols = image.Width();
    int intensity = 0;

    //loop through every entry in source (now the copy)
    for ( int r = 0; r < nrows; r++ )
        for ( int c = 0; c < ncols; c++ )
        {
            //apply filter on copy back into original image
            for (int r2 = 0; r2 < 3; r2++)
            {
                for (int c2 = 0; c2 < 3; c2++)
                {
                    //here we use modulus wrapping in lookup
                    intensity += imageCopy[(r + r2 - 1 + nrows) % nrows][(c + c2 - 1 + nrows) % ncols] * filter[r2][c2];
                }
            }

            //divide for weighted average
            image[r][c] = intensity / 16.0;

            //reset average intensity
            intensity = 0;
        }

    // return true to update the image
    return true;
}
