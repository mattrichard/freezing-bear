#include "mainwindow.h"

using namespace std;

bool MainWindow::Menu_Neighborhood_Min(Image &image)
{
    if(image.IsNull())
        return false;

    int n;
    if(!Dialog("Filter size").Add(n, "size").Show())
        return false;

    if(n <= 0 || n > min((int)image.Height(), (int)image.Width()))
        return false;

    Image imageCopy = image;

    int lower = -n / 2;
    int upper = n / 2;

    if(n % 2 == 0)
        lower += 1;

    int nrows = image.Height();
    int ncols = image.Width();
    for(int r = 0; r < nrows; r++)
    {
        for(int c = 0; c < ncols; c++)
        {
            int min = 255;
            for(int i = lower; i <= upper; i++)
                for(int j = lower; j <= upper; j++)
                    if(imageCopy[(r + i + nrows) % nrows][(c + j + ncols) % ncols] < min)
                        min = imageCopy[(r + i + nrows) % nrows][(c + j + ncols) % ncols];

            image[r][c] = min;
        }
    }

    return true;
}
