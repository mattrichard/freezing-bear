

/*

Assignment 2 for CSC 442

Author: Aubrey Olson // Matt Richard
Date:   Feb 2015

Modifications:
*/

/******************************************************************************
 * Function: Menu_Neighborhood_Standard_Deviation_NxN
 * Description: Looks for difference in NxN filter. Compares   |1|1|1|
 *              all values surrounding to each other. Then     |1|X|1|
 *              an average and standard deviation is taken and |1|1|1|
 *              converted to an intensity.
 * Parameters: image - the image to operate on
 * Returns: true if the image was successfully updated; otherwise, false
 *****************************************************************************/

#include "mainwindow.h"

bool MainWindow::Menu_Neighborhood_Standard_Deviation_NxN( Image &image )
{

    if ( image.IsNull() ) return false; // not essential, but good practice

    //prompt user for filter size
    int filterSize = 0;
    if(!Dialog("Filter Size").Add(filterSize, "Size").Show())
        return false;

    //temp image
    Image imageCopy = image;

    // variables
    int nrows = image.Height();
    int ncols = image.Width();
    int intensity = 0;
    int offset = (filterSize - 0.5) / 2;
    int mean = 0;
    int stdDev = 0;

    //check that filterSize isn't nonsense (i.e. 0 or lower or larger than image)
    if(filterSize < 1)
        return false;
    if(filterSize > nrows || filterSize > ncols)
        return false;

    //loop through every entry in source (now the copy)
    for ( int r = 0; r < nrows; r++ )
        for ( int c = 0; c < ncols; c++ )
        {
            //apply filter on copy back into original image
            for (int r2 = 0; r2 < filterSize; r2++)
            {
                for (int c2 = 0; c2 < filterSize; c2++)
                {
                    //here we use modulus wrapping in lookup
                    intensity = imageCopy[(r + r2 - offset + nrows) % nrows][(c + c2 - offset + nrows) % ncols];

                    //increment sum
                    mean += intensity;
                }
            }

            //determine mean
            mean = mean / (filterSize*filterSize);

            //update image
            image[r][c] = intensity;

            //reset average intensity,mean,stddev
            intensity = 0;
            mean = 0;
            stdDev = 0;
        }

    // return true to update the image
    return true;
}


