#include "enemy.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include <cmath>

int Enemy::distance = 440;

Enemy::Enemy(int xpos, int ypos) : QObject(), QGraphicsRectItem()
{
    dx = 1;
    dy = 0;
    xdir = 1;
    speed = 1;
    initx = xpos;
    setRect(0,0,40,40);
    setPos(xpos,ypos);
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(initSpeed);
}


void Enemy::move()
{
    setPos(x()+(40 * dx * xdir),y()+ (40 * dy));


    if(pos().x() == (initx + distance) && dx !=0){
        dy = 1;
        xdir = -1;
        dx = 0;
        speed++;
        timer->start(initSpeed / speed);
    }
    else if(pos().x()== initx && dx !=0){
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
