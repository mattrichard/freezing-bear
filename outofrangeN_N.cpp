

/*

Assignment 2 for CSC 442

Author: Aubrey Olson // Matt Richard
Date:   Feb 2015

Modifications:
*/

/******************************************************************************
 * Function: Menu_Neighborhood_RangeNxN
 * Description: Looks for range in a NxN filter. Compares   |1|1|1|
 *              all values surrounding to each other. Range |1|1|1|
 *              is computed and middle pixel is replaced    |1|1|1|
 *              by range value.
 * Parameters: image - the image to operate on
 * Returns: true if the image was successfully updated; otherwise, false
 *****************************************************************************/

#include "mainwindow.h"

bool MainWindow::Menu_Neighborhood_RangeNxN( Image &image )
{

    if ( image.IsNull() ) return false; // not essential, but good practice

    //prompt user for filter size
    int filterSize = 3;
    if(!Dialog("Filter Size").Add(filterSize, "Size").Show())
        return false;

    //temp image
    Image imageCopy = image;

    // variables
    int nrows = image.Height();
    int ncols = image.Width();
    int intensity = 0;
    int offset = (filterSize - 0.5) / 2;
    int maxRange = 0;
    int minRange = 0;

    //check that filterSize isn't nonsense (i.e. 0 or lower or larger than image)
    if(filterSize < 1)
        return false;
    if(filterSize > nrows || filterSize > ncols)
        return false;

    //loop through every entry in source (now the copy)
    for ( int r = 0; r < nrows; r++ )
        for ( int c = 0; c < ncols; c++ )
        {
            //set max/min to an initial value within the matrix
            maxRange = minRange = imageCopy[(r - offset + nrows) % nrows][(c - offset + ncols) % ncols];

            //apply filter on copy back into original image
            for (int r2 = 0; r2 < filterSize; r2++)
            {
                for (int c2 = 0; c2 < filterSize; c2++)
                {
                    //here we use modulus wrapping in lookup
                    intensity = imageCopy[(r + r2 - offset + nrows) % nrows][(c + c2 - offset + ncols) % ncols];

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

