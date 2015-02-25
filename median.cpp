/*

median.cpp

Assignment 2 for CSC 442

Author: Aubrey Olson // Matt Richard
Date:   Feb 2015

Modifications:
*/

#include "mainwindow.h"

#include <vector>
#include <algorithm>

using namespace std;

/******************************************************************************
 * Function: Menu_Neighborhood_Median_NxN
 * Description: Replaces each pixel in the given image with the median value
                in an nxn neighborhood of the pixel.
 * Parameters: image - the image to operate on
 * Returns: true if the image was successfully updated; otherwise, false
 *****************************************************************************/
bool MainWindow::Menu_Neighborhood_Median_NxN(Image &image)
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
            vector<int> list;

            // Add each pixel to a list to be sorted
            for(int i = lower; i <= upper; i++)
                for(int j = lower; j <= upper; j++)
                    list.push_back(imageCopy[(r + i + nrows) % nrows][(c + j + ncols) % ncols]);

            sort(list.begin(), list.end());

            image[r][c] = list[(list.size() - 1) / 2];
        }
    }

    return true;
}
