
#include <QApplication>
#include "title.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

   Title window;
   window.show();

    return a.exec();
}
