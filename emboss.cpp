#include "mainwindow.h"

bool MainWindow::Menu_Neighborhood_Emboss(Image &image)
{
    if(image.IsNull()) return false;

    Image imageCopy = image;
    int mask[3][3] = {{0, 0, 0}, {0, -1, 0}, {0, 0, 1}};

    int nrows = image.Height();
    int ncols = image.Width();
    for(int r = 0; r < nrows; r++)
    {
        for(int c = 0; c < ncols; c++)
        {
            int intensity = 0;
            for(int i = -1; i <=1; i++)
                for(int j = -1; j <= 1; j++)
                    intensity += imageCopy[(r + i + nrows) % nrows][(c + j + ncols) % ncols] * mask[i + 1][j + 1];

            intensity = (intensity + 255) / 2.0;

            if(intensity > 255)
                intensity = 255;
            else if(intensity < 0)
                intensity = 0;

            image[r][c] = intensity;
        }
    }

    return true;
}
