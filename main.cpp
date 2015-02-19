#include "mainwindow.h"

int main(int argc, char *argv[])
{
    MainWindow mw;
    ImageApp app(argc, argv);
    app.AddActions(&mw);
    return app.Start();
}
