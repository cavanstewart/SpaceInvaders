#include "lazer.h"
#include "enemy.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>

int Lazer::numLazers = 0;

Lazer::Lazer ()
{
    setRect(0,0,10,50);
    setBrush(*new QBrush(Qt::yellow));
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(10);
    numLazers++;

}

Lazer::~Lazer(){
    numLazers--;
}


void Lazer::move(){
    QList<QGraphicsItem *> colliding_items = collidingItems();

    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){

            // remove them from the scene (still on the heap)
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            // delete them from the heap to save memory
            delete colliding_items[i];
            delete this;


            return;
        }
    }

    //move lazer up
    setPos(x(),y()-10);



    //delete lazer if it leaves scene
    if (pos().y() + rect().height() < 0){
        scene()->removeItem(this);
        delete this;
        static bool onScreen = false;
    }
}
