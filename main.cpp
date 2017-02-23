
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "myrect.h"
#include "enemy.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //create a scene
    QGraphicsScene* scene = new QGraphicsScene();

    //create item to put in scene
    MyRect* player = new MyRect;
    player->setRect(0,0,100,100);
    Enemy* enemy = new Enemy;
    //add player to scene
    scene->addItem(player);
    scene->addItem(enemy);

    //make rect focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //add a view
    QGraphicsView* view = new QGraphicsView(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);

    player->setPos(view->width()/2,view->height()-player->rect().height());

    return a.exec();
}
