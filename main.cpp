
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //create a scene
    QGraphicsScene* scene = new QGraphicsScene();

    //create item to put in scene
    QGraphicsRectItem* rect = new QGraphicsRectItem;
    rect->setRect(0,0,100,100);

    //add item to scene
    scene->addItem(rect);

    //add a view
    QGraphicsView* view = new QGraphicsView(scene);


    view->show();



    return a.exec();
}
