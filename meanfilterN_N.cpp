

/*

Assignment 2 for CSC 442

Author: Aubrey Olson // Matt Richard
Date:   Feb 2015

Modifications:
*/

/******************************************************************************
 * Function: Menu_Neighborhood_Mean_NxN
 * Description: Looks for noise in a 3x3 filter. Compares   |1|1|1|
 *              all values surrounding to middle pixel. If  |1|X|1|
 *              determined to be noise (by user threshold)  |1|1|1|
 *              then middle pixel replaced by average
 * Parameters: image - the image to operate on
 * Returns: true if the image was successfully updated; otherwise, false
 *****************************************************************************/

#include "mainwindow.h"

bool MainWindow::Menu_Neighborhood_Mean_NxN( Image &image )
{

    if ( image.IsNull() ) return false; // not essential, but good practice

    //prompt user for filter size
    int threshold = 0;
    if(!Dialog("Filter Size").Add(threshold, "Size").Show())
        return false;

    //create filter (all ones)
    int filter[threshold][threshold];

    for ( int r = 0; r < threshold; r++ )
        for ( int c = 0; c < threshold; c++ )
        {
            filter[r][c] = 1;
        }

    //temp image
    Image imageCopy = image;

    // variables
    int nrows = image.Height();
    int ncols = image.Width();
    int intensity = 0;
    int offset = (threshold - 0.5) / 2;

    //check that threshold isn't nonsense (i.e. 0 or lower or larger than image)
    if(threshold < 1)
        return false;
    if(threshold > nrows || threshold > ncols)
        return false;

    //loop through every entry in source (now the copy)
    for ( int r = 0; r < nrows; r++ )
        for ( int c = 0; c < ncols; c++ )
        {
            //apply filter on copy back into original image
            for (int r2 = 0; r2 < threshold; r2++)
            {
                for (int c2 = 0; c2 < threshold; c2++)
                {
                    //here we use modulus wrapping in lookup
                    intensity += imageCopy[(r + r2 - offset + nrows) % nrows][(c + c2 - offset + nrows) % ncols] * filter[r2][c2];
                }
            }

            //weighted average
            intensity = intensity / (threshold*threshold);

            //if the average intensity of surrounding pixels minus the middle pixel is more than the threshold, replace middle with average
            if((imageCopy[r][c] - intensity) > threshold)
                image[r][c] = intensity;

            //reset average intensity
            intensity = 0;
        }

    // return true to update the image
    return true;
}
