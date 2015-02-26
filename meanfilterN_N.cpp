/*

Assignment 2 for CSC 442

Author: Aubrey Olson // Matt Richard
Date:   Feb 2015
*/

/******************************************************************************
 * Function: Menu_Neighborhood_MeanNxN
 * Description: Averages a NxN filter with middle. Compares   |1|1|1|
 *              all values surrounding to middle pixel.       |1|1|1|
 *              Replaces middle pixel with average.           |1|1|1|
 *              Offsets up and left if even N.
 * Parameters: image - the image to operate on
 * Returns: true if the image was successfully updated; otherwise, false
 *****************************************************************************/

#include "mainwindow.h"

bool MainWindow::Menu_Neighborhood_MeanNxN( Image &image )
{

    if ( image.IsNull() ) return false; // not essential, but good practice

    //prompt user for filter size
    int filterSize = 3;
    if(!Dialog("Filter Size").Add(filterSize, "Size").Show())
        return false;

    //create filter (all ones)
    int filter[filterSize][filterSize];

    for ( int r = 0; r < filterSize; r++ )
        for ( int c = 0; c < filterSize; c++ )
        {
            filter[r][c] = 1;
        }

    //temp image
    Image imageCopy = image;

    // variables
    int nrows = image.Height();
    int ncols = image.Width();
    int intensity = 0;
    int offset = (filterSize - 0.5) / 2;

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
                    intensity += imageCopy[(r + r2 - offset + nrows) % nrows][(c + c2 - offset + ncols) % ncols] * filter[r2][c2];
                }
            }

            //weighted average
            intensity = intensity / (filterSize*filterSize);

            //if the average intensity of surrounding pixels minus the middle pixel is more than the filterSize, replace middle with average
            if((imageCopy[r][c] - intensity) > filterSize)
                image[r][c] = intensity;

            //reset average intensity
            intensity = 0;
        }

    // return true to update the image
    return true;
}
