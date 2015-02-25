/*
Assignment 2 for CSC 442
Author: Aubrey Olson // Matt Richard
Date: Feb 2015
Modifications:
*/
/******************************************************************************
* Function: Menu_Neighborhood_Sobel_Edge_Mag                      Gx         Gy
* Description: Finds edge magnitude using Sobel method. Then  |-1|0 |1 | | 1|0 |-1|
*              displays relative intensity based on magnitude |-2|0 |2 | | 1|0 |-2|
*                                                             |-1|0 |1 | | 1|0 |-1|
* Parameters: image - the image to operate on
* Returns: true if the image was successfully updated; otherwise, false
*****************************************************************************/
#include "mainwindow.h"
#include <math.h>

bool MainWindow::Menu_Neighborhood_Sobel_Edge( Image &image )
{
    if ( image.IsNull() ) return false; // not essential, but good practice

    //create smoothing filter
    int filterGx[3][3] = {{-1,0,1},{-2,0,2},{-1,0,1}};
    int filterGy[3][3] = {{-1,-2,-1},{0,0,0},{1,2,1}};

    //temp image
    Image imageCopy = image;

    //variables
    int nrows = image.Height();
    int ncols = image.Width();
    int intensityX,intensityY,magnitude = 0;

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
                    intensityX += imageCopy[(r + r2 - 1 + nrows) % nrows][(c + c2 - 1 + nrows) % ncols] * filterGx[r2][c2];
                    intensityY += imageCopy[(r + r2 - 1 + nrows) % nrows][(c + c2 - 1 + nrows) % ncols] * filterGy[r2][c2];
                }
            }

            magnitude = sqrt((intensityX*intensityX)+(intensityY*intensityY));

            //convert magnitude to intensity level
            image[r][c] = (magnitude / 2 * M_PI) * 255;

            //reset average intensity
            intensityX = 0;
            intensityY = 0;
        }

    // return true to update the image
    return true;
}
