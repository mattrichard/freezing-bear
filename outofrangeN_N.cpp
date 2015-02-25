

/*

Assignment 2 for CSC 442

Author: Aubrey Olson // Matt Richard
Date:   Feb 2015

Modifications:
*/

/******************************************************************************
 * Function: Menu_Neighborhood_RangeNxN
 * Description: Looks for noise in a NxN filter. Compares   |1|1|1|
 *              all values surrounding to middle pixel. If  |1|X|1|
 *              determined to be noise (outside of )  |1|1|1|
 *              then middle pixel replaced by average
 * Parameters: image - the image to operate on
 * Returns: true if the image was successfully updated; otherwise, false
 *****************************************************************************/

#include "mainwindow.h"

bool MainWindow::Menu_Neighborhood_RangeNxN( Image &image )
{

    if ( image.IsNull() ) return false; // not essential, but good practice

    //prompt user for filter size
    int threshold = 0;
    if(!Dialog("Filter Size").Add(threshold, "Size").Show())
        return false;

    //temp image
    Image imageCopy = image;

    // variables
    int nrows = image.Height();
    int ncols = image.Width();
    int intensity = 0;
    int offset = (threshold - 0.5) / 2;
    int maxRange = 0;
    int minRange = 0;

    //check that threshold isn't nonsense (i.e. 0 or lower or larger than image)
    if(threshold < 1)
        return false;
    if(threshold > nrows || threshold > ncols)
        return false;

    //loop through every entry in source (now the copy)
    for ( int r = 0; r < nrows; r++ )
        for ( int c = 0; c < ncols; c++ )
        {
            //set max/min to an initial value within the matrix
            maxRange = minRange = imageCopy[(r - offset + nrows) % nrows][(c - offset + nrows) % ncols];

            //apply filter on copy back into original image
            for (int r2 = 0; r2 < threshold; r2++)
            {
                for (int c2 = 0; c2 < threshold; c2++)
                {
                    //here we use modulus wrapping in lookup
                    intensity = imageCopy[(r + r2 - offset + nrows) % nrows][(c + c2 - offset + nrows) % ncols];

                    //check if we have hit new min or max
                    if(intensity > maxRange)
                        maxRange = intensity;
                    if(intensity < minRange)
                        minRange = intensity;

                }
            }

            //set intensity to range difference
            intensity = maxRange - minRange;

            //update image
            image[r][c] = intensity;

            //reset average intensity
            intensity = 0;
        }

    // return true to update the image
    return true;
}

