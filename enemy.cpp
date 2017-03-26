#include "enemy.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include <cmath>

Enemy::Enemy(int xpos, int ypos) : QObject(), QGraphicsRectItem()
{
    dx = 1;
    dy = 0;
    xdir = 1;
    speed = 1;
    setRect(0,0,40,40);
    setPos(xpos,ypos);
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(initSpeed);
}


void Enemy::move()
{
    setPos(x()+(40 * dx * xdir),y()+ (40 * dy));

    if(pos().x() == 800 - rect().width() && dx !=0){
        dy = 1;
        xdir = -1;
        dx = 0;
        speed++;
        timer->start(initSpeed / speed);
    }
    else if(pos().x()==0 && dx !=0){
        dy = 1;
        xdir = 1;
        dx = 0;
        speed++;
        timer->start(initSpeed / speed);
    }
        else {
        dx = 1;
        dy = 0;
    }


}
