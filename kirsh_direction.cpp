/*

kirsh_direction.cpp

Assignment 2 for CSC 442

Author: Aubrey Olson // Matt Richard
Date:   Feb 2015

Modifications:
*/

#include "mainwindow.h"

/******************************************************************************
 * Function: Menu_Neighborhood_KirshDirection
 * Description: Uses 8 kirsh masks to detect edge direction on the given image.
 * Parameters: image - the image to operate on
 * Returns: true if the image was successfully updated; otherwise, false
 *****************************************************************************/
bool MainWindow::Menu_Neighborhood_KirshDirection(Image &image)
{
    Image imageCopy = image;
    int mask1[3][3] = {{-3, -3, 5}, {-3, 0, 5}, {-3, -3, 5}};
    int mask2[3][3] = {{-3, -3, -3}, {-3, 0, 5}, {-3, 5, 5}};
    int mask3[3][3] = {{-3, -3, -3}, {-3, 0, -3}, {5, 5, 5}};
    int mask4[3][3] = {{-3, -3, -3}, {5, 0, -3}, {5, 5, -3}};
    int mask5[3][3] = {{5, -3, -3}, {5, 0, -3}, {5, -3, -3}};
    int mask6[3][3] = {{5, 5, -3}, {5, 0, -3}, {-3, -3, -3}};
    int mask7[3][3] = {{5, 5, 5}, {-3, 0, -3}, {-3, -3, -3}};
    int mask8[3][3] = {{-3, 5, 5}, {-3, 0, 5}, {-3, -3, -3}};

    if(image.IsNull())
        return false;

    int nrows = image.Height();
    int ncols = image.Width();
    // Loop through every pixel in the image
    for(int r = 0; r < nrows; r++)
    {
        for(int c = 0; c < ncols; c++)
        {
            int intensity[8] = { 0 };
            // Convolve each of the 8 masks
            for(int i = -1; i <= 1; i++)
            {
                for(int j = -1; j <= 1; j++)
                {
                    intensity[0] += imageCopy[(r + i + nrows) % nrows][(c + j + ncols) % ncols] * mask1[i + 1][j + 1];
                    intensity[1] += imageCopy[(r + i + nrows) % nrows][(c + j + ncols) % ncols] * mask2[i + 1][j + 1];
                    intensity[2] += imageCopy[(r + i + nrows) % nrows][(c + j + ncols) % ncols] * mask3[i + 1][j + 1];
                    intensity[3] += imageCopy[(r + i + nrows) % nrows][(c + j + ncols) % ncols] * mask4[i + 1][j + 1];
                    intensity[4] += imageCopy[(r + i + nrows) % nrows][(c + j + ncols) % ncols] * mask5[i + 1][j + 1];
                    intensity[5] += imageCopy[(r + i + nrows) % nrows][(c + j + ncols) % ncols] * mask6[i + 1][j + 1];
                    intensity[6] += imageCopy[(r + i + nrows) % nrows][(c + j + ncols) % ncols] * mask7[i + 1][j + 1];
                    intensity[7] += imageCopy[(r + i + nrows) % nrows][(c + j + ncols) % ncols] * mask8[i + 1][j + 1];
                }
            }

            int max_index = 0;
            // Determine the direction from the mask that provides the maximum response
            for(int i = 0; i < 8; i++)
                if(intensity[i] > intensity[max_index])
                    max_index = i;
            int direction = (360 - max_index * 45) % 360;

            direction = direction / 360.0 * 255;

            image[r][c] = direction;
        }
    }

    return true;
}
