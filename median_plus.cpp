/*

median_plus.cpp

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
 * Function: Menu_Neighborhood_MedianPlus
 * Description: Replaces each pixel in the given image with the median value
 *              in a plus shaped neighborhood of each pixel.
 * Parameters: image - the image to operate on
 * Returns: true if the image was successfully updated; otherwise, false
 *****************************************************************************/
bool MainWindow::Menu_Neighborhood_MedianPlus(Image &image)
{
    if(image.IsNull())
        return false;

    Image imageCopy = image;

    int nrows = image.Height();
    int ncols = image.Width();
    // Loop through every pixel in the image
    for(int r = 0; r < nrows; r++)
    {
        for(int c = 0; c < ncols; c++)
        {
            vector<int> list;

            // Add each pixel in a plus shape to a list to be sorted
            list.push_back(imageCopy[(r - 1 + nrows) % nrows][c]);
            list.push_back(imageCopy[r][(c - 1 + ncols) % ncols]);
            list.push_back(imageCopy[r][c]);
            list.push_back(imageCopy[r][(c + 1 + ncols) % ncols]);
            list.push_back(imageCopy[(r + 1 + nrows) % nrows][c]);

            sort(list.begin(), list.end());

            image[r][c] = list[(list.size() - 1) / 2];
        }
    }

    return true;
}
