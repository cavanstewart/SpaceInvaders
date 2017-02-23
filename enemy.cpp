#include "enemy.h"
#include <QGraphicsScene>
#include <QTimer>

Enemy::Enemy(int xpos, int ypos) : QObject(), QGraphicsRectItem()
{
    setRect(0,0,100,100);
    setPos(xpos,ypos);
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}


void Enemy::move()
{
    setPos(x()+5,y());
}
