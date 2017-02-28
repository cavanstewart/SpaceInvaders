#include "enemy.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include <cmath>

Enemy::Enemy(int xpos, int ypos) : QObject(), QGraphicsRectItem()
{
    dir = 1;
    setRect(0,0,40,40);
    setPos(xpos,ypos);
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(1000);
}


void Enemy::move()
{
    setPos(x()+(40 * dir),y());

    if(pos().x() == 800 - rect().width()){
        timer->stop();
        setPos(x(),y()+40);
        dir = -1;
    }

    if(pos().x()==0){
        dir = 1;
        setPos(x(),y()+40);
    }


}
