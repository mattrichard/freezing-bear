/*

Assignment 2 for CSC 442

Author: Aubrey Olson // Matt Richard
Date:   Feb 2015
*/

/******************************************************************************
 * Function: Menu_Neighborhood_Standard_Deviation_NxN
 * Description: Looks for stdDev in a NxN filter. Compares  |1|1|1|
 *              all values surrounding to each other. stdDev|1|1|1|
 *              is computed and middle pixel is replaced    |1|1|1|
 *              by stdDev value.
 * Parameters: image - the image to operate on
 * Returns: true if the image was successfully updated; otherwise, false
 *****************************************************************************/

#include "mainwindow.h"
#include <math.h>

bool MainWindow::Menu_Neighborhood_Standard_Deviation_NxN( Image &image )
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
    int intensityArray[filterSize*filterSize];
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
                    intensity = imageCopy[(r + r2 - offset + nrows) % nrows][(c + c2 - offset + ncols) % ncols];

                    intensityArray[r2*filterSize + c2] = intensity;

                    //increment sum
                    mean += intensity;
                }
            }

            //determine mean
            mean = mean / (filterSize*filterSize);

            //determine stdDev
            for(int i = 0; i < filterSize*filterSize; i++)
            {
                stdDev += (intensityArray[i] - mean) * (intensityArray[i] - mean);
            }

            stdDev = stdDev / (filterSize*filterSize - 1);
            stdDev = sqrt(stdDev);

            //update image
            image[r][c] = stdDev;

            //reset average intensity,mean,stddev
            intensity = 0;
            mean = 0;
            stdDev = 0;
        }

    // return true to update the image
    return true;
}


