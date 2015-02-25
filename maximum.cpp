/*

maximum.cpp

Assignment 2 for CSC 442

Author: Aubrey Olson // Matt Richard
Date:   Feb 2015

Modifications:
*/

#include "mainwindow.h"

using namespace std;

/******************************************************************************
 * Function: Menu_Neighborhood_Maximum_NxN
 * Description:
 * Parameters: image - the image to operate on
 * Returns: true if the image was successfully updated; otherwise, false
 *****************************************************************************/
bool MainWindow::Menu_Neighborhood_Maximum_NxN(Image &image)
{
    Image imageCopy = image;

    if(image.IsNull())
        return false;

    int n = 3;
    // Get n from the user
    if(!Dialog("Filter size").Add(n, "Size").Show())
        return false;

    // Validate n
    if(n <= 0 || n > min((int)image.Height(), (int)image.Width()))
        return false;

    int lower = -n / 2;
    int upper = n / 2;

    if(n % 2 == 0)
        lower += 1;

    int nrows = image.Height();
    int ncols = image.Width();
    // Loop through every pixel in the image
    for(int r = 0; r < nrows; r++)
    {
        for(int c = 0; c < ncols; c++)
        {
            int max = 0;
            // Find the maximum intesity in a neighborhood of the image
            for(int i = lower; i <= upper; i++)
                for(int j = lower; j <= upper; j++)
                    if(imageCopy[(r + i + nrows) % nrows][(c + j + ncols) % ncols] > max)
                        max = imageCopy[(r + i + nrows) % nrows][(c + j + ncols) % ncols];

            image[r][c] = max;
        }
    }

    return true;
}
