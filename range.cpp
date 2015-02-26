
/*

Assignment 2 for CSC 442

Author: Aubrey Olson // Matt Richard
Date:   Feb 2015
*/

/******************************************************************************
 * Function: Menu_Neighborhood_Out_Of_Range
 * Description: Looks for noise in a 3x3 filter. Compares   |1|1|1|
 *              all values surrounding to middle pixel. If  |1|X|1|
 *              determined to be noise (by user threshold)  |1|1|1|
 *              then middle pixel replaced by average
 * Parameters: image - the image to operate on
 * Returns: true if the image was successfully updated; otherwise, false
 *****************************************************************************/

#include "mainwindow.h"

bool MainWindow::Menu_Neighborhood_Out_Of_Range( Image &image )
{

    if ( image.IsNull() ) return false; // not essential, but good practice

    //create filter
    int filter[3][3] = {{1,1,1},{1,0,1},{1,1,1}};

    //temp image
    Image imageCopy = image;

    // variables
    int nrows = image.Height();
    int ncols = image.Width();
    int intensity = 0;

    //prompt user for threshold
    int threshold = 0;
    if(!Dialog("Threshold Range").Add(threshold, "Threshold", 0, 127).Show())
        return false;

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
                    intensity += imageCopy[(r + r2 - 1 + nrows) % nrows][(c + c2 - 1 + ncols) % ncols] * filter[r2][c2];
                }
            }

            //weighted average
            intensity = intensity / 8.0;

            //if the average intensity of surrounding pixels minus the middle pixel is more than the threshold, replace middle with average
            if((imageCopy[r][c] - intensity) > threshold)
                image[r][c] = intensity;

            //reset average intensity
            intensity = 0;
        }

    // return true to update the image
    return true;
}
