#include "mainwindow.h"

#include <vector>
#include <algorithm>

using namespace std;

bool MainWindow::Menu_Neighborhood_PlusShapedMedian(Image &image)
{
    if(image.IsNull())
        return false;

    Image imageCopy = image;

    int nrows = image.Height();
    int ncols = image.Width();
    for(int r = 0; r < nrows; r++)
    {
        for(int c = 0; c < ncols; c++)
        {
            vector<int> list;

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
