
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "myrect.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //create a scene
    QGraphicsScene* scene = new QGraphicsScene();

    //create item to put in scene
    MyRect* rect = new MyRect;
    rect->setRect(0,0,100,100);

    //add item to scene
    scene->addItem(rect);

    //make rect focusable
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    //add a view
    QGraphicsView* view = new QGraphicsView(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();



    return a.exec();
}
