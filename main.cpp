/*

main.cpp

Assignment 2 for CSC 442

Author: Aubrey Olson // Matt Richard
Date:   Feb 2015

Modifications:
*/

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    MainWindow mw;
    ImageApp app(argc, argv);
    app.AddActions(&mw);
    return app.Start();
}
