#include <QApplication>
#include "exitmsg.h"
#include "textedit.h"

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    Window w;
    w.setFixedSize(250,170);
    w.show();
    return a.exec();
}


